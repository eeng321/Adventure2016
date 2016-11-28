//
// Created by jmedwid on 11/4/16.
//
#include "../../../back_end/includes/parser.h"
#include "../../../model/include/messageModel.h"
#include "Command.h"
#include "Combat.h"
#include "Controller.h"
#include "display.h"
#include "GameState.h"
#include "../../../model/include/room.h"
#include <boost/algorithm/string/join.hpp>
#include <string>
#include <vector>


using std::vector;

StatusCode NorthCommand::execute(std::string &result, const std::vector<std::string>& args) {
    return moveInDirection(result, Direction::north);
}

StatusCode SouthCommand::execute(std::string& result, const std::vector<std::string>& args) {
    return moveInDirection(result, Direction::south);
}

StatusCode EastCommand::execute(std::string& result, const std::vector<std::string>& args) {
    return moveInDirection(result, Direction::east);
}

StatusCode WestCommand::execute(std::string& result, const std::vector<std::string>& args) {
    return moveInDirection(result, Direction::west);
}

StatusCode moveInDirection(std::string &result, Direction d) {
    if (!GameState::inCombat()) {
        roomId currentRoomId = GameState::getLocation();
        Room room;
        Controller::getRoom(currentRoomId, room);
        try {
            roomId nextRoomId = room.getRoomInDirection(d);
            Controller::moveToRoom(nextRoomId);
            Controller::getRoom(nextRoomId, room);
            result += boost::algorithm::join(room.getDescription(), " ") + "\n";
            return STATUS_OK;
        }
        catch (const std::domain_error& e) {
            result = "You cannot move in this direction.";
            return STATUS_OK;
        }
    }
    else {
        Display::addStringToCombatWindow("You cannot move while in combat! Stand and fight!");
        return STATUS_OK;
    }

}

StatusCode HelpCommand::execute(std::string& result, const std::vector<std::string>& args) {
    result = "You can say:\n";
    result += "help whoami whereami north east south west look take quit";
    return STATUS_OK;
}

/*
StatusCode WhoCommand::execute(std::string& result, const std::vector<std::string>& args) {
    result = "You are player ID " + std::to_string((int) player.getPlayerId());
    return STATUS_OK;
}*/

StatusCode WhereCommand::execute(std::string& result, const std::vector<std::string>& args) {
    roomId currentRoomId = GameState::getLocation();
    Room room;
    Controller::getRoom(currentRoomId, room);
    result += "You are in room " + room.getId().to_string() + "\n";
    result += "You can move to:\n";
    // TODO: replace with for-each, need printable Direction for that
    try {
        roomId newRoomId = room.getRoomInDirection(Direction::north);
        result += newRoomId.to_string() + " north\n";
    }
    catch (const std::domain_error& e) {

    }
    try {
        roomId newRoomId = room.getRoomInDirection(Direction::east);
        result += newRoomId.to_string() + " east\n";
    }
    catch (const std::domain_error& e) {

    }
    try {
        roomId newRoomId = room.getRoomInDirection(Direction::south);
        result += newRoomId.to_string() + " south\n";
    }
    catch (const std::domain_error& e) {

    }
    try {
        roomId newRoomId = room.getRoomInDirection(Direction::west);
        result += newRoomId.to_string() + " west\n";
    }
    catch (const std::domain_error& e) {

    }
    return STATUS_OK;
}

StatusCode LookCommand::execute(std::string& result, const std::vector<std::string>& args) {
    roomId currentRoomId = GameState::getLocation();
    Room room;
    Controller::getRoom(currentRoomId, room);

    result += "You are here: " + boost::algorithm::join(room.getDescription(), " ") + "\n";
    result += "You can move:";
    // TODO: streamline
    try {
        room.getDoor(Direction::north);
        result += " north";
    }
    catch (const std::domain_error& e) {

    }
    try {
        room.getDoor(Direction::east);
        result += " east";
    }
    catch (const std::domain_error& e) {

    }
    try {
        room.getDoor(Direction::south);
        result += " south";
    }
    catch (const std::domain_error& e) {

    }
    try {
        room.getDoor(Direction::west);
        result += " west";
    }
    catch (const std::domain_error& e) {

    }
    result += "\n";
    result += "Others in the room:\n" + showNpcs(room) + "\n";
    result += "Items here:\n" + showItems(room) + "\n";

    return STATUS_OK;
}

