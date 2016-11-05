#ifndef ADVENTURE2016_DICTIONARY_H
#define ADVENTURE2016_DICTIONARY_H

#include <iostream>
#include <string>
#include <bitset>
#include <sstream>
#include <map>
#include <cctype>


//The following is based off of: http://www.dreamincode.net/forums/topic/38412-the-command-pattern-c/

class commandExecuter {
public:
    virtual StatusCode execute(std::string& result) = 0;
    virtual ~commandExecuter() {}
};

class northCommand : public commandExecuter {
public:
    StatusCode execute(std::string& result);
};

class southCommand : public commandExecuter {
public:
    StatusCode execute(std::string& result);
};

class eastCommand : public commandExecuter {
public:
    StatusCode execute(std::string& result);
};

class westCommand : public commandExecuter {
public:
    StatusCode execute(std::string& result);
};

class helpCommand : public commandExecuter {
public:
    StatusCode execute(std::string& result);
};

class whoCommand : public commandExecuter {
public:
    StatusCode execute(std::string& result);
};

class whereCommand : public commandExecuter {
public:
    StatusCode execute(std::string& result);
};

class lookCommand : public commandExecuter {
public:
    StatusCode execute(std::string& result);
};

class takeCommand : public commandExecuter {
public:
    StatusCode execute(std::string& result);
};

class Dictionary {
    std::map<std::string, commandExecuter*> dictionaryCmdMap;
    std::map<std::string, std::string> providedLanguageMap;
public:
    Dictionary();
    void insertIntoLanguageMap(std::string key, std::string value);
    commandExecuter* lookup(std::string command);
    ~Dictionary();
private:

};


#endif //ADVENTURE2016_DICTIONARY_H
