//
// Created by william on 19/10/16.
// TEST FILE FOR BACKEND, JUST MODIFY THE CMAKELIST.TXT
//
#include <iostream>
#include "parser.h"
#include "../../model/include/room.h"
#include <typeinfo>


using namespace std;
int main(){

    Door door;
//    std::vector<std::string> keywords;
//    keywords.push_back("test1");
//    keywords.push_back("test2");
    door.direction = Direction ::north;
//    door.keywords = keywords;
    door.doorId = (id)300;
    door.description.push_back("DOOR 1 DESCRIPTION test1");
    door.description.push_back("DOOR 1 DESCRIPTION test2");
    //door.build(Direction::north, keywords, (id)1);
    Door door2;
    std::vector<std::string> keywordz;
    keywordz.push_back("testz1");
    keywordz.push_back("testz2");
    //door2.build(Direction::south, keywordz, (id)2);
    door2.doorId = (id)200;
    door2.description.push_back("DESCRIPTION DOOR 2");
    door2.direction = Direction::east;
    door2.keywords = keywordz;
    RoomModel test;
    test.mainDescription.push_back("test main desc1");
    test.mainDescription.push_back("test main desc2");
//    test.area = "test area";
    test.roomId = (id)3;
    test.name = "test name";
//    test.navigable = true;
    test.doors.push_back(door);
    test.doors.push_back(door2);
//    test.extendedDescriptions.push_back("ex desc 2");
//    test.npcList.push_back((id)102);
//    test.npcList.push_back((id)105);
//    test.playerList.push_back("bob");
//    test.playerList.push_back("joe");
//    test.itemList.push_back((id) 75);
//    test.itemList.push_back((id) 129);

//    YAML::Node testNode = YAML::LoadFile("/home/william/cmpt373/adventure2016/test.yaml");
//    YAML::Node roomsNode = testNode["ROOMS"];
//    if(roomsNode){
//        cout << "found rooms node" << endl;
//    }else{
//        cout << "did not find" << endl;
//    }
//    std::vector<RoomModel> rooms = parser::extractRoomsFromSequence(roomsNode);
//    cout << "extracted" << endl;
//    std::vector<RoomModel> rooms2;
//    for(auto s : rooms){
//        std::string test = parser::roomSerialize(s);
//        std::cout << test << endl;
//        rooms2.push_back(parser::roomDeserialize(test));
//    }

////    std::cout << testNode.as<std::string>();
//
    std::string testss = parser::roomSerialize(test);// << std::cout;
    std::cout << testss << std::endl;
//    std::cout << "after testss" << endl;
//    RoomModel model = parser::roomDeserialize(testss);
//    std::cout << model.name << endl;
//    for(auto s: model.doors){
//        for(auto i : s.description){
//            std::cout << i << std::endl;
//        }
//        std::cout << parser::serializeDirection(s.direction) << s.doorId << std::endl;
//        for(auto i: s.keywords){
//            std::cout << i << std::endl;
//        }
//    }
    return 0;
}

