//door.cpp
//resources: cplusplus.com, cppreference.com

#include <string>
#include <vector>

#include "door.h"

using std::vector;

void Door::build(const Direction& directionIn, const std::vector<keyword>& keywordsIn, const roomId& roomIn) {
	direction = directionIn;
	keywords = keywordsIn;
	room = roomIn;
}

