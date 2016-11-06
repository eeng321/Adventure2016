#include "../../model/include/npcModel.h"
#include <string>

typedef bool success;

//void createDB();
void printNpc();

NpcModel loadNpc(int npcId);
NpcModel addNpc(NpcModel npc);
NpcModel modifyNpc(int npcId, NpcModel updateFields);
success removeNpc(int npcId);