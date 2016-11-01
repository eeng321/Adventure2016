//door.cpp
//resources: cplusplus.com, cppreference.com

#include <string>
#include <vector>

#include "door.h"
#include "doorModel.h"

using std::vector;
using keyword_t = std::string;
using description_t = std::vector<std::string>

void Door::build(const Direction& directionIn, const vector<keyword_t>& keywordsIn, const roomId& roomIn, const description_t desc) {
	direction = directionIn;
	keywords = keywordsIn;
	roomTo = roomIn;
	description = desc;
}

DoorModel Door::getModel() const{
	model DoorModel;
	model.direction = direction;
	model.keywords = keywords;
	model.roomTo = roomTo.value;
	model.description = description;
	return model;
}

void loadModel(doorModel model){
	direction = model.direction;
	keywords = model.keywords;
	direction = model.direction;
	roomTo = roomId(model.roomTo.value);
}


