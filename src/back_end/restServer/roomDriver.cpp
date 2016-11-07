#include "roomDriver.h"

#include "../../model/include/doorModel.h"

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

/*    RoomModel demo;
    demo.area = "White Plains";
    demo.id = 1;
    demo.name =  "the field";
    demo.mainDescription = {"the empty green field filled with flowers "};
    extendedDescription description;
    description.description = {"test"};
    description.keywords = {"sppoky", "dangerous"};
    demo.extendedDescriptions = {description};
*/
    try{
        YAML::Node testNode = YAML::LoadFile("/home/sukh/Documents/CMPT_373/adventure2016/smurf.yaml");//TODO Couldn't use ~/cmpt373/adventure2016.... must have path be absolute? how to fix
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
    hiberlite::bean_ptr<RoomModel> demo = db.loadBean<RoomModel>(roomId);

    RoomModel room;
    room.area = demo->area;
    room.id = demo->id;
    room.name = demo->name;
    room.mainDescription = demo->mainDescription;
    room.extendedDescriptions = demo->extendedDescriptions;
    room.doors = demo->doors;
    room.npcList = demo->npcList;
    room.playerList = demo->playerList;
    room.itemList = demo->itemList;
    //room.navigable = demo->navigable;

    return room;
}

RoomModel addRoom(RoomModel room){
    hiberlite::Database db;
    db.open("AdventureDatabase.db");
    hiberlite::bean_ptr<RoomModel> r=db.copyBean(room);
    r->id = room.id;
    r.save();
    printRoomDB();

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
    //editRoom->navigable = updateFields.navigable;
    editRoom.save();

    return loadRoom(roomId);
}

bool removeRoom(int roomId){
    hiberlite::Database db;
    db.open("AdventureDatabase.db");
    hiberlite::bean_ptr<RoomModel> room = db.loadBean<RoomModel>(roomId);
    vector< hiberlite::bean_ptr<RoomModel> > listRooms=db.getAllBeans<RoomModel>();
    int numOfRooms = listRooms.size();
    room.destroy();
    //printRoomDB();
    //return true if number of players in db changes after deleting
    return (numOfRooms != listRooms.size());
    
}

