//
// Created by jmedwid on 11/23/16.
//

#include "../../../back_end/includes/parser.h"
#include "Controller.h"
#include "display.h"
#include "Combat.h"
#include "../../../model/include/npcModel.h"
#include <sstream>
#include <string>
#include <unistd.h>

StatusCode Combat::playerAttacksNPC(std::string& result) {
    char combatString[MAX_CHAR_LIMIT];
    npcId npc = GameState::getEngagedInCombatWith();
    std::string getNPCPayload = Controller::getNPC(npc);
    NpcModel engagedNPC = parser::npcDeserialize(getNPCPayload);
    auto damageDone = 10; //Can add modifiers to this later with weapons but let us assumes fistacuffs were used
    auto NPCHealth = engagedNPC.health;
    auto newNPCHealth = NPCHealth - damageDone;
    std::stringstream combatDamageString;
    combatDamageString << "You have done " << damageDone << " damage to NPC " << npc.to_string();
    std::string finalCombatString = combatDamageString.str();
    strcpy(combatString, finalCombatString.c_str());
    Display::addStringToCombatWindow(combatString);
    engagedNPC.health = newNPCHealth;
    std::string putNPCPayload = parser::npcSerialize(engagedNPC);
    StatusCode code  = Controller::putNPC(npc, putNPCPayload, result);
    if(newNPCHealth <= 0) {
        std::string deathString = "You killed him man...Just....stop... you monster.";
        memset(&combatString[0], 0, sizeof(combatString));
        strcpy(combatString, deathString.c_str());
        Display::addStringToCombatWindow(combatString);
        Controller::deleteNPC(npc);
        GameState::setEngagedInCombatWith(0);
        GameState::setAttackFlag(false);
    } else {
        //Combat::npcAttacksPlayer();
    }
    return code;
}

void Combat::npcAttacksPlayer() {
    PlayerModel currentPlayer = GameState::getPlayerModel();
    char combatString[MAX_CHAR_LIMIT];
    while(GameState::inCombat()) {
        auto damageDone = (rand() % 12) + 1; //Can add modifiers in the future
        auto playerHealth = currentPlayer.health;
        auto newPlayerHealth = playerHealth - damageDone;
        std::stringstream combatDamageString;
        combatDamageString << "The NPC did" << damageDone << " damage to you";
        std::string finalCombatString = combatDamageString.str();
        strcpy(combatString, finalCombatString.c_str());
        if(newPlayerHealth <= 0) {
            newPlayerHealth = 0;
            std::string deathString = "OH MAN. You just got owned. Plz git gud.";
            memset(&combatString[0], 0, sizeof(combatString));
            strcpy(combatString, deathString.c_str());
            Display::addStringToCombatWindow(combatString);
            GameState::setEngagedInCombatWith(0);
            GameState::setAttackFlag(false);
            //TODO: respawn player at default room
        }
        currentPlayer.health = newPlayerHealth;
        std::string showPlayerHealth = "Your health: " + currentPlayer.health;
        Display::addStringToCombatWindow(showPlayerHealth.c_str());
        GameState::setPlayerModel(currentPlayer);
    }
}