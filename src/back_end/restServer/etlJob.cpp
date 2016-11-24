//
// Created by william on 11/11/16.
//

#include <iostream>
#include <fstream>
#include <playerDriver.h>
#include "../includes/etlJob.h"
#include "initializeDB.h"

void etl::createDB() {
    std::ifstream ifile("AdventureDatabase.db");
    if(ifile){
        std::cout << "DB exists" << std::endl;
        return;
    }else{
        initializeDB();
        LoadRoomsToDB();
        LoadNPCsToDB();
        LoadItemsToDB();
    }
}

void etl::LoadRoomsToDB() {
    try{
        //createRoomDB();
        YAML::Node smurf = YAML::LoadFile("smurf.yaml");
        YAML::Node roomsNode = smurf["ROOMS"];
        std::vector<RoomModel> rooms = parser::extractRoomsFromSequence(roomsNode);
        for(auto &room : rooms){
            addRoom(room);
        }
    }catch(...){
        std::cout << "Could not load yaml file or rooms not available in the file" << std::endl;
    }
}

void etl::LoadNPCsToDB() {
    try{
        YAML::Node smurf = YAML::LoadFile("smurf.yaml");
        YAML::Node npcNode = smurf["NPCS"];
        std::vector<NpcModel> vectorNPC = parser::extractNPCFromSequence(npcNode);
        std::vector<reset> resets = etl::loadNPCResets();
        for(auto reset : resets){
            std::cout << "npc reset action and id: " << reset.action << ", " << reset.id << std::endl;
        }
        for(auto &npc : vectorNPC){

            addNpc(npc);
        }
    }catch(...){
        std::cout << "Could not load yaml file or npcs not available in the file" << std::endl;
    }
}

void etl::LoadItemsToDB() {
    try{
        YAML::Node items = YAML::LoadFile("smurf.yaml");
        YAML::Node itemNode = items["OBJECTS"];
        std::vector<ItemModel> vectorItemModel = parser::extractItemsFromSequence(itemNode);
        std::vector<reset> resets = etl::loadItemResets();
        for(auto reset : resets){
            std::cout << "item reset action and id: " << reset.action << ", " << reset.id << std::endl;
        }
        for(auto &item : vectorItemModel){
            std::cout << "adding item..." << std::endl;
            addItem(item);
        }
    }catch(...){
        std::cout << "could not load yaml file or items not available in the file" << std::endl;
    }
}

std::vector<reset> etl::loadNPCResets(){
    try{
        YAML::Node resets = YAML::LoadFile("smurf.yaml");
        YAML::Node resetNode = resets["RESETS"];
        std::vector<reset> npcResets;
        std::string const npcAction = "npc";
        npcResets = parser::extractResetsFromSequence(resetNode, npcAction);
        return npcResets;
    }catch(...){
        std::cout << "could not load yaml file or resets not available in the file" << std::endl;
    }
}

std::vector<reset> etl::loadItemResets(){

    try{
        YAML::Node resets = YAML::LoadFile("smurf.yaml");
        YAML::Node resetNode = resets["RESETS"];
        std::vector<reset> itemResets;
        std::string const itemAction = "object";
        itemResets = parser::extractResetsFromSequence(resetNode, itemAction);
        return itemResets;

    }catch(...){
        std::cout << "could not load yaml file or resets not available in the file" << std::endl;
    }
}