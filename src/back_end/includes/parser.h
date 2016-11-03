//
// Created by william on 13/10/16.
//Class for parsing and emitting YAML
//

#ifndef ADVENTURE2016_PARSER_H
#define ADVENTURE2016_PARSER_H

#include <yaml-cpp/yaml.h>
#include <string>
#include "../../model/include/playerModel.h"
#include "../../model/include/messageModel.h"


std::string const PLAYER_NAME_KEY = "LOGIN";
std::string const PLAYER_ID_KEY = "ID";
std::string const PLAYER_COORDINATE_KEY = "COORDINATE";
std::string const PLAYER_HEALTH_KEY = "HEALTH";

std::string const MESSAGE_TO = "TO";
std::string const MESSAGE_FROM = "FROM";
std::string const MESSAGE_BODY = "MESSAGE";

namespace parser {

    std::string playerSerialize(PlayerModel player);
    PlayerModel playerDeserialize(const std::string body);

    std::string messageSerialize(MessageModel message);
    MessageModel messageDeserialize(const std::string& body);

    std::string messageVectorSerialize(std::vector<MessageModel> message);
    std::vector<MessageModel> messageVectorDeserialize(const std::string& body);
};

#endif //ADVENTURE2016_PARSER_H
