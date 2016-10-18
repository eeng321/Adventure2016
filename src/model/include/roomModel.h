//room.h
#ifndef ROOM_MODEL_H
#define ROOM_MODEL_H

#include <string>
#include <vector>
#include "door.h"

using description = std::string;
using username = std::string;

class RoomModel {//Tile interface
public:
	std::string area;
	id roomId;
	std::string name;
	description mainDescription;
	std::vector<description> extendedDescriptions;
	std::vector<Door> doors;
	std::vector<id> npcList;
	std::vector<username> playerList;
	std::vector<id> itemList;
	bool navigable;

};

#endif