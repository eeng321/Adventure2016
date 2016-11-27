#include "GameState.h"

const int PLAYER_ID_NONE = 0;
const int PIGLATIN_INITIAL_TIME = 30;

static bool combatFlag = false;
static npcId engagedInCombatWith = 0;
static int piglatinTimer = 0;
static long piglatinTimeStamp = 0;

Player GameState::player = Player(playerId(PLAYER_ID_NONE));

GameState::GameState() {

}

std::string GameState::getPlayerId() {
    return player.getId().to_string();
}

PlayerModel GameState::getPlayerModel() {
    return player.getModel();
}

void GameState::setPlayerModel(PlayerModel model) {
    player.setModel(model);
}

int GameState::getPlayerHealth() {
    return player.getHealth();
}

void GameState::setPlayerHealth(int health) {
    player.setHealth(health);
}

roomId GameState::getLocation() {
    return player.getLocation();
}

void GameState::setLocation(roomId id) {
    player.setLocation(id);
}

void GameState::setAttackFlag(bool state) {
    combatFlag = state;
}

bool GameState::inCombat() {
    return combatFlag;
}

void GameState::setEngagedInCombatWith(npcId npc) {
    engagedInCombatWith = npc;
}

npcId GameState::getEngagedInCombatWith() {
    return engagedInCombatWith;
}

bool GameState::PiglatinIsActive(){
    return piglatinTimer != 0;
}

void GameState::decrementPiglatinTimer(){
    piglatinTimer--;
}

void GameState::initializePiglatinTimer(){
    piglatinTimer = PIGLATIN_INITIAL_TIME;
}

long GameState::getPiglatinTimeStamp(){
    return piglatinTimeStamp;
}

long GameState::setPiglatinTimeStamp(long timeStamp){
    piglatinTimeStamp = timeStamp;
}
