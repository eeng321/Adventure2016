//
// Created by braden on 13/10/16.
//

#ifndef ITEM_MODEL_H
#define ITEM_MODEL_H

#include <string>
#include <vector>

#include "id.h"


class ItemModel {
public:
    std::vector<std::string> attributes;
    int cost;
    std::vector<std::string> extra;
	int id;
    std::string type;//What type should this be?
	std::vector<std::string> keywords;
	std::string longDesc;
	std::string shortDesc;
	std::vector<std::string> wear_flags;
    int weight;

	ItemModel();
};


#endif //ITEM_MODEL_H
