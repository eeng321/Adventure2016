#ifndef ADVENTURE2016_DICTIONARY_H
#define ADVENTURE2016_DICTIONARY_H

class Dictionary {
    std::map<std::string, commandExecuter*> dictionaryCmdMap;
public:
    Dictionary();
    void insertIntoLanguageMap(std::string key, std::string value);
    commandExecuter* lookup(std::string command);
private:
    static std::map<std::string, std::string> providedLanguageMap;
};
//The following is based off of: http://www.dreamincode.net/forums/topic/38412-the-command-pattern-c/

class commandExecuter {
public:
    virtual StatusCode execute(std::string& result) = 0;
    virtual ~commandExecuter() {}
};

class northCommand : commandExecuter {
public:
    StatusCode execute(std::string& result);
};

class southCommand : commandExecuter {
public:
    StatusCode execute(std::string& result);
};

class eastCommand : commandExecuter {
public:
    StatusCode execute(std::string& result);
};

class westCommand : commandExecuter {
public:
    StatusCode execute(std::string& result);
};

class helpCommand : commandExecuter {
public:
    StatusCode execute(std::string& result);
};

class whoCommand : commandExecuter {
public:
    StatusCode execute(std::string& result);
};

class whereCommand : commandExecuter {
public:
    StatusCode execute(std::string& result);
};

class lookCommand : commandExecuter {
public:
    StatusCode execute(std::string& result);
};

class takeCommand : commandExecuter {
public:
    StatusCode execute(std::string& result);
};



#endif //ADVENTURE2016_DICTIONARY_H
