#include "../../model/include/npcModel.h"
#include <string>

#ifndef ADVENTURE2016_NPC_DRIVER_H
#define ADVENTURE2016_NPC_DRIVER_H

typedef bool success;

//void createDB();
void printNpcDB();

NpcModel loadNpc(int npcId);
NpcModel addNpc(NpcModel npc);
NpcModel modifyNpc(int npcId, NpcModel updateFields);
success removeNpc(int npcId);

#endif