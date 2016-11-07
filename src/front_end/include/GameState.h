#ifndef ADVENTURE2016_GAMESTATE_H
#define ADVENTURE2016_GAMESTATE_H

#include <vector>
#include "Player.h"
#include "../../model/include/playerModel.h"

class GameState {
public:
    GameState();
    static void setPlayerModel(PlayerModel model);
    static roomId getLocation();
    static void setLocation(roomId id);

private:
    static Player player;
};


#endif //ADVENTURE2016_GAMESTATE_H
