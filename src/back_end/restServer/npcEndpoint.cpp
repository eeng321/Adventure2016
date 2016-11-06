//
// Created by michael on 10/10/16.
//

#include <sstream>
#include <iostream>
#include "npcEndpoint.h"
#include "parser.h"
#include "npcDriver.h"
#include <boost/algorithm/string.hpp>

using namespace std;
using namespace Net;

void NpcEndpoint::createNpc(const Rest::Request& request, Net::Http::ResponseWriter response) {
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

void NpcEndpoint::retrieveNpc(const Rest::Request& request, Net::Http::ResponseWriter response) {
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

void NpcEndpoint::updateNpc(const Rest::Request& request, Net::Http::ResponseWriter response) {
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

void NpcEndpoint::deleteNpc(const Rest::Request& request, Net::Http::ResponseWriter response) {
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
