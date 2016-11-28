//
// Created by curtis on 23/11/16.
//

#include <string>

#include "spell.h"

Spell::Spell() {

}

Spell::Spell(std::string nameIn,
             int casterEffectIn,
             int victimEffectIn,
             std::string messageIn)
        : name(nameIn),
          casterEffect(casterEffectIn),
          victimEffect(victimEffectIn),
          message(std::move(messageIn)) {}

std::string Spell::getSpellName() const {
    return name;
};

int Spell::getCasterEffect() const {
    return casterEffect;
}

int Spell::getVictimEffect() const {
    return victimEffect;
}

std::string Spell::getMessage() const {
    return message;
}


// Reference to stackoverflow.com/questions/3418231/replace-part-of-a-string-with-another-string
std::string Spell::getMessage(std::string casterName, std::string victimName) const {
    std::string newMessage = message;
    std::string casterKey = "<caster>";
    std::string victimKey = "<victim>";

    size_t casterStartPos = message.find(casterKey);
    if (casterStartPos != std::string::npos) {
        newMessage.replace(casterStartPos, casterKey.length(), casterName);
    }

    size_t victimStartPos = message.find(victimKey);
    if (victimStartPos != std::string::npos) {
        newMessage.replace(victimStartPos, victimKey.length(), victimName);
    }
    return newMessage;
}