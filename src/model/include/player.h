#ifndef ADVENTURE2016_PLAYER_H
#define ADVENTURE2016_PLAYER_H

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
    Player();
    Player(int playerID);
    //~Player();
    int getPlayerID();
    vector<int> getCoordinate();
    void updateCoordinate(vector<int> newCoordinate);

//private:
    // Player identification attributes
    int id;
    string login_name;

    // Player information attributes
    vector<int> coordinate;

    // Player stats
    int health;
};

HIBERLITE_EXPORT_CLASS(Player)


#endif //ADVENTURE2016_PLAYER_H
