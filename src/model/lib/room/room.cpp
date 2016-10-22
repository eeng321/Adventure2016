//room.cpp
//resources: cplusplus.com, cppreference.com

#include <string>
#include <stdexcept>
#include <algorithm>
#include <memory>

#include "room.h"
#include "roomModel.h"

using std::string;
using std::vector;
using std::find;


Room::Room(const string& areaIn,
	const roomID& idIn,
	const string& nameIn,
	const description& descriptionIn,
	const vector<description>& extendedDescriptionIn,
	const vector<Door>& doorsIn,
	const vector<npcID>& npcListIn,
	const vector<username>& playerListIn,
	const vector<itemID>& itemListIn,
	bool navigabilityIn)
	:model(std::make_unique<RoomModel>()) {

	build(areaIn,
	  idIn,
	  nameIn,
	  descriptionIn,
	  extendedDescriptionIn,
	  doorsIn,
	  npcListIn,
	  playerListIn,
	  itemListIn,
	  navigabilityIn);


}

void Room::build(const std::string& areaIn,
	const roomID& idIn,
	const std::string& nameIn,
	const description& descriptionIn,
	const std::vector<description>& extendedDescriptionIn,
	const std::vector<Door>& doorsIn,
	const std::vector<npcID>& npcListIn,
	const std::vector<username>& playerListIn,
	const std::vector<itemID>& itemListIn,
	bool navigabilityIn){

	build(areaIn, idIn, nameIn, descriptionIn, extendedDescriptionIn, doorsIn);
	model->npcList = npcListIn;
	model->playerList = playerListIn;
	model->itemList = itemListIn;
	model->navigable = navigabilityIn;
}


Room::Room(const string& areaIn,
	const roomID& idIn,
	const string& nameIn,
	const description& descriptionIn,
	const vector<description>& extendedDescriptionIn,
	const vector<Door>& doorsIn)
	:model(std::make_unique<RoomModel>()) {

	build(areaIn, idIn, nameIn, descriptionIn, extendedDescriptionIn, doorsIn);

}


void Room::build(const std::string& areaIn,
	const roomID& idIn,
	const std::string& nameIn,
	const description& descriptionIn,
	const std::vector<description>& extendedDescriptionIn,
	const std::vector<Door>& doorsIn){

	model->area = areaIn;
	model->id = idIn;
	model->name = nameIn;
	model->mainDescription = descriptionIn;
	model->extendedDescriptions = extendedDescriptionIn;
	model->doors = doorsIn;
}

string Room::getArea() const {
	return model->area;
}

/* a function for returning the raw description string, not the function
   for returning the string that will be seen by the user */
description Room::getDescription() const {
	return  model->mainDescription;
}

roomID Room::getId() const {
	return  model->id;
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

vector<npcID> Room::getNpcList() const {
	return  model->npcList;
}

vector<username> Room::getPlayerList() const {
	return  model->playerList;
}

vector<itemID> Room::getItemList() const {
	return model->itemList;
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
//bool Room::canMove(Direction d) {
//	for (auto door : model->doors) {
//		if (d == door.direction) {//possibly add in checks later for obstructions
//			return true;
//		}
//	}
//	return false;
//}

roomID Room::getRoomInDirection(Direction d) const{
	Door door = getDoor(d);//throws an exception if no door is found
	return door.room;
}

Door Room::getDoor(Direction d) const {
	for (const auto &door : model->doors) {
		if (door.direction == d) {
			return door;
		}
	}
	throw std::domain_error("No door in that direction");
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
void Room::addNpc(npcID npc) {
	model->npcList.push_back(npc);
}

void Room::removeNpc(npcID npc) {
	auto element = find( model->npcList.begin(),  model->npcList.end(), npc);

	/* Tell the calling function that the player is not in the room
	 * and don't try to remove them */
	if (element ==  model->npcList.end()) {
		throw std::domain_error("NPC not in room");
	}
	model->npcList.erase(element);
}

void Room::addItem(itemID item) {
	auto element = find( model->itemList.begin(),  model->itemList.end(), item);

	if (element !=  model->itemList.end()) {
		throw std::domain_error("Item already in room");
	}
	model->itemList.push_back(item);
}

void Room::removeItem(itemID item) {
	auto element = find( model->itemList.begin(),  model->itemList.end(), item);

	/* Tell the calling function that the player is not in the room
	 * and don't try to remove them */
	if (element ==  model->itemList.end()) {
		throw std::domain_error("Item not in room");
	}
	model->itemList.erase(element);
}
