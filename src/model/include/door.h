//
// Created by braden on 13/10/16.
//

#ifndef DOOR_H
#define DOOR_H

#pragma once
#include "../../back_end/lib/hiberlite/include/hiberlite.h"



enum class Direction {
	north, south, east, west
};

typedef int id;

typedef std::string description;

typedef std::string username;

class Door {
public:

	friend class hiberlite::access;
	template<class Archive>
	void hibernate(Archive & ar)
	{
		//ar & HIBERLITE_NVP(direction);
		//ar & HIBERLITE_NVP(keywords);
		//ar & HIBERLITE_NVP(doorId);
	}

	Direction direction;
	std::vector<std::string> keywords;
	id doorId;
	void build(Direction d, std::vector<std::string> k, id dID);
};


#endif //DOOR_H
