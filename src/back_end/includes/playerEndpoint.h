//
// Created by michael on 10/10/16.
//

#ifndef ADVENTURE2016_PLAYERENDPOINT_H
#define ADVENTURE2016_PLAYERENDPOINT_H

#include "../lib/pistache/include/http.h"
#include "../lib/pistache/include/router.h"
#include "parser.h"

namespace PlayerEndpoint {

    void login(const Net::Rest::Request& request, Net::Http::ResponseWriter response);

    void createPlayer(const Net::Rest::Request& request, Net::Http::ResponseWriter response);
    void retrievePlayer(const Net::Rest::Request& request, Net::Http::ResponseWriter response);
    void updatePlayer(const Net::Rest::Request& request, Net::Http::ResponseWriter response);
    void deletePlayer(const Net::Rest::Request& request, Net::Http::ResponseWriter response);

}

#endif //ADVENTURE2016_PLAYERENDPOINT_H
