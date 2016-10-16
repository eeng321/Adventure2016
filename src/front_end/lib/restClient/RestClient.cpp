//
// Created by Michael Nguyen on 29/09/16.
// Reference by: Mathieu Stefani, 07 février 2016
//

#include "RestClient.h"
#include "../../../back_end/includes/parser.h"
using namespace Rest;

const int NUM_THREADS = 8;
const int MAX_CONNECTIONS_PER_HOST = 8;

RestClient::RestClient() {
    auto options = Net::Http::Client::options()
            .threads(NUM_THREADS)
            .maxConnectionsPerHost(MAX_CONNECTIONS_PER_HOST);
    _client.init(options);
}

std::string RestClient::Get(std::string request) {
    std::vector<Async::Promise<Net::Http::Response>> responses;
    std::string body;
    auto resp = _client.get(request).send();
    resp.then([&](Net::Http::Response response) {
        if (response.code() == Net::Http::Code(400)){
            body = "Fail";
        }
        body = response.body();

    }, Async::IgnoreException);
    responses.push_back(std::move(resp));

    auto sync = Async::whenAll(responses.begin(), responses.end());
    Async::Barrier<std::vector<Net::Http::Response>> barrier(sync);

    barrier.wait_for(std::chrono::seconds(5));

    return body;
}

// proof of concept. need to talk via json
std::string RestClient::Post(std::string request, std::string payload) {

    std::vector<Async::Promise<Net::Http::Response>> responses;
    std::string body;
    auto resp = _client.post(request).body(payload).send();
    resp.then([&](Net::Http::Response response) {
        if (response.code() == Net::Http::Code(400)){
            body = "0";
        }
        body = response.body();

    }, Async::IgnoreException);
    responses.push_back(std::move(resp));

    auto sync = Async::whenAll(responses.begin(), responses.end());
    Async::Barrier<std::vector<Net::Http::Response>> barrier(sync);

    barrier.wait_for(std::chrono::seconds(5));

    return body;
}

std::string RestClient::Put(std::string request, std::string payload) {
    std::vector<Async::Promise<Net::Http::Response>> responses;
    std::string body;
    auto resp = _client.put(request).body(payload).send();
    resp.then([&](Net::Http::Response response) {
        if (response.code() == Net::Http::Code(400)){
            body = "0";
        }
        body = response.body();

    }, Async::IgnoreException);
    responses.push_back(std::move(resp));

    auto sync = Async::whenAll(responses.begin(), responses.end());
    Async::Barrier<std::vector<Net::Http::Response>> barrier(sync);

    barrier.wait_for(std::chrono::seconds(5));

    return body;
}
