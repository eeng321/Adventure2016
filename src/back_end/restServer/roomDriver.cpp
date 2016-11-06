#include "roomDriver.h"
#include <iostream>

using namespace std;

void printRoom(RoomModel room){
    cout << "AREA NAME: " << room.area << endl;
    cout << "ID: " << room.id << endl;
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
    demo.id = 1;
    demo.name =  "the field";
    demo.mainDescription = {"the empty green field filled with flowers "};
    extendedDescription description;
    description.description = {"test"};
    description.keywords = {"sppoky", "dangerous"};
    demo.extendedDescriptions = {description};

    try{
        YAML::Node testNode = YAML::LoadFile("/home/william/cmpt373/adventure2016/smurf.yaml");//TODO Couldn't use ~/cmpt373/adventure2016.... must have path be absolute? how to fix
        YAML::Node roomsNode = testNode["ROOMS"];
        if(roomsNode){
            cout << "found rooms node" << endl;
        }else{
            cout << "did not find" << endl;
        }
        std::vector<RoomModel> rooms = parser::extractRoomsFromSequence(roomsNode);//TODO Load all these onto the db
        hiberlite::bean_ptr<RoomModel> db_room;
        for(auto room : rooms){
            db_room = db.copyBean(room);
        }
    }catch(exception ex){
        std::cout << "Could not load yaml file or rooms not available in the file" << endl;
    }

   // demo.navigable = true;
    //hiberlite::bean_ptr<RoomModel> db_room =db.copyBean(demo);

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
        cout << "id = " << listRooms[j]->id << "]\n";
    }
}

RoomModel loadRoom(int roomId){

    hiberlite::Database db;
    db.open("AdventureDatabase2.db");
    hiberlite::bean_ptr<RoomModel> demo = db.loadBean<RoomModel>(roomId);

    RoomModel room;
    room.area = demo->area;
    room.id = demo->id;
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
    r->id = r.get_id();
    room.id = r.get_id();
    r.save();
    printRoomDB();

    return room;
}

RoomModel modifyRoom(int roomId, RoomModel updateFields){
    hiberlite::Database db;
    db.open("AdventureDatabase2.db");
    hiberlite::bean_ptr<RoomModel> editRoom = db.loadBean<RoomModel>(roomId);

    editRoom->id = updateFields.id;
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

