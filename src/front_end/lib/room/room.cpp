//room.cpp
//resources: cplusplus.com, cppreference.com

#include <string>
#include <exception>

#include "room.h"
using std::string;

void Room::addPlayer(string username) {
	try{
		int position = indexInRoom(username);
	} catch (const std::exception& e){
		
	}
	playerList.push_back(username);
}

void Room::removePlayer(string username) {
	try{
		int position = indexInRoom(username);
		playerList.erase(playerList.begin() + position);
	} catch (const std::exception& e){
		throw;//propogate error to the calling function
	}
}

int Room::indexInRoom(string username){
	for (int i = 0; i < playerList.size(); i++){
		if(playerList[i] == username){
			return i;
		} 
	}
	throw std::domain_error("Player not in room");	
}

Room::~Room(){

}

Room::Room(const Description& d, 
	const vector<Description>& ed, 
	ID idIn, 
	const string& nameIn, 
	const vector<Door>& doorsIn)
:description(d), extendedDescriptions(ed), id(idIn), name(nameIn), doors(doorsIn){

}

Room::Room(Room r)
:description(r.description), 
extendedDescriptions(r.extendedDescriptions, 
id(r.id), 
name(r.name), 
doors(r.doors)),
playerList(r.playerList),
npcList(r.npcList){
	
}

string Room::getDescription() const {
	return description
}

int Room::getId() const {
	return id.value;
}

void Room::makeUnnavigable() {
	navigable = false;
}

void Room::makeNavigable() {
	navigable = true;
}

bool Room::isNavigable() const {
	return navigable;
}

vector<ID> Room::getNpcList() const {
	return npcList;
}

vector<ID> Room::getPlayerList() const {
	return playerList;
}

/* canMove checks to ensure that there is a room in the direction the player is trying to move */
bool Room::canMove(Direction d){
	for (auto door : doors){
		if (d.direction == door.direction){//possibly add in checks later for obstructions
			return true;
		}
	}
	return false;
}
