#include "Controller.h"
#include "Dictionary.h"
#include "Command.h"
#include <iostream>
#include <algorithm>
#include <map>

//TODO: Actually have movement and connect with the player class properly
//TODO: Hook this up with UserInput and test

Dictionary::Dictionary() {
    dictionaryCmdMap.insert(std::make_pair("north", new NorthCommand));
    dictionaryCmdMap.insert(std::make_pair("south", new SouthCommand));
    dictionaryCmdMap.insert(std::make_pair("east", new EastCommand));
    dictionaryCmdMap.insert(std::make_pair("west", new WestCommand));
    dictionaryCmdMap.insert(std::make_pair("help", new HelpCommand));
    //dictionaryCmdMap.insert(std::make_pair("who", new WhoCommand));
    dictionaryCmdMap.insert(std::make_pair("where", new WhereCommand));
    dictionaryCmdMap.insert(std::make_pair("look", new LookCommand));
    dictionaryCmdMap.insert(std::make_pair("take", new TakeCommand));
    dictionaryCmdMap.insert(std::make_pair("/s", new GlobalChatCommand));
    dictionaryCmdMap.insert(std::make_pair("move", new MoveCommand));
    dictionaryCmdMap.insert(std::make_pair("engage", new EngageCommand));
    dictionaryCmdMap.insert(std::make_pair("piglatin", new PiglatinCommand));
}

Dictionary::~Dictionary() {
    for (auto& pair : dictionaryCmdMap) {
        delete pair.second;
    }
    dictionaryCmdMap.clear();
}

void Dictionary::insertIntoLanguageMap(std::string key, std::string value) {
    providedLanguageMap.insert(std::make_pair(key, value));
}

Command* Dictionary::lookup(std::string command) {
    std::transform(command.begin(), command.end(), command.begin(), ::tolower);
    std::string userIntendedCmd = providedLanguageMap[command];

    std::transform(userIntendedCmd.begin(), userIntendedCmd.end(), userIntendedCmd.begin(), ::tolower);
    std::map<std::string, Command*>::const_iterator iterDictionary;
    iterDictionary = dictionaryCmdMap.find(userIntendedCmd);
    if(iterDictionary != dictionaryCmdMap.end()) {
        return iterDictionary->second;
    } else {
        return NULL;
    }
}