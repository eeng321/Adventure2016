#ifndef ADVENTURE2016_CONTROLLER_H
#define ADVENTURE2016_CONTROLLER_H

#include <string>
#include "RestClient.h"
#include "Player.h"
#include "../../model/include/room.h"

enum StatusCode {STATUS_OK = 0, STATUS_USER_EXISTS = 1, STATUS_BAD_PASSWORD = 2, STATUS_LOGGED_OUT = 3};

class Controller {
public:
    Controller();

    /**
     * Attempt to log into the server with the specified credentials.
     * @param username      The username.
     * @param password      The user password.
     * @param result        A string reference to write the results of the operation to.
     * @return              A status code that reflects whether the operation was successful.
     */
    static StatusCode logIn(const std::string& username, const std::string& password, std::string& result);

    /**
     * Attempt to create an account on the server.
     * @param username      The username.
     * @param password      The user password.
     * @param result        A string reference to write the results of the operation to.
     * @return              A status code that reflects whether the operation was successful.
     */
    static StatusCode registerAccount(const std::string& username, const std::string& password, std::string& result);

    /**
     * Accept and process a user command. Legal values include the cardinal
     * directions and the shorthands n, e, s, or w; whoami; look; and take
     * @param command       User input at the terminal.
     * @param result        A string reference to write the results of the player action to.
     * @return              A status code that reflects whether the operation was successful.
     */
    static StatusCode parseCommand(std::string& command, std::string& result);

private:
    static std::string makeGetRequest(const std::string& url);
    static std::string makePutRequest(const std::string& url, const std::string& payload);
    static std::string makePostRequest(const std::string& url, const std::string& payload);
    static StatusCode who(std::string& result);
    static StatusCode moveNorth(std::string& result);
    static StatusCode moveEast(std::string& result);
    static StatusCode moveSouth(std::string& result);
    static StatusCode moveWest(std::string& result);
    static StatusCode look(std::string& result);
    static StatusCode take(const std::string& arg, std::string& result);

    static Player player;
    static Room* room;
    static Rest::RestClient client;
};

#endif //ADVENTURE2016_PARSER_H
