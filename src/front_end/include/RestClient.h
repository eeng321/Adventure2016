// Created by michael on 30/09/16.
//

#ifndef ADVENTURE2016_RESTCLIENT_H
#define ADVENTURE2016_RESTCLIENT_H

#include <iostream>
#include "include/net.h"
#include "include/http.h"
#include "include/client.h"

namespace Rest {

    class RestClient {
    public:
        RestClient();
        std::string Get(std::string request);
        std::string Post(std::string request, std::string payload);
        std::string Put(std::string request);
        std::string Delete(std::string request);

    private:
        Net::Http::Client _client;
    };
}

#endif //ADVENTURE2016_RESTCLIENT_H
