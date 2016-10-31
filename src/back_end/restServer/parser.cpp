
#include "parser.h"
#include <iostream>
#include <fstream>
using namespace std;

std::string parser::playerSerialize(PlayerModel player) {

    YAML::Emitter out;
    out << YAML::BeginMap;
    out << YAML::Key << PLAYER_NAME_KEY;
    out << YAML::Value << player.loginName;
    out << YAML::Key << PLAYER_ID_KEY;
    out << YAML::Value << player.playerId;
    out << YAML::Key << PLAYER_COORDINATE_KEY;
    out << YAML::Value << player.roomId;
    out << YAML::Key << PLAYER_HEALTH_KEY;
    out << YAML::Value << player.health;
    out << YAML::EndMap;

    std::cout << "YAML representation of player:\n " << out.c_str() << endl;

    return out.c_str();
}

PlayerModel parser::playerDeserialize(const std::string body) {

    if(body.empty()) {
        std::cout << "Request is empty. Error." << endl;
        exit(1);
    }
    std::cout << body << std::endl;
    YAML::Node node = YAML::Load(body);

    PlayerModel player;
    player.loginName = node[PLAYER_NAME_KEY].as<string>();
    player.playerId = node[PLAYER_ID_KEY].as<int>();
    player.roomId = node[PLAYER_COORDINATE_KEY].as<int>();
    player.health = node[PLAYER_HEALTH_KEY].as<int>();
    return player;

}

std::string parser::modelSerialize(MessageModel message) {
    YAML::Emitter out;
    out << YAML::BeginMap;
    out << YAML::Key << MESSAGE_TO;
    out << YAML::Value << message.To;
    out << YAML::Key << MESSAGE_FROM;
    out << YAML::Value << message.From;
    out << YAML::Key << MESSAGE_BODY;
    out << YAML::Value << message.Message;
    out << YAML::EndMap;

    return out.c_str();
}
MessageModel parser::messageDeserialize(const std::string body) {
    YAML::Node node = YAML::Load(body);

    MessageModel message;
    message.To = node[MESSAGE_TO].as<string>();
    message.From = node[MESSAGE_FROM].as<string>();
    message.Message = node[MESSAGE_BODY].as<string>();

    return message;
}
