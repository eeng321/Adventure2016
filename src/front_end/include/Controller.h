#ifndef ADVENTURE2016_CONTROLLER_H
#define ADVENTURE2016_CONTROLLER_H

#include <string>
#include "RestClient.h"
#include "Player.h"
#include "../../model/include/npc.h"
#include "../../model/include/item.h"
#include "GameState.h"
#include "../../model/include/room.h"

enum StatusCode {
    STATUS_OK = 0,
    STATUS_USER_EXISTS = 1,
    STATUS_BAD_PASSWORD = 2,
    STATUS_LOGGED_OUT = 3,
    STATUS_QUIT = 4,
    STATUS_SERVER_ERROR = 5,
    STATUS_COMMAND_NOT_FOUND = 6
};

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
     * Get a Room object by querying the server.
     * @param id        The room ID.
     * @param room      A Room object reference to write the retrieved room information to.
     * @return          A status code that reflects whether the operation was successful.
     */
    static StatusCode parseCommand(std::string& command, std::string& result);
    static StatusCode sendGlobalMessage(const std::string& payload, std::string& result);
    static std::string getLatestGlobalMessages();
    static StatusCode getRoom(roomId id, Room& room);

    static StatusCode moveToRoom(roomId id);
    static StatusCode putPlayer(std::string& result);

    static std::string getPlayerId();

    static void deleteNPC(npcId npc);

    static StatusCode getNpc(npcId id, Npc& npc);
    static StatusCode putNpc(Npc& npc, std::string &result);

    static StatusCode getItem(itemId id, Item& item);

    static std::string server;

private:
    static std::string makeGetRequest(const std::string& url);
    static std::string makePutRequest(const std::string& url, const std::string& payload);
    static std::string makePostRequest(const std::string& url, const std::string& payload);
    static Rest::RestClient client;
    static GameState state;
};

#endif //ADVENTURE2016_PARSER_H
