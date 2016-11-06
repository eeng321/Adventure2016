#include "GameState.h"

const int PLAYER_ID_NONE = 0;

Player GameState::player = Player(playerId(PLAYER_ID_NONE));

GameState::GameState() {

}

void GameState::setPlayerModel(PlayerModel model) {
    player.setModel(model);
}

roomId GameState::getLocation() {
    return player.getLocation();
}

void GameState::setLocation(roomId id) {
    player.setLocation(id);
}
