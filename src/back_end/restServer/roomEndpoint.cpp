//
// Created by sukh on 14/10/16.
//

#include "roomEndpoint.h"
#include <iostream>
#include <sstream>

#include "roomDriver.h"
#include <boost/algorithm/string.hpp>

using namespace std;
using namespace Net;



void RoomEndpoint::createRoom(const Net::Rest::Request& request, Net::Http::ResponseWriter response){
  /*  cout << "Request for resource: " << request.method() << request.resource() << endl;
    //auto roomModel = parser::roomDesearialize(request.body()); //if parser is complete
    //auto createdRoom = //wait for parser

    istringstream roomParams(request.body());
    int linesRequestBody = 8;
    string parseBody(linesRequestBody);

    for (int i =0; i < linesRequestBody; i++){
         getline(roomParams, parseBody[i]);
    }

    RoomModel demo = addRoom(stoi(parseBody[3], parseBody[7]));
    cout << "Printing newly added room \n";
    cout << demo.roomId << endl;
    cout << demo.mainDescription << endl;
    cout << demo.name << endl;

    auto success = true;

    if (success) {
        response.send(Http::Code::Ok, demo);
    }
    else {
        response.send(Http::Code::Bad_Request);
    }

*/
}
void RoomEndpoint::retrieveRoom(const Net::Rest::Request& request, Net::Http::ResponseWriter response){
    cout << "Request for resource: " << request.method() << request.resource() << endl;
    try {
        auto roomId = request.param(":id").as<int>();

        RoomModel room;
        room.name = "";
        room = loadRoom(roomId);

        if (room.name != "") {
            response.send(Http::Code::Ok, room.name);
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

}
void RoomEndpoint::deleteRoom(const Net::Rest::Request& request, Net::Http::ResponseWriter response);
