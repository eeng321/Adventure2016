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

Net::Http::Response RestClient::Get(std::string request) {

    std::vector<Async::Promise<Net::Http::Response>> responses;
    Net::Http::Response response;

    auto resp = _client.get(request).send();
    resp.then([&](Net::Http::Response promisedResponse) {
        response = promisedResponse;
    }, Async::IgnoreException);

    responses.push_back(std::move(resp));
    auto sync = Async::whenAll(responses.begin(), responses.end());
    Async::Barrier<std::vector<Net::Http::Response>> barrier(sync);
    barrier.wait_for(std::chrono::seconds(5));
    _client.shutdown();

    return response;
}

Net::Http::Response RestClient::Post(std::string request, std::string payload) {

    std::vector<Async::Promise<Net::Http::Response>> responses;
    Net::Http::Response response;

    auto resp = _client.post(request).body(payload).send();
    resp.then([&](Net::Http::Response promisedResponse) {
        response = promisedResponse;
    }, Async::IgnoreException);

    responses.push_back(std::move(resp));
    auto sync = Async::whenAll(responses.begin(), responses.end());
    Async::Barrier<std::vector<Net::Http::Response>> barrier(sync);
    barrier.wait_for(std::chrono::seconds(5));
    _client.shutdown();

    return response;
}

Net::Http::Response RestClient::Put(std::string request, std::string payload) {
    std::vector<Async::Promise<Net::Http::Response>> responses;
    Net::Http::Response response;

    auto resp = _client.put(request).body(payload).send();
    resp.then([&](Net::Http::Response promisedResponse) {
        response = promisedResponse;
    }, Async::IgnoreException);

    responses.push_back(std::move(resp));
    auto sync = Async::whenAll(responses.begin(), responses.end());
    Async::Barrier<std::vector<Net::Http::Response>> barrier(sync);
    barrier.wait_for(std::chrono::seconds(5));
    _client.shutdown();

    return response;
}

Net::Http::Response RestClient::Delete(std::string request) {

    std::vector<Async::Promise<Net::Http::Response>> responses;
    Net::Http::Response response;

    auto resp = _client.del(request).send();
    resp.then([&](Net::Http::Response promisedResponse) {
        response = promisedResponse;
    }, Async::IgnoreException);

    responses.push_back(std::move(resp));
    auto sync = Async::whenAll(responses.begin(), responses.end());
    Async::Barrier<std::vector<Net::Http::Response>> barrier(sync);
    barrier.wait_for(std::chrono::seconds(5));
    _client.shutdown();

    return response;
}

void RestClient::Shutdown() {
    _client.shutdown();
}