//resets.h

#ifndef RESETS_H
#define RESETS_H

#include "room.h"
#include "player.h"

struct objectReset{
    id objectId;
    id roomId;
};

struct npcReset{
    string comment;
    id npcId;
    int limit;
    id roomId;
};

struct giveReset{
    string comment;
    id objectId;//not sure what this ID refers to, object id's?
};



class resets {
private:
    std::vector<objectReset> objectResets;
    std::vector<npcReset> npcResets;
    std::vector<giveReset> giveResets;
    
public:
    resets();

    void runAll();
    void runNpc();
    void runObject();
    void runGive();

    void addObject(const objectReset& object);
    void addNpc(const npcReset& npc);
    void addGive(const giveReset& give);

};

//void actionObject(id object, id room);



#endif //RESETS_H
