#include "roomDriver.h"
#include <iostream>

using namespace std;

void printRoom(RoomModel room){
    cout << "AREA NAME: " << room.area << endl;
    cout << "ID: " << room.roomId << endl;
    cout << "description: " << room.mainDescription << endl;
   // cout << "EXTENDED DESCRIPTION: " << room.extendedDescriptions << endl;
    //cout << "DOORS: " << room.doors << endl;
    //cout << "NPCLIST: " << room.npcList << endl;
    //cout << "PLAYERLIST: " << room.playerList << endl;
    //cout << "ITEMLIST: " << room.itemList << endl;
  //  cout << "NAVIGABLE: " << room.navigable << endl;

}

void createRoomDB(){
    hiberlite::Database db("AdventureDatabase.db");
    //register bean classes
    db.registerBeanClass<RoomModel>();
    //drop all tables beans will use
    db.dropModel();
    //create those tables again with proper schema
    db.createModel();

    RoomModel demo;
    demo.area = "White Plains";
    demo.roomId = 1;
    demo.name =  "the field";
    demo.mainDescription = "the empty green field filled with flowers ";
   // demo.navigable = true;
    hiberlite::bean_ptr<RoomModel> db_room =db.copyBean(demo);

}

void printRoomDB(){

    hiberlite::Database db("AdventureDatabase.db");

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
    db.open("AdventureDatabase.db");
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
    room.navigable = demo->navigable; */

    return room;
}

RoomModel addRoom(RoomModel room){
    hiberlite::Database db;
    db.open("AdventureDatabase.db");
    hiberlite::bean_ptr<RoomModel> r=db.copyBean(room);
    r->roomId = r.get_id();
    room.roomId = r.get_id();
    r.save();
    printRoomDB();

    return room;
}
/*
PlayerModel modifyPlayer(int playerId, PlayerModel updateFields){
    hiberlite::Database db;
    db.open("AdventureDatabase.db");
    hiberlite::bean_ptr<PlayerModel> editPlayer = db.loadBean<PlayerModel>(playerId);

    editPlayer->roomId = updateFields.roomId;
    editPlayer->health = updateFields.health;
    editPlayer.save();

    return loadPlayer(playerId);
}

success removePlayer(int playerId){
    hiberlite::Database db;
    db.open("AdventureDatabase.db");
    hiberlite::bean_ptr<PlayerModel> player = db.loadBean<PlayerModel>(playerId);
    hiberlite::bean_ptr<Credential> account = db.loadBean<Credential>(playerId);
    vector< hiberlite::bean_ptr<PlayerModel> > listPlayers=db.getAllBeans<PlayerModel>();
    int numOfPlayers = listPlayers.size();
    player.destroy();
    account.destroy();
    //printDB();
    //return true if number of players in db changes after deleting
    return (numOfPlayers != listPlayers.size());
    
}

*/