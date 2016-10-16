#include <string>
#include "../include/player.h"

using namespace std;

const int DEFAULT_SPAWN = 0;
const int START_HEALTH = 100;


int Player::getPlayerID() {
    return playerId;
}

int Player::getCoordinate() {
    return coordinate;
}

void Player::updateCoordinate(int newRoomId) {
    coordinate = newRoomId;
}

HIBERLITE_EXPORT_CLASS(Player)
