
#include "parser.h"
#include <iostream>
#include <fstream>
#include <string>

std::string parser::itemSerialize(ItemModel const &item) {
    YAML::Emitter out;
    out << YAML::BeginMap;
    out << YAML::Key << ITEM_ATTRIBUTES_KEY;
    out << YAML::BeginSeq;
    for(auto e : item.attributes) {
        out << e;
    }
    out << YAML::EndSeq;
    out << YAML::Key << ITEM_COST_KEY;
    out << YAML::Value << item.cost;
    out << YAML::Key << ITEM_EXTRA_KEY;
    out << YAML::BeginSeq;
    for(auto &e : item.extra) {
        out << YAML::BeginMap;
        out << YAML::Key << ITEM_EX_DESCRIPTION_KEYWORDS_KEY;
        out << YAML::Value << e.description;

        out << YAML::Key << ITEM_EX_DESCRIPTION_KEYWORDS_KEY;
        out << YAML::Value << e.keywords;
        out << YAML::EndMap;
    }
    out << YAML::EndSeq;
    out << YAML::Key << ITEM_ID_KEY;
    out << YAML::Value << item.id;
    out << YAML::Key << ITEM_KEYWORDS_KEY;
    out << YAML::BeginSeq;
    for(auto &keyword : item.keywords) {
        out << keyword;
    }
    out << YAML::EndSeq;
    out << YAML::Key << ITEM_LONGDESC_KEY;
    out << YAML::Value << item.longDesc;
    out << YAML::Key << ITEM_SHORTDESC_KEY;
    out << YAML::Value << item.shortDesc;
    out << YAML::Key << ITEM_WEARFLAGS_KEY;
    out << YAML::Value << item.wearFlags;
    out << YAML::Key << ITEM_WEIGHT_KEY;
    out << YAML::Value << item.weight;
    out << YAML::Key << ITEM_ROOM_ID_KEY;
    out << YAML::Value << item.roomId;

    out << YAML::EndMap;

    return out.c_str();
}

ItemModel parser::itemDeserialize(std::string const &body) {
    YAML::Node itemNode = YAML::Load(body);

    return itemDeserializeFromNode(itemNode);
}

ItemModel parser::itemDeserializeFromNode(YAML::Node const &itemNode) {

    //TODO if itemNode[""].isDefined() ERROR CHECKING
    ItemModel item;
    if(itemNode[ITEM_ATTRIBUTES_KEY]){
        item.attributes = itemNode[ITEM_ATTRIBUTES_KEY].as<std::vector<std::string>>();
    }
    if(itemNode[ITEM_COST_KEY]){
        item.cost = itemNode[ITEM_COST_KEY].as<int>();
    }else{
        item.cost = 0;
    }
    if(itemNode[ITEM_EXTRA_KEY]){
        for(auto innerStruct: itemNode[ITEM_EXTRA_KEY]){
            extendedDescription ex_desc;
            for(auto desc : innerStruct[ITEM_EX_DESCRIPTION_DESC_KEY]){
                ex_desc.description.push_back(desc.as<std::string>());
            }

            for(auto keyword : innerStruct[ITEM_EX_DESCRIPTION_KEYWORDS_KEY]){
                ex_desc.keywords.push_back(keyword.as<std::string>());
            }
            item.extra.push_back(ex_desc);
        }
    }
    if(itemNode[ITEM_ID_KEY]){
        item.id = itemNode[ITEM_ID_KEY].as<int>();
    }else{
        item.id = -1; //invalid item id TODO fix
    }
    if(itemNode[ITEM_KEYWORDS_KEY]){
        item.keywords = itemNode[ITEM_KEYWORDS_KEY].as<std::vector<std::string>>();
    }
    if(itemNode[ITEM_LONGDESC_KEY]){
        item.longDesc = itemNode[ITEM_LONGDESC_KEY].as<std::vector<std::string>>();
    }
    if(itemNode[ITEM_SHORTDESC_KEY]){
        item.shortDesc = itemNode[ITEM_SHORTDESC_KEY].as<std::string>();
    }
    if(itemNode[ITEM_WEARFLAGS_KEY]){
        item.wearFlags = itemNode[ITEM_WEARFLAGS_KEY].as<std::vector<std::string>>();
    }
    if(itemNode[ITEM_WEIGHT_KEY]){
        item.weight = itemNode[ITEM_WEIGHT_KEY].as<int>();
    }
    if(itemNode[ITEM_ROOM_ID_KEY]){
        item.roomId = itemNode[ITEM_ROOM_ID_KEY].as<int>();
    }

    return item;
}

