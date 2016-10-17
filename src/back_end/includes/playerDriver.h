#include "../../model/include/playerModel.h"

typedef bool success;

void printPlayer(PlayerModel player);
void createDB();
void printDB();

PlayerModel loadPlayer(int playerId);
PlayerModel addPlayer(PlayerModel player);
PlayerModel modifyPlayer(int playerId, PlayerModel updateFields);
void removePlayer(int playerId);
PlayerModel verifyCredentials(string username, string pw);
PlayerModel registerAccount(string username, string pw);
