#include <string>
#include <memory>

using std::string;

struct Coordinate {
	int x;
	int y;
};

class Tile {//Tile interface
public:
	virtual ~Tile();
	virtual string description() const = 0;
	virtual Coordinate getLocation() const = 0;
	virtual void makeUnnavigable() = 0;
	virtual void makeNavigable() = 0;
	virtual bool isNavigable() const = 0;
	virtual std::unique_ptr<Tile> clone() = 0;
};//Tile class

class Field : public Tile {//simple implementation of the tile interface
public:
	~Field();
	Field(Coordinate c);

	string description() const;

	Coordinate getLocation() const;

	void makeUnnavigable();

	void makeNavigable();

	bool isNavigable() const;

	std::unique_ptr<Tile> clone();

private:
	Coordinate location;
	bool navigable;

};//field class
