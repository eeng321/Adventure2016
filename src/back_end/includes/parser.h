//
// Created by william on 13/10/16.
//Class for parsing and emitting YAML
//

#ifndef ADVENTURE2016_PARSER_H
#define ADVENTURE2016_PARSER_H
#include "yaml-cpp/yaml.h"
#include <string>
namespace parser{

    YAML::Node serializeLogin(const std::string username, const std::string password);
    void deserializeLogin(std::string &username, std::string &password, YAML::Node &node);
}

#endif //ADVENTURE2016_PARSER_H
