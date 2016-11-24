#include "roomDriver.h"
#include <iostream>

using namespace std;

void printRoomDB(){

    hiberlite::Database db;
    db.open("AdventureDatabase.db");

    cout << string(15,'=')+"\nreading the DB\n";

    vector< hiberlite::bean_ptr<RoomModel> > listRooms=db.getAllBeans<RoomModel>();
    cout << "found " << listRooms.size() << " Rooms in the database:\n";

    for(size_t j=0;j<listRooms.size();j++){
        cout << "[name = " << listRooms[j]->name << "     ";
        cout << "[area = " << listRooms[j]->area << "     ";
        cout << "id = " << listRooms[j]->id << "]\n";
        for (int i = 0; i< listRooms[j]->mainDescription.size(); i++) {
            cout << "[Main Description = " << listRooms[j]->mainDescription[i] << "     ";
        }
        for (auto extendedDesc : listRooms[j]->extendedDescriptions) {
            for (auto keyword : extendedDesc.keywords){
                cout << "[ExtendedDescription keywords = " << keyword << "     ";

            }
            }
    }
}

RoomModel loadRoom(int roomId){

    hiberlite::Database db;
    db.open("AdventureDatabase.db");
    vector< hiberlite::bean_ptr<RoomModel> > listRooms=db.getAllBeans<RoomModel>();
    RoomModel room;

    for(auto demo : listRooms ){
        if(demo->id == roomId ){
            room.area = demo->area;
            room.id = demo->id;
            room.name = demo->name;
            room.mainDescription = demo->mainDescription;
            room.extendedDescriptions = demo->extendedDescriptions;
            room.doors = demo->doors;
            room.npcList = demo->npcList;
            room.playerList = demo->playerList;
            room.itemList = demo->itemList;
            break;
        }
    }

    return room;
}

RoomModel addRoom(RoomModel room){
    hiberlite::Database db;
    db.open("AdventureDatabase.db");
    hiberlite::bean_ptr<RoomModel> r=db.copyBean(room);
    r->id = room.id;
    r.save();

    return room;
}

RoomModel modifyRoom(int roomId, RoomModel updateFields){
    hiberlite::Database db;
    db.open("AdventureDatabase.db");
    hiberlite::bean_ptr<RoomModel> editRoom = db.loadBean<RoomModel>(roomId);

    editRoom->id = updateFields.id;
    editRoom->name = updateFields.name;
    editRoom->mainDescription = updateFields.mainDescription;
    editRoom->extendedDescriptions = updateFields.extendedDescriptions;
    editRoom->doors = updateFields.doors;
    editRoom->npcList = updateFields.npcList;
    editRoom->playerList = updateFields.playerList;
    editRoom->itemList = updateFields.itemList;
    editRoom.save();

    return loadRoom(roomId);
}

bool removeRoom(int roomId){
    hiberlite::Database db;
    db.open("AdventureDatabase.db");
    vector< hiberlite::bean_ptr<RoomModel> > listRooms=db.getAllBeans<RoomModel>();
    
    int numOfRooms = listRooms.size();

    for(int i = 0; i < listRooms.size(); i++ ) {

        if (listRooms[i]->id == roomId) {

            listRooms[i].destroy();

        }
    }


    //printRoomDB();
    //return true if number of players in db changes after deleting
    return (numOfRooms != listRooms.size());
    
}

