//Player class

#include <string>

#include <odb/core.hxx>

#pragma db object
class Player
{
public:
    Player (unsigned long id,
            const std::string& name,
            const int health);
    friend class odb::access;

#pragma db id auto
    unsigned long id_; //player id

    std::string name_; //player name
    int health; 		 //player health
    //#pragma db object(player)
    //#pragma db member(player::id_) id
private:
    //Player() {}





    //int row_, col_; 		 //player position
};

