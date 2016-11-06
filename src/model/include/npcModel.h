//
// Created by braden on 31/10/16.
//

#ifndef ADVENTURE2016_NPCMODEL_H
#define ADVENTURE2016_NPCMODEL_H

#include <vector>
#include <string>

class NpcModel {
public:
	std::vector<std::string> mainDesc;
	int npcId;
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
	std::vector<int> inventory;
	int health;
};

#endif //ADVENTURE2016_NPCMODEL_H
