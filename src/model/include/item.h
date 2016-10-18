//
// Created by braden on 13/10/16.
//

#ifndef ITEM_H
#define ITEM_H

#include<memory>

class ItemModel;

class Item {
private:
	std::unique_ptr<ItemModel> model;

public:


	void build();
};


#endif //ITEM_H
