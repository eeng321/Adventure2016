#include <string>

using std::string

struct Coordinate {
	int x;
	int y;
};

class Tile {//tile interface
	virtual ~tile();
	virtual string description() const = 0;
	virtual Coordinate getLocation() const = 0;
	virtual void makeUnnavigable() = 0;
	virtual void makeNavigable() = 0;
	virtual bool isNavigable() const = 0;

private:
	Coordinate location;
	bool navigable;
};//Tile class

class Field : public Tile {//simple implementation of the tile interface
public:

	field(Coordinate c)
	:location(c){
		navigable = false;
	}

	string description() const {

	}

	Coordinate getLocation() const {
		return location
	}

	void makeUnnavigable(){
		navigable = false;
	}

	void makeNavigable(){
		navigable = true;
	}

	bool isNavigable(){
		return navigable;
	}

};//field class