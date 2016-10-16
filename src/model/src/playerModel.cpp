#include <string>
#include "playerModel.h"

using namespace std;

const int DEFAULT_SPAWN = 0;
const int START_HEALTH = 100;


int PlayerModel::getPlayerID() {
    return playerId;
}

int PlayerModel::getCoordinate() {
    return coordinate;
}

void PlayerModel::updateCoordinate(int newRoomId) {
    coordinate = newRoomId;
}

HIBERLITE_EXPORT_CLASS(PlayerModel)
