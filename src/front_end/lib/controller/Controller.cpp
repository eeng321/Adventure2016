#include "../../../back_end/includes/parser.h"
#include "../../include/utility.h"
#include "Controller.h"
#include <algorithm>
#include <iostream>


using namespace utility;

// TODO
const std::string SERVER = "http://localhost:8080/";
//Room Controller::room = Room();
Rest::RestClient Controller::client;
GameState state;

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

    PlayerModel model = parser::playerDeserialize(response.body());
    state.setPlayerModel(model);

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

    PlayerModel model = parser::playerDeserialize(response.body());
    state.setPlayerModel(model);

    result = response.body();
    return STATUS_OK;
}

StatusCode Controller::sendGlobalMessage(const std::string &payload, std::string &result) {
    result = "";
    Net::Http::Response response = client.Post(SERVER + "chat/", payload);
    if (response.code() == Net::Http::Code::Internal_Server_Error) {
        // TODO: handle
        return STATUS_SERVER_ERROR;
    }
    result = response.body();
    return STATUS_OK;
}

std::string Controller::getLatestGlobalMessages() {
    Net::Http::Response response = client.Get(SERVER + "chat/");
    if (response.code() != Net::Http::Code::Ok) {
        // TODO: handle
        return "ERROR: HTTP error.";
    }
    return response.body();
}

StatusCode Controller::getRoom(roomId id, Room& room) {
    Net::Http::Response response = client.Get(SERVER + "room/" + id.to_string());
    if (response.code() == Net::Http::Code::Forbidden) {
        // TODO: correct error code
        return STATUS_SERVER_ERROR;
    }
    else if (response.code() == Net::Http::Code::Internal_Server_Error) {
        // TODO
        return STATUS_SERVER_ERROR;
    }

    //RoomModel model = parser::roomDeserialize(response.body());
    //room.setModel(model);
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
