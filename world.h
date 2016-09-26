//world.h
//reference: cplusplus.com

#include <vector>
#include <unordered_map>
#include <string>
#include <exception>
#include <memory>

#include "tile.h"

using std::unordered_map;
using std::vector;
using std::string;
using std::unique_ptr;

enum Direction{north, south, east, west};

class World {//NOTE FOR FUTURE: split this class into multiple classes that has better cohesion 
private:
	vector< vector< unique_ptr<Tile> > > map;
	unordered_map<string,Coordinate> players;//key: username, value location
	Coordinate spawnLocation;

public:

	World(int size, Coordinate spawn);

	void enterWorld(const string& username);

	Tile* getTile(const Coordinate& c) const;

	Tile* getTileToEdit(const Coordinate& c);

	void modifyTile(Tile& t);

	void move(string username, Direction d);
};

