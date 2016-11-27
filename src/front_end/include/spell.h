//
// Created by curtis on 23/11/16.
//

#ifndef ADVENTURE2016_SPELL_H
#define ADVENTURE2016_SPELL_H

#include <string>


class Spell {
public:
    Spell(std::string nameIn,
          int casterEffectIn,
          int victimEffectIn,
          std::string message);

    Spell();

    std::string getSpellName() const;
    int getCasterEffect() const;
    int getVictimEffect() const;

    std::string getMessage() const;
    std::string getMessage(std::string casterName, std::string victimName) const;

private:
    std::string name;
    int casterEffect;
    int victimEffect;
    std::string message;

};

#endif //ADVENTURE2016_SPELL_H
