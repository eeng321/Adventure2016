//world.cpp

//world.h
//reference: cplusplus.com, cppreference.com

#include <vector>
#include <unordered_map>
#include <string>
#include <exception>

#include "world.h"

using std::unordered_map;
using std::vector;
using std::string;


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


World::World(int size, Coordinate spawn)
:spawnLocation(spawn){
	for(int x = 0; x < size; x++){

		for(int y = 0; y < size; y++){
			Field f{ Coordinate{x,y} };
			auto temp = std::make_unique<Field>(Coordinate{x,y});
			map[x].push_back(std::move(temp));
		}	
	}
}

void World::enterWorld(const string& username){
	players.insert(std::make_pair(username, spawnLocation));
}

Tile* World::getTile(const Coordinate& c) const {//getTileToEdit may be the only time a tile is needed to be returned, possibly don't need this method
	return map[c.x][c.y].get();
}

Tile* World::getTileToEdit(const Coordinate& c){
	map[c.x][c.y]->makeUnnavigable();
	return map[c.x][c.y].get();
}

void World::modifyTile(Tile& t){
	Coordinate c = t.getLocation();
	map[c.x][c.y].reset(std::move(&t)); 	
	map[c.x][c.y]->makeNavigable();	
}

/* 
   Move the desired player in one of four directions. 
   Throw a domain error if the user is trying to go off
   the world or if the tile they are trying to go to is
   not vavigable
 */
void World::move(string username, Direction d){
	Coordinate currentLocation = players[username];
	if(d == north && 
		currentLocation.y > 0 && //greater than last tile
		map[currentLocation.x][currentLocation.y - 1]->isNavigable() ){

		currentLocation.y--;
		players[username] = currentLocation;

	} else if(d == south &&
		currentLocation.y < map[currentLocation.x].size() - 1 && //less than last tile
		map[currentLocation.x][currentLocation.y + 1]->isNavigable() ){

		currentLocation.y++;
		players[username] = currentLocation;

	} else if(d == east &&
		currentLocation.x < map.size() - 1 && //less than last tile
		map[currentLocation.x + 1][currentLocation.y]->isNavigable()){

		currentLocation.x++;
		players[username] = currentLocation;

	} else if(d == west &&
		currentLocation.x > 0 && //greater than last tile
		map[currentLocation.x - 1][currentLocation.y]->isNavigable()){

		currentLocation.x--;
		players[username] = currentLocation;

	} else {
		throw std::domain_error("Unable to walk in that direction");
	}
}


