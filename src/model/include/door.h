//
// Created by braden on 13/10/16.
//

#ifndef DOOR_H
#define DOOR_H


enum class Direction {
	north, south, east, west
};

using id = int;
using keyword = std::string;

class Door {
public:
	Direction direction;
	std::vector<keyword> keywords;
	id doorId;
	void build(Direction directionIn, std::vector<keyword> keywordsIn, id doorIdIn);
};


#endif //DOOR_H
