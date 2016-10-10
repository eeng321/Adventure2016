//
// Created by michael on 10/10/16.
//

#include "playerEndpoint.h"
#include "../lib/pistache/include/net.h"
#include "../lib/pistache/include/http.h"
#include "../lib/pistache/include/client.h"
#include "../lib/pistache/include/endpoint.h"
#include "../lib/pistache/include/router.h"

using namespace std;
using namespace Net;

void PlayerEndpoint::login(const Rest::Request& request, Net::Http::ResponseWriter response) {
    cout << "Request for resource: " << request.resource() << endl;

    request.param("test").name();

    // Verify credentials with DB. => bool

    response.send(Http::Code::Ok, "200");
}

void PlayerEndpoint::getPlayer(const Rest::Request& request, Net::Http::ResponseWriter response) {
    cout << "Request for resource: " << request.resource() << endl;

    // todo: Route this to PlayerController to update DB Model
    auto playerId = request.param(":id").as<int>();
    auto mockedPlayer = "[\n"
                                "  {\n"
                                "    \"id\": " + std::to_string(playerId) + "\n"
                                "  },\n"
                                "  {\n"
                                "    \"name\": \"Michael Nguyen\"\n"
                                "  },\n"
                                "  {\n"
                                "    \"age\": 23\n"
                                "  },\n"
                                "  {\n"
                                "    \"health\": 100\n"
                                "  }\n"
                                "]\n";

    response.send(Http::Code::Ok, mockedPlayer);
}

void PlayerEndpoint::createPlayer(const Rest::Request& request, Net::Http::ResponseWriter response) {
    cout << "Request for resource: " << request.resource() << endl;

    auto body = request.body();

    // Parse body to grab player arguments

    // Send to ODB

    // Send Success/Fail
    response.send(Http::Code::Ok, body);
}
