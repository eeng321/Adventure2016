//world.h
//reference: cplusplus.com

#ifndef world_h
#define world_h

#include <vector>
#include <unordered_map>
#include <string>
#include <exception>

#include "tile.h"

using std::unordered_map
using std::vector
using std::string

enum Direction{north, south, east, west};

class World {//NOTE FOR FUTURE: split this class into multiple classes that has better cohesion 
private:
	vectore< vector<Tile> > map;
	unordered_map(string,Coordinate) players;//key: username, value location
	Coordinate spawnLocation;

public:

	world(int size, Coordinate spawn);

	void enterWorld(const string& username);

	vector< vector<Tile> > getMap() const;

	Tile getTile(const Coordinate& c) const;

	Tile getTileToEdit(const Coordinate& c);

	void modifyTile(const Tile& t);

	void move(string username, Direction d);
};

#endif /* world_h */