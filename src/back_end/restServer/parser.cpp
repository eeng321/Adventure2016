
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
    for(auto &s : room.mainDescription){
        out << YAML::Value << s;
    }
    out<< YAML::EndSeq;

    out << YAML::Key << ROOM_DOOR_KEY;
    out << YAML::BeginSeq;
    for(auto& s : room.doors){
        doorSerialize(out, s);
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
    out << YAML::Flow << room.itemList;//TODO Critical Extended Descriptions must be rewritten

    out << YAML::Key << ROOM_NPCLIST_KEY;
    out << YAML::Flow << room.npcList;

    out << YAML::Key << ROOM_PLAYERLIST_KEY;
    out << YAML::Flow << room.playerList;

    out << YAML::EndMap;

    return out.c_str();
}

std::string parser::doorSerialize(YAML::Emitter &out, Door door) {
    out << YAML::BeginMap;
    out << YAML::Key << DOOR_DESCRIPTION_KEY;
    out << YAML::Value << door.description;

    out << YAML::Key << DOOR_DIRECTION_KEY;
    out << YAML::Value << parser::serializeDirection(door.direction);
    out << YAML::Key << DOOR_KEYWORDS_KEY;
    out << YAML::BeginSeq;
    for(auto keyWords : door.keywords){
        out << keyWords;
    }
    out << YAML::EndSeq;
    out << YAML::Key << DOOR_ID_KEY;
    out << YAML::Value << door.doorId;
    out << YAML::EndMap;

    return out.c_str();
}



RoomModel parser::roomDeserializeFromNode(YAML::Node roomNode) {
    //TODO error checking
    RoomModel model;

    for(auto innerString : roomNode[ROOM_DESCRIPTION_KEY]){
        model.mainDescription.push_back(innerString.as<std::string>());
    }

    for(auto currentNode: roomNode[ROOM_DOOR_KEY]){
        Door door = doorDeserialize(currentNode);
        model.doors.push_back(door);
    }
    model.name = roomNode[ROOM_NAME_KEY].as<std::string>();
    model.roomId = (id)roomNode[ROOM_ID_KEY].as<int>();
    for(auto innerString: roomNode[ROOM_EX_DESCRIPTION_KEY]){
        model.extendedDescriptions.push_back(innerString.as<std::string>());
    }

    roomDeserializeAndAppendExtras(model, roomNode);


    return model;
}

void parser::roomDeserializeAndAppendExtras(RoomModel &model, YAML::Node const roomNode){


    if(roomNode[ROOM_NAVIGABLE_KEY]){
        model.navigable = roomNode[ROOM_NAVIGABLE_KEY].as<bool>();
    }
    if(roomNode[ROOM_AREA_KEY]){
        model.area = roomNode[ROOM_AREA_KEY].as<std::string>();
    }
    if(roomNode[ROOM_ITEMLIST_KEY]){
        for(auto innerString: roomNode[ROOM_ITEMLIST_KEY]){
            model.itemList.push_back( (id)innerString.as<int>() );
        }
    }
    if(roomNode[ROOM_NPCLIST_KEY]){
        for(auto innerString: roomNode[ROOM_NPCLIST_KEY]){
            model.npcList.push_back( (id)innerString.as<int>() );
        }
    }
    if(roomNode[ROOM_PLAYERLIST_KEY]){
        for(auto innerString: roomNode[ROOM_PLAYERLIST_KEY]){
            model.playerList.push_back(innerString.as<std::string>());
        }
    }
}

RoomModel parser::roomDeserialize(std::string const body) {
    YAML::Node roomNode = YAML::Load(body);
    return roomDeserializeFromNode(roomNode);
}

Door parser::doorDeserialize(YAML::Node const doorNode) {
    Door door;
    for(auto innerString : doorNode[DOOR_DESCRIPTION_KEY]){
        door.description.push_back(innerString.as<std::string>());
    }
    door.doorId = (id)doorNode[DOOR_ID_KEY].as<int>();
    Direction dir = deserializeDirection(doorNode[DOOR_DIRECTION_KEY].as<std::string>());
    door.direction = dir;
    for(auto innerString: doorNode[DOOR_KEYWORDS_KEY]){
        door.keywords.push_back(innerString.as<std::string>());
    }

    return door;
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

std::vector<RoomModel> parser::extractRoomsFromSequence(YAML::Node const roomNode) {
    std::vector<RoomModel> rooms;
    for(auto s : roomNode){
        rooms.push_back(parser::roomDeserializeFromNode(s));
        std::cout << "test" << endl;
    }

    return rooms;
}