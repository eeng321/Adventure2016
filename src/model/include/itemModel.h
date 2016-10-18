//
// Created by braden on 13/10/16.
//

#ifndef ITEM_MODEL_H
#define ITEM_MODEL_H

using id = int;

class ItemModel {
public:
	std::vector<std::string> extra;
	id itemId;
	std::vector<std::string> keywords;
	std::string longdesc;
	std::string shortdesc;
};


#endif //ITEM_MODEL_H
