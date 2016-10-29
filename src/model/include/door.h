//
// Created by braden on 13/10/16.
//

#ifndef DOOR_H
#define DOOR_H

#include "id.h"

enum class Direction {
	north, south, east, west
};

//using id = int;
using keyword = std::string;

class Door {
public:
	Direction direction;
	std::vector<keyword> keywords;
	roomId room;
	void build(const Direction& directionIn, const std::vector<keyword>& keywordsIn, const roomId& roomIn);
};


#endif //DOOR_H
