
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
    out << YAML::BeginSeq;
    for(auto &s : room.extendedDescriptions){
        out << YAML::Key << ROOM_DESCRIPTION_KEY;
        for(auto &i : s.description){
            out << YAML::Value << i;
        }
        out << YAML::Key << DOOR_KEYWORDS_KEY;
        for(auto &i : s.keywords){
            out << YAML::Value << i;
        }
    }
    out << YAML::EndSeq;
    //out << YAML::Flow << room.extendedDescriptions;


    out << YAML::Key << ROOM_ID_KEY;
    out << YAML::Value << room.id;

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

std::string parser::doorSerialize(YAML::Emitter &out, DoorModel door) {
    out << YAML::BeginMap;
    out << YAML::Key << DOOR_DESCRIPTION_KEY;
    out << YAML::BeginSeq;
    for(auto desc : door.description){
        out << desc;
    }
    out << YAML::EndSeq;

    out << YAML::Key << DOOR_DIRECTION_KEY;
    out << YAML::Value << parser::serializeDirection(door.direction);
    out << YAML::Key << DOOR_KEYWORDS_KEY;
    out << YAML::BeginSeq;
    for(auto keyWords : door.keywords){
        out << YAML::Value << keyWords;
    }
    out << YAML::EndSeq;
    out << YAML::Key << DOOR_ROOMTO_KEY;
    out << YAML::Value << door.roomTo;
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

        DoorModel door = doorDeserialize(currentNode);
        model.doors.push_back(door);
    }
    model.name = roomNode[ROOM_NAME_KEY].as<std::string>();
    model.id = roomNode[ROOM_ID_KEY].as<int>();

    for(auto innerStruct: roomNode[ROOM_EX_DESCRIPTION_KEY]){
        extendedDescription ex_desc;
        for(auto desc : innerStruct[ROOM_DESCRIPTION_KEY]){
            ex_desc.description.push_back(desc.as<std::string>());
        }
        for(auto keyword : innerStruct[DOOR_KEYWORDS_KEY]){
            ex_desc.keywords.push_back(keyword.as<std::string>());
        }
        model.extendedDescriptions.push_back(ex_desc);
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
            model.itemList.push_back( innerString.as<int>() );
        }
    }
    if(roomNode[ROOM_NPCLIST_KEY]){
        for(auto innerString: roomNode[ROOM_NPCLIST_KEY]){
            model.npcList.push_back( innerString.as<int>() );
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

DoorModel parser::doorDeserialize(YAML::Node const doorNode) {
    DoorModel door;
    for(auto innerString : doorNode[DOOR_DESCRIPTION_KEY]){
        door.description.push_back(innerString.as<std::string>());
    }
    door.roomTo = doorNode[DOOR_ROOMTO_KEY].as<int>();
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
    std::cout << "before" << endl;
    int count = 0;
    for(auto s : roomNode){
        rooms.push_back(parser::roomDeserializeFromNode(s));
        std::cout << count++ << endl;
    }

    return rooms;
}

std::string parser::messageSerialize(MessageModel const &message) {
    YAML::Emitter out;
    out << YAML::BeginMap;
    out << YAML::Key << MESSAGE_TO;
    out << YAML::Value << message.To;
    out << YAML::Key << MESSAGE_FROM;
    out << YAML::Value << message.From;
    out << YAML::Key << MESSAGE_BODY;
    out << YAML::Value << message.Message;
    out << YAML::EndMap;

    return out.c_str();
}

MessageModel parser::messageDeserialize(const std::string &body) {
    YAML::Node node = YAML::Load(body);

    MessageModel message;
    message.To = node[MESSAGE_TO].as<string>();
    message.From = node[MESSAGE_FROM].as<string>();
    message.Message = node[MESSAGE_BODY].as<string>();

    return message;
}

YAML::Emitter& operator << (YAML::Emitter& out, const MessageModel &message) {
    out << YAML::BeginMap;
    out << YAML::Key << parser::MESSAGE_TO;
    out << YAML::Value << message.To;
    out << YAML::Key << parser::MESSAGE_FROM;
    out << YAML::Value << message.From;
    out << YAML::Key << parser::MESSAGE_BODY;
    out << YAML::Value << message.Message;
    out << YAML::EndMap;
    return out;
}

std::string parser::messageVectorSerialize(std::vector<MessageModel> const &messages){

    YAML::Emitter out;

    out << YAML::BeginSeq;
    for (auto message : messages) {
        out << message;
    }
    out << YAML::EndSeq;

    return out.c_str();
}

std::vector<MessageModel> parser::messageVectorDeserialize(std::string const &body) {

    std::vector<MessageModel> messageModels;

    // TODO: [mn]: Best way to do this is to set-up YAML::convert<> template.
    YAML::Node messages = YAML::Load(body);
    for (auto message : messages) {
        MessageModel temp;
        temp.To = message[MESSAGE_TO].as<string>();
        temp.From = message[MESSAGE_FROM].as<string>();
        temp.Message = message[MESSAGE_BODY].as<string>();
        messageModels.push_back(temp);
    }

    return messageModels;
}