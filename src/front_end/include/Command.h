#ifndef ADVENTURE2016_COMMAND_H
#define ADVENTURE2016_COMMAND_H

#include "Controller.h"

class Command {
public:
    virtual StatusCode execute(std::string& result, const std::vector<std::string>& args) = 0;
};

class NorthCommand : public Command {
public:
    StatusCode execute(std::string& result, const std::vector<std::string>& args);
};

class SouthCommand : public Command {
public:
    StatusCode execute(std::string& result, const std::vector<std::string>& args);
};

class EastCommand : public Command {
public:
    StatusCode execute(std::string& result, const std::vector<std::string>& args);
};

class WestCommand : public Command {
public:
    StatusCode execute(std::string& result, const std::vector<std::string>& args);
};

class HelpCommand : public Command {
public:
    StatusCode execute(std::string& result, const std::vector<std::string>& args);
};

class WhoCommand : public Command {
public:
    StatusCode execute(std::string& result, const std::vector<std::string>& args);
};

class WhereCommand : public Command {
public:
    StatusCode execute(std::string& result, const std::vector<std::string>& args);
};

class LookCommand : public Command {
public:
    StatusCode execute(std::string& result, const std::vector<std::string>& args);
};

class TakeCommand : public Command {
public:
    StatusCode execute(std::string& result, const std::vector<std::string>& args);
};

class SwapCommand : public Command {
public:
    StatusCode execute(std::string& result, const std::vector<std::string>& args);
};

#endif //ADVENTURE2016_COMMAND_H
