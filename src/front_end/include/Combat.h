//
// Created by jmedwid on 11/23/16.
//

#ifndef ADVENTURE2016_COMBAT_H
#define ADVENTURE2016_COMBAT_H


class Combat {
public:
    static StatusCode playerAttacksNPC(std::string& result);
    static void npcAttacksPlayer();
    static void startCombatThread();
    static void closeCombatThread();
};


#endif //ADVENTURE2016_COMBAT_H
