/* 
   Reference Code: Mathieu Stefani, 07 février 2016
   Updated by: Michael Nguyen for CMPT 373.
*/

//#include "http.h"
//#include "router.h"
//#include "endpoint.h"
//#include "lib/pistache/include/net.h"
//#include "lib/pistache/include/http.h"
//#include "lib/pistache/include/client.h"
#include "../lib/pistache/include/net.h"
#include "../lib/pistache/include/http.h"
#include "../lib/pistache/include/client.h"
#include "../lib/pistache/include/endpoint.h"
#include "../lib/pistache/include/router.h"
#include "../lib/hiberlite/include/hiberlite.h"
#include "../../model/include/player.h"
#include <algorithm>


using namespace std;
using namespace Net;

//todo: move these to new  class files
class PlayerEndPoint {
public:
    PlayerEndPoint(Net::Address addr) : httpEndpoint(std::make_shared<Net::Http::Endpoint>(addr)) { }

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
        Routes::Post(router, "/login", Routes::bind(&PlayerEndPoint::login, this));
        Routes::Get(router, "/player/:id", Routes::bind(&PlayerEndPoint::getPlayer, this));
        Routes::Post(router, "/player", Routes::bind(&PlayerEndPoint::createPlayer, this));
    }

    void login(const Rest::Request& request, Net::Http::ResponseWriter response) {
        cout << "Request for resource: " << request.resource() << endl;

        // Grab username
        // Grab password

        // Verify with DB.
        cout << request.resource() << endl;
        response.send(Http::Code::Ok, "/login Success!\n");
    }

    void getPlayer(const Rest::Request& request, Net::Http::ResponseWriter response) {
        cout << "Request for resource: " << request.resource() << endl;

        // todo: Route this to PlayerController to update DB Model
        auto playerId = request.param(":id").as<int>();

        hiberlite::Database db("player.db");
        //register bean class
        db.registerBeanClass<Player>();

        hiberlite::bean_ptr<Player> p=db.loadBean<Player>(1);
        cout << p->id;
        auto mockedPlayer = "";
        // auto mockedPlayer = "[\n"
        //         "  {\n"
        //         "    \"id\": " + std::to_string(playerId) + "\n"
        //         "  },\n"
        //         "  {\n"
        //         "    \"name\": \"Michael Nguyen\"\n"
        //         "  },\n"
        //         "  {\n"
        //         "    \"age\": 23\n"
        //         "  },\n"
        //         "  {\n"
        //         "    \"health\": 100\n"
        //         "  }\n"
        //         "]\n";

        response.send(Http::Code::Ok, mockedPlayer);
    }

    void createPlayer(const Rest::Request& request, Net::Http::ResponseWriter response) {
        cout << "Request for resource: " << request.resource() << endl;

        auto body = request.body();

        // Parse body to grab player arguments

        //hiberlite
        hiberlite::Database db("player.db");

        //register bean class
        db.registerBeanClass<Player>();
        //drop all tables beans will use
        db.dropModel();
        //create those tables again with proper schema
        db.createModel();

        Player demo;

        hiberlite::bean_ptr<Player> p=db.copyBean(demo); //create a managed copy of the object
        cout << p->id;
        cout << demo.id;

        //

        // Send Success/Fail
        response.send(Http::Code::Ok, body);
    }
};

int main(int argc, char *argv[]) {
    // todo: Grab these from config file
    Net::Port port(8080);
    int numThreads = 2;

    Net::Address addr(Net::Ipv4::any(), port);

    cout << "Welcome to Adventure 2016 by Team Ashure." << endl;
    cout << "Adventure Server Configured for: http://" << addr.host() << ":" << addr.port() << endl;
    cout << "CPU Cores = " << hardware_concurrency() << endl;
    cout << "Using " << numThreads << " threads" << endl;

    PlayerEndPoint playerEndPoint(addr);

    playerEndPoint.init(numThreads);
    playerEndPoint.start();

    playerEndPoint.shutdown();
}
