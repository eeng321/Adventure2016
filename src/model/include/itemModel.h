//
// Created by braden on 13/10/16.
//

#ifndef ITEM_MODEL_H
#define ITEM_MODEL_H

#include <string>
#include <vector>

#include "id.h"

using id = int;

class ItemModel {
public:
	std::vector<std::string> extra;
	itemID id;
	std::vector<std::string> keywords;
	std::string longdesc;
	std::string shortdesc;
	ItemModel();
};


#endif //ITEM_MODEL_H
