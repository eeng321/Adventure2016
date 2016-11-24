//
// Created by william on 11/11/16.
//

#ifndef ADVENTURE2016_YAMLKEYS_H
#define ADVENTURE2016_YAMLKEYS_H

namespace parser{

    //When adding new keys, make sure they match the yaml files given to us.
    char constexpr ITEM_ATTRIBUTES_KEY[] = "attributes";
    char constexpr ITEM_COST_KEY[] = "cost";
    char constexpr ITEM_EXTRA_KEY[] = "extra";
    char constexpr ITEM_ID_KEY[] = "id";
    char constexpr ITEM_ITEMTYPE_KEY[] = "item_type";
    char constexpr ITEM_KEYWORDS_KEY[] = "keywords";
    char constexpr ITEM_LONGDESC_KEY[] = "longdesc";
    char constexpr ITEM_SHORTDESC_KEY[] = "shortdesc";
    char constexpr ITEM_WEARFLAGS_KEY[] = "wear_Flags";
    char constexpr ITEM_WEIGHT_KEY[] = "weight";
    char constexpr ITEM_ROOM_ID_KEY[] = "roomId";

    char constexpr PLAYER_NAME_KEY[] = "loginName";
    char constexpr PLAYER_ID_KEY[] = "playerId";
    char constexpr PLAYER_COORDINATE_KEY[] = "roomId";
    char constexpr PLAYER_HEALTH_KEY[] = "health";

    char constexpr ROOM_AREA_KEY[] = "area";
    char constexpr ROOM_ID_KEY[] = "id";
    char constexpr ROOM_DESCRIPTION_KEY[] = "desc";
    char constexpr ROOM_EX_DESCRIPTION_KEY[] = "extended_descriptions";
    char constexpr ROOM_DOOR_KEY[] = "doors";
    char constexpr ROOM_NPCLIST_KEY[] = "npcList";
    char constexpr ROOM_PLAYERLIST_KEY[] = "playerList";
    char constexpr ROOM_ITEMLIST_KEY[] = "itemList";
    char constexpr ROOM_NAVIGABLE_KEY[] = "navigable";
    char constexpr ROOM_NAME_KEY[] = "name";
    char constexpr ROOM_EX_DESCRIPTION_DESC_KEY[] = "desc";
    char constexpr ROOM_EX_DESCRIPTION_KEYWORDS_KEY[] = "keywords";

    char constexpr DOOR_DESCRIPTION_KEY[] = "desc";
    char constexpr DOOR_DIRECTION_KEY[] = "dir";
    char constexpr DOOR_KEYWORDS_KEY[] = "keywords";
    char constexpr DOOR_ROOMTO_KEY[] = "to";

    char constexpr NPC_ID_KEY[] = "id";
    char constexpr NPC_MAINDESC_KEY[] = "description";
    char constexpr NPC_LONGDESC_KEY[] = "longdesc";
    char constexpr NPC_SHORTDESC_KEY[] = "shortdesc";
    char constexpr NPC_KEYWORDS_KEY[] = "keywords";
    char constexpr NPC_DAMAGE_KEY[] = "damage";
    char constexpr NPC_ARMOR_KEY[] = "armor";
    char constexpr NPC_HIT_KEY[] = "hit";
    char constexpr NPC_EXP_KEY[] = "exp";
    char constexpr NPC_GOLD_KEY[] = "gold";
    char constexpr NPC_LEVEL_KEY[] = "level";
    char constexpr NPC_THAC0_KEY[] = "thac0";
    char constexpr NPC_ROOM_ID_KEY[] = "roomId";

    char constexpr MESSAGE_TO[] = "to";
    char constexpr MESSAGE_FROM[] = "from";
    char constexpr MESSAGE_BODY[] = "message";

    char constexpr NORTH[] = "north";
    char constexpr EAST[] = "east";
    char constexpr SOUTH[] = "south";
    char constexpr WEST[] = "west";

    char constexpr RESET_ACTION[] = "action";
    char constexpr RESET_ID[] = "id";
    char constexpr RESET_LIMIT[] = "limit";
    char constexpr RESET_ROOM[] = "room";
}

#endif //ADVENTURE2016_YAMLKEYS_H
