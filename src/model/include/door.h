//
// Created by braden on 13/10/16.
//

#ifndef DOOR_H
#define DOOR_H


enum class Direction {
	north, south, east, west
};

typedef int id;

typedef std::string description;

typedef std::string username;

class Door {
public:
	Direction direction;
	std::vector<std::string> keywords;
	id doorId;
	std::vector<std::string> description;
	void build(Direction d, std::vector<std::string> k, id dID);
};


#endif //DOOR_H
