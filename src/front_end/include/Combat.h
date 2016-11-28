//
// Created by jmedwid on 11/23/16.
//

#ifndef ADVENTURE2016_COMBAT_H
#define ADVENTURE2016_COMBAT_H


class Combat {
public:
    static StatusCode playerAttacksNPC(std::string& result);
    static void npcAttacksPlayer();
    static StatusCode spellCast(int castorEffect, int victimEffect, std::string& result);
};


#endif //ADVENTURE2016_COMBAT_H
