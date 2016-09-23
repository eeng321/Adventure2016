//tile.cpp

#ifdef tile_h;

#include <string>

using std::string

field::field(Coordinate c)
:location(c){
	navigable = false;
}

string field::description() const {

}

Coordinate field::getLocation() const {
	return location
}

void field::makeUnnavigable(){
	navigable = false;
}

void field::makeNavigable(){
	navigable = true;
}

bool field::isNavigable(){
	return navigable;
}

#endif