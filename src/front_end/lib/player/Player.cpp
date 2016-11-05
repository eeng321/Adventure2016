#include <string>
#include <vector>
#include <algorithm>

#include "Player.h"
//#include "../../model/include/id.h"
#include "../../model/include/playerModel.h"

using description = std::vector<std::string>;
using keyword = std::string;

using std::string;
using std::vector;

const int DEFAULT_SPAWN = 0;
const int START_HEALTH = 100;

Player::Player(playerId idIn)
        : id(std::move(idIn)),
          username(""),
          location(DEFAULT_SPAWN),
          health(START_HEALTH) {}

Player::Player(playerId idIn,
               string usernameIn,
               roomId locationIn,
               string damageIn,
               int healthIn,
               int armorIn,
               string hitIn,
               int expIn,
               int goldIn,
               int levelIn,
               int thac0In,
               std::vector<itemId> inventoryIn)
        : id(std::move(idIn)),
          username(std::move(usernameIn)),
          location(std::move(locationIn)),
          damage(std::move(damageIn)),
          armor(armorIn),
          hit(std::move(hitIn)),
          exp(expIn),
          gold(goldIn),
          level(levelIn),
          thac0(thac0In),
          health(healthIn),
          inventory(std::move(inventoryIn)) {}

PlayerModel Player::getModel() {
    PlayerModel model;
    model.playerId = id.value;
    model.loginName = username;
    model.roomId = location.value;
    model.damage = damage;
    model.armor = armor;
    model.hit = hit;
    model.exp = exp;
    model.gold = gold;
    model.level = level;
    model.thac0 = thac0;
    model.health = health;
    for (const itemId &item: inventory) {
        model.inventory.push_back(item.value);
    }
    return model;
}

void Player::setModel(PlayerModel model) {
    id.value = model.playerId;
    username = model.loginName;
    location = model.roomId;
    damage = model.damage;
    armor = model.armor;
    hit = model.hit;
    exp = model.exp;
    gold = model.gold;
    level = model.level;
    thac0 = model.thac0;
    health = model.health;

    inventory.clear();
    for (int item : model.inventory) {
        inventory.push_back(itemId(item));
    }
}

playerId Player::getId() const {
    return id;
}

string Player::getUsername() const {
    return username;
}

roomId Player::getLocation() const {
    return location;
}

string Player::getDamage() const {
    return damage;
}

int Player::getArmor() const {
    return armor;
}

string Player::getHit() const {
    return hit;
}

int Player::getExp() const {
    return exp;
}

int Player::getGold() const {
    return gold;
}

int Player::getLevel() const {
    return level;
}

int Player::getThac0() const {
    return thac0;
}

std::vector<itemId> Player::getInventory() const {
    return inventory;
}

int Player::getHealth() const {
    return health;
}

void Player::addToInventory(itemId item) {
    inventory.push_back(std::move(item));
}

void Player::removeFromInventory(const itemId &item) {
    auto element = std::find(inventory.begin(), inventory.end(), item);
    if (element == inventory.end()) {
        throw std::domain_error("item not in inventory");
    }
    inventory.erase(element);
}

void Player::incrementLevel() {
    level++;
}

void Player::addExp(int expAdded) {
    exp = exp + expAdded;
    if (exp > 100) {
        exp = exp - 100;
        incrementLevel();
    }
}

void Player::deceaseHealth(int change) {
    health = health - change;
}

void Player::increaseHealth(int change) {
    health = health + change;
}

void Player::setLocation(roomId id) {
    location = id;
}