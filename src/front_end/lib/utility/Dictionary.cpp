#include <iostream>
#include <algorithm>
#include "Controller.h"
#include "Dictionary.h"

//TODO: Fill up language map with something
//TODO: Actually have movement and connect with the player class properly
//TODO: Hook this up with UserInput and test

Dictionary::Dictionary() {
    dictionaryCmdMap.insert(std::make_pair("north", new northCommand));
    dictionaryCmdMap.insert(std::make_pair("south", new southCommand));
    dictionaryCmdMap.insert(std::make_pair("east", new eastCommand));
    dictionaryCmdMap.insert(std::make_pair("west", new westCommand));
    dictionaryCmdMap.insert(std::make_pair("help", new helpCommand));
    dictionaryCmdMap.insert(std::make_pair("who", new whoCommand));
    dictionaryCmdMap.insert(std::make_pair("where", new whereCommand));
    dictionaryCmdMap.insert(std::make_pair("look", new lookCommand));
    dictionaryCmdMap.insert(std::make_pair("take", new takeCommand));
}

void Dictionary::insertIntoLanguageMap(std::string key, std::string value) {
    providedLanguageMap.insert(std::make_pair(key, value));
}

commandExecuter* Dictionary::lookup(std::string command) {
    std::transform(command.begin(), command.end(), command.begin(), ::tolower);
    std::map<std::string, std::string>::const_iterator iterLanguage;
    iterLanguage = providedLanguageMap.find(command);
    std::string userIntendedCmd;
    if(iterLanguage != providedLanguageMap.end()) {
        userIntendedCmd = iterLanguage->first;
    } else {
        userIntendedCmd = "";
    }

    std::transform(userIntendedCmd.begin(), userIntendedCmd.end(), userIntendedCmd.begin(), ::tolower);
    std::map<std::string, commandExecuter*>::const_iterator iterDictionary;
    iterDictionary = dictionaryCmdMap.find(userIntendedCmd);
    if(iterDictionary != dictionaryCmdMap.end()) {
        return iterDictionary->second;
    } else {
        return NULL;
    }
}

StatusCode northCommand::execute(std::string &result) {
    // TODO: make put request with player ID, and room ID north of current room
    result = "The Earth itself blocks your way.";
    return STATUS_OK;
}

StatusCode southCommand::execute(std::string &result) {
    result = "The Earth itself blocks your way.";
    return STATUS_OK;
}
StatusCode eastCommand::execute(std::string &result) {
    result = "The Earth itself blocks your way.";
    return STATUS_OK;
}
StatusCode westCommand::execute(std::string &result) {
    result = "The Earth itself blocks your way.";
    return STATUS_OK;
}
StatusCode helpCommand::execute(std::string &result) {
    result = "You can say:\n";
    result += "help whoami whereami north east south west look take quit";
    return STATUS_OK;
}
StatusCode whoCommand::execute(std::string &result) {
    result = "You are player ID " + std::to_string((int) player.getPlayerId());
    return STATUS_OK;
}
StatusCode whereCommand::execute(std::string &result) {
    result = "You are in room " + std::to_string((int) player.getRoomId());
    return STATUS_OK;
}
StatusCode lookCommand::execute(std::string &result) {
    result = "You see only darkness.";
    return STATUS_OK;
}
StatusCode takeCommand::execute(std::string &result) {
    result = "There is nothing to take.";
    return STATUS_OK;
}