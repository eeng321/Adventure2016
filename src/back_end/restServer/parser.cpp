
#include "parser.h"
#include <iostream>
#include <fstream>

using namespace std;
using namespace parser;


YAML::Node parser::serializeLogin(const std::string username, const std::string password){

    YAML::Node node;
    node["USERNAME"] = username;
    node["PASSWORD"] = password;
    return node;


}

void parser::deserializeLogin(std::string &username, std::string &password, YAML::Node node){
    username = node["USERNAME"].as<string>();
    password = node["PASSWORD"].as<string>();
}


