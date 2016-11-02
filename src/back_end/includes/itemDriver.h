//
// Created by curtis on 01/11/16.
//

#ifndef ADVENTURE2016_ITEMDRIVER_H
#define ADVENTURE2016_ITEMDRIVER_H

#include "../../model/include/itemModel.h"

typedef bool success;

void printPlayer(ItemModel item);
void createDB();
void printDB();

ItemModel loadItem(int itemId);
ItemModel addItem(ItemModel item);
ItemModel modifyItem(int itemId, ItemModel updateFields);
success removeItem(int ItemId);

#endif //ADVENTURE2016_ITEMDRIVER_H
