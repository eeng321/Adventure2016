//
// Created by josh on 29/09/16.
//

#include <algorithm>
#include <iostream>
#include "Controller.h"
#include "../../include/utility.h"

using namespace utility;

// TODO
const std::string SERVER = "http://localhost:8080/";

Controller::Controller() : player(Player((id) 1)), room(nullptr) {

}

StatusCode Controller::logIn(std::string username, std::string password) {
    std::string responseBody = makeGetRequest(SERVER + "login/?username=" + username + "&password=" + password);

    // TODO: set up logged in player using attributes in server response
    player = Player((id) 1);
    player.updateRoomId((id) 1);

    // TODO: set up current room

    return StatusCode::STATUS_OK;
}

std::string Controller::parseCommand(std::string command) {
    if (player.getPlayerId() == (id) 0) {
        return "Not logged in.";
    }

    std::transform(command.begin(), command.end(), command.begin(), ::tolower);
    if (command == "whoami") {
        return who();
    }
    else if (command == "n" || command == "north" || command == "up") {
        return moveNorth();
    }
    else if (command == "e" || command == "east" || command == "right") {
        return moveEast();
    }
    else if (command == "s" || command == "south" || command == "down") {
        return moveSouth();
    }
    else if (command == "w" || command == "west" || command == "left") {
        return moveWest();
    }
    else if (command == "l" || command == "look") {
        return look();
    }
    else if (command == "t" || command == "take") {
        // TODO: tokenize input command so second word can be passed to take()
        return take("");
    }
}

std::string Controller::makeGetRequest(std::string url) {
    Net::Http::Response response = client.Get(url);
    if (response.code() != Net::Http::Code::Ok) {
        // TODO: handle
        return "ERROR: HTTP error.";
    }
    return response.body();
}

std::string Controller::makePutRequest(std::string url, std::string payload) {
    Net::Http::Response response = client.Put(url, payload);
    if (response.code() != Net::Http::Code::Ok) {
        // TODO: handle
        return "ERROR: HTTP error.";
    }
    return response.body();
}

std::string Controller::makePostRequest(std::string url, std::string payload) {
    Net::Http::Response response = client.Post(url, payload);
    if (response.code() != Net::Http::Code::Ok) {
        // TODO: handle
        return "ERROR: HTTP error.";
    }
    return response.body();
}

std::string Controller::who() {
    std::string responseBody = makeGetRequest(SERVER + "player/" + player.getPlayerId());
    // TODO: deserialize YAML Player object and return name or appropriate info
    return responseBody;
}

std::string Controller::moveNorth() {
    // TODO: make put request with player ID, and room ID north of current room
    return "The Earth itself blocks your way.";
}

std::string Controller::moveEast() {
    return "The Earth itself blocks your way.";
}

std::string Controller::moveSouth() {
    return "The Earth itself blocks your way.";
}

std::string Controller::moveWest() {
    return "The Earth itself blocks your way.";
}

std::string Controller::look() {
    return "You see only darkness.";
}

std::string Controller::take(std::string arg) {
    return "There is nothing to take.";
}