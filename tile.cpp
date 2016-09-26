//tile.cpp

#include <string>

#include "tile.h"
using std::string;

Field::Field(Coordinate c)
:location(c){
	navigable = false;
}

string Field::description() const {
	return "a Simple descirption";
}

Coordinate Field::getLocation() const {
	return location;
}

void Field::makeUnnavigable(){
	navigable = false;
}

void Field::makeNavigable(){
	navigable = true;
}

bool Field::isNavigable() const {
	return navigable;
}

// std::unique_ptr<Tile> Field::clone(){//uses clone pattern as seen on cplusplus.com
// 	return std::make_unique<Tile>(*this);
// }