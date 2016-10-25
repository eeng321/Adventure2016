//room.h
#ifndef ROOM_MODEL_H
#define ROOM_MODEL_H

#include <string>
#include <vector>

#include "door.h"
#include "id.h"

using description = std::string;
using username = std::string;

class RoomModel {
public:
	std::string area;
	int id;
	std::string name;
	description mainDescription;
	std::vector<description> extendedDescriptions;
	std::vector<Door> doors;
	std::vector<int> npcList;
	std::vector<username> playerList;
	std::vector<int> itemList;
	bool navigable;

	RoomModel();
};

#endif