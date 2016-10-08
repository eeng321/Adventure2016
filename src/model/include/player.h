#ifndef ADVENTURE2016_PLAYER_H
#define ADVENTURE2016_PLAYER_H


#include <string>
#include <vector>

using namespace std;

class Player{
public:
    Player(int playerID);
    int getPlayerID();
    vector<int> getCoordinate();
    void updateCoordinate(vector<int> newCoordinate);

private:
    // Player identification attributes
    int id;
    string login_name;

    // Player information attributes
    vector<int> coordinate;

    // Player stats
    int health;
};




#endif //ADVENTURE2016_PLAYER_H
