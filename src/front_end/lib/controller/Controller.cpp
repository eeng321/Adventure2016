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

// TODO: dynamic player ID
Controller::Controller() : player(Player(1)) {

}

std::string Controller::parseCommand(std::string command) {
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

std::string Controller::who() {

    return client.Get(SERVER + "player/" + player.getPlayerId()).body();
}

std::string Controller::moveNorth() {
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