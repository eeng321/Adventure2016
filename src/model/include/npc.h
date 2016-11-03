// npc.h
// Npc object structure. Uses values from a parse Npc from a YAML file.

#ifndef ADVENTURE2016_NPC_H
#define ADVENTURE2016_NPC_H

#include <string>
#include <vector>

#include "id.h"

class NpcModel;

class Npc {
public:
    Npc(std::vector<std::string> desc,
        npcId nid,
        std::vector<std::string> key,
        std::vector<std::string> ldesc,
		std::vector<std::string> sdesc,
		std::string damage,
		int armor,
		std::string hit,
		int exp,
		int gold,
		int level,
		int thac0);
	Npc();

	void setModel(const NpcModel& model);
	NpcModel getModel();

	std::vector<std::string> getMainDesc() const;
    npcId getNpcId() const;
    std::vector<std::string> getKeywords() const;
	std::vector<std::string> getLongDesc() const;
	std::vector<std::string> getShortDesc() const;
	std::string getDamage() const;
	int getArmor() const;
	std::string getHit() const;
	int getExp() const;
	int getGold() const;
	int getLevel() const;
	int getThac0() const;
	std::vector<itemId> getInventory() const;

	void addToInventory(itemId item);
	void removeFromInventory(const itemId& item);

private:
	std::vector<std::string> mainDesc;
	npcId id;
	std::vector<std::string> keywords;
	std::vector<std::string> longDesc;
	std::vector<std::string> shortDesc;
	std::string damage;
	int armor;
	std::string hit;
	int exp;
	int gold;
	int level;
	int thac0;
	std::vector<itemId> inventory;

};

#endif //ADVENTURE2016_NPC_H
