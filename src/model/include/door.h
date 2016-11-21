//
// Created by braden on 13/10/16.
//

#ifndef DOOR_H
#define DOOR_H

#include "id.h"
#include "doorModel.h"
//TODO Why here again?
//enum class Direction {
//	north, south, east, west
//};

class DoorModel;

class Door {
public:
	Direction direction;
	std::vector<std::string> keywords;
	roomId roomTo;
	std::vector<std::string> description;
	Door();
	void build(const Direction& directionIn, const std::vector<std::string>& keywordsIn, const roomId& roomIn, const std::vector<std::string>& desc);
	DoorModel getModel() const;
	void loadModel(DoorModel model);
};


#endif //DOOR_H
