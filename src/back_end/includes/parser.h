//
// Created by william on 13/10/16.
//Class for parsing and emitting YAML
//

#ifndef ADVENTURE2016_PARSER_H
#define ADVENTURE2016_PARSER_H

#include <yaml-cpp/yaml.h>
#include <string>
#include "../../model/include/playerModel.h"
#include "../../model/include/roomModel.h"
#include "../../model/include/door.h"
#include "../../model/include/messageModel.h"

namespace parser {
    //Do not change any of these unless required. Must match the yaml files given, NOT CLASS FIELD NAMES
    char constexpr PLAYER_NAME_KEY[] = "loginName";
    char constexpr PLAYER_ID_KEY[] = "playerId";
    char constexpr PLAYER_COORDINATE_KEY[] = "roomId";
    char constexpr PLAYER_HEALTH_KEY[] = "health";

    char constexpr ROOM_AREA_KEY[] = "area";
    char constexpr ROOM_ID_KEY[] = "id";
    char constexpr ROOM_DESCRIPTION_KEY[] = "desc";
    char constexpr ROOM_EX_DESCRIPTION_KEY[] = "extended_descriptions";
    char constexpr ROOM_DOOR_KEY[] = "doors";
    char constexpr ROOM_NPCLIST_KEY[] = "npcList";
    char constexpr ROOM_PLAYERLIST_KEY[] = "playerList";
    char constexpr ROOM_ITEMLIST_KEY[] = "itemList";
    char constexpr ROOM_NAVIGABLE_KEY[] = "navigable";
    char constexpr ROOM_NAME_KEY[] = "name";

    char constexpr DOOR_DESCRIPTION_KEY[] = "desc";
    char constexpr DOOR_DIRECTION_KEY[] = "dir";
    char constexpr DOOR_KEYWORDS_KEY[] = "keywords";
    char constexpr DOOR_ROOMTO_KEY[] = "to";

    char constexpr MESSAGE_TO[] = "to";
    char constexpr MESSAGE_FROM[] = "from";
    char constexpr MESSAGE_BODY[] = "message";

    std::string playerSerialize(PlayerModel const player);
    PlayerModel playerDeserialize(std::string const body);

    std::string roomSerialize(RoomModel const room);
    RoomModel roomDeserialize(std::string const body);
    RoomModel roomDeserializeFromNode(YAML::Node roomNode);
    void roomDeserializeAndAppendExtras(RoomModel &model, YAML::Node const roomNode);

    std::string doorSerialize(YAML::Emitter &out, DoorModel door);
    DoorModel doorDeserialize(YAML::Node const doorNode);

    std::string serializeDirection(Direction const directionEnum);
    Direction deserializeDirection(std::string const directionString);

    std::vector<RoomModel> extractRoomsFromSequence(YAML::Node const roomNode);

    std::string messageSerialize(MessageModel const &message);
    MessageModel messageDeserialize(std::string const &body);

    std::string messageVectorSerialize(std::vector<MessageModel> const &message);
    std::vector<MessageModel> messageVectorDeserialize(std::string const &body);

};

#endif //ADVENTURE2016_PARSER_H
