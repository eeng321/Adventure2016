#include "roomDriver.h"
#include <iostream>

using namespace std;

void printRoom(RoomModel room){
    cout << "AREA NAME: " << room.area << endl;
    cout << "ID: " << room.roomId << endl;
    //cout << "description: " << room.mainDescription << endl;
   // cout << "EXTENDED DESCRIPTION: " << room.extendedDescriptions << endl;
    //cout << "DOORS: " << room.doors << endl;
    //cout << "NPCLIST: " << room.npcList << endl;
    //cout << "PLAYERLIST: " << room.playerList << endl;
    //cout << "ITEMLIST: " << room.itemList << endl;
  //  cout << "NAVIGABLE: " << room.navigable << endl;

}

void createRoomDB(){
    hiberlite::Database db("AdventureDatabase2.db");
    //register bean classes
    db.registerBeanClass<RoomModel>();
    //db.registerBeanClass<Door>();
    //drop all tables beans will use
    db.dropModel();
    //create those tables again with proper schema
    db.createModel();

    RoomModel demo;
    demo.area = "White Plains";
    demo.roomId = (id)1;
    demo.name =  "the field";
    demo.mainDescription = "the empty green field filled with flowers ";
   // demo.navigable = true;
    hiberlite::bean_ptr<RoomModel> db_room =db.copyBean(demo);

}

void printRoomDB(){

    hiberlite::Database db;
    db.open("AdventureDatabase2.db");

    cout << string(15,'=')+"\nreading the DB\n";

    vector< hiberlite::bean_ptr<RoomModel> > listRooms=db.getAllBeans<RoomModel>();
    cout << "found " << listRooms.size() << " Rooms in the database:\n";

    for(size_t j=0;j<listRooms.size();j++){
        cout << "[name = " << listRooms[j]->name << "     ";
        cout << "[area = " << listRooms[j]->area << "     ";
        cout << "id = " << listRooms[j]->roomId << "]\n";
    }
}

RoomModel loadRoom(int roomId){

    hiberlite::Database db;
    db.open("AdventureDatabase2.db");
    hiberlite::bean_ptr<RoomModel> demo = db.loadBean<RoomModel>(roomId);

    RoomModel room;
    room.area = demo->area;
    room.roomId = demo->roomId;
    room.name = demo->name;
    room.mainDescription = demo->mainDescription;
    /*room.doors = demo->doors;
    room.npcList = demo->npcList;
    room.playerList = demo->playerList;
    room.itemList = demo->itemList;
    room.navigable = demo->navigable;
    */
    return room;
}

RoomModel addRoom(RoomModel room){
    hiberlite::Database db;
    db.open("AdventureDatabase2.db");
    hiberlite::bean_ptr<RoomModel> r=db.copyBean(room);
    r->roomId = (id)r.get_id();
    room.roomId = (id)r.get_id();
    r.save();
    printRoomDB();

    return room;
}

RoomModel modifyRoom(int roomId, RoomModel updateFields){
    hiberlite::Database db;
    db.open("AdventureDatabase2.db");
    hiberlite::bean_ptr<RoomModel> editRoom = db.loadBean<RoomModel>(roomId);

    editRoom->roomId = updateFields.roomId;
    editRoom->name = updateFields.name;
    editRoom.save();

    return loadRoom(roomId);
}

bool removeRoom(int roomId){
    hiberlite::Database db;
    db.open("AdventureDatabase2.db");
    hiberlite::bean_ptr<RoomModel> room = db.loadBean<RoomModel>(roomId);
    vector< hiberlite::bean_ptr<RoomModel> > listPlayers=db.getAllBeans<RoomModel>();
    int numOfPlayers = listPlayers.size();
    room.destroy();
    printRoomDB();
    //return true if number of players in db changes after deleting
    return (numOfPlayers != listPlayers.size());
    
}

