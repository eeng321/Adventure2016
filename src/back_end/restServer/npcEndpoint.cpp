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
        NpcModel npc;
        npc = parser::npcDeserialize(request.body());

        addNpc(npc);

        //todo: fix this with proper returns
        auto success = true;
        if (success) {
            response.send(Http::Code::Created, parser::npcSerialize(npc));
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
        auto npcId = request.param(":id").as<int>();

        NpcModel npc;
        npc.level = -1; //used to test if npc is retrieved properly
        npc = loadNpc(npcId); //if succeed, level won't be -1

        if (npc.level != -1) {
            response.send(Http::Code::Ok, parser::npcSerialize(npc));
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
        auto npcId = request.param(":id").as<int>();
        NpcModel updateFields = parser::npcDeserialize(request.body());

        auto updatedNpc = modifyNpc(npcId, updateFields);

        //todo: fix this with proper returns
        if (true) {
            response.send(Http::Code::Ok, parser::npcSerialize(updatedNpc));
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
        auto npcId = request.param(":id").as<int>();
        removeNpc(npcId);

        //todo: fix this with proper returns
        if (true) {
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
