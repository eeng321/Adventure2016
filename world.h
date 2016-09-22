//world.h
//reference: cplusplus.com
#include <vector>
#include <unordered_map>
#include <string>
#include <exception>

#include "tile.h"

using std::unordered_map
using std::vector
using std::string

enum Direction{north, south, east, west};

/*
	  ------X-------
	| [][][][][][][]
	| [][][][][][][]
	| [][][][][][][]
	Y [][][][][][][]
	| [][][][][][][]
	| [][][][][][][]
	| [][][][][][][]
*/

class World {//NOTE FOR FUTURE: split this class into multiple classes that has better cohesion 
private:
	vectore< vector<Tile> > map;
	unordered_map(string,Coordinate) players;//key: username, value location
	Coordinate spawnLocation;

public:

	world(int size, Coordinate spawn)
	:spawnLocation(spawn){
		for(int x := 0; x < size; x++){

			vector<Tile> column;
			for(int y := 0; y < size; y++){
				Field temp(Coordinate{x,y});//initialize map with only generic field tiles
				column.pushBack(temp)
			}

			map.push_back(column);
		}
	}

	void enterWorld(const string& username){
		players.insert(std::make_pair<string,Coordinate>(username, spawn));
	}

	vector< vector<Tile> > getMap() const {
		return map;
	}

	Tile getTile(const Coordinate& c) const {//getTileToEdit may be the only time a tile is needed to be returned, possibly don't need this method
		return map[c.x][c.y];
	}

	Tile getTileToEdit(const Coordinate& c){
		map[c.x][c.y].makeUnnavigable();
		return map[c.x][c.y];
	}

	void modifyTile(const Tile& t){
		Coordinate c = t.getLocation();
		map[c.x][c.y] = t;//overwrite tile with the new tile 	
		map[c.x][c.y].makeNavigable();	
	}

	/* 
	   Move the desired player in one of four directions. 
	   Throw a domain error if the user is trying to go off
	   the world or if the tile they are trying to go to is
	   not vavigable
	 */
	void move(string username, Direction d){
		Coordinate currentLocation = players.find("username");
		if(d = north && 
			currentLocation.y > 0 && //greater than last tile
			map[currentLocation.x][currentLocation.y - 1].isNavigable() ){

			currentLocation.y--;
			players[username] = currentLocation;

		} else if(d = south &&
			currentLocation.y < map[currentLocation.x].size() - 1 && //less than last tile
			map[currentLocation.x][currentLocation.y + 1].isNavigable() ){

			currentLocation.y++;
			players[username] = currentLocation;

		} else if(d = east &&
			currentLocation.x < map.size() - 1 && //less than last tile
			map[currentLocation.x + 1][currentLocation.y].isNavigable){

			currentLocation.x++;
			players[username] = currentLocation;

		} else if(d = west &&
			currentLocation.x > 0 && //greater than last tile
			map[currentLocation.x - 1][currentLocation.y].isNavigable){

			currentLocation.x--;
			players[username] = currentLocation;

		} else {
			throw std::domain_error;
		}
	}
};