//room.h
#ifndef ROOM_MODEL_H
#define ROOM_MODEL_H

#include <string>
#include <vector>

#include "doorModel.h"
#include "extendedDescription.h"

using id = int;

class RoomModel {
public:
	std::string area;
	int id;
	std::string name;
	std::vector<std::string> mainDescription;
	std::vector<extendedDescription> extendedDescriptions;
	std::vector<DoorModel> doors;
	std::vector<int> npcList;
	std::vector<std::string> playerList;
	std::vector<int> itemList;
	bool navigable;

	RoomModel();
};

#endif