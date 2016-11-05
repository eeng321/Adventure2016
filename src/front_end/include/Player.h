#ifndef ADVENTURE2016_PLAYER_H
#define ADVENTURE2016_PLAYER_H


#include <string>
#include <memory>

#include "../../model/include/id.h"

class PlayerModel;

class Player {
public:
    Player(playerId idIn);

    Player(playerId idIn,
           std::string username,
           roomId locationIn,
           std::string damageIn,
           int healthIn,
           int armorIn,
           std::string hitIn,
           int expIn,
           int goldIn,
           int levelIn,
           int thac0In,
           std::vector<itemId> inventoryIn);

    PlayerModel getModel();
    void setModel(PlayerModel model);

    playerId getId() const;//used to be get getPlayerId
    std::string getUsername() const;
    roomId getLocation() const;//used to be getRoomId
    int getHealth() const;
    std::string getDamage() const;
    int getArmor() const;
    std::string getHit() const;
    int getExp() const;
    int getGold() const;
    int getLevel() const;
    int getThac0() const;
    std::vector<itemId> getInventory() const;

    void incrementLevel();
    void addExp(int expAdded);
    void setLocation(roomId id);;//used to be updateRoomId
    void decreaseHealth(int change);
    void increaseHealth(int change);

    void addToInventory(itemId item);
    void removeFromInventory(const itemId &item);

private:
    playerId id;
    std::string username;//used to be loginName
    roomId location;
    int health;
    std::string damage;
    int armor;
    std::string hit;
    int exp;
    int gold;
    int level;
    int thac0;
    std::vector<itemId> inventory;
};

#endif //ADVENTURE2016_PLAYER_H
