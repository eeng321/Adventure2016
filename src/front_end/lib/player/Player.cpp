#include <string>
#include "../../include/Player.h"

using namespace std;

const int DEFAULT_SPAWN = 0;
const int START_HEALTH = 100;

Player::Player(id pid)
        : playerId(pid), loginName(""), playerLocationId(DEFAULT_SPAWN), health(START_HEALTH) {
}

id Player::getPlayerId() {
    return playerId;
}

id Player::getRoomId() {
    return playerLocationId;
}

void Player::updateRoomId(id newRoomId) {
    playerLocationId = newRoomId;
}
