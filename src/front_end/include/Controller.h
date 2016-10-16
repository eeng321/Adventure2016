#ifndef ADVENTURE2016_CONTROLLER_H
#define ADVENTURE2016_CONTROLLER_H

#include <string>
#include "RestClient.h"
#include "../../model/include/player.h"
#include "../../model/include/room.h"

enum StatusCode {STATUS_OK = 0, STATUS_USER_EXISTS = 1, STATUS_BAD_PASSWORD = 2};

class Controller {
public:
    Controller();

    /**
     * Attempt to log into the server with the specified credentials.
     * @param username      The user ID.
     * @param password      The user password.
     * @return              Whether the login was accepted.
     */
    StatusCode logIn(std::string username, std::string password);

    /**
     * Accept and process a user command. Legal values include the cardinal
     * directions and the shorthands n, e, s, or w; whoami; look; and take
     * @param command       User input at the terminal.
     * @return              The server response to the query or action.
     */
    std::string parseCommand(std::string command);

private:
    std::string makeGetRequest(std::string url);
    std::string makePutRequest(std::string url, std::string payload);
    std::string makePostRequest(std::string url, std::string payload);
    std::string who();
    std::string moveNorth();
    std::string moveEast();
    std::string moveSouth();
    std::string moveWest();
    std::string look();
    std::string take(std::string arg);

    Player player;
    Room* room;
    Rest::RestClient client;
};

#endif //ADVENTURE2016_PARSER_H
