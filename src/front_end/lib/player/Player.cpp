#include <string>
#include "../../include/Player.h"

using namespace std;

const int DEFAULT_SPAWN = 0;
const int START_HEALTH = 100;

Player::Player(id pid) {
    model.playerId = (int) pid;
    model.loginName = "";
    model.roomId = DEFAULT_SPAWN;
    model.health = START_HEALTH;
}

PlayerModel Player::getModel() {
    return model;
}

void Player::setModel(PlayerModel model) {
    this->model = model;
}

id Player::getPlayerId() {
    return (id) model.playerId;
}

id Player::getRoomId() {
    return (id) model.roomId;
}

void Player::updateRoomId(id newRoomId) {
    model.roomId = (int) newRoomId;
}