std::string showNpcs(Room& room) {
    // TODO: error checking
    vector<npcId> npcIds = room.getNpcList();
    std::string out;
    for (const npcId& n : npcIds) {
        Npc npc;
        Controller::getNpc(n, npc);
        out += "(" +  npc.getNpcId().to_string() + ") " + boost::algorithm::join(npc.getLongDesc(), "\n") + "\n";
    }
    return out;
}

std::string showItems(Room& room) {
    // TODO: error checking
    vector<itemId> itemIds = room.getItemList();
    std::string out;
    for (const itemId& id : itemIds) {
        Item item;
        Controller::getItem(id, item);
        out += boost::algorithm::join(item.getLongDesc(), "\n") + "\n";
    }
    return out;
}

StatusCode TalkCommand::execute(std::string& result, const std::vector<std::string>& args) {
    roomId currentRoomId = GameState::getLocation();
    Room room;
    Controller::getRoom(currentRoomId, room);

    if (args.size() < 1) {
        result = "Talk to whom? You can say: ";
        for (const npcId& id : room.getNpcList()) {
            Npc npc;
            Controller::getNpc(id, npc);
            result += "talk " + boost::algorithm::join(npc.getKeywords(), " ") + "\n";
        }
        return STATUS_OK;
    }

    const std::string& target = args[0];
    for (const npcId& id : room.getNpcList()) {
        Npc npc;
        Controller::getNpc(id, npc);
        const std::vector<std::string>& keywords = npc.getKeywords();
        // found the NPC we are looking for
        if (std::find(keywords.begin(), keywords.end(), target) != keywords.end()) {
            result = boost::algorithm::join(npc.getMainDesc(), " ") + "\n";
            break;
        }
    }
}

StatusCode TakeCommand::execute(std::string& result, const std::vector<std::string>& args) {
    // TODO
    result = "";
    for (const std::string& s : args) {
        result += "Took " + s + "\n";
    }
    return STATUS_OK;
}

StatusCode GlobalChatCommand::execute(std::string &result, const std::vector<std::string>& args) {
    std::string commandMessage = "";
    for(const std::string s : args) {
        commandMessage += s + " ";
    }
    MessageModel playerMessage;
    playerMessage.To = "global";
    playerMessage.From = GameState::getPlayerId();
    playerMessage.Message = commandMessage;
    std::string postPayload = parser::messageSerialize(playerMessage);

    auto statusCode = Controller::sendGlobalMessage(postPayload, result);
    result = "";
    return statusCode;
}

StatusCode SwapCommand::execute(std::string& result, const std::vector<std::string>& args) {

}

StatusCode MoveCommand::execute(std::string& result, const std::vector<std::string>& args) {
    roomId nextRoom{atoi(args[0].c_str())};
    return Controller::moveToRoom(nextRoom);
}

StatusCode EngageCommand::execute(std::string& result, const std::vector<std::string>& args) {
    char commandString[MAX_CHAR_LIMIT];
    std::string commandArg = "";
    for (const std::string s : args) {
        commandArg += s;
    }
    roomId currentRoomId = GameState::getLocation();
    Room room;
    Controller::getRoom(currentRoomId, room);
    std::vector<npcId> npcs = room.getNpcList();
    bool npcFound = false;
    std::string engagedNPC = "";
    for (auto& npc : npcs) {
        if(commandArg.compare(npc.to_string()) == 0){
            npcFound = true;
            GameState::setEngagedInCombatWith(npc);
            engagedNPC = npc.to_string();
            break;
        }
    }
    if (npcFound) {
        GameState::setAttackFlag(true);
        std::string engagedMsg = "You are now engaged in combat with " + engagedNPC;
        strcpy(commandString, engagedMsg.c_str());
        Display::addStringToCombatWindow(commandString);
        //TODO: Create a thread man...somewhere
    }
    else {
        std::string noNPCFound = "There is no one with that name to engage in combat with!";
        strcpy(commandString, noNPCFound.c_str());
        Display::addStringToCombatWindow(commandString);
    }
    return STATUS_OK;
}

StatusCode AttackCommand::execute(std::string& result, const std::vector<std::string>& args) {
    char commandString[MAX_CHAR_LIMIT];
    StatusCode code;
    npcId notAllowed = 0;
    if (!GameState::inCombat()) {
        std::string noNPCFound = "You are not engaged in combat with anyone.";
        strcpy(commandString, noNPCFound.c_str());
        Display::addStringToCombatWindow(commandString);
        code = STATUS_OK;
    }
    else {
        code = Combat::playerAttacksNPC(result);
    }
    return code;
}
