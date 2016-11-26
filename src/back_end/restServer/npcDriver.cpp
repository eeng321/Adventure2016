#include "npcDriver.h"
#include "roomDriver.h"
#include <iostream>

using namespace std;

// void createDB(){
//     hiberlite::Database db("AdventureDatabase.db");
//     //register bean classes
//     db.registerBeanClass<NpcModel>(); 
//     //drop all tables beans will use
//     db.dropModel();
//     //create those tables again with proper schema
//     db.createModel();

// }

void printNpc(){

    hiberlite::Database db("AdventureDatabase.db");

    cout << string(15,'=')+"\nreading the DB\n";

    vector< hiberlite::bean_ptr<NpcModel> > listNpcs=db.getAllBeans<NpcModel>();
    cout << "found " << listNpcs.size() << " Npcs in the database:\n";

    for(size_t j=0;j<listNpcs.size();j++){
        cout << "[level = " << listNpcs[j]->level << "     ";
        cout << "hit = " << listNpcs[j]->hit << "     ";
        cout << "damage = " << listNpcs[j]->damage << "     ";
        cout << "id = " << listNpcs[j]->npcId << "]\n";
    }
}

NpcModel loadNpc(int npcId){

    hiberlite::Database db;
    db.open("AdventureDatabase.db");
    hiberlite::bean_ptr<NpcModel> loadNpc = db.loadBean<NpcModel>(npcId);

    NpcModel npc;
    npc.npcId = loadNpc->npcId;
    npc.mainDesc = loadNpc->mainDesc;
    npc.keywords = loadNpc->keywords;
    npc.longDesc = loadNpc->longDesc;
    npc.shortDesc = loadNpc->shortDesc;
    npc.damage = loadNpc->damage;
    npc.armor = loadNpc->armor;
    npc.hit = loadNpc->hit;
    npc.exp = loadNpc->exp;
    npc.gold = loadNpc->gold;
    npc.level = loadNpc->level;
    npc.thac0 = loadNpc->thac0;
    npc.roomId = loadNpc->roomId;
    npc.health = loadNpc->health;

    db.close();

    return npc;
}

NpcModel addNpc(NpcModel npc){
    hiberlite::Database db;
    db.open("AdventureDatabase.db");
    hiberlite::bean_ptr<NpcModel> p=db.copyBean(npc);
    p->npcId = p.get_id();
    npc.npcId = p.get_id();
    p->roomId = npc.roomId;

    p.save();


    if(npc.roomId == -1 ){

    }
    else {
        RoomModel room = loadRoom(npc.roomId);
        room.npcList.push_back(p->npcId);
        modifyRoom(room.id, room);
        db.close();
    }

    return npc;
}

NpcModel modifyNpc(int npcId, NpcModel updateFields){
    hiberlite::Database db;
    db.open("AdventureDatabase.db");
    hiberlite::bean_ptr<NpcModel> editNpc = db.loadBean<NpcModel>(npcId);
    int prevRoomId = editNpc->roomId;
    editNpc->health = updateFields.health;
    editNpc->hit = updateFields.hit;
    editNpc->armor = updateFields.armor;
    editNpc->damage = updateFields.damage;
    editNpc->roomId = updateFields.roomId;

    if (prevRoomId != updateFields.roomId){
        RoomModel oldRoom = loadRoom(prevRoomId);
        for (int i = 0; i < oldRoom.npcList.size(); i++ ){
            cout << oldRoom.npcList[i] << endl;
            cout<< editNpc->npcId << endl;
            if(oldRoom.npcList[i] == editNpc->npcId){
                oldRoom.npcList.erase(oldRoom.npcList.begin()+ i);
            }
        }
        modifyRoom(oldRoom.id, oldRoom);
    }
    if(updateFields.roomId == -1) {

    }
    else {
        RoomModel newRoom = loadRoom(updateFields.roomId);
        newRoom.npcList.push_back(editNpc->npcId);
        modifyRoom(newRoom.id, newRoom);

    }
    editNpc.save();
    db.close();

    return loadNpc(npcId);
}

success removeNpc(int npcId){
    hiberlite::Database db;
    db.open("AdventureDatabase.db");
    hiberlite::bean_ptr<NpcModel> npc = db.loadBean<NpcModel>(npcId);
    vector< hiberlite::bean_ptr<NpcModel> > listNpcs=db.getAllBeans<NpcModel>();
    int numOfNpcs = listNpcs.size();
    RoomModel room = loadRoom(npc->roomId);
    for (int i = 0; i < room.npcList.size(); i++ ){
        if(npc->npcId == room.npcList[i]){
            room.npcList.erase(room.npcList.begin()+ i);
        }
    }

    modifyRoom(room.id, room);

    npc.destroy();
    db.close();
    //printNpc();
    //return true if number of npcs in db changes after deleting
    return (numOfNpcs != listNpcs.size());
    
}