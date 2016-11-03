
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

std::string parser::messageSerialize(MessageModel message) {
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

MessageModel parser::messageDeserialize(const std::string& body) {
    YAML::Node node = YAML::Load(body);

    MessageModel message;
    message.To = node[MESSAGE_TO].as<string>();
    message.From = node[MESSAGE_FROM].as<string>();
    message.Message = node[MESSAGE_BODY].as<string>();

    return message;
}

YAML::Emitter& operator << (YAML::Emitter& out, const MessageModel& message) {
    out << YAML::BeginMap;
    out << YAML::Key << MESSAGE_TO;
    out << YAML::Value << message.To;
    out << YAML::Key << MESSAGE_FROM;
    out << YAML::Value << message.From;
    out << YAML::Key << MESSAGE_BODY;
    out << YAML::Value << message.Message;
    out << YAML::EndMap;
    return out;
}

std::string parser::messageVectorSerialize(std::vector<MessageModel> messages){

    YAML::Emitter out;

    out << YAML::BeginSeq;
    for (auto message : messages) {
        out << message;
    }
    out << YAML::EndSeq;

    return out.c_str();
}

std::vector<MessageModel> parser::messageVectorDeserialize(const std::string& body) {

    std::vector<MessageModel> messageModels;

    // TODO: [mn]: Best way to do this is to set-up YAML::convert<> template.
    YAML::Node messages = YAML::Load(body);
    for (auto message : messages) {
        MessageModel temp;
        temp.To = message[MESSAGE_TO].as<string>();
        temp.From = message[MESSAGE_FROM].as<string>();
        temp.Message = message[MESSAGE_BODY].as<string>();
        messageModels.push_back(temp);
    }

    return messageModels;
}
