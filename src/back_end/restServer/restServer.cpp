/* 
   Reference Code: Mathieu Stefani, 07 février 2016
   Updated by: Michael Nguyen for CMPT 373.
*/

#include "../lib/pistache/include/net.h"
#include "../lib/pistache/include/http.h"
#include "../lib/pistache/include/client.h"
#include "../lib/pistache/include/endpoint.h"
#include "../lib/pistache/include/router.h"

#include "playerEndpoint.h"
//#include "../lib/yaml-parser/include/yaml-cpp/yaml.h"

#include <algorithm>

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
        Routes::Post(router, "/login", Routes::bind(&PlayerEndpoint::login));
        Routes::Get(router, "/player/:id", Routes::bind(&PlayerEndpoint::getPlayer));
        Routes::Post(router, "/player", Routes::bind(&PlayerEndpoint::createPlayer));
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

    Endpoints endpoints(addr);

    endpoints.init(numThreads);
    endpoints.start();

    endpoints.shutdown();
}
