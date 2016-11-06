//
// Created by jmedwid on 11/4/16.
//
#include "../../../back_end/includes/parser.h"
#include "../../../model/include/messageModel.h"
#include "Command.h"
#include "Controller.h"
#include "display.h"


StatusCode NorthCommand::execute(std::string &result) {
    // TODO: make put request with player ID, and room ID north of current room
    result = "The Earth itself blocks your way.";
    return STATUS_OK;
}

StatusCode SouthCommand::execute(std::string &result) {
    result = "The Earth itself blocks your way.";
    return STATUS_OK;
}
StatusCode EastCommand::execute(std::string &result) {
    result = "The Earth itself blocks your way.";
    return STATUS_OK;
}
StatusCode WestCommand::execute(std::string &result) {
    result = "The Earth itself blocks your way.";
    return STATUS_OK;
}
StatusCode HelpCommand::execute(std::string &result) {
    result = "You can say:\n";
    result += "help whoami whereami north east south west look take quit";
    return STATUS_OK;
}

/*
StatusCode WhoCommand::execute(std::string &result) {
    result = "You are player ID " + std::to_string((int) player.getPlayerId());
    return STATUS_OK;
}
StatusCode WhereCommand::execute(std::string &result) {
    result = "You are in room " + std::to_string((int) player.getRoomId());
    return STATUS_OK;
}
 */

StatusCode LookCommand::execute(std::string &result) {
    result = "You see only darkness.";
    return STATUS_OK;
}
StatusCode TakeCommand::execute(std::string &result) {
    result = "There is nothing to take.";
    return STATUS_OK;
}

StatusCode GlobalChatCommand::execute(std::string &result) {
    Display::addStringToMainWindow("Please type what you want to say:");
    char commandString[MAX_CHAR_LIMIT];
    Display::readUserInput(commandString);
    std::string commandStringConverted(commandString);
    MessageModel playerMessage;
    playerMessage.To = "global";
    playerMessage.From = "Justin"; //TODO: Faking until can grab username
    playerMessage.Message = commandStringConverted;
    std::string postPayload = parser::messageSerialize(playerMessage);

    return Controller::sendGlobalMessage(postPayload, result);
}