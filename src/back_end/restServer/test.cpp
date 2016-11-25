//
// Created by william on 19/10/16.
// TEST FILE FOR BACKEND, JUST MODIFY THE CMAKELIST.TXT
//
#include <iostream>
#include "../../model/include/npcModel.h"
#include "parser.h"
#include "../../model/include/room.h"
#include <typeinfo>
#include <fstream>


using namespace std;
int main(){
    YAML::Node node = YAML::LoadFile("midgaard.yml");
    YAML::Node resetNode = node[parser::WORLD_RESET];
    std::vector<reset> resets = parser::extractResetsFromSequence(resetNode, "npc");
//    YAML::Node NPCNode = node[parser::WORLD_NPC];
//    std::vector<NpcModel> npcs = parser::extractNPCFromSequence(NPCNode);
////    for(auto s : npcs){
////        cout << s.npcId << endl;
////    }
//    reset res;
//    res.id = 2907;
//    for(auto &reset : resets){
//        auto it = std::find_if(npcs.begin(), npcs.end(), [&reset](const NpcModel& obj) {
//            return obj.npcId == reset.id;
//        });
//        if(it != npcs.end()){
//            it->roomId = reset.room;
//            cout << it->roomId << endl;
//
//        }
//    }

    YAML::Node itemsNode = node[parser::WORLD_ITEM];
    std::vector<ItemModel> items = parser::extractItemsFromSequence(itemsNode);
    for(auto &item : items){
        cout << item.id << endl;
    }

//    YAML::Node roomNode = node[parser::WORLD_ROOMS];
//    std::vector<RoomModel> rooms = parser::extractRoomsFromSequence(roomNode);
//    for(auto &room : rooms){
//        cout << room.name << endl;
//    }
    return 0;
}

