//
// Created by curtis on 01/11/16.
//

#include "itemDriver.h"
#include <iostream>

using namespace std;
//hiberlite::Database db("AdventureDatabase.db");

void printItem(ItemModel item){
    cout << "ID: " << item.id << endl;
    cout << "Long Description: " << item.longDesc << endl;
    cout << "Short Description: " << item.shortDesc << endl;
    cout << "Keywords: ";
    for (auto keyword = item.keywords.begin(); i != item.keywords.end(); ++keyword){
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

void printDB(){

    hiberlite::Database db("AdventureDatabase.db");

    cout << string(15,'=')+"\nreading the DB\n";

    vector< hiberlite::bean_ptr<ItemModel> > listItems=db.getAllBeans<ItemModel>();
    cout << "found " << listItems.size() << " items in the database:\n";

    for(size_t j=0;j<listItems.size();j++){
        cout << "[id = " << listItems[j]->id << "     ";
        cout << "[shortDesc = " << listItems[j]->shortDesc << "]\n";
    }
}

ItemModel loadItem(int itemId){

    hiberlite::Database db;
    db.open("AdventureDatabase.db");
    hiberlite::bean_ptr<ItemModel> demo = db.loadBean<ItemModel>(itemId);

    ItemModel item;
    item.id = demo->id;
    item.extra = demo->extra;
    item.keywords = demo->keywords;
    item.longDesc = demo->longDesc;
    item.shortDesc = demo->shortDesc;
    return item;
}

ItemModel addItem(ItemModel item){
    hiberlite::Database db;
    db.open("AdventureDatabase.db");
    hiberlite::bean_ptr<ItemModel> i=db.copyBean(item);
    i->id = i.get_id();
    item.id = i.get_id();
    i.save();
    printDB();

    return item;
}

ItemModel modifyItem(int itemId, ItemModel updateFields){
    hiberlite::Database db;
    db.open("AdventureDatabase.db");
    hiberlite::bean_ptr<ItemModel> editItem = db.loadBean<ItemModel>(id);

    editItem->extra = updateFields.extra;
    editItem->keywords = updateFields.keywords;
    editItem->longDesc = updateFields.longDesc;
    editItem->shortDesc = updateFields.shortDesc;
    editItem.save();

    return loadItem(id);
}

success removeItem(int itemId){
    hiberlite::Database db;
    db.open("AdventureDatabase.db");
    hiberlite::bean_ptr<ItemModel> item = db.loadBean<ItemModel>(id);
    vector< hiberlite::bean_ptr<ItemModel> > listItems=db.getAllBeans<ItemModel>();
    int numOfItems = listItems.size();
    item.destroy();
    account.destroy();
    //printDB();
    //return true if number of items in db changes after deleting
    return (numOfItems != listItems.size());
}
