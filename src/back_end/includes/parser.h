//
// Created by william on 13/10/16.
//Class for parsing and emitting YAML
//

#ifndef ADVENTURE2016_PARSER_H
#define ADVENTURE2016_PARSER_H
#include <yaml-cpp/yaml.h>
#include <string>
#include "../../model/include/player.h"

std::string const LOGIN_NAME_KEY = "LOGIN";
std::string const LOGIN_ID_KEY = "ID";

namespace parser{

    std::string playerSerialize(Player player);
    Player playerDeserialize(const std::string body);
}

#endif //ADVENTURE2016_PARSER_H
