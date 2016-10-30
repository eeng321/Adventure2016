
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
    out << YAML::BeginMap;

    out << YAML::Key << ROOM_DESCRIPTION_KEY;
    out << YAML::BeginSeq;
    int size = 0;
    for(auto &s : room.mainDescription){
        out << YAML::Value << s;
        cout << size++;
    }
    out<< YAML::EndSeq;

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
    out << YAML::EndSeq;

    out << YAML::Key << ROOM_AREA_KEY;
    out << YAML::Value << room.area;

    out << YAML::Key << ROOM_NAME_KEY;
    out << YAML::Value << room.name;

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

RoomModel parser::roomDeserialize(std::string body) {
    //TODO error checking
    YAML::Node roomNode = YAML::Load(body);
    RoomModel model;

    for(auto innerString : roomNode[ROOM_DESCRIPTION_KEY]){
        model.mainDescription.push_back(innerString.as<std::string>());
    }

    for(auto currentNode: roomNode[ROOM_DOOR_KEY]){
        Door door;
        for(auto innerString : currentNode[DOOR_DESCRIPTION_KEY]){
            door.description.push_back(innerString.as<std::string>());
            std::cout << innerString.as<std::string>() << endl;
        }
        door.doorId = (id)currentNode[DOOR_ID_KEY].as<int>();
        Direction dir = deserializeDirection(currentNode[DOOR_DIRECTION_KEY].as<std::string>());
        door.direction = dir;
        for(auto innerString: currentNode[DOOR_KEYWORDS_KEY]){
            door.keywords.push_back(innerString.as<std::string>());
        }
        model.doors.push_back(door);
    }

    model.area = roomNode[ROOM_AREA_KEY].as<std::string>();

    model.name = roomNode[ROOM_NAME_KEY].as<std::string>();

    for(auto innerString: roomNode[ROOM_EX_DESCRIPTION_KEY]){
        model.extendedDescriptions.push_back(innerString.as<std::string>());
    }

    model.roomId = (id)roomNode[ROOM_ID_KEY].as<int>();

    model.navigable = roomNode[ROOM_NAVIGABLE_KEY].as<bool>();

    for(auto innerString: roomNode[ROOM_ITEMLIST_KEY]){
        model.itemList.push_back( (id)innerString.as<int>() );
    }

    for(auto innerString: roomNode[ROOM_NPCLIST_KEY]){
        model.npcList.push_back( (id)innerString.as<int>() );
    }

    for(auto innerString: roomNode[ROOM_PLAYERLIST_KEY]){
        model.playerList.push_back(innerString.as<std::string>());
    }

    return model;

}

std::string parser::doorSerialize(Door door) {

}


Door parser::doorDeserialize(YAML::Emitter &out, YAML::Node const doorNode) {

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

