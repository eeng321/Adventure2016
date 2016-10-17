#include "../../model/include/playerModel.h"
#include <string>

typedef bool success;

void printPlayer(PlayerModel player);
void createDB();
void printDB();

PlayerModel loadPlayer(int playerId);
PlayerModel addPlayer(PlayerModel player);
PlayerModel modifyPlayer(int playerId, PlayerModel updateFields);
void removePlayer(int playerId);
PlayerModel verifyCredentials(std::string username, std::string pw);
PlayerModel registerAccount(std::string username, std::string pw);