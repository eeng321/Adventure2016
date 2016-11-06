/* 
   Reference Code: Mathieu Stefani, 07 février 2016
   Updated by: Michael Nguyen for CMPT 373.
*/

#include <algorithm>
#include "../lib/pistache/include/net.h"
#include "../lib/pistache/include/http.h"
#include "../lib/pistache/include/client.h"
#include "../lib/pistache/include/endpoint.h"
#include "../lib/pistache/include/router.h"
#include "playerDriver.h"
#include "playerEndpoint.h"
#include "npcDriver.h"
#include "npcEndpoint.h"


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
        setupRoutes();
    }

    void start() {
        httpEndpoint->setHandler(router.handler());
        httpEndpoint->serve();
    }

    void shutdown() {
        httpEndpoint->shutdown();
    }

private:
    std::shared_ptr<Net::Http::Endpoint> httpEndpoint;
    Rest::Router router;

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

        //NPC CRUDS
        Routes::Get(router, "/npc/:id", Routes::bind(&NpcEndpoint::retrieveNpc));
        Routes::Put(router, "/npc/:id", Routes::bind(&NpcEndpoint::updateNpc));
        Routes::Post(router, "/npc", Routes::bind(&NpcEndpoint::createNpc));
        Routes::Delete(router, "/npc/:id", Routes::bind(&NpcEndpoint::deleteNpc));
        // Todo: Room Routes
        // Routes::Get(router, "/room/:id", Routes::bind(&RoomEndpoint::retrieveRoom));
        // Routes::Put(router, "/room/:id", Routes::bind(&RoomEndpoint::updateRoom));
        // Routes::Post(router, "/room", Routes::bind(&RoomEndpoint::createRoom));
        // Routes::Delete(router, "/room/:id", Routes::bind(&RoomEndpoint::deleteRoom));

    }
};

int main(int argc, char *argv[]) {
    // todo: Grab these from config file or command line?
    Net::Port port(8080);
    int numThreads = 2;

    if (argc >= 2) {
        port = std::stol(argv[1]);
    }

    Net::Address addr(Net::Ipv4::any(), port);

    cout << "Welcome to Adventure 2016 by Team Ashure!" << endl;
    cout << "Adventure Server Configured for: http://" << addr.host() << ":" << addr.port() << endl;
    cout << "CPU Cores = " << hardware_concurrency() << endl;
    cout << "Using " << numThreads << " threads" << endl;

    createDB();
    //createRoomDB();
    //printRoomDB();

    Endpoints endpoints(addr);

    endpoints.init(numThreads);
    endpoints.start();

    endpoints.shutdown();
}
