#include "npcDriver.h"
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

    return npc;
}

NpcModel addNpc(NpcModel npc){
    hiberlite::Database db;
    db.open("AdventureDatabase.db");
    hiberlite::bean_ptr<NpcModel> p=db.copyBean(npc);
    p->npcId = p.get_id();
    npc.npcId = p.get_id();
    p.save();

    return npc;
}

NpcModel modifyNpc(int npcId, NpcModel updateFields){
    hiberlite::Database db;
    db.open("AdventureDatabase.db");
    hiberlite::bean_ptr<NpcModel> editNpc = db.loadBean<NpcModel>(npcId);

    editNpc->hit = updateFields.hit;
    editNpc->armor = updateFields.armor;
    editNpc->damage = updateFields.damage;
    editNpc.save();

    return loadNpc(npcId);
}

success removeNpc(int npcId){
    hiberlite::Database db;
    db.open("AdventureDatabase.db");
    hiberlite::bean_ptr<NpcModel> npc = db.loadBean<NpcModel>(npcId);
    vector< hiberlite::bean_ptr<NpcModel> > listNpcs=db.getAllBeans<NpcModel>();
    int numOfNpcs = listNpcs.size();
    npc.destroy();
    //printNpc();
    //return true if number of npcs in db changes after deleting
    return (numOfNpcs != listNpcs.size());
    
}