//
// Created by josh on 29/09/16.
//

#include "Controller.h"
#include <algorithm>
#include <iostream>
#include "../../include/utility.h"

using namespace utility;

// TODO
const std::string SERVER = "http://localhost:8080/";
Player Controller::player = Player((id) 1);
Room* Controller::room = nullptr;

Controller::Controller() {

}

StatusCode Controller::logIn(const std::string& username, const std::string& password, std::string& result) {
    std::string responseBody = makeGetRequest(SERVER + "login/?username=" + username + "&password=" + password);

    // TODO: set up logged in player using attributes in server response
    player = Player((id) 1);
    player.updateRoomId((id) 1);

    // TODO: set up current room

    result = (int) player.getPlayerId();
    return STATUS_OK;
}

StatusCode Controller::parseCommand(std::string& command, std::string& result) {
    if (player.getPlayerId() == (id) 0) {
        result = "Not logged in.";
        return STATUS_LOGGED_OUT;
    }

    std::transform(command.begin(), command.end(), command.begin(), ::tolower);
    if (command == "whoami") {
        return who(result);
    }
    else if (command == "n" || command == "north" || command == "up") {
        return moveNorth(result);
    }
    else if (command == "e" || command == "east" || command == "right") {
        return moveEast(result);
    }
    else if (command == "s" || command == "south" || command == "down") {
        return moveSouth(result);
    }
    else if (command == "w" || command == "west" || command == "left") {
        return moveWest(result);
    }
    else if (command == "l" || command == "look") {
        return look(result);
    }
    else if (command == "t" || command == "take") {
        // TODO: tokenize input command so second word can be passed to take()
        return take("", result);
    }
    else if (command == "exit" || command == "q" || "quit") {
        return STATUS_QUIT;
    }
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

StatusCode Controller::who(std::string& result) {
    std::string responseBody = makeGetRequest(SERVER + "player/" + player.getPlayerId());
    // TODO: deserialize YAML Player object and return name or appropriate info
    result = responseBody;
    return STATUS_OK;
}

StatusCode Controller::moveNorth(std::string& result) {
    // TODO: make put request with player ID, and room ID north of current room
    result = "The Earth itself blocks your way.";
    return STATUS_OK;
}

StatusCode Controller::moveEast(std::string& result) {
    result = "The Earth itself blocks your way.";
    return STATUS_OK;
}

StatusCode Controller::moveSouth(std::string& result) {
    result = "The Earth itself blocks your way.";
    return STATUS_OK;
}

StatusCode Controller::moveWest(std::string& result) {
    result = "The Earth itself blocks your way.";
    return STATUS_OK;
}

StatusCode Controller::look(std::string& result) {
    result = "You see only darkness.";
    return STATUS_OK;
}

StatusCode Controller::take(const std::string& arg, std::string& result) {
    result = "There is nothing to take.";
    return STATUS_OK;
}