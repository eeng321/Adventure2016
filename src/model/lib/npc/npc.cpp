#include <string>
#include "../../include/npc.h"

Npc::Npc(description desc,
         id nid,
         std::vector<std::string> key,
         description ldesc,
         description sdesc)
        : mainDesc(desc), npcId(nid), keywords(key), longDesc(ldesc), shortDesc(sdesc) {
}

std::string Npc::getMainDesc() {
    return mainDesc;
}

id Npc::getNpcId() {
    return npcId;
}

std::vector<std::string> Npc::getKeywords() {
    return keywords;
}

std::string Npc::getLongDesc() {
    return longDesc;
}

std::string Npc::getShortDesc() {
    return shortDesc;
}