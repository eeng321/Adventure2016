//
// Created by jmedwid on 11/4/16.
//

#include "Command.h"
#include "Controller.h"
#include "GameState.h"

StatusCode NorthCommand::execute(std::string &result, const std::vector<std::string>& args) {
    // TODO: make put request with player ID, and room ID north of current room
    roomId currentRoom = GameState::getLocation();
    result = "The Earth itself blocks your way.";
    return STATUS_OK;
}

StatusCode SouthCommand::execute(std::string& result, const std::vector<std::string>& args) {
    result = "The Earth itself blocks your way.";
    return STATUS_OK;
}
StatusCode EastCommand::execute(std::string& result, const std::vector<std::string>& args) {
    result = "The Earth itself blocks your way.";
    return STATUS_OK;
}
StatusCode WestCommand::execute(std::string& result, const std::vector<std::string>& args) {
    result = "The Earth itself blocks your way.";
    return STATUS_OK;
}
StatusCode HelpCommand::execute(std::string& result, const std::vector<std::string>& args) {
    result = "You can say:\n";
    result += "help whoami whereami north east south west look take quit";
    return STATUS_OK;
}

/*
StatusCode WhoCommand::execute(std::string& result, const std::vector<std::string>& args) {
    result = "You are player ID " + std::to_string((int) player.getPlayerId());
    return STATUS_OK;
}
StatusCode WhereCommand::execute(std::string& result, const std::vector<std::string>& args) {
    result = "You are in room " + std::to_string((int) player.getRoomId());
    return STATUS_OK;
}
 */

StatusCode LookCommand::execute(std::string& result, const std::vector<std::string>& args) {
    result = "You see only darkness.";
    return STATUS_OK;
}
StatusCode TakeCommand::execute(std::string& result, const std::vector<std::string>& args) {
    result = "";
    for (const std::string& s : args) {
        result += "Took " + s + "\n";
    }
    return STATUS_OK;
}

StatusCode SwapCommand::execute(std::string& result, const std::vector<std::string>& args) {

}