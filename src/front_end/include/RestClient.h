// Created by michael on 30/09/16.
//

#ifndef ADVENTURE2016_RESTCLIENT_H
#define ADVENTURE2016_RESTCLIENT_H

#include <iostream>
#include "../../back_end/lib/pistache/include/net.h"
#include "../../back_end/lib/pistache/include/http.h"
#include "../../back_end/lib/pistache/include/client.h"

namespace Rest {

    class RestClient {
    public:
        RestClient();
        Net::Http::Response Get(std::string request);
        Net::Http::Response Post(std::string request, std::string payload);
        Net::Http::Response Put(std::string request, std::string payload);
        Net::Http::Response Delete(std::string request);

    private:
        Net::Http::Client _client;
    };
}

#endif //ADVENTURE2016_RESTCLIENT_H
