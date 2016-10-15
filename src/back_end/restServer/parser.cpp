
#include "parser.h"
#include <iostream>
#include <fstream>

using namespace std;

std::string parser::playerSerialize(Player player){

    YAML::Emitter out;
    out << YAML::BeginMap;
    out << YAML::Key << LOGIN_NAME_KEY;
    out << YAML::Value << player.loginName;
    out << YAML::Key << LOGIN_ID_KEY;
    out << YAML::Value << player.playerId;
    out << YAML::EndMap;

    std::cout << "YAML representation of player:\n " << out.c_str() << endl;

    return out.c_str();
}

Player parser::playerDeserialize(const std::string body){

    if(body.empty()){
        std::cout << "Request is empty. Error." << endl;
        exit(1);
    }
    std::cout << body << std::endl;
    YAML::Node node = YAML::Load(body);

    Player player;
    player.loginName = node[LOGIN_NAME_KEY].as<string>();
    player.playerId = node[LOGIN_ID_KEY].as<int>();

    return player;

}


