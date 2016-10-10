//
// Created by michael on 10/10/16.
//

#ifndef ADVENTURE2016_PLAYERENDPOINT_H
#define ADVENTURE2016_PLAYERENDPOINT_H

#include "../lib/pistache/include/net.h"
#include "../lib/pistache/include/http.h"
#include "../lib/pistache/include/client.h"
#include "../lib/pistache/include/endpoint.h"
#include "../lib/pistache/include/router.h"

namespace PlayerEndpoint {

    void login(const Net::Rest::Request& request, Net::Http::ResponseWriter response);
    void getPlayer(const Net::Rest::Request& request, Net::Http::ResponseWriter response);
    void createPlayer(const Net::Rest::Request& request, Net::Http::ResponseWriter response);

}

#endif //ADVENTURE2016_PLAYERENDPOINT_H
