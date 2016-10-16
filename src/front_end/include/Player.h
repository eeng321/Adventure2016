#ifndef ADVENTURE2016_PLAYER_H
#define ADVENTURE2016_PLAYER_H


#include <string>

using namespace std;

typedef int id;

class Player {
public:
    Player(id pid);
    id getPlayerId();
    id getRoomId();
    void updateRoomId(id newRoomId);

private:
    // Player identification attributes
    id playerId;
    string loginName;

    // Player information attributes
    id playerLocationId;

    // Player stats
    int health;
};

#endif //ADVENTURE2016_PLAYER_H
