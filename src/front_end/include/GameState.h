#ifndef ADVENTURE2016_GAMESTATE_H
#define ADVENTURE2016_GAMESTATE_H

#include <vector>
#include "Player.h"
#include "../../model/include/playerModel.h"

class GameState {
public:
    GameState();
    static std::string getPlayerId();
    static PlayerModel getPlayerModel();
    static void setPlayerModel(PlayerModel model);
    static roomId getLocation();
    static void setLocation(roomId id);
    static void setAttackFlag(bool state);
    static void bool inCombat();
private:
    static Player player;
};


#endif //ADVENTURE2016_GAMESTATE_H
