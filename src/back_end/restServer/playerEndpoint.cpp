//
// Created by michael on 10/10/16.
//

#include "playerEndpoint.h"

#include "../lib/pistache/include/client.h"
#include "../lib/pistache/include/endpoint.h"

using namespace std;
using namespace Net;

void PlayerEndpoint::login(const Rest::Request& request, Net::Http::ResponseWriter response) {
    cout << "Request for resource: " << request.method() << request.resource() << endl;

    // Verify credentials with DB.

    auto success = true;
    if (success) {
        response.send(Http::Code::Ok, "Success. Returns the retrieved player YAML");
    }
    else {
        response.send(Http::Code::Forbidden);
    }
}

void PlayerEndpoint::createPlayer(const Rest::Request& request, Net::Http::ResponseWriter response) {
    cout << "Request for resource: " << request.method() << request.resource() << endl;

    // Parse body to grab player arguments

    // Send to ODB
    auto success = true;
    if (success) {
        response.send(Http::Code::Created, "Success. Returns Created Player Yaml.");
    }
    else {
        response.send(Http::Code::Bad_Request);
    }
}

void PlayerEndpoint::retrievePlayer(const Rest::Request& request, Net::Http::ResponseWriter response) {
    cout << "Request for resource: " << request.method() << request.resource() << endl;

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

    auto success = true;
    if (success) {
        response.send(Http::Code::Ok, mockedPlayer);
    }
    else {
        response.send(Http::Code::Bad_Request);
    }
}

void PlayerEndpoint::updatePlayer(const Rest::Request& request, Net::Http::ResponseWriter response) {
    cout << "Request for resource: " << request.method() << request.resource() << endl;

    auto playerId = request.param(":id").as<int>();

    // Parse body to grab player arguments

    // Send to ODB
    auto success = true;
    if (success) {
        response.send(Http::Code::Ok, "Success. Returns Updated Player Yaml.");
    }
    else {
        response.send(Http::Code::Bad_Request);
    }
}

void PlayerEndpoint::deletePlayer(const Rest::Request& request, Net::Http::ResponseWriter response) {
    cout << "Request for resource: " << request.method() << request.resource() << endl;

    auto playerId = request.param(":id").as<int>();

    // Parse body to grab player arguments

    // Send to ODB
    auto success = true;
    if (success) {
        response.send(Http::Code::Ok);
    }
    else {
        response.send(Http::Code::Bad_Request);
    }
}