//
// Created by josh on 29/09/16.
//

#include "Controller.h"
#include <algorithm>
#include <iostream>
#include "../../include/utility.h"
#include "../../../back_end/includes/parser.h"

using namespace utility;

// TODO
const std::string SERVER = "http://localhost:8080/";
Player Controller::player = Player(playerId(0));
//Room Controller::room = Room();
Rest::RestClient Controller::client;

Controller::Controller() {

}

StatusCode Controller::logIn(const std::string& username, const std::string& password, std::string& result) {
    result = "";
    Net::Http::Response response = client.Post(SERVER + "login", "?username=" + username + "&password=" + password);
    if (response.code() == Net::Http::Code::Forbidden) {
        return STATUS_BAD_PASSWORD;
    }
    else if (response.code() != Net::Http::Code::Ok) {
        return STATUS_SERVER_ERROR;
    }

    PlayerModel playerModel = parser::playerDeserialize(response.body());
    player = Player(playerId(playerModel.playerId));
    player.setModel(playerModel);

    // TODO: set up current room
    //result = (int) player.getPlayerId();
    result = response.body();
    return STATUS_OK;
}

StatusCode Controller::registerAccount(const std::string& username, const std::string& password, std::string& result) {
    result = "";
    Net::Http::Response response = client.Post(SERVER + "register", "?username=" + username + "&password=" + password);
    if (response.code() == Net::Http::Code::Forbidden) {
        // TODO: any other reasons for 403?
        return STATUS_USER_EXISTS;
    }
    else if (response.code() == Net::Http::Code::Internal_Server_Error) {
        return STATUS_SERVER_ERROR;
    }

    PlayerModel playerModel = parser::playerDeserialize(response.body());
    player = Player(playerId(playerModel.playerId));
    player.setModel(playerModel);

    // TODO: set up current room
    //result = (int) player.getPlayerId();
    result = response.body();
    return STATUS_OK;
}

std::string Controller::makeGetRequest(const std::string& url) {
    Net::Http::Response response = client.Get(url);
    if (response.code() != Net::Http::Code::Ok) {
        // TODO: handle
        return "ERROR: HTTP error.";
    }
    return response.body();
}

std::string Controller::makePutRequest(const std::string& url, const std::string& payload) {
    Net::Http::Response response = client.Put(url, payload);
    if (response.code() != Net::Http::Code::Ok) {
        // TODO: handle
        return "ERROR: HTTP error.";
    }
    return response.body();
}

std::string Controller::makePostRequest(const std::string& url, const std::string& payload) {
    Net::Http::Response response = client.Post(url, payload);
    if (response.code() != Net::Http::Code::Ok) {
        // TODO: handle
        return "ERROR: HTTP error.";
    }
    return response.body();
}
