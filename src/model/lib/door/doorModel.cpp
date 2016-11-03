//door.cpp
//resources: cplusplus.com, cppreference.com

#include <string>
#include <vector>

#include "door.h"
#include "doorModel.h"
<<<<<<< HEAD
#include "id.h"
=======
>>>>>>> 802e2297afec0991082322ee57c940da3a66c340

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
<<<<<<< HEAD
	//roomTo = roomId(model.roomTo);
	roomTo.value = model.roomTo;
}

HIBERLITE_EXPORT_CLASS(DoorModel)
=======
	roomTo = roomId(model.roomTo);
}


>>>>>>> 802e2297afec0991082322ee57c940da3a66c340
