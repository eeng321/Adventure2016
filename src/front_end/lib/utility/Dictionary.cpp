#include <iostream>
#include <algorithm>
#include <map>
#include "Controller.h"
#include "Dictionary.h"
#include "Command.h"

//TODO: Actually have movement and connect with the player class properly
//TODO: Hook this up with UserInput and test

Dictionary::Dictionary() {
    dictionaryCmdMap.insert(std::make_pair("north", new NorthCommand));
    dictionaryCmdMap.insert(std::make_pair("south", new SouthCommand));
    dictionaryCmdMap.insert(std::make_pair("east", new EastCommand));
    dictionaryCmdMap.insert(std::make_pair("west", new WestCommand));
    dictionaryCmdMap.insert(std::make_pair("help", new HelpCommand));
    //dictionaryCmdMap.insert(std::make_pair("who", new WhoCommand));
    //dictionaryCmdMap.insert(std::make_pair("where", new WhereCommand));
    dictionaryCmdMap.insert(std::make_pair("look", new LookCommand));
    dictionaryCmdMap.insert(std::make_pair("take", new TakeCommand));
}

Dictionary::~Dictionary() {
    while(dictionaryCmdMap.begin() != dictionaryCmdMap.end()) {
        delete dictionaryCmdMap.begin()->second;
        dictionaryCmdMap.erase(dictionaryCmdMap.begin());
    }
}

void Dictionary::insertIntoLanguageMap(std::string key, std::string value) {
    providedLanguageMap.insert(std::make_pair(key, value));
}

Command* Dictionary::lookup(std::string command) {
    std::transform(command.begin(), command.end(), command.begin(), ::tolower);
    std::map<std::string, std::string>::const_iterator iterLanguage;
    std::string userIntendedCmd = "";
    for(iterLanguage = providedLanguageMap.begin(); iterLanguage != providedLanguageMap.end(); ++iterLanguage){
        if(iterLanguage->second == command) {
            userIntendedCmd = iterLanguage->first;
        }
    }

    std::transform(userIntendedCmd.begin(), userIntendedCmd.end(), userIntendedCmd.begin(), ::tolower);
    std::map<std::string, Command*>::const_iterator iterDictionary;
    iterDictionary = dictionaryCmdMap.find(userIntendedCmd);
    if(iterDictionary != dictionaryCmdMap.end()) {
        return iterDictionary->second;
    } else {
        return NULL;
    }
}