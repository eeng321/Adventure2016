//
// Created by braden on 13/10/16.
//

#ifndef ITEM_MODEL_H
#define ITEM_MODEL_H

#include <string>
#include <vector>

#include "id.h"
#include "itemType.h"


class ItemModel {
public:
    std::vector<std::string> attributes;
    int cost;
    std::vector<std::string> extra;
	int id;
    item_type type;
	std::vector<std::string> keywords;
	std::string longDesc;
	std::string shortDesc;
	std::vector<std::string> wear_flags;
    int weight;

	ItemModel();
};


#endif //ITEM_MODEL_H
