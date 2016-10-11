//npc.h

#ifndef ADVENTURE2016_NPC_H
#define ADVENTURE2016_NPC_H

#include <string>
#include <vector>

typedef int id;
typedef std::string description;

class Npc{
public:
    Npc(description desc,
        id nid,
        std::vector<std::string> key,
        description ldesc,
        description sdesc);

    std::string getMaindesc();
    id getNpcID();
    std::vector<std::string> getKeywords();
    std::string getLongdesc();
    std::string getShortdesc();

private:
    description maindesc;
    id npcID;
    std::vector<std::string> keywords;
    description longdesc;
    description shortdesc;


};

#endif //ADVENTURE2016_NPC_H
