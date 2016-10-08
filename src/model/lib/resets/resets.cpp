//resets.cpp

#include "resets.h"

resets::resets(){}

void resets::runAll(){
    runNpc();
    runObject();
    runGive();
}

void resets::runNpc(){
    for (auto npcReset : npcResets){
        //TODO place npcReset.npcId into npcReset.roomId up to npcReset.limit times
    }
}

void resets::runObject(){
    for (auto objectReset : objectResets){
        //TODO place  objectReset.objectId into objectReset.roomId
    }
}

void resets::runGive(){
    for (auto giveReset : giveResets){
        //TODO not sure what a give action does!!!!
    }
}

void resets::addObject(const objectReset& object){
    objectResets.push_back(object);
}

void resets::addNpc(const npcReset& npc){
    npcResets.push_back(npc);
}

void resets::addGive(const giveReset& give){
    giveResets.push_back(give);
}
