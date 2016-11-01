// npc.h
// Npc object structure. Uses values from a parse Npc from a YAML file.

#ifndef ADVENTURE2016_NPC_H
#define ADVENTURE2016_NPC_H

#include <string>
#include <vector>

#include "npcModel.h"

typedef int id;
typedef std::string description;

class Npc {
public:
    Npc(description desc,
        id nid,
        std::vector<std::string> key,
        description ldesc,
        description sdesc);
    std::string getMainDesc();
    id getNpcId();
    std::vector<std::string> getKeywords();
    std::string getLongDesc();
    std::string getShortDesc();

private:
    description mainDesc;
    id npcId;
    std::vector<std::string> keywords;
    description longDesc;
    description shortDesc;


};

#endif //ADVENTURE2016_NPC_H
