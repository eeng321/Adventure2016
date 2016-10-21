
#include "parser.h"
#include <iostream>
#include <fstream>
using namespace std;

std::string parser::playerSerialize(PlayerModel const player) {

    YAML::Emitter out;
    out << YAML::BeginMap;
    out << YAML::Key << PLAYER_NAME_KEY;
    out << YAML::Value << player.loginName;
    out << YAML::Key << PLAYER_ID_KEY;
    out << YAML::Value << player.playerId;
    out << YAML::Key << PLAYER_COORDINATE_KEY;
    out << YAML::Value << player.roomId;
    out << YAML::Key << PLAYER_HEALTH_KEY;
    out << YAML::Value << player.health;
    out << YAML::EndMap;

    std::cout << "YAML representation of player:\n " << out.c_str() << endl;

    return out.c_str();
}

PlayerModel parser::playerDeserialize(std::string const body) {

    YAML::Node playerNode = YAML::Load(body);

    //TODO if playerNode[""].isDefined() ERROR CHECKING
    PlayerModel player;
    player.loginName = playerNode[PLAYER_NAME_KEY].as<string>();
    player.playerId = playerNode[PLAYER_ID_KEY].as<int>();
    player.roomId = playerNode[PLAYER_COORDINATE_KEY].as<int>();
    player.health = playerNode[PLAYER_HEALTH_KEY].as<int>();
    return player;

}

std::string parser::roomSerialize(RoomModel const room) {

    //TODO Error Checking

    YAML::Emitter out;
    //out << YAML::BeginSeq;
    out << YAML::BeginMap;

    out << YAML::Key << ROOM_DESCRIPTION_KEY;
    out << YAML::Value << room.mainDescription;

    out << YAML::Key << ROOM_DOOR_KEY;
    out << YAML::BeginSeq;
    for(auto& s : room.doors){
        out << YAML::BeginMap;
        out << YAML::Key << DOOR_DESCRIPTION_KEY;
        out << YAML::Value << s.description;

        out << YAML::Key << DOOR_DIRECTION_KEY;
        out << YAML::Value << parser::serializeDirection(s.direction);

        out << YAML::Key << DOOR_KEYWORDS_KEY;
        out << YAML::Flow << s.keywords;

        out << YAML::Key << DOOR_ID_KEY;
        out << YAML::Value << s.doorId;
        out << YAML::EndMap;
    }
    out <<YAML::EndSeq;
    YAML::EndMap;
    YAML::BeginMap;
    out << YAML::Key << ROOM_AREA_KEY;
    out << YAML::Value << room.area;

    out << YAML::Key << ROOM_EX_DESCRIPTION_KEY;
    out << YAML::Flow << room.extendedDescriptions;


    out << YAML::Key << ROOM_ID_KEY;
    out << YAML::Value << room.roomId;

    out << YAML::Key << ROOM_NAVIGABLE_KEY;
    out << YAML::Value << room.navigable;

    out << YAML::Key << ROOM_ITEMLIST_KEY;
    out << YAML::Flow << room.itemList;

    out << YAML::Key << ROOM_NPCLIST_KEY;
    out << YAML::Flow << room.npcList;

    out << YAML::Key << ROOM_PLAYERLIST_KEY;
    out << YAML::Flow << room.playerList;

    out << YAML::EndMap;
    //out << YAML::EndSeq;

    return out.c_str();
}

RoomModel parser::roomDeserialize(std::string const body) {

    YAML::Node roomNode = YAML::Load(body);

    RoomModel model;
    model.mainDescription = roomNode[ROOM_DESCRIPTION_KEY].as<string>();

    YAML::Node doorNode = roomNode[ROOM_DOOR_KEY];
    for(auto s: doorNode){
        Door door;
        door.description = s[DOOR_DESCRIPTION_KEY].as<std::string>();
        std::cout << door.description;
        door.direction = parser::deserializeDirection(s[DOOR_DIRECTION_KEY].as<string>());
    }

    model.area = roomNode[ROOM_AREA_KEY].as<std::string>();


}

std::string parser::serializeDirection(Direction const directionEnum){
    switch (directionEnum) {
        case Direction::north:
            return "north";
        case Direction::east:
            return "east";
        case Direction::west:
            return "west";
        case Direction::south:
            return "south";
        }//TODO error checking
}

Direction parser::deserializeDirection(std::string const directionString) {

    if(directionString.compare("north") == 0){
        return Direction::north;
    }else if(directionString.compare("east") == 0){
        return Direction::east;
    }else if(directionString.compare("west") == 0){
        return Direction::west;
    }else if(directionString.compare("south") == 0){
        return Direction::south;
    }//TODO error checking?
}

