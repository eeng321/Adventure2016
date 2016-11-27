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
    static void setPlayerHealth(int health);
    static roomId getLocation();
    static void setLocation(roomId id);
    static void setAttackFlag(bool state);
    static bool inCombat();
    static void setEngagedInCombatWith(npcId npc);
    static npcId getEngagedInCombatWith();
private:
    static Player player;
};


#endif //ADVENTURE2016_GAMESTATE_H
