
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

    //TODO if playerNode[""].isDefined()
    PlayerModel player;
    player.loginName = playerNode[PLAYER_NAME_KEY].as<string>();
    player.playerId = playerNode[PLAYER_ID_KEY].as<int>();
    player.roomId = playerNode[PLAYER_COORDINATE_KEY].as<int>();
    player.health = playerNode[PLAYER_HEALTH_KEY].as<int>();
    return player;

}

std::string parser::roomSerialize(RoomModel const room) {

    //TODO ITEMLIST NPCLIST PLAYERLIST

    YAML::Emitter out;
    out << YAML::BeginMap;

    out << YAML::Key << ROOM_DESCRIPTION_KEY;
    out << YAML::Value << room.mainDescription;

    out << YAML::Key << ROOM_DOOR_KEY;
    out << YAML::BeginMap;
    for(auto& s : room.doors){
        //TODO DIRECTION DESC
        out << YAML::Key << "desc";
        out << YAML::Value << "dummy description";

        out << YAML::Key << "keywords";
        out << YAML::Flow << s.keywords;

        out << YAML::Key << "to";
        out << YAML::Value << s.doorId;
    }
    out << YAML::EndMap;

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


    return out.c_str();
}

RoomModel parser::roomDeserialize(std::string const body) {

    YAML::Node roomNode = YAML::Load(body);

}

