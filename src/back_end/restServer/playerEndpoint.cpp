//
// Created by michael on 10/10/16.
//

#include <sstream>
#include <iostream>
#include "playerEndpoint.h"
#include "parser.h"
#include "playerDriver.h"
#include <boost/algorithm/string.hpp>

using namespace std;
using namespace Net;

void PlayerEndpoint::login(const Rest::Request& request, Net::Http::ResponseWriter response) {
    cout << "Request for resource: " << request.method() << request.resource() << endl;

    try {
        string accountInfo(request.body());
        vector<string> inputs;
        boost::split(inputs, accountInfo, boost::is_any_of("?=&"));

        PlayerModel player = verifyCredentials(inputs[2], inputs[4]);

        if (player.loginName == inputs[2]) {
            response.send(Http::Code::Ok, parser::playerSerialize(player));
        }
        else {
            response.send(Http::Code::Forbidden);
        }
    }
    catch (...) {
        response.send(Http::Code::Internal_Server_Error);
    }
}

void PlayerEndpoint::registerPlayer(const Rest::Request& request, Net::Http::ResponseWriter response) {
    cout << "Request for resource: " << request.method() << request.resource() << endl;

    try {
        string accountInfo(request.body());
        vector<string> inputs;
        boost::split(inputs, accountInfo, boost::is_any_of("?=&"));

        PlayerModel player = registerAccount(inputs[2], inputs[4]);

        if (player.loginName == inputs[2]) {
            response.send(Http::Code::Ok, parser::playerSerialize(player));
        }
        // else if (player.loginName == ""){
        //     response.send(Http::Code::Forbidden, "Username already exists.\n");
        // }
        else {
            response.send(Http::Code::Forbidden);
        }
    }
    catch (...) {
        response.send(Http::Code::Internal_Server_Error);
    }

}

void PlayerEndpoint::createPlayer(const Rest::Request& request, Net::Http::ResponseWriter response) {
    cout << "Request for resource: " << request.method() << request.resource() << endl;

    try {
        // Parse body to grab player arguments
        PlayerModel player;
        player = parser::playerDeserialize(request.body());

        addPlayer(player);

        //todo: fix this with proper returns
        auto success = true;
        if (success) {
            response.send(Http::Code::Created, parser::playerSerialize(player));
        }
        else {
            response.send(Http::Code::Bad_Request);
        }
    }
    catch (...) {
        response.send(Http::Code::Internal_Server_Error);
    }
}

void PlayerEndpoint::retrievePlayer(const Rest::Request& request, Net::Http::ResponseWriter response) {
    cout << "Request for resource: " << request.method() << request.resource() << endl;

    try {
        auto playerId = request.param(":id").as<int>();

        PlayerModel player;
        player.loginName = "";
        player = loadPlayer(playerId);

        if (player.loginName != "") {
            response.send(Http::Code::Ok, parser::playerSerialize(player));
        }
        else {
            response.send(Http::Code::Bad_Request);
        }
    }
    catch (...) {
        response.send(Http::Code::Internal_Server_Error);
    }
}

void PlayerEndpoint::updatePlayer(const Rest::Request& request, Net::Http::ResponseWriter response) {
    cout << "Request for resource: " << request.method() << request.resource() << endl;

    try {
        auto playerId = request.param(":id").as<int>();
        PlayerModel updateFields = parser::playerDeserialize(request.body());

        auto updatedPlayer = modifyPlayer(playerId, updateFields);

        //todo: fix this with proper returns
        if (true) {
            response.send(Http::Code::Ok, parser::playerSerialize(updatedPlayer));
        }
        else {
            response.send(Http::Code::Bad_Request);
        }
    }
    catch (...) {
        response.send(Http::Code::Internal_Server_Error);
    }
}

void PlayerEndpoint::deletePlayer(const Rest::Request& request, Net::Http::ResponseWriter response) {
    cout << "Request for resource: " << request.method() << request.resource() << endl;

    try {
        auto playerId = request.param(":id").as<int>();
        removePlayer(playerId);

        //todo: fix this with proper returns
        auto success = true;
        if (success) {
            response.send(Http::Code::Ok);
        }
        else {
            response.send(Http::Code::Bad_Request);
        }
    }
    catch (...) {
        response.send(Http::Code::Internal_Server_Error);
    }
}
