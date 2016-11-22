//
// Created by william on 13/10/16.
//Class for parsing and emitting YAML
//

#ifndef ADVENTURE2016_PARSER_H
#define ADVENTURE2016_PARSER_H

#include <yaml-cpp/yaml.h>
#include <string>
#include "../../model/include/playerModel.h"
#include "../../model/include/roomModel.h"
#include "../../model/include/messageModel.h"
#include "../../model/include/itemModel.h"
#include "../../model/include/npcModel.h"
#include "../../model/include/door.h"
#include "resetStruct.h"
#include "yamlKeys.h"

namespace parser{

    //Do not change any of these unless required. Must match the yaml files given, NOT CLASS FIELD NAMES

    std::string itemSerialize(ItemModel const &item);
    ItemModel itemDeserialize(std::string const &body);
    ItemModel itemDeserializeFromNode(YAML::Node const &itemNode);

    std::string playerSerialize(PlayerModel const &player);
    PlayerModel playerDeserialize(std::string const &body);

    std::string roomSerialize(RoomModel const &room);
    RoomModel roomDeserialize(std::string const &body);
    RoomModel roomDeserializeFromNode(YAML::Node const &roomNode);
    void roomDeserializeAndAppendExtras(RoomModel &model, YAML::Node const &roomNode);

    std::string doorSerialize(YAML::Emitter &out, DoorModel const &door);
    DoorModel doorDeserialize(YAML::Node const &doorNode);

    std::string serializeDirection(Direction const &directionEnum);
    Direction deserializeDirection(std::string const &directionString);

    NpcModel npcDeserialize(std::string const &body);
    NpcModel npcDeserializeFromNode(YAML::Node const &npcNode);
    void npcDeserializeAndAppendOptionals(NpcModel &npc, YAML::Node const &npcNode);
    std::string npcSerialize(NpcModel const &npc);

    std::string messageSerialize(MessageModel const &message);
    MessageModel messageDeserialize(std::string const &body);

    std::string messageVectorSerialize(std::vector<MessageModel> const &message);
    std::vector<MessageModel> messageVectorDeserialize(std::string const &body);

    std::vector<RoomModel> extractRoomsFromSequence(YAML::Node const &roomNode);
    std::vector<NpcModel> extractNPCFromSequence(YAML::Node const &npcNode);
    std::vector<ItemModel> extractItemsFromSequence(YAML::Node const &itemNode);

    reset deserializeReset(YAML::Node const &resetNode);//Only supporting objects and npcs

};

#endif //ADVENTURE2016_PARSER_H