std::string parser::playerSerialize(PlayerModel const &player) {
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


    return out.c_str();
}

PlayerModel parser::playerDeserialize(std::string const &body) {

    YAML::Node playerNode = YAML::Load(body);

    //TODO if playerNode[""].isDefined() ERROR CHECKING
    PlayerModel player;
    player.loginName = playerNode[PLAYER_NAME_KEY].as<std::string>();
    player.playerId = playerNode[PLAYER_ID_KEY].as<int>();
    player.roomId = playerNode[PLAYER_COORDINATE_KEY].as<int>();
    player.health = playerNode[PLAYER_HEALTH_KEY].as<int>();
    return player;

}

std::string parser::roomSerialize(RoomModel const &room) {

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
        out << YAML::BeginMap;
        out << YAML::Key << ROOM_EX_DESCRIPTION_KEYWORDS_KEY;
        out << YAML::Value << s.description;

        out << YAML::Key << ROOM_EX_DESCRIPTION_KEYWORDS_KEY;
        out << YAML::Value << s.keywords;
        out << YAML::EndMap;
    }
    out << YAML::EndSeq;

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

std::string parser::doorSerialize(YAML::Emitter &out, DoorModel const &door) {
    out << YAML::BeginMap;
    out << YAML::Key << DOOR_DESCRIPTION_KEY;
    out << YAML::Value << door.description;

    out << YAML::Key << DOOR_DIRECTION_KEY;
    out << YAML::Value << parser::serializeDirection(door.direction);
    out << YAML::Key << DOOR_KEYWORDS_KEY;
    out << YAML::Value << door.keywords;

    out << YAML::Key << DOOR_ROOMTO_KEY;
    out << YAML::Value << door.roomTo;
    out << YAML::EndMap;

    return out.c_str();
}

RoomModel parser::roomDeserializeFromNode(YAML::Node const &roomNode) {
    //TODO error checking
    RoomModel model;

    model.mainDescription = roomNode[ROOM_DESCRIPTION_KEY].as<std::vector<std::string>>();


    for(auto currentNode: roomNode[ROOM_DOOR_KEY]){

        DoorModel door = doorDeserialize(currentNode);
        model.doors.push_back(door);
    }

    model.name = roomNode[ROOM_NAME_KEY].as<std::string>();
    model.id = roomNode[ROOM_ID_KEY].as<int>();

    for(auto innerStruct: roomNode[ROOM_EX_DESCRIPTION_KEY]){
        extendedDescription ex_desc;
        for(auto desc : innerStruct[ROOM_EX_DESCRIPTION_DESC_KEY]){
            ex_desc.description.push_back(desc.as<std::string>());
        }

        for(auto keyword : innerStruct[ROOM_EX_DESCRIPTION_KEYWORDS_KEY]){
            ex_desc.keywords.push_back(keyword.as<std::string>());
        }
        model.extendedDescriptions.push_back(ex_desc);
    }
    roomDeserializeAndAppendExtras(model, roomNode);

    return model;
}

