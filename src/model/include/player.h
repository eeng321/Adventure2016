#ifndef ADVENTURE2016_PLAYER_H
#define ADVENTURE2016_PLAYER_H


#include <string>

using namespace std;

typedef int id;

class Player{
public:
    Player(id playerID);
    id getPlayerID();
    id getRoomID();
    void updateRoomID(id newRoomID);

private:
    // Player identification attributes
    id player_id;
    string login_name;

    // Player information attributes
    id player_location_id;

    // Player stats
    int health;
};

#endif //ADVENTURE2016_PLAYER_H

