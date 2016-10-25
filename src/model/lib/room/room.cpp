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
	const vector<description>& extendedDescriptionsIn,
	const vector<Door>& doorsIn,
	const vector<npcID>& npcListIn,
	const vector<username>& playerListIn,
	const vector<itemID>& itemListIn,
	bool navigabilityIn)
	: area(areaIn),
	id(idIn),
	name(nameIn),
	mainDescription(descriptionIn),
	extendedDescriptions(extendedDescriptionsIn),
	doors(doorsIn),
	npcList(npcListIn),
	playerList(playerListIn),
	itemList(itemListIn),
	navigable(navigabilityIn) {}

Room::Room(const string& areaIn,
		   const roomID& idIn,
		   const string& nameIn,
		   const description& descriptionIn,
		   const vector<description>& extendedDescriptionsIn,
		   const vector<Door>& doorsIn)
		: area(areaIn),
		  id(idIn),
		  name(nameIn),
		  mainDescription(descriptionIn),
		  extendedDescriptions(extendedDescriptionsIn),
		  doors(doorsIn){}

void Room::build(const std::string& areaIn,
	const roomID& idIn,
	const string& nameIn,
	const description& descriptionIn,
	const vector<description>& extendedDescriptionIn,
	const vector<Door>& doorsIn,
	const vector<npcID>& npcListIn,
	const vector<username>& playerListIn,
	const vector<itemID>& itemListIn,
	bool navigabilityIn) {

	build(areaIn, idIn, nameIn, descriptionIn, extendedDescriptionIn, doorsIn, navigable = navigabilityIn);
	npcList = npcListIn;
	playerList = playerListIn;
	itemList = itemListIn;
}

void Room::build(const std::string& areaIn,
	const roomID& idIn,
	const std::string& nameIn,
	const description& descriptionIn,
	const std::vector<description>& extendedDescriptionIn,
	const std::vector<Door>& doorsIn,
	bool navigabilityIn){

	area = areaIn;
	id = idIn;
	name = nameIn;
	mainDescription = descriptionIn;
	extendedDescriptions = extendedDescriptionIn;
	doors = doorsIn;
	navigable = navigabilityIn;
}

void Room::setModel(const RoomModel& model){
	build(model.area, roomID(model.id), model.name, model.mainDescription, model.extendedDescriptions, model.doors, model.navigable);
	playerList = model.playerList;
	for(int id : model.itemList){
		itemList.push_back(itemID(id));
	}
	for(int id : model.npcList) {
		npcList.push_back(npcID(id));
	}
}

RoomModel Room::getModel() const {
	RoomModel model;
	model.name = name;
	model.id = id.value;
	model.area = area;
	model.mainDescription = mainDescription;
	model.extendedDescriptions = extendedDescriptions;
	model.doors = doors;
	model.playerList = playerList;
	model.navigable = navigable;
	for(const itemID& itemid : itemList){
		model.itemList.push_back(itemid.value);
	}
	for(const npcID& npcid : npcList) {
		model.npcList.push_back(npcid.value);
	}
	return model;
}

string Room::getArea() const {
	return area;
}

/* a function for returning the raw description string, not the function
   for returning the string that will be seen by the user */
description Room::getDescription() const {
	return  mainDescription;
}

roomID Room::getId() const {
	return  id;
}

string Room::getName() const {
	return  name;
}

vector<description> Room::getExtendedDescriptions() const {
	return  extendedDescriptions;
}

vector<Door> Room::getDoors() const {
	return  doors;
}

vector<npcID> Room::getNpcList() const {
	return  npcList;
}

vector<username> Room::getPlayerList() const {
	return  playerList;
}

vector<itemID> Room::getItemList() const {
	return itemList;
}

void Room::makeUnnavigable() {
	navigable = false;
}

void Room::makeNavigable() {
	navigable = true;
}

bool Room::isNavigable() const {
	return  navigable;
}

/* Ensure there is a room in the direction the player is trying to move */
//bool Room::canMove(Direction d) {
//	for (auto door : doors) {
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
	for (const auto &door : doors) {
		if (door.direction == d) {
			return door;
		}
	}
	throw std::domain_error("No door in that direction");
}

void Room::addPlayer(username player) {
	auto element = find( playerList.begin(),  playerList.end(), player);

	/* Add the player to the room if they are not already in it */
	if (element !=  playerList.end()) {
		throw std::domain_error("Player already in room");
	}
	playerList.push_back(player);
}

void Room::removePlayer(username player) {
	auto element = find( playerList.begin(),  playerList.end(), player);

	/* Tell the calling function that the player is not in the room
	 * and don't try to remove them */
	if (element ==  playerList.end()) {
		throw std::domain_error("Player not in room");
	}
	playerList.erase(element);
}

/* Add the NPC to the room, doesn't check for duplicates b/c
 * multiple instances of an NPC can be in a room at once */
void Room::addNpc(npcID npc) {
	npcList.push_back(npc);
}

void Room::removeNpc(npcID npc) {
	auto element = find( npcList.begin(),  npcList.end(), npc);

	/* Tell the calling function that the player is not in the room
	 * and don't try to remove them */
	if (element ==  npcList.end()) {
		throw std::domain_error("NPC not in room");
	}
	npcList.erase(element);
}

void Room::addItem(itemID item) {
	auto element = find( itemList.begin(),  itemList.end(), item);

	if (element !=  itemList.end()) {
		throw std::domain_error("Item already in room");
	}
	itemList.push_back(item);
}

void Room::removeItem(itemID item) {
	auto element = find( itemList.begin(),  itemList.end(), item);

	/* Tell the calling function that the player is not in the room
	 * and don't try to remove them */
	if (element ==  itemList.end()) {
		throw std::domain_error("Item not in room");
	}
	itemList.erase(element);
}
