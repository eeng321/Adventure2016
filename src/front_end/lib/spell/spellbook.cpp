//
// Created by curtis on 23/11/16.
//

#include <string>
#include <map>
#include <vector>
#include "spell.h"

class SpellBook {
public:
    void addSpell(Spell spell){
        spellBook.insert(std::make_pair(spell.getSpellName(), spell));
    }

    SpellBook() {
        SpellBook::addSpell(Spell("fireball", 0, -20, "<caster> shot a ball of flame at <victim>!"));
        SpellBook::addSpell(Spell("bodyslam", -15, -30, "<victim> was lifted up and smashed to the ground,"
                " but <caster> took some damage in the process!"));
        SpellBook::addSpell(Spell("meditate", 20, 0, "With great concentration, <caster> increased their vitality"));
        SpellBook::addSpell(Spell("trip", -5, 0, "<caster>'s clumsiness resulted self inflicted damage..."));
    }

    std::vector<std::string> getSpellList() {
        std::vector<std::string> spellList;
        for (std::map<std::string, Spell>::iterator it = spellBook.begin(); it != spellBook.end(); it++) {
            spellList.push_back(it->first);
        }
        return spellList;
    }

    Spell getSpell(std::string spellName) {
        return spellBook[spellName];
    }
private:
    std::map<std::string, Spell> spellBook;
};