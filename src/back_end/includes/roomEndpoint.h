//
// Created by sukh on 14/10/16.
//

#ifndef ADVENTURE2016_ROOMENDPOINT_H
#define ADVENTURE2016_ROOMENDPOINT_H

#include "../lib/pistache/include/http.h"
#include "../lib/pistache/include/router.h"
#include "../lib/pistache/include/client.h"
#include "../lib/pistache/include/endpoint.h"

namespace RoomEndpoint {

    void createRoom(const Net::Rest::Request& request, Net::Http::ResponseWriter response);
    void retrieveRoom(const Net::Rest::Request& request, Net::Http::ResponseWriter response);
    void updateRoom(const Net::Rest::Request& request, Net::Http::ResponseWriter response);
    void deleteRoom(const Net::Rest::Request& request, Net::Http::ResponseWriter response);

}

#endif //ADVENTURE2016_ROOMENDPOINT_H
