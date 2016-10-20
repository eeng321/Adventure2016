//room.cpp
//resources: cplusplus.com, cppreference.com

#include <string>
#include <stdexcept>
#include <algorithm>
#include <unordered_map>

#include "room.h"
#include "roomModel.h"


using std::string;
using std::vector;
using std::find;
using std::unordered_map;

Room::~Room() {

}

Room::Room() {}

Room::Room(const string &areaIn,
		   id roomIdIn,
		   const string &nameIn,
		   const description &descriptionIn,
		   const vector<description> &extendedDescriptionIn,
		   const vector<Door> &doorsIn,
		   const vector<id> &npcListIn,
		   const vector<string> playerListIn,
		   const vector<id> &itemListIn,
		   bool navigabilityIn) {

	model->area = areaIn;
	model->roomId = roomIdIn;
	model->name = nameIn;
	model->mainDescription = descriptionIn;
	model->extendedDescriptions = extendedDescriptionIn;
	model->doors = doorsIn;
	model->npcList = npcListIn;
	model->playerList = playerListIn;
	model->itemList = itemListIn;
	model->navigable = navigabilityIn;
}

Room::Room(const string &areaIn,
		   const description &descriptionIn,
		   const vector<description> &extendedDescriptionIn,
		   id roomIdIn,
		   const string &nameIn,
		   const vector<Door> &doorsIn) {
	model->area = areaIn;
	model->roomId = roomIdIn;
	model->name = nameIn;
	model->mainDescription = descriptionIn;
	model->extendedDescriptions = extendedDescriptionIn;
	model->doors = doorsIn;
}

//void Room::build(const string &areaIn,
//	id idIn,
//	const string &nameIn,
//	const description &descriptionIn,
//	const vector<description> &extendedDescriptionIn,
//	const vector<Door> &doorsIn,
//	const vector<id> &npcListIn,
//	const vector<string> playerListIn,
//	const vector<id> &objectListIn,
//	bool navigabilityIn) {
//
//	area = areaIn;
//	mainDescription = descriptionIn;
//	extendedDescriptions = extendedDescriptionIn;
//	roomId = idIn;
//	name = nameIn;
//	doors = doorsIn;
//	npcList = npcListIn;
//	playerList = playerListIn;
//	objectList = objectListIn;
//	navigable = navigabilityIn;
//}

//void Room::build(const string &areaIn,
//	const description &descriptionIn,
//	const vector<description> &extendedDescriptionIn,
//	id idIn,
//	const string &nameIn,
//	const vector<Door> &doorsIn) {
//
//	area = areaIn;
//	mainDescription = descriptionIn;
//	extendedDescriptions = extendedDescriptionIn;
//	roomId = idIn;
//	name = nameIn;
//	doors = doorsIn;
//}

string Room::getArea() const {
	return model->area;
}

/* a function for returning the raw description string, not the function
   for returning the string that will be seen by the user */
description Room::getDescription() const {
	return  model->mainDescription;
}

id Room::getId() const {
	return  model->roomId;
}

string Room::getName() const {
	return  model->name;
}

vector<description> Room::getExtendedDescriptions() const {
	return  model->extendedDescriptions;
}

vector<Door> Room::getDoors() const {
	return  model->doors;
}

vector<id> Room::getNpcList() const {
	return  model->npcList;
}

vector<username> Room::getPlayerList() const {
	return  model->playerList;
}


void Room::makeUnnavigable() {
	model->navigable = false;
}

void Room::makeNavigable() {
	model->navigable = true;
}

bool Room::isNavigable() const {
	return  model->navigable;
}

/* Ensure there is a room in the direction the player is trying to move */
bool Room::canMove(Direction d) {
	for (auto door : model->doors) {
		if (d == door.direction) {//possibly add in checks later for obstructions
			return true;
		}
	}
	return false;
}

void Room::addPlayer(username player) {
	auto element = find( model->playerList.begin(),  model->playerList.end(), player);

	/* Add the player to the room if they are not already in it */
	if (element !=  model->playerList.end()) {
		throw std::domain_error("Player already in room");
	}
	model->playerList.push_back(player);
}

void Room::removePlayer(username player) {

	auto element = find( model->playerList.begin(),  model->playerList.end(), player);

	/* Tell the calling function that the player is not in the room
	 * and don't try to remove them */
	if (element ==  model->playerList.end()) {
		throw std::domain_error("Player not in room");
	}
	model->playerList.erase(element);
}

/* Add the NPC to the room, doesn't check for duplicates b/c
 * multiple instances of an NPC can be in a room at once */
void Room::addNpc(id npc) {
	model->npcList.push_back(npc);
}

void Room::removeNpc(id npc) {
	auto element = find( model->npcList.begin(),  model->npcList.end(), npc);

	/* Tell the calling function that the player is not in the room
	 * and don't try to remove them */
	if (element ==  model->npcList.end()) {
		throw std::domain_error("NPC not in room");
	}
	model->npcList.erase(element);
}

void Room::addObject(id object) {
	auto element = find( model->itemList.begin(),  model->itemList.end(), object);

	if (element !=  model->itemList.end()) {
		throw std::domain_error("Object already in room");
	}
	model->itemList.push_back(object);
}

void Room::removeObject(id object) {
	auto element = find( model->itemList.begin(),  model->itemList.end(), object);

	/* Tell the calling function that the player is not in the room
	 * and don't try to remove them */
	if (element ==  model->itemList.end()) {
		throw std::domain_error("Object not in room");
	}
	model->itemList.erase(element);
}
