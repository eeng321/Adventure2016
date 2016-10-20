//door.cpp
//resources: cplusplus.com, cppreference.com

#include <string>
#include <vector>

#include "door.h"

using std::vector;

void Door::build(const Direction& directionIn, const std::vector<keyword>& keywordsIn, id doorIdIn) {
	direction = directionIn;
	keywords = keywordsIn;
	doorId = doorIdIn;
}

