#ifndef ADVENTURE2016_DICTIONARY_H
#define ADVENTURE2016_DICTIONARY_H

#include <iostream>
#include <string>
#include <bitset>
#include <sstream>
#include <map>
#include <cctype>

#include "Command.h"

//The following is based off of: http://www.dreamincode.net/forums/topic/38412-the-command-pattern-c/

class Dictionary {
    std::map<std::string, Command*> dictionaryCmdMap;
    std::map<std::string, std::string> providedLanguageMap;
public:
    Dictionary();
    void insertIntoLanguageMap(std::string key, std::string value);
    Command* lookup(std::string command);
    ~Dictionary();
};


#endif //ADVENTURE2016_DICTIONARY_H
