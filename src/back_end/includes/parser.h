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




namespace parser{

    char constexpr PLAYER_NAME_KEY[] = "loginName";
    char constexpr PLAYER_ID_KEY[] = "playerId";
    char constexpr PLAYER_COORDINATE_KEY[] = "roomId";
    char constexpr PLAYER_HEALTH_KEY[] = "health";
    std::string playerSerialize(PlayerModel const player);
    PlayerModel playerDeserialize(std::string const body);


    char constexpr ROOM_AREA_KEY[] = "area";
    char constexpr ROOM_ID_KEY[] = "roomId";
    char constexpr ROOM_DESCRIPTION_KEY[] = "mainDescription";
    char constexpr ROOM_EX_DESCRIPTION_KEY[] = "extendedDescriptions";
    char constexpr ROOM_DOOR_KEY[] = "doors";
    char constexpr ROOM_NPCLIST_KEY[] = "npcList";
    char constexpr ROOM_PLAYERLIST_KEY[] = "playerList";
    char constexpr ROOM_ITEMLIST_KEY[] = "itemList";
    char constexpr ROOM_NAVIGABLE_KEY[] = "navigable";

    char constexpr DOOR_DESCRIPTION_KEY[] = "descriptions";
    char constexpr DOOR_DIRECTION_KEY[] = "direction";
    char constexpr DOOR_KEYWORDS_KEY[] = "keywords";
    char constexpr DOOR_ID_KEY[] = "doorId";

    std::string roomSerialize(RoomModel const room);
    RoomModel roomDeserialize(std::string body);

    std::string serializeDirection(Direction const directionEnum);
    Direction deserializeDirection(std::string const directionString);

};

#endif //ADVENTURE2016_PARSER_H
