//resets.h

#ifndef RESETS_H
#define RESETS_H

#include <string>
#include "room.h"
#include "playerModel.h"

struct itemReset {
	itemID item;
	roomID room;
};

struct npcReset {
	std::string comment;
	npcID npc;
	int limit;
	roomID room;
};

struct giveReset {
	std::string comment;
	itemID item;//not sure what this ID refers to, object id's?
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
