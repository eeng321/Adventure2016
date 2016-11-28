#ifndef ADVENTURE2016_GAMESTATE_H
#define ADVENTURE2016_GAMESTATE_H

#include <vector>
#include "Player.h"
#include "../../model/include/playerModel.h"
#include "../../model/include/npc.h"

class GameState {
public:
    GameState();
    static std::string getPlayerId();
    static std::string getPlayerName();
    static PlayerModel getPlayerModel();
    static void setPlayerModel(PlayerModel model);
    static int getPlayerHealth();
    static void setPlayerHealth(int health);
    static roomId getLocation();
    static void setLocation(roomId id);
    static void setAttackFlag(bool state);
    static bool inCombat();
    static void setEngagedInCombatWith(npcId npc);
    static npcId getEngagedInCombatWith();
    static bool PiglatinIsActive();
    static void decrementPiglatinTimer();
    static void initializePiglatinTimer();
    static long getPiglatinTimeStamp();
    static long setPiglatinTimeStamp(long timeStamp);
    static bool isSwapped();
    static void setSwapped(bool newSwapped);
    static Npc getControlledNpc();
    static void setControlledNpc(Npc npc);
    static void resetControl();
private:
    static Player player;
    static Npc controlledNpc;
    static bool swapped;
};


#endif //ADVENTURE2016_GAMESTATE_H
