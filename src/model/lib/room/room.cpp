//room.cpp
//resources: cplusplus.com, cppreference.com

#include <string>
#include <stdexcept>
#include <algorithm>

#include "room.h"
using std::string;
using std::vector;
using std::find;

Room::~Room(){

}

Room::Room(const string& a,
	id rid,
	const string& n,
	const description& des,
	const vector<description>& ed,
	const vector<Door>& d,
	const vector<id>& nl,
	const vector<string> pl,
	const vector<id>& ol,
	bool nav)
: area(a), 
	mainDescription(des), 
	extendedDescriptions(ed),
	roomId(rid), 
	name(n), 
	doors(d),
	npcList(nl),
	playerList(pl),
	objectList(ol),
	navigable(nav){


}

Room::Room(const string& a,
	const description& d, 
	const vector<description>& ed, 
	id idIn, 
	const string& nameIn,
	const vector<Door>& doorsIn)
:area(a), mainDescription(d), extendedDescriptions(ed), roomId(idIn), name(nameIn), doors(doorsIn){

}

string Room::getArea() const {
	return area;
}

/* a function for returning the raw description string, not the function
   for returning the string that will be seen by the user */
description Room::getDescription() const {
	return mainDescription;
}

id Room::getId() const {
	return roomId;
}

string Room::getName() const {
	return name;
}

vector<description> Room::getExtendedDescriptions() const {
	return extendedDescriptions;
}

vector<Door> Room::getDoors() const {
	return doors;
}

vector<id> Room::getNpcList() const {
	return npcList;
}

vector<username> Room::getPlayerList() const {
	return playerList;
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

/* Ensure there is a room in the direction the player is trying to move */
bool Room::canMove(Direction d){
	for (auto door : doors){
		if (d == door.direction){//possibly add in checks later for obstructions
			return true;
		}
	}
	return false;
}

void Room::addPlayer(username player) {
	auto element = find(playerList.begin(), playerList.end(), player);

    /* Add the player to the room if they are not already in it */
    if(element != playerList.end()){
		throw std::domain_error("Player already in room");
    }
	playerList.push_back(player);
}

void Room::removePlayer(username player) {

    auto element = find(playerList.begin(), playerList.end(), player);

    /* Tell the calling function that the player is not in the room
     * and don't try to remove them */
    if(element == playerList.end()){
        throw std::domain_error("Player not in room");
    }
    playerList.erase(element);
}

/* Add the NPC to the room, doesn't check for duplicates b/c
 * multiple instances of an NPC can be in a room at once */
void Room::addNpc(id npc) {
    npcList.push_back(npc);
}

void Room::removeNpc(id npc) {
    auto element = find(npcList.begin(), npcList.end(), npc);

    /* Tell the calling function that the player is not in the room
     * and don't try to remove them */
    if(element == npcList.end()){
        throw std::domain_error("NPC not in room");
    }
    npcList.erase(element);
}

void Room::addObject(id object) {
	auto element = find(objectList.begin(), objectList.end(), object);

    if(element != objectList.end()){
		throw std::domain_error("Object already in room");
    }
	objectList.push_back(object);
}

void Room::removeObject(id object) {
    auto element = find(objectList.begin(), objectList.end(), object);

    /* Tell the calling function that the player is not in the room
     * and don't try to remove them */
    if(element == objectList.end()){
        throw std::domain_error("Object not in room");
    }
    objectList.erase(element);
}
