//resets.h

#ifndef RESETS_H
#define RESETS_H

#include <string>
#include "room.h"
#include "playerModel.h"

struct itemReset {
	itemId item;
	roomId room;
};

struct npcReset {
	std::string comment;
	npcId npc;
	int limit;
	roomId room;
};

struct giveReset {
	std::string comment;
	itemId item;//not sure what this ID refers to, object id's?
};


class resets {
private:
	std::vector<itemReset> itemResets;
	std::vector<npcReset> npcResets;
	std::vector<giveReset> giveResets;

public:
	resets();

	void runAll();

	void runNpc();

	void runItem();

	void runGive();

	void addItem(const itemReset &item);

	void addNpc(const npcReset &npc);

	void addGive(const giveReset &give);

};

//void actionObject(id object, id room);



#endif //RESETS_H
