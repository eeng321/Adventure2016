//door.cpp
//resources: cplusplus.com, cppreference.com

#include <string>
#include <vector>

#include "door.h"
#include "doorModel.h"
#include "id.h"

using std::vector;
using keyword_t = std::string;
using description_t = std::vector<std::string>;

void Door::build(const Direction& directionIn, const vector<keyword_t>& keywordsIn, const roomId& roomIn, const description_t& desc) {
	direction = directionIn;
	keywords = keywordsIn;
	roomTo = roomIn;
	description = desc;
}

DoorModel Door::getModel() const{
	DoorModel model;
	model.direction = direction;
	model.keywords = keywords;
	model.roomTo = roomTo.value;
	model.description = description;
	return model;
}

void Door::loadModel(DoorModel model){
	direction = model.direction;
	keywords = model.keywords;
	description = model.description;
	//roomTo = roomId(model.roomTo);
	roomTo.value = model.roomTo;
}

HIBERLITE_EXPORT_CLASS(DoorModel)
