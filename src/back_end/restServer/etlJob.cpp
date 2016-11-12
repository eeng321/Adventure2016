//
// Created by william on 11/11/16.
//

#include <iostream>
#include "../includes/etlJob.h"
#include "../../model/include/roomModel.h"
#include "../../model/include/doorModel.h"
#include "../../model/include/npcModel.h"

void etl::LoadRoomsToDB() {
    try{
//        FILE
//        if()
        YAML::Node smurf = YAML::LoadFile("smurf.yaml");//TODO Couldn't use ~/cmpt373/adventure2016.... must have path be absolute? how to fix
        YAML::Node roomsNode = smurf["ROOMS"];
        std::vector<RoomModel> rooms = parser::extractRoomsFromSequence(roomsNode);//TODO Load all these onto the db
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
        for(auto &npc : vectorNPC){
            addNpc(npc);
        }
    }catch(...){
        std::cout << "Could not load yaml file or npcs not available in the file" << std::endl;
    }
}