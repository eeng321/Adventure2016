#ifndef ADVENTURE2016_PLAYER_H
#define ADVENTURE2016_PLAYER_H

#pragma once
#include "../../back_end/lib/hiberlite/include/hiberlite.h"
#include <string>

using namespace std;


class PlayerModel {
public:

    friend class hiberlite::access;
    template<class Archive>
    void hibernate(Archive & ar)
    {
        ar & HIBERLITE_NVP(playerId);
        ar & HIBERLITE_NVP(loginName);
        ar & HIBERLITE_NVP(coordinate);
        ar & HIBERLITE_NVP(health);
    }

    int getPlayerID();
    int getCoordinate();
    void updateCoordinate(int newCoordinate);

    // Player identification attributes
    int playerId;
    string loginName;

    // Player information attributes
    int coordinate;

    // Player stats
    int health;
};


#endif //ADVENTURE2016_PLAYER_H

