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

    std::string const PLAYER_NAME_KEY = "loginName";
    std::string const PLAYER_ID_KEY = "playerId";
    std::string const PLAYER_COORDINATE_KEY = "roomId";
    std::string const PLAYER_HEALTH_KEY = "health";
    std::string playerSerialize(PlayerModel const player);
    PlayerModel playerDeserialize(std::string const body);


//    std::string area;
//    id roomId;
//    std::string name;
//    description mainDescription;
//    std::vector<description> extendedDescriptions;
//    std::vector<Door> doors;
//    std::vector<id> npcList;
//    std::vector<std::string> playerList;
//    std::vector<id> itemList;
//    bool navigable;

    std::string const ROOM_AREA_KEY = "area";
    std::string const ROOM_ID_KEY = "roomId";
    std::string const ROOM_DESCRIPTION_KEY = "mainDescription";
    std::string const ROOM_EX_DESCRIPTION_KEY = "extendedDescriptions";
    std::string const ROOM_DOOR_KEY = "doors";
    std::string const ROOM_NPCLIST_KEY = "npcList";
    std::string const ROOM_PLAYERLIST_KEY = "playerList";
    std::string const ROOM_ITEMLIST_KEY = "itemList";
    std::string const ROOM_NAVIGABLE_KEY = "navigable";
    std::string roomSerialize(RoomModel const room);
    RoomModel roomDeserialize(std::string const body);



};

#endif //ADVENTURE2016_PARSER_H
