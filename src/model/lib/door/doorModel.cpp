//door.cpp
//resources: cplusplus.com, cppreference.com

#include <string>
#include <vector>

#include "door.h"

using std::string;
using std::vector;

void Door::build(Direction d, vector<string> k, id dID) {
	direction = d;
	keywords = k;
	doorId = dID;
}

