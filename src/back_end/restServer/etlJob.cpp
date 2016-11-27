//
// Created by william on 11/11/16.
//

#include <iostream>
#include <fstream>
#include <playerDriver.h>
#include "../includes/etlJob.h"
#include "initializeDB.h"
std::string db = "midgaard.yml";
void etl::createDB() {
    std::ifstream ifile("AdventureDatabase.db");
    if(ifile){
        std::cout << "DB exists" << std::endl;
        return;
    }else{
        std::cout << "Adding entries to the db." << std::endl;
        initializeDB();
        LoadRoomsToDB();
        LoadNPCsToDB();
        LoadItemsToDB();
        std::cout << "Database is ready." << std::endl;
    }
}

void etl::LoadRoomsToDB() {
    try{
        YAML::Node smurf = YAML::LoadFile(db);
        YAML::Node roomsNode = smurf[parser::WORLD_ROOMS];
        std::vector<RoomModel> rooms = parser::extractRoomsFromSequence(roomsNode);
        for(auto &room : rooms){
            addRoom(room);
        }
        std::cout << "Rooms Added." << std::endl;
    }catch(...){
        std::cout << "Could not load yaml file or rooms not available in the file" << std::endl;
    }
}

void etl::LoadNPCsToDB() {
    try{
        YAML::Node smurf = YAML::LoadFile(db);
        YAML::Node npcNode = smurf[parser::WORLD_NPC];
        std::vector<NpcModel> vectorNPC = parser::extractNPCFromSequence(npcNode);
        std::vector<reset> resets = etl::loadResets("npc");

        for(auto &reset : resets){
            auto it = std::find_if(vectorNPC.begin(), vectorNPC.end(), [&reset](const NpcModel& obj) {
                return obj.npcId == reset.id;
            });
            if(it != vectorNPC.end()){
                NpcModel npc = *it;
                npc.roomId = reset.room;
                for(int x = 0; x < reset.limit; x++){
                    addNpc(npc);
                }
            }
        }
        std::cout << "NPCs Added." << std::endl;
    }catch(...){
        std::cout << "Could not load yaml file or npcs not available in the file" << std::endl;
    }
}

void etl::LoadItemsToDB() {
    try{
        YAML::Node items = YAML::LoadFile(db);
        YAML::Node itemNode = items[parser::WORLD_ITEM];
        std::vector<ItemModel> vectorItemModel = parser::extractItemsFromSequence(itemNode);
        std::vector<reset> resets = etl::loadResets("object");

        for(auto &reset : resets){
            auto it = std::find_if(vectorItemModel.begin(), vectorItemModel.end(), [&reset](const ItemModel& obj) {
                return obj.id == reset.id;
            });
            if(it != vectorItemModel.end()){
                ItemModel item = *it;
                item.roomId = reset.room;
                for(int x = 0; x < reset.limit; x++){
                    addItem(item);
                }
            }
        }
        std::cout << "Items added to DB." << std::endl;
    }catch(...){
        std::cout << "could not load yaml file or items not available in the file" << std::endl;
    }
}

std::vector<reset> etl::loadResets(std::string const &action){
    try{
        YAML::Node resets = YAML::LoadFile(db);
        YAML::Node resetNode = resets[parser::WORLD_RESET];
        std::vector<reset> npcResets;
        npcResets = parser::extractResetsFromSequence(resetNode, action);
        return npcResets;
    }catch(...){
        std::cout << "could not load yaml file or resets not available in the file" << std::endl;
    }
}
