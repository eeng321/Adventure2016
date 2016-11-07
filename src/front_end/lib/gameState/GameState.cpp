#include "GameState.h"

const int PLAYER_ID_NONE = 0;

Player GameState::player = Player(playerId(PLAYER_ID_NONE));

GameState::GameState() {

}

std::string GameState::getPlayerId() {
    return player.getUsername();
}

PlayerModel GameState::getPlayerModel() {
    return player.getModel();
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
