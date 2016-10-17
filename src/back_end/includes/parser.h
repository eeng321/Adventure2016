//
// Created by william on 13/10/16.
//Class for parsing and emitting YAML
//

#ifndef ADVENTURE2016_PARSER_H
#define ADVENTURE2016_PARSER_H

#include <yaml-cpp/yaml.h>
#include <string>
#include "../../model/include/playerModel.h"

std::string const PLAYER_NAME_KEY = "LOGIN";
std::string const PLAYER_ID_KEY = "ID";
std::string const PLAYER_COORDINATE_KEY = "COORDINATE";
std::string const PLAYER_HEALTH_KEY = "HEALTH";


namespace parser{

   std::string playerSerialize(PlayerModel player);
   PlayerModel playerDeserialize(const std::string body);
   
};

#endif //ADVENTURE2016_PARSER_H
