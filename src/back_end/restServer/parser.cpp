
#include "parser.h"
#include <iostream>
#include <fstream>

using namespace std;
using namespace parser;


YAML::Node parser::serializeLogin(const std::string username, const std::string password){

    YAML::Node node = YAML::LoadFile("yaml.yaml");
    std::cout << node["USERNAME"];
    //node["PASSWORD"] = password;
    return node;
}

void parser::deserializeLogin(std::string &username, std::string &password, const YAML::Node node){
    
    username = node["USERNAME"].as<string>();
    password = node["PASSWORD"].as<string>();
}


