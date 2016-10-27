
#ifndef ADVENTURE2016_ITEMENDPOINT_H
#define ADVENTURE2016_ITEMENDPOINT_H

#include "../lib/pistache/include/http.h"
#include "../lib/pistache/include/router.h"
#include "../lib/pistache/include/client.h"
#include "../lib/pistache/include/endpoint.h"


namespace ItemEndpoint {

    void login(const Net::Rest::Request& request, Net::Http::ResponseWriter response);
    void registerItem(const Net::Rest::Request& request, Net::Http::ResponseWriter response);

    void createItem(const Net::Rest::Request& request, Net::Http::ResponseWriter response);
    void retrieveItem(const Net::Rest::Request& request, Net::Http::ResponseWriter response);
    void updateItem(const Net::Rest::Request& request, Net::Http::ResponseWriter response);
    void deleteItem(const Net::Rest::Request& request, Net::Http::ResponseWriter response);
}

#endif //ADVENTURE2016_ITEMENDPOINT_H
