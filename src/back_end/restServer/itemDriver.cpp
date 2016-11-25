//
// Created by curtis on 01/11/16.
//

#include "itemDriver.h"
#include "roomDriver.h"
#include <iostream>

using namespace std;
//hiberlite::Database db("AdventureDatabase.db");

void printItem(ItemModel item){
    cout << "ID: " << item.id << endl;
    cout << "Long Description: " << item.longDesc << endl;
    cout << "Short Description: " << item.shortDesc << endl;
    cout << "Keywords: ";
    for (auto keyword = item.keywords.begin(); keyword != item.keywords.end(); ++keyword){
        cout << *keyword << ' ';
    }
    cout << endl;
    // TODO: when verified above works.
    //cout << "Extras: " << item.id << endl;
}

/*void createDB(){
    hiberlite::Database db("AdventureDatabase.db");
    //register bean classes
    db.registerBeanClass<ItemModel>();
    //drop all tables beans will use
    db.dropModel();
    //create those tables again with proper schema
    db.createModel();
}*/

/*void printDB(){

    hiberlite::Database db("AdventureDatabase.db");

    cout << string(15,'=')+"\nreading the DB\n";

    vector< hiberlite::bean_ptr<ItemModel> > listItems=db.getAllBeans<ItemModel>();
    cout << "found " << listItems.size() << " items in the database:\n";

    for(size_t j=0;j<listItems.size();j++){
        cout << "[id = " << listItems[j]->id << "     ";
        cout << "[shortDesc = " << listItems[j]->shortDesc << "]\n";
    }
}*/

ItemModel loadItem(int itemId){

    hiberlite::Database db;
    db.open("AdventureDatabase.db");
    hiberlite::bean_ptr<ItemModel> demo = db.loadBean<ItemModel>(itemId);

    ItemModel item;
    item.attributes = demo->attributes;
    item.cost = demo->cost;
    item.extra = demo->extra;
    item.id = demo->id;
    item.type = demo->type;
    item.keywords = demo->keywords;
    item.longDesc = demo->longDesc;
    item.shortDesc = demo->shortDesc;
    item.wearFlags = demo->wearFlags;
    item.weight = demo->weight;
    db.close();
    return item;
}

ItemModel addItem(ItemModel item){
    hiberlite::Database db;
    db.open("AdventureDatabase.db");
    hiberlite::bean_ptr<ItemModel> i=db.copyBean(item);
    i->id = i.get_id();
    item.id = i.get_id();
    i.save();

    RoomModel room = loadRoom(item.roomId);
    room.itemList.push_back(item.id);
    modifyRoom(room.id, room);
    db.close();
    return item;
}

ItemModel modifyItem(int itemId, ItemModel updateFields){
    hiberlite::Database db;
    db.open("AdventureDatabase.db");
    hiberlite::bean_ptr<ItemModel> editItem = db.loadBean<ItemModel>(itemId);

    editItem->attributes = updateFields.attributes;
    editItem->cost = updateFields.cost;
    editItem->extra = updateFields.extra;
    editItem->type = updateFields.type;
    editItem->keywords = updateFields.keywords;
    editItem->longDesc = updateFields.longDesc;
    editItem->shortDesc = updateFields.shortDesc;
    editItem->wearFlags = updateFields.wearFlags;
    editItem->weight = updateFields.weight;
    editItem.save();
    db.close();
    return loadItem(itemId);
}

success removeItem(int itemId){
    hiberlite::Database db;
    db.open("AdventureDatabase.db");
    hiberlite::bean_ptr<ItemModel> item = db.loadBean<ItemModel>(itemId);
    vector< hiberlite::bean_ptr<ItemModel> > listItems=db.getAllBeans<ItemModel>();
    int numOfItems = listItems.size();

    RoomModel room = loadRoom(item->roomId);
    for (int i = 0; i < room.itemList.size(); i++ ){
        if(item->id == room.itemList[i]){
            room.npcList.erase(room.itemList.begin()+ i);
        }
    }

    modifyRoom(room.id, room);

    item.destroy();
    db.close();
    //printDB();
    //return true if number of items in db changes after deleting
    return (numOfItems != listItems.size());
}
