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
    const char* fileName = "AdventureDatabase.db";
    std::ifstream ifile(fileName);
    if( ifile){
        std::cout << "exists" << endl;
    }else{
        std::cout << "doesn't exist" << endl;
    }
//
    NpcModel npcmodel;
    npcmodel.keywords.push_back("keyword 1");
    npcmodel.keywords.push_back("keyword 2");
    npcmodel.shortDesc = "short desc";
    npcmodel.npcId = 123;
    npcmodel.mainDesc.push_back("this is a");
    npcmodel.mainDesc.push_back("main desc");
    npcmodel.longDesc.push_back("this is a long");
    npcmodel.longDesc.push_back("desc");

    //cout << parser::npcSerialize(npcmodel) << endl;
    //NpcModel newModel = parser::npcDeserialize(parser::npcSerialize(npcmodel));
    //cout << parser::npcSerialize(newModel) << endl;
    //try{
        YAML::Node smurf = YAML::LoadFile("smurf.yaml");
        YAML::Node npcNode = smurf["NPCS"];
//        std::vector<NpcModel> vectorNPC = parser::extractNPCFromSequence(npcNode);
//
//    for(auto &s : vectorNPC){
//        cout << parser::npcSerialize(s) << endl;
//    }
    //}catch(...){
      //  cout << "can't find file" << endl;
    //}
//    if(npcNode){
//        cout << "found " << endl;
//    }else{
//        cout << "not found" << endl;
//    }
//    DoorModel door;
//    std::vector<std::string> keywords;
//    keywords.push_back("test1");
//    keywords.push_back("test2");
//    door.direction = Direction ::north;
//    door.keywords = keywords;
//    door.roomTo = 300;
//    door.description.push_back("DOOR 1 DESCRIPTION test1");
//    door.description.push_back("DOOR 1 DESCRIPTION test2");
//    //door.build(Direction::north, keywords, (id)1);
//    DoorModel door2;
//    std::vector<std::string> keywordz;
//    keywordz.push_back("testz1");
//    keywordz.push_back("testz2");
//    //door2.build(Direction::south, keywordz, (id)2);
//    door2.roomTo = 23;
//    door2.description.push_back("DESCRIPTION DOOR 2");
//    door2.direction = Direction::east;
//    door2.keywords = keywordz;
//    RoomModel test;
//    test.mainDescription.push_back("test main desc1");
//    test.mainDescription.push_back("test main desc2");
//    test.area = "test area";
//
//    test.id = 3;
//    test.name = "test name";
//    test.navigable = true;
//    test.doors.push_back(door);
//    test.doors.push_back(door2);
//    extendedDescription exTest;
//    exTest.keywords.push_back("ex test keywords");
//    exTest.description.push_back("ex test desc 1");
//    exTest.description.push_back("ex test desc 2");
//    test.extendedDescriptions.push_back(exTest);
//    test.npcList.push_back(102);
//    test.npcList.push_back(105);
//    test.playerList.push_back("bob");
//    test.playerList.push_back("joe");
//    test.itemList.push_back( 75);
//    test.itemList.push_back(129);
//
//    std::string testss = parser::roomSerialize(test);// << std::cout;
//    std::cout << testss << std::endl;
//    std::cout << "after testss" << endl;
//    RoomModel model = parser::roomDeserialize(testss);
//    std::cout << model.name << endl;
//    for(auto s: model.doors){
//        for(auto i : s.description){
//            std::cout << i << std::endl;
//        }
//        std::cout << parser::serializeDirection(s.direction) << s.roomTo << std::endl;
//        for(auto i: s.keywords){
//            std::cout << i << std::endl;
//        }
//    }
    return 0;
}