void parser::roomDeserializeAndAppendExtras(RoomModel &model, YAML::Node const &roomNode){


    if(roomNode[ROOM_NAVIGABLE_KEY]){
        model.navigable = roomNode[ROOM_NAVIGABLE_KEY].as<bool>();
    }else{
        model.navigable = true; //TODO CHANGE DEFAULT BEHAVIOUR
    }
    if(roomNode[ROOM_AREA_KEY]){
        model.area = roomNode[ROOM_AREA_KEY].as<std::string>();
    }else{
        model.area = "no area";
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

RoomModel parser::roomDeserialize(std::string const &body) {
    YAML::Node roomNode = YAML::Load(body);
    return roomDeserializeFromNode(roomNode);
}

DoorModel parser::doorDeserialize(YAML::Node const &doorNode) {
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

std::string parser::serializeDirection(Direction const &directionEnum){
    switch (directionEnum) {
        case Direction::north:
            return NORTH;
        case Direction::east:
            return EAST;
        case Direction::west:
            return WEST;
        case Direction::south:
            return SOUTH;
        }//TODO error checking
}

Direction parser::deserializeDirection(std::string const &directionString) {

    if(directionString.compare(NORTH) == 0){
        return Direction::north;
    }else if(directionString.compare(EAST) == 0){
        return Direction::east;
    }else if(directionString.compare(WEST) == 0){
        return Direction::west;
    }else if(directionString.compare(SOUTH) == 0){
        return Direction::south;
    }//TODO error checking?
}

std::vector<RoomModel> parser::extractRoomsFromSequence(YAML::Node const &roomNode) {
    std::vector<RoomModel> rooms;
    //Has to be a copy for some reason (gives me an error otherwise)
    for(auto s : roomNode){
        rooms.push_back(parser::roomDeserializeFromNode(s));
    }
    return rooms;
}

std::vector<NpcModel> parser::extractNPCFromSequence(YAML::Node const &npcNode) {
    std::vector<NpcModel> npcs;
    for(auto s : npcNode){
        NpcModel npc = parser::npcDeserializeFromNode(s);
        npcs.push_back(npc);
    }
    return npcs;
}

std::vector<ItemModel> parser::extractItemsFromSequence(YAML::Node const &itemNode) {
    std::vector<ItemModel> items;
    int count = 0;
    for(auto s : itemNode){
        std::cout << count << std::endl;
        count++;
        items.push_back(parser::itemDeserializeFromNode(s));
    }

    return items;
}

NpcModel parser::npcDeserialize(std::string const &body) {

    YAML::Node npcNode = YAML::Load(body);

    return parser::npcDeserializeFromNode(npcNode);
}

NpcModel parser::npcDeserializeFromNode(YAML::Node const &npcNode) {

    NpcModel npc;
    //TODO if npcNode[""].isDefined() ERROR CHECKING
    npc.npcId = npcNode[NPC_ID_KEY].as<int>();
<<<<<<< 6b65f343eee9be8d0cdd91b062814a4ad9cd92d1
=======

    if(npcNode[NPC_ROOM_ID_KEY]){
        npc.roomId = npcNode[NPC_ROOM_ID_KEY].as<int>();
    }

>>>>>>> [sg] Missed one of the merge conflicts
    npc.mainDesc = npcNode[NPC_MAINDESC_KEY].as<std::vector<std::string>>();
    npc.keywords = npcNode[NPC_KEYWORDS_KEY].as<std::vector<std::string>>();
    npc.longDesc = npcNode[NPC_LONGDESC_KEY].as<std::vector<std::string>>();
    npc.shortDesc = npcNode[NPC_SHORTDESC_KEY].as<std::string>();

    npcDeserializeAndAppendOptionals(npc, npcNode);
    return npc;
}

void parser::npcDeserializeAndAppendOptionals(NpcModel &npc, YAML::Node const &npcNode){

    if(npcNode[NPC_DAMAGE_KEY]){
        npc.damage = npcNode[NPC_DAMAGE_KEY].as<std::string>();
    }else{
        npc.damage = "";
    }
    if(npcNode[NPC_ARMOR_KEY]){
        npc.armor = npcNode[NPC_ARMOR_KEY].as<int>();
    }else{
        npc.armor = 0;
    }
    if(npcNode[NPC_HIT_KEY]){
        npc.hit = npcNode[NPC_HIT_KEY].as<std::string>();
    }else{
        npc.hit = "";
    }
    if(npcNode[NPC_EXP_KEY]){
        npc.exp = npcNode[NPC_EXP_KEY].as<int>();
    }else{
        npc.exp = 0;
    }
    if(npcNode[NPC_GOLD_KEY]){
        npc.gold = npcNode[NPC_GOLD_KEY].as<int>();
    }else{
        npc.gold = 0;
    }
    if(npcNode[NPC_LEVEL_KEY]){
        npc.level = npcNode[NPC_LEVEL_KEY].as<int>();
    }else{
        npc.level = 0;
    }
    if(npcNode[NPC_THAC0_KEY]){
        npc.thac0 = npcNode[NPC_THAC0_KEY].as<int>();
    }else{
        npc.thac0 = 0;
    }

    if(npcNode[NPC_HEALTH_KEY]){
        npc.health = npcNode[NPC_HEALTH_KEY].as<int>();
    }else{
        npc.health = 100;

    if(npcNode[NPC_ROOM_ID_KEY]){
        npc.roomId = npcNode[NPC_ROOM_ID_KEY].as<int>();
    }
    else{
        npc.roomId = -1;
    }
}

std::string parser::npcSerialize(NpcModel const &npc) {

    YAML::Emitter out;
    out << YAML::BeginMap;
    out << YAML::Key << NPC_MAINDESC_KEY;
    out << YAML::Value << npc.mainDesc;

    out << YAML::Key << NPC_ID_KEY;
    out << YAML::Value << npc.npcId;

    out << YAML::Key << NPC_KEYWORDS_KEY;
    out << YAML::Value << npc.keywords;

    out << YAML::Key << NPC_LONGDESC_KEY;
    out << YAML::Value << npc.longDesc;

    out << YAML::Key << NPC_SHORTDESC_KEY;
    out << YAML::Value << npc.shortDesc;


    out << YAML::Key << NPC_DAMAGE_KEY;
    out << YAML::Value << npc.damage;
    out << YAML::Key << NPC_EXP_KEY;
    out << YAML::Value << npc.exp;
    out << YAML::Key << NPC_ARMOR_KEY;
    out << YAML::Value << npc.armor;
    out << YAML::Key << NPC_HIT_KEY;
    out << YAML::Value << npc.hit;
    out << YAML::Key << NPC_THAC0_KEY;
    out << YAML::Value << npc.thac0;
    out << YAML::Value << NPC_GOLD_KEY;
    out << YAML::Value << npc.gold;
    out << YAML::Key << NPC_LEVEL_KEY;
    out << YAML::Value << npc.level;
    out << YAML::Key << NPC_HEALTH_KEY;
    out << YAML::Value << npc.health;
    out << YAML::Key << NPC_ROOM_ID_KEY;
    out << YAML::Value << npc.roomId;

    out << YAML::EndMap;

    return out.c_str();
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
    out << YAML::Key << MESSAGE_TIMESTAMP;
    out << YAML::Value << message.Timestamp;
    out << YAML::EndMap;

    return out.c_str();
}

MessageModel parser::messageDeserialize(const std::string &body) {
    YAML::Node node = YAML::Load(body);

    MessageModel message;
    message.To = node[MESSAGE_TO].as<std::string>();
    message.From = node[MESSAGE_FROM].as<std::string>();
    message.Message = node[MESSAGE_BODY].as<std::string>();
//    message.Timestamp = node[MESSAGE_TIMESTAMP].as<long>();

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
    out << YAML::Key << parser::MESSAGE_TIMESTAMP;
    out << YAML::Value << message.Timestamp;
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
        temp.To = message[MESSAGE_TO].as<std::string>();
        temp.From = message[MESSAGE_FROM].as<std::string>();
        temp.Message = message[MESSAGE_BODY].as<std::string>();
        temp.Timestamp = message[MESSAGE_TIMESTAMP].as<long>();
        messageModels.push_back(temp);
    }

    return messageModels;
}

reset parser::resetDeserializeFromNode(YAML::Node const &resetNode){
    reset resetAction;
    resetAction.action = resetNode[RESET_ACTION].as<std::string>();
    resetAction.id = resetNode[RESET_ID].as<int>();
    if(resetNode[RESET_LIMIT]){
        resetAction.limit = resetNode[RESET_LIMIT].as<int>();
    }else{
        resetAction.limit = 1; //TODO what's the limit otherwise?
    }
    if(resetNode[RESET_ROOM]){
        resetAction.room = resetNode[RESET_ROOM].as<int>();
    }else{//some resets don't have room or limits
        //TODO behaviour uncertain,
    }
    return resetAction;
}

std::vector<reset> parser::extractResetsFromSequence(YAML::Node const &resetNode, std::string const &resetType) {
    std::vector<reset> resets;

    for(auto s : resetNode){

        reset currentReset = parser::resetDeserializeFromNode(s);
        if(currentReset.action.compare(resetType) == 0){
            resets.push_back(currentReset);
        }
    }

    return resets;
}