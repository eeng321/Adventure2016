

#ifndef DOOR_H
#define DOOR_H

enum class Direction {
	north, south, east, west
};

class DoorModel {
public:
	Direction direction;
	std::vector<std::string> keywords;
	int roomTo;
	std::vector<std::string> description;

	int doorId;
};


#endif //DOOR_H