#include "roomDriver.h"

#include <iostream>

using namespace std;

void printRoom(RoomModel room){
    cout << "AREA NAME: " << room.area << endl;
    cout << "ID: " << room.id << endl;

}

void createRoomDB(){
    //hiberlite::Database db("AdventureDatabase2.db");
    hiberlite::Database db;
    db.open("AdventureDatabase.db");
    //register bean classes
    db.registerBeanClass<RoomModel>();
    db.registerBeanClass<DoorModel>();

    db.dropModel();
    //create room and door tables again with proper schema
    db.createModel();



    //FOR TESTING PURPOSES
//
//    RoomModel demo;
//    demo.area = "White Plains";
//    demo.id = 1;
//    demo.name =  "the field";
//    demo.mainDescription = {"the empty green field filled with flowers "};
//    extendedDescription description;
//    description.description = {"test"};
//    description.keywords = {"sppoky", "dangerous"};
//    demo.extendedDescriptions = {description};

   // demo.navigable = true;
    //hiberlite::bean_ptr<RoomModel> db_room =db.copyBean(demo);

}

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

        }
    }

    //room.navigable = demo->navigable;

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
    vector< hiberlite::bean_ptr<RoomModel> > listRooms=db.getAllBeans<RoomModel>();
    for(int i = 0; i < listRooms.size(); i++ ) {
        if (listRooms[i]->id == roomId) {
            listRooms[i]->id = updateFields.id;
            listRooms[i]->name = updateFields.name;
            listRooms[i]->mainDescription = updateFields.mainDescription;
            listRooms[i]->extendedDescriptions = updateFields.extendedDescriptions;
            listRooms[i]->doors = updateFields.doors;
            listRooms[i]->npcList = updateFields.npcList;
            listRooms[i]->playerList = updateFields.playerList;
            listRooms[i]->itemList = updateFields.itemList;
            //listRooms[i]->navigable = updateFields.navigable;
            listRooms[i].save();


        }
    }



    return loadRoom(roomId);
}

bool removeRoom(int roomId){
    hiberlite::Database db;
    db.open("AdventureDatabase.db");
    vector< hiberlite::bean_ptr<RoomModel> > listRooms=db.getAllBeans<RoomModel>();

    for(int i = 0; i < listRooms.size(); i++ ) {

        if (listRooms[i]->id == roomId) {

            listRooms[i].destroy();

        }
    }
    int numOfRooms = listRooms.size();

    //printRoomDB();
    //return true if number of players in db changes after deleting
    return (numOfRooms != listRooms.size());
    
}

