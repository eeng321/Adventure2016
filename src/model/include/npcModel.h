//
// Created by braden on 31/10/16.
//

#ifndef ADVENTURE2016_NPCMODEL_H
#define ADVENTURE2016_NPCMODEL_H

#pragma once
#include "../../back_end/lib/hiberlite/include/hiberlite.h"
#include <vector>
#include <string>

class NpcModel {
public:
	friend class hiberlite::access;
    template<class Archive>
    void hibernate(Archive & ar)
    {
        ar & HIBERLITE_NVP(mainDesc);
        ar & HIBERLITE_NVP(npcId);
        ar & HIBERLITE_NVP(keywords);
        ar & HIBERLITE_NVP(longDesc);
        ar & HIBERLITE_NVP(shortDesc);
        ar & HIBERLITE_NVP(damage);
        ar & HIBERLITE_NVP(armor);
        ar & HIBERLITE_NVP(hit);
        ar & HIBERLITE_NVP(exp);
        ar & HIBERLITE_NVP(gold);
        ar & HIBERLITE_NVP(level);
        ar & HIBERLITE_NVP(thac0);
    }

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
};

#endif //ADVENTURE2016_NPCMODEL_H
