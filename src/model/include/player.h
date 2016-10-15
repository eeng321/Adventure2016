#ifndef ADVENTURE2016_PLAYER_H
#define ADVENTURE2016_PLAYER_H

#pragma once
#include "../../back_end/lib/hiberlite/include/hiberlite.h"
#include <string>
#include <vector>

using namespace std;

class Player{
public:

    friend class hiberlite::access;
    template<class Archive>
    void hibernate(Archive & ar)
    {
        ar & HIBERLITE_NVP(id);
        ar & HIBERLITE_NVP(login_name);
        ar & HIBERLITE_NVP(coordinate);
        ar & HIBERLITE_NVP(health);
    }

    int getPlayerID();

    int getCoordinate();

    void updateCoordinate(int newCoordinate);

    // Player identification attributes
    int id;
    string login_name;

    // Player information attributes
    int coordinate;

    // Player stats
    int health;
};

HIBERLITE_EXPORT_CLASS(Player)


#endif //ADVENTURE2016_PLAYER_H
