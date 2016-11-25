#include "roomDriver.h"
#include <iostream>

using namespace std;

static std::map<int, hiberlite::sqlid_t> roomIdMap;

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

    auto sqlId = roomIdMap[roomId];

    hiberlite::bean_ptr<RoomModel> roomRecord = db.loadBean<RoomModel>(sqlId);

    RoomModel room;
    room.area = roomRecord->area;
    room.id = roomRecord->id;
    room.name = roomRecord->name;
    room.mainDescription = roomRecord->mainDescription;
    room.extendedDescriptions = roomRecord->extendedDescriptions;
    room.doors = roomRecord->doors;
    room.npcList = roomRecord->npcList;
    room.playerList = roomRecord->playerList;
    room.itemList = roomRecord->itemList;
    db.close();
    return room;
}

RoomModel addRoom(RoomModel room){
    hiberlite::Database db;
    db.open("AdventureDatabase.db");
    hiberlite::bean_ptr<RoomModel> r = db.copyBean(room);
    r->id = room.id;
    r.save();

    roomIdMap.insert(std::make_pair(room.id, r.get_id()));
    db.close();
    return room;
}

RoomModel modifyRoom(int roomId, RoomModel updateFields){
    hiberlite::Database db;
    db.open("AdventureDatabase.db");
    auto sqlId = roomIdMap[roomId];

    hiberlite::bean_ptr<RoomModel> editRoom = db.loadBean<RoomModel>(sqlId);

    editRoom->id = updateFields.id;
    editRoom->name = updateFields.name;
    editRoom->mainDescription = updateFields.mainDescription;
    editRoom->extendedDescriptions = updateFields.extendedDescriptions;
    editRoom->doors = updateFields.doors;
    editRoom->npcList = updateFields.npcList;
    editRoom->playerList = updateFields.playerList;
    editRoom->itemList = updateFields.itemList;
    editRoom.save();
    db.close();
    return loadRoom(roomId);
}

bool removeRoom(int roomId){
    hiberlite::Database db;
    db.open("AdventureDatabase.db");
    vector< hiberlite::bean_ptr<RoomModel> > listRooms=db.getAllBeans<RoomModel>();
    
    int numOfRooms = listRooms.size();

    for(auto demo : listRooms ) {
        if (demo->id == roomId) {
            demo.destroy();
            demo.save();
        }
    }

    db.close();

    //printRoomDB();
    //return true if number of players in db changes after deleting
    return (numOfRooms != listRooms.size());
    
}

