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
    npcId id = GameState::getEngagedInCombatWith();
    Npc engagedNpc;
    Controller::getNpc(id, engagedNpc);
    auto damageDone = 10; //Can add modifiers to this later with weapons but let us assumes fistacuffs were used
    auto npcHealth = engagedNpc.getHealth();
    std::string printNpcHealth = std::to_string(npcHealth);
    memset(&combatString[0], 0, sizeof(combatString));
    strcpy(combatString, printNpcHealth.c_str());
    Display::addStringToCombatWindow(combatString);
    auto newNpcHealth = npcHealth - damageDone;
    StatusCode code;

    std::stringstream combatDamageString;
    combatDamageString << "You have done " << damageDone << " damage to NPC " << id.to_string();
    std::string finalCombatString = combatDamageString.str();
    strcpy(combatString, finalCombatString.c_str());
    Display::addStringToCombatWindow(combatString);

    if (newNpcHealth <= 0) {
        std::string deathString = "You killed him man...Just....stop... you monster.";
        memset(&combatString[0], 0, sizeof(combatString));
        strcpy(combatString, deathString.c_str());
        Display::addStringToCombatWindow(combatString);
        engagedNpc.setHealth(newNpcHealth);
        code = Controller::putNpc(engagedNpc, result);
        Controller::deleteNPC(id);
        GameState::setEngagedInCombatWith(0);
        GameState::setAttackFlag(false);
    } else {
        engagedNpc.setHealth(newNpcHealth);
        code = Controller::putNpc(engagedNpc, result);
        //Combat::npcAttacksPlayer();
    }


    return code;
}

void Combat::npcAttacksPlayer() {
    char combatString[MAX_CHAR_LIMIT];
    auto missOrHit = (rand()%4) + 1;

    if(missOrHit == 4) {
        std::string missString = "NPC missed!";
        memset(&combatString[0], 0, sizeof(combatString));
        strcpy(combatString, missString.c_str());
        Display::addStringToCombatWindow(combatString);
    } else {
        auto damageDone = (rand() % 12) + 1; //Can add modifiers in the future
        auto playerHealth = GameState::getPlayerHealth();
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
        GameState::setPlayerHealth(newPlayerHealth);
    }
}

StatusCode Combat::spellCast(int castorEffect, int victimEffect, std::string& result) {
    char combatString[MAX_CHAR_LIMIT];
    npcId id = GameState::getEngagedInCombatWith();
    Npc engagedNpc;
    Controller::getNpc(id, engagedNpc);
    auto playerHealth = GameState::getPlayerHealth();
    auto newPlayerHealth = playerHealth - castorEffect;
    auto npcHealth = engagedNpc.getHealth();
    auto newNpcHealth = npcHealth - victimEffect;
    StatusCode code;

    std::stringstream combatDamageNpcString;
    combatDamageNpcString << "You have done " << victimEffect << " damage to NPC " << id.to_string();
    std::string finalCombatNpcString = combatDamageNpcString.str();
    strcpy(combatString, finalCombatNpcString.c_str());
    Display::addStringToCombatWindow(combatString);

    if (newNpcHealth <= 0) {
        std::string deathString = "You killed him man...Just....stop... you monster.";
        memset(&combatString[0], 0, sizeof(combatString));
        strcpy(combatString, deathString.c_str());
        Display::addStringToCombatWindow(combatString);
        engagedNpc.setHealth(newNpcHealth);
        code = Controller::putNpc(engagedNpc, result);
        Controller::deleteNPC(id);
        GameState::setEngagedInCombatWith(0);
        GameState::setAttackFlag(false);
    }
    else {
        engagedNpc.setHealth(newNpcHealth);
        code = Controller::putNpc(engagedNpc, result);
    }

    std::stringstream combatDamagePlayerString;
    combatDamagePlayerString << "You have received " << castorEffect << " damage";
    std::string finalCombatPlayerString = combatDamagePlayerString.str();
    strcpy(combatString, finalCombatPlayerString.c_str());
    Display::addStringToCombatWindow(combatString);

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
    GameState::setPlayerHealth(newPlayerHealth);
    return code;
}