#ifndef ADVENTURE2016_COMMAND_H
#define ADVENTURE2016_COMMAND_H

#include "Controller.h"

class Command {
public:
    virtual StatusCode execute(std::string& result) = 0;
};

class NorthCommand : public Command {
public:
    StatusCode execute(std::string& result);
};

class SouthCommand : public Command {
public:
    StatusCode execute(std::string& result);
};

class EastCommand : public Command {
public:
    StatusCode execute(std::string& result);
};

class WestCommand : public Command {
public:
    StatusCode execute(std::string& result);
};

class HelpCommand : public Command {
public:
    StatusCode execute(std::string& result);
};

class WhoCommand : public Command {
public:
    StatusCode execute(std::string& result);
};

class WhereCommand : public Command {
public:
    StatusCode execute(std::string& result);
};

class LookCommand : public Command {
public:
    StatusCode execute(std::string& result);
};

class TakeCommand : public Command {
public:
    StatusCode execute(std::string& result);
};

#endif //ADVENTURE2016_COMMAND_H
