//
// Created by william on 19/10/16.
//
#include <iostream>
#include "parser.h"
#include "../../model/include/room.h"

int main(){

    Door door;
    std::vector<std::string> keywords;
    keywords.push_back("test1");
    keywords.push_back("test2");
    door.direction = Direction ::north;
    door.keywords = keywords;
    door.doorId = (id)1;
    //door.build(Direction::north, keywords, (id)1);
    Door door2;
    std::vector<std::string> keywordz;
    keywordz.push_back("testz1");
    keywordz.push_back("testz2");
    //door2.build(Direction::south, keywordz, (id)2);
    door2.doorId = (id)2;
    door2.direction = Direction::east;
    door2.keywords = keywordz;
    RoomModel test;
    test.mainDescription = "test main desc";
    test.area = "test area";
    test.roomId = (id)1;
    test.name = "test name";
    test.navigable = true;
    test.doors.push_back(door);
    test.doors.push_back(door2);
    test.extendedDescriptions.push_back("ex desc 1");
    test.extendedDescriptions.push_back("ex desc 2");
    test.npcList.push_back((id)102);
    test.npcList.push_back((id)105);
    test.playerList.push_back("bob");
    test.playerList.push_back("joe");
    test.itemList.push_back((id) 75);
    test.itemList.push_back((id) 129);

    //parser::roomSerialize(test);
    std::string testss = parser::roomSerialize(test);// << std::cout;
    std::cout << testss << std::endl;

    YAML::Node nodeTest = YAML::Load(testss);
    std::string bob = nodeTest["playerList"][0].as<std::string>();
    std::cout << bob <<std::endl ;

    return 0;
}

