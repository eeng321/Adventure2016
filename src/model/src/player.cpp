#include <string>
#include "../include/player.h"

using namespace std;

const int DEFAULT_SPAWN = 0;
const int START_HEALTH = 100;

Player::Player(id playerID){

    player_id = playerID;

    login_name = "";

    player_location_id = DEFAULT_SPAWN;

    health = START_HEALTH;
}

id Player::getPlayerID(){
    return player_id;
}

id Player::getRoomID(){
    return player_location_id;
}

void player::updateRoomID(id newRoomID){
    player_location_id = newRoomID;
}

