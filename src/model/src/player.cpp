#include <string>
#include <vector>
#include "../include/player.h"

using namespace std;

Player::Player(){
    // initialize values
    id = 0;
    login_name = "";
    // set default coordinate to 0,0
    coordinate.assign(0,0);

    health = 100;
}

Player::Player(int playerID){
    // initialize values
    id = playerID;
    login_name = "default";
    // set default coordinate to 0,0
    coordinate.assign(0,0);

    health = 100;
}

int Player::getPlayerID(){
    return id;
}

vector<int> Player::getCoordinate(){
    return coordinate;
}

void Player::updateCoordinate(vector<int> newCoordinate){
    newCoordinate = newCoordinate;
}