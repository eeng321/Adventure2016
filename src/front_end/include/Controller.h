//
// Created by josh on 29/09/16.
//

#ifndef ADVENTURE2016_PARSER_H
#define ADVENTURE2016_PARSER_H

#include <string>
#include "RestClient.h"
#include "../../model/include/player.h"

class Controller {
public:
    Controller();
    /**
     * Accept and process a user command. Legal values include the cardinal
     * directions and the shorthands n, e, s, or w; whoami; look; and take
     * @param command       User input at the terminal.
     * @return              The server response to the query or action.
     */
    std::string parseCommand(std::string command);

private:
    std::string who();
    std::string moveNorth();
    std::string moveEast();
    std::string moveSouth();
    std::string moveWest();
    std::string look();
    std::string take(std::string arg);

    Player player;
    // TODO
    //World world;
    Rest::RestClient client;
};

#endif //ADVENTURE2016_PARSER_H
