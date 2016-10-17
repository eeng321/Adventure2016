#ifndef ADVENTURE2016_PLAYER_H
#define ADVENTURE2016_PLAYER_H


#include <string>
#include <memory>
#include "../../model/include/playerModel.h"

typedef int id;

class Player {
public:
    Player(id pid);
    PlayerModel getModel();
    void setModel(PlayerModel model);
    id getPlayerId();
    id getRoomId();
    void updateRoomId(id newRoomId);

private:
    PlayerModel model;
};

#endif //ADVENTURE2016_PLAYER_H
