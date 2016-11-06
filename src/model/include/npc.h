// npc.h
// Npc object structure. Uses values from a parse Npc from a YAML file.

#ifndef ADVENTURE2016_NPC_H
#define ADVENTURE2016_NPC_H

#include <string>
#include <vector>

typedef int id;
typedef std::string description;

class Npc {
public:
    friend class hiberlite::access;
    template<class Archive>
    void hibernate(Archive & ar)
    {
        ar & HIBERLITE_NVP(desc);
        ar & HIBERLITE_NVP(nid);
        ar & HIBERLITE_NVP(key);
        ar & HIBERLITE_NVP(ldesc);
        ar & HIBERLITE_NVP(sdesc);
    }

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
