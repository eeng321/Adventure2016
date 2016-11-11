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
        YAML::Node testNode = YAML::LoadFile("smurf.yaml");//TODO Couldn't use ~/cmpt373/adventure2016.... must have path be absolute? how to fix
        YAML::Node roomsNode = testNode["ROOMS"];
        if(roomsNode){
            std::cout << "found rooms node" << std::endl;
        }else{
            std::cout << "did not find" << std::endl;
        }
        std::vector<RoomModel> rooms = parser::extractRoomsFromSequence(roomsNode);//TODO Load all these onto the db
        for(auto room : rooms){
            addRoom(room);
        }
    }catch(...){
        std::cout << "Could not load yaml file or rooms not available in the file" << std::endl;
    }
}

void etl::LoadNPCsToDB() {

}