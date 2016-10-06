//room.cpp
//resources: cplusplus.com, cppreference.com

#include <string>
#include <stdexcept>

#include "room.h"
using std::string;

int Room::indexPlayer(username player){
	for (int i = 0; i < playerList.size(); i++){
		if(playerList[i] == player){
			return i;
		} 
	}
	throw std::domain_error("Player not in room");	
}

int Room::indexObject(id object){
    for (int i = 0; i < objectList.size(); i++){
        if(objectList[i] == object){
            return i;
        }
    }
    throw std::domain_error("Object not in room");
}

int Room::indexNpc(id npc){
    for (int i = 0; i < npcList.size(); i++){
        if(npcList[i] == npc){
            return i;
        }
    }
    throw std::domain_error("Object not in room");
}

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

/* canMove checks to ensure that there is a room in the direction the player is trying to move */
bool Room::canMove(Direction d){
	for (auto door : doors){
		if (d == door.direction){//possibly add in checks later for obstructions
			return true;
		}
	}
	return false;
}

void Room::addPlayer(username player) {
    bool inRoom = false;

    /* Find if the player is already in the room */
    for (int i = 0; i < playerList.size(); i++){
        if(playerList[i] == player){
            inRoom = true;
            break;
        }
    }

    /* Add the player to the room if they are not already in it */
    if(!inRoom){
        playerList.push_back(player);
        return;
    }
    throw std::domain_error("Player already in room");//will only run if the player was already in the room
}

void Room::removePlayer(username player) {
    try{
        int position = indexPlayer(player);
        playerList.erase(playerList.begin() + position);
    } catch (const std::exception& e){
        throw;//propogate error to the calling function
    }
}

void Room::addNpc(id npc) {
    bool inRoom = false;
    for (int i = 0; i < npcList.size(); i++){
        if(npcList[i] == npc){
            inRoom = true;
            break;
        }
    }

    if(!inRoom){
        npcList.push_back(npc);
        return;
    }
    throw std::domain_error("NPC already in room");
}

void Room::removeNpc(id npc) {
    try{
        int position = indexNpc(npc);
        npcList.erase(npcList.begin() + position);
    } catch (const std::exception& e){
        throw;//propogate error to the calling function
    }
}

void Room::addObject(id object) {
    bool inRoom = false;
    for (int i = 0; i < objectList.size(); i++){
        if(objectList[i] == object){
            inRoom = true;
            break;
        }
    }

    if(!inRoom){
        objectList.push_back(object);
        return;
    }
    throw std::domain_error("Object already in room");
}

void Room::removeObject(id object) {
    try{
        int position = indexObject(object);
        objectList.erase(objectList.begin() + position);
    } catch (const std::exception& e){
        throw;//propogate error to the calling function
    }
}
