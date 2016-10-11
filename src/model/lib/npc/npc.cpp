#include <string>
#include "../../include/npc.h"

Npc::Npc(description desc,
         id nid,
         std::vector<std::string> key,
         description ldesc,
         description sdesc)
        :maindesc(desc), npcID(nid), keywords(key), longdesc(ldesc), shortdesc(sdesc){

}

std::string Npc::getMaindesc(){
    return maindesc;
}

id Npc::getNpcID(){
    return npcID;
}

std::vector<std::string> Npc::getKeywords(){
    return keywords;
}

std::string Npc::getLongdesc(){
    return longdesc;
}

std::string Npc::getShortdesc(){
    return shortdesc;
}