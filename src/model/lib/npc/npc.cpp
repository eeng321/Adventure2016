#include <string>
#include <utility>
#include <algorithm>
#include <stdexcept>

#include "npcModel.h"
#include "npc.h"

using description = std::vector<std::string>;
using keyword = std::string;

Npc::Npc(description desc,
         npcId nid,
         std::vector<keyword> key,
         description ldesc,
         description sdesc,
         std::string damageIn,
         int armorIn,
         std::string hitIn,
         int expIn,
         int goldIn,
         int levelIn,
         int thac0In,
         int healthIn,
         std::vector<itemId> inventoryIn)
        : mainDesc(std::move(desc)),
          id(std::move(nid)),
          keywords(std::move(key)),
          longDesc(std::move(ldesc)),
          shortDesc(std::move(sdesc)),
          damage(std::move(damageIn)),
          armor(armorIn),
          hit(std::move(hitIn)),
          exp(expIn),
          gold(goldIn),
          level(levelIn),
          thac0(thac0In),
          health(healthIn),
          inventory(std::move(inventoryIn)) {}

NpcModel Npc::getModel() {
    NpcModel model;
    model.mainDesc = mainDesc;
    model.npcId = id.value;
    model.keywords = keywords;
    model.longDesc = longDesc;
    model.shortDesc = shortDesc;
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

void Npc::setModel(const NpcModel &model) {
    mainDesc = model.mainDesc;
    id.value = model.npcId;
    keywords = model.keywords;
    longDesc = model.longDesc;
    shortDesc = model.shortDesc;
    damage = model.damage;
    armor = model.armor;
    hit = model.hit;
    exp = model.exp;
    gold = model.gold;
    level = model.level;
    thac0 = model.thac0;

    inventory.clear();
    for (int item : model.inventory) {
        inventory.push_back(itemId(item));
    }
}

description Npc::getMainDesc() const {
    return mainDesc;
}

npcId Npc::getNpcId() const {
    return id;
}

std::vector<keyword> Npc::getKeywords() const {
    return keywords;
}

description Npc::getLongDesc() const {
    return longDesc;
}

description Npc::getShortDesc() const {
    return shortDesc;
}

std::string Npc::getDamage() const {
    return damage;
}

int Npc::getArmor() const {
    return armor;
}

std::string Npc::getHit() const {
    return hit;
}

int Npc::getExp() const {
    return exp;
}

int Npc::getGold() const {
    return gold;
}

int Npc::getLevel() const {
    return level;
}

int Npc::getThac0() const {
    return thac0;
}

std::vector<itemId> Npc::getInventory() const {
    return inventory;
}

int Npc::getHealth() const {
    return health;
}

void Npc::addToInventory(itemId item) {
    inventory.push_back(std::move(item));
}

void Npc::removeFromInventory(const itemId &item) {
    auto element = std::find(inventory.begin(), inventory.end(), item);
    if (element == inventory.end()) {
        throw std::domain_error("item not in inventory");
    }
    inventory.erase(element);
}

void Npc::incrementLevel() {
    level++;
}

void Npc::addExp(int expAdded) {
    exp = exp + expAdded;
    if (exp > 100) {
        exp = exp - 100;
        incrementLevel();
    }
}

void Npc::deceaseHealth(int change) {
    health = health - change;
}

void Npc::increaseHealth(int change) {
    health = health + change;
}