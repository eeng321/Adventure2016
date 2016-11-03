

#ifndef DOOR_MODEL_H
#define DOOR_MODEL_H


enum class Direction {
	north, south, east, west
};

class DoorModel {
public:
	Direction direction;
	std::vector<std::string> keywords;
	int roomTo;//The room this door leads too
	std::vector<std::string> description;
};


#endif //DOOR_H