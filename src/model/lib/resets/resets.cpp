//resets.cpp

#include "resets.h"

resets::resets(){}

void resets::runAll(){
    runNpc();
    runItem();
    runGive();
}

void resets::runNpc(){
    for (auto npcReset : npcResets){
        //TODO
    }
}

void resets::runItem(){
    for (auto itemReset : itemResets){
        //TODO
    }
}

void resets::runGive(){
    for (auto giveReset : giveResets){
        //TODO
    }
}

void resets::addItem(const itemReset& item){
    itemResets.push_back(item);
}

void resets::addNpc(const npcReset& npc){
    npcResets.push_back(npc);
}

void resets::addGive(const giveReset& give){
    giveResets.push_back(give);
}
