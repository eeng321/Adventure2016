/* 
   Reference Code: Mathieu Stefani, 07 février 2016
   Updated by: Michael Nguyen for CMPT 373.
*/

#include <algorithm>
#include <string.h>
#include "../lib/pistache/include/net.h"
#include "../lib/pistache/include/http.h"
#include "../lib/pistache/include/client.h"
#include "../lib/pistache/include/endpoint.h"
#include "../lib/pistache/include/router.h"
#include "playerDriver.h"
#include "playerEndpoint.h"
#include "roomDriver.h"
#include "roomEndpoint.h"
#include "etlJob.h"
#include "npcDriver.h"
#include "npcEndpoint.h"
#include "chatEndpoint.h"
#include "itemEndpoint.h"
#include "Constants.h"

using namespace std;
using namespace Net;

class Endpoints {
public:
    Endpoints(Net::Address addr) : httpEndpoint(std::make_shared<Net::Http::Endpoint>(addr)) { }

    void init(size_t thr = 2) {
        auto opts = Net::Http::Endpoint::options()
                .threads(thr)
                .flags(Net::Tcp::Options::InstallSignalHandler);
        httpEndpoint->init(opts);
        //todo: [mn]: Pistache is having trouble using smart pointers. Using crappy pointers in the mean time.
        chatEndpoint = new ChatEndpoint();
        setupRoutes();
    }

    void start() {
        httpEndpoint->setHandler(router.handler());
        httpEndpoint->serve();
    }

    void shutdown() {
        delete chatEndpoint;
        httpEndpoint->shutdown();
    }

private:
    std::shared_ptr<Net::Http::Endpoint> httpEndpoint;
    Rest::Router router;
    ChatEndpoint *chatEndpoint;

    void setupRoutes() {
        using namespace Net::Rest;

        // Authentication Routes
        Routes::Post(router, "/login", Routes::bind(&PlayerEndpoint::login));
        Routes::Post(router, "/register", Routes::bind(&PlayerEndpoint::registerPlayer));

        // Player CRUDS
        Routes::Get(router, "/player/:id", Routes::bind(&PlayerEndpoint::retrievePlayer));
        Routes::Put(router, "/player/:id", Routes::bind(&PlayerEndpoint::updatePlayer));
        Routes::Post(router, "/player", Routes::bind(&PlayerEndpoint::createPlayer));
        Routes::Delete(router, "/player/:id", Routes::bind(&PlayerEndpoint::deletePlayer));

        // Item CRUDS
        Routes::Get(router, "/item/:id", Routes::bind(&ItemEndpoint::retrieveItem));
        Routes::Put(router, "/item/:id", Routes::bind(&ItemEndpoint::updateItem));
        Routes::Post(router, "/item", Routes::bind(&ItemEndpoint::createItem));
        Routes::Delete(router, "/item/:id", Routes::bind(&ItemEndpoint::deleteItem));

        // Todo: Room Routes
        Routes::Get(router, "/room/:id", Routes::bind(&RoomEndpoint::retrieveRoom));
        Routes::Put(router, "/room/:id", Routes::bind(&RoomEndpoint::updateRoom));
        Routes::Post(router, "/room", Routes::bind(&RoomEndpoint::createRoom));
        Routes::Delete(router, "/room/:id", Routes::bind(&RoomEndpoint::deleteRoom));

        // Chat Routes
        Routes::Get(router, "/chat", Routes::bind(&ChatEndpoint::getMessage, chatEndpoint));
        Routes::Post(router, "/chat", Routes::bind(&ChatEndpoint::sendMessage, chatEndpoint));

        //NPC CRUDS
        Routes::Get(router, "/npc/:id", Routes::bind(&NpcEndpoint::retrieveNpc));
        Routes::Put(router, "/npc/:id", Routes::bind(&NpcEndpoint::updateNpc));
        Routes::Post(router, "/npc", Routes::bind(&NpcEndpoint::createNpc));
        Routes::Delete(router, "/npc/:id", Routes::bind(&NpcEndpoint::deleteNpc));
    }
};



int main(int argc, char *argv[]) {

    // todo: Grab these from config file or command line?
    if (argc >= 3) {
        try {
            Net::Port port(std::stol(argv[2]));

            int bytes[kNumBytesInIpv4];
            char *inputAddr = argv[1];
            char *parseAddr = strtok(argv[1], kAddresDelim);

            for (int i = 0; i < kNumBytesInIpv4; i++) {
                bytes[i] = std::stol(parseAddr);
                parseAddr = strtok(NULL, kAddresDelim);
            }
            Ipv4 ipv4Addr(bytes[0], bytes[1], bytes[2], bytes[3]);
            Net::Address addr(ipv4Addr, port);
        }
        catch (int e) {
            throw e;
        }
    }
    Net::Port port(kDefaultPort);
    Net::Address addr(Net::Ipv4::any(), port);

    int numThreads = kDefaultThreads;

    cout << "Welcome to Adventure 2016 by Team Ashure!" << endl;
    cout << "Adventure Server Configured for: http://" << addr.host() << ":" << addr.port() << endl;
    cout << "CPU Cores = " << hardware_concurrency() << endl;
    cout << "Using " << numThreads << " threads" << endl;

    etl::createDB();
    printNpc();
    printRoomDB();
    Endpoints endpoints(addr);

    endpoints.init(numThreads);
    endpoints.start();

    endpoints.shutdown();

}
