//
// Created by sukh on 14/10/16.
//

#include "roomEndpoint.h"
#include <iostream>
#include <sstream>

#include "roomDriver.h"
#include <boost/algorithm/string.hpp>
#include "parser.h"

using namespace std;
using namespace Net;



void RoomEndpoint::createRoom(const Net::Rest::Request& request, Net::Http::ResponseWriter response){
    cout << "Request for resource: " << request.method() << request.resource() << endl;

    try {
        //auto roomId = request.param(":id").as<int>();
        //auto roomName = request.param(":name").as<std::string>();

        // Parse body to grab room arguments
        RoomModel room;
        room = parser::roomDeserialize(request.body());

        addRoom(room);

        auto success = true;
        if (success) {
            response.send(Http::Code::Created, parser::roomSerialize(room));
        }
        else {
            response.send(Http::Code::Bad_Request);
        }
    }
    catch (...) {
        response.send(Http::Code::Internal_Server_Error);
    }
}
void RoomEndpoint::retrieveRoom(const Net::Rest::Request& request, Net::Http::ResponseWriter response){
    cout << "Request for resource: " << request.method() << request.resource() << endl;
    try {

        auto roomId = request.param(":id").as<int>();
        cout << "ID: " << roomId << endl;

        RoomModel room;
        room = loadRoom(roomId);

        if (room.name != "") {
            response.send(Http::Code::Ok, parser::roomSerialize(room));
        }
        else {
            response.send(Http::Code::Bad_Request);
        }
    }
    catch (...) {
        response.send(Http::Code::Internal_Server_Error);
    }
}
void RoomEndpoint::updateRoom(const Net::Rest::Request& request, Net::Http::ResponseWriter response){
    cout << "Request for resource: " << request.method() << request.resource() << endl;

    try {
        auto roomId = request.param(":id").as<int>();
        RoomModel updateFields = parser::roomDeserialize(request.body());

        auto updatedRoom = modifyRoom(roomId, updateFields);

        //todo: fix this with proper returns
        if (true) {
            response.send(Http::Code::Ok, parser::roomSerialize(updatedRoom));
        }
        else {
            response.send(Http::Code::Bad_Request);
        }
    }
    catch (...) {
        response.send(Http::Code::Internal_Server_Error);
    }
}
void RoomEndpoint::deleteRoom(const Net::Rest::Request& request, Net::Http::ResponseWriter response){
    cout << "Request for resource: " << request.method() << request.resource() << endl;

    try {
        auto roomId = request.param(":id").as<int>();
        auto success = removeRoom(roomId);

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
