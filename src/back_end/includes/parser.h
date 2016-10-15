//
// Created by william on 13/10/16.
//Class for parsing and emitting YAML
//

#ifndef ADVENTURE2016_PARSER_H
#define ADVENTURE2016_PARSER_H
#include <yaml-cpp/yaml.h>
#include <string>
namespace parser{

    std::string serializeLogin(std::string &body);
    std::string deserializeLogin(std::string &body);
}

#endif //ADVENTURE2016_PARSER_H
