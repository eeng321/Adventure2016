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

void printNpcDB(){

    hiberlite::Database db("AdventureDatabase.db");

    cout << string(15,'=')+"\nreading the DB\n";

    vector< hiberlite::bean_ptr<NpcModel> > listNpcs=db.getAllBeans<NpcModel>();
    cout << "found " << listNpcs.size() << " Npcs in the database:\n";

    for(size_t j=0;j<listNpcs.size();j++){
        cout << "[shortDesc = " << listNpcs[j]-> shortDesc << "     ";
        cout << "id = " << listNpcs[j]->npcId << "]\n";
    }
}

NpcModel loadNpc(int npcId){

    hiberlite::Database db;
    db.open("AdventureDatabase.db");
    hiberlite::bean_ptr<NpcModel> demo = db.loadBean<NpcModel>(npcId);

    NpcModel npc;
    npc.npcId = demo->npcId;
    npc.mainDesc = demo->mainDesc;
    npc.keywords = demo->keywords;
    npc.longDesc = demo->longDesc;
    npc.shortDesc = demo->shortDesc;
    npc.damage = demo->damage;
    npc.armor = demo->armor;
    npc.hit = demo->hit;
    npc.exp = demo->exp;
    npc.gold = demo->gold;
    npc.level = demo->level;
    npc.thac0 = demo->thac0;

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
    //printDB();
    //return true if number of npcs in db changes after deleting
    return (numOfNpcs != listNpcs.size());
    
}