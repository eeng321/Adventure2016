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

StatusCode Controller::parseCommand(std::string& command, std::string& result) {
    if (player.getId().value == 0) {
        result = "Not logged in.";
        return STATUS_LOGGED_OUT;
    }

    std::transform(command.begin(), command.end(), command.begin(), ::tolower);
    if (command == "help" || command == "h") {
        return help(result);
    }
    else if (command == "whoami" || command == "who") {
        return who(result);
    }
    else if (command == "whereami" || command == "where") {
        return where(result);
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
    else if (command == "exit" || command == "quit" || command == "q") {
        client.Shutdown();
        return STATUS_QUIT;
    }
    else {
        result = "Unrecognized command. Say \"help\" to view available commands.";
        return STATUS_OK;
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

StatusCode Controller::help(std::string& result) {
    result = "You can say:\n";
    result += "help whoami whereami north east south west look take quit";
    return STATUS_OK;
}

StatusCode Controller::who(std::string& result) {
    result = "You are player ID " + std::to_string(player.getId().value);
    return STATUS_OK;
}

StatusCode Controller::where(std::string& result) {
    result = "You are in room " + std::to_string(player.getLocation().value);
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