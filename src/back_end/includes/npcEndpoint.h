
#ifndef ADVENTURE2016_NPCENDPOINT_H
#define ADVENTURE2016_NPCENDPOINT_H

#include "../lib/pistache/include/http.h"
#include "../lib/pistache/include/router.h"
#include "../lib/pistache/include/client.h"
#include "../lib/pistache/include/endpoint.h"


namespace NpcEndpoint {

    void createNpc(const Net::Rest::Request& request, Net::Http::ResponseWriter response);
    void retrieveNpc(const Net::Rest::Request& request, Net::Http::ResponseWriter response);
    void updateNpc(const Net::Rest::Request& request, Net::Http::ResponseWriter response);
    void deleteNpc(const Net::Rest::Request& request, Net::Http::ResponseWriter response);
}

#endif //ADVENTURE2016_NPCENDPOINT_H
