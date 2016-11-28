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
    auto secondsOfRest = 2; //This could change based upon weapons equipped but shall assume nothing was equipped at the time
    npcId id = GameState::getEngagedInCombatWith();
    Npc engagedNpc;
    Controller::getNpc(id, engagedNpc);
    auto damageDone = 10; //Can add modifiers to this later with weapons but let us assumes fistacuffs were used
    auto npcHealth = engagedNpc.getHealth();
    auto newNpcHealth = npcHealth - damageDone;
    std::stringstream combatDamageString;
    combatDamageString << "You have done " << damageDone << " damage to NPC " << id.to_string();
    std::string finalCombatString = combatDamageString.str();
    strcpy(combatString, finalCombatString.c_str());
    Display::addStringToCombatWindow(combatString);
    if (newNpcHealth <= 0) {
        newNpcHealth = 0;
        std::string deathString = "You killed him man...Just....stop... you monster.";
        memset(&combatString[0], 0, sizeof(combatString));
        strcpy(combatString, deathString.c_str());
        Display::addStringToCombatWindow(combatString);
        GameState::setEngagedInCombatWith(0);
        GameState::setAttackFlag(false);
    }
    engagedNpc.setHealth(newNpcHealth);
    StatusCode code = Controller::putNpc(engagedNpc, result);
    Display::addStringToMainWindow("You must rest because of your attack");
    for(int i = 1; i <= secondsOfRest; i++) {
        sleep(1);
        memset(&combatString[0], 0, sizeof(combatString));
        strcpy(combatString, std::to_string(i).c_str());
        Display::addStringToMainWindow(combatString);
    }
    return code;
}

void Combat::npcAttacksPlayer() {
    PlayerModel currentPlayer = GameState::getPlayerModel();
    char combatString[MAX_CHAR_LIMIT];
    while(GameState::inCombat()) {
        auto damageDone = (rand() % 12) + 1; //Can add modifiers in the future
        auto secondsOfRest = (rand() % 4) + 2; //Depending on what the NPC may have, this number can change
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
        }
        currentPlayer.health = newPlayerHealth;
        GameState::setPlayerModel(currentPlayer);
        sleep(secondsOfRest);
    }
}

void Combat::startCombatThread() {

}

void Combat::closeCombatThread() {

}