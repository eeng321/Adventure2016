//room.cpp
//resources: cplusplus.com, cppreference.com

#include <string>
#include <stdexcept>
#include <algorithm>
#include <memory>

#include "roomModel.h"
#include "room.h"


using std::string;
using std::vector;
using std::find;
<<<<<<< HEAD
=======
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
>>>>>>> parent of 58fff20... npc-controller finished

using description = std::vector<std::string>;
using keyword = std::string;
using username = std::string;

Room::Room(const string& areaIn,
	const roomId& idIn,
	const string& nameIn,
	const description& descriptionIn,
	const vector<extendedDescription>& extendedDescriptionsIn,
	const vector<Door>& doorsIn,
	const vector<npcId>& npcListIn,
	const vector<username>& playerListIn,
	const vector<itemId>& itemListIn,
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
		   const roomId& idIn,
		   const string& nameIn,
		   const description& descriptionIn,
		   const vector<extendedDescription>& extendedDescriptionsIn,
		   const vector<Door>& doorsIn)
		: area(areaIn),
		  id(idIn),
		  name(nameIn),
		  mainDescription(descriptionIn),
		  extendedDescriptions(extendedDescriptionsIn),
		  doors(doorsIn){}

void Room::build(const std::string& areaIn,
	const roomId& idIn,
	const string& nameIn,
	const description& descriptionIn,
	const vector<extendedDescription>& extendedDescriptionIn,
	const vector<Door>& doorsIn,
	const vector<npcId>& npcListIn,
	const vector<username>& playerListIn,
	const vector<itemId>& itemListIn,
	bool navigabilityIn) {

	build(areaIn, idIn, nameIn, descriptionIn, extendedDescriptionIn, doorsIn, navigable = navigabilityIn);
	npcList = npcListIn;
	playerList = playerListIn;
	itemList = itemListIn;
}

void Room::build(const std::string& areaIn,
	const roomId& idIn,
	const std::string& nameIn,
	const description& descriptionIn,
	const std::vector<extendedDescription>& extendedDescriptionIn,
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

//void Room::setModel(const Room& model){
//	build(model.area, roomId(model.id), model.name, model.mainDescription, model.extendedDescriptions, model.doors, model.navigable);
//	playerList = model.playerList;
//	for(int id : model.itemList){
//		itemList.push_back(itemId(id));
//	}
//	for(int id : model.npcList) {
//		npcList.push_back(npcId(id));
//	}
//}

Room Room::getModel() const {
	Room model;
	model.name = name;
	model.id = id.value;
	model.area = area;
	model.mainDescription = mainDescription;
	model.extendedDescriptions = extendedDescriptions;
	model.doors = doors;
	model.playerList = playerList;
	model.navigable = navigable;
	for(const itemId& itemid : itemList){
		model.itemList.push_back(itemid.value);
	}
	for(const npcId& npcid : npcList) {
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
<<<<<<< HEAD
	return  mainDescription;
=======
	return  model->mainDescription;
>>>>>>> parent of 58fff20... npc-controller finished
}

roomId Room::getId() const {
	return  id;
}

string Room::getName() const {
	return  name;
}

vector<extendedDescription> Room::getExtendedDescriptions() const {
	return  extendedDescriptions;
}

description Room::getExtendedDescriptionByKey(keyword key) const {
	for(const auto& extendedDesc : extendedDescriptions){
		auto keyItr = find(extendedDesc.keywords.begin(), extendedDesc.keywords.end(), key);
		if(keyItr != extendedDesc.keywords.end()){
			return extendedDesc.description;
		}
	}
	throw std::domain_error("Keyword not found");
}

vector<Door> Room::getDoors() const {
	return  doors;
}

vector<npcId> Room::getNpcList() const {
	return  npcList;
}

vector<username> Room::getPlayerList() const {
	return  playerList;
}

vector<itemId> Room::getItemList() const {
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

roomId Room::getRoomInDirection(Direction d) const{
	Door door = getDoor(d);//throws an exception if no door is found
	return door.roomTo;
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
void Room::addNpc(npcId npc) {
	npcList.push_back(npc);
}

void Room::removeNpc(npcId npc) {
	auto element = find( npcList.begin(),  npcList.end(), npc);

	/* Tell the calling function that the player is not in the room
	 * and don't try to remove them */
	if (element ==  npcList.end()) {
		throw std::domain_error("NPC not in room");
	}
	npcList.erase(element);
}

void Room::addItem(itemId item) {
	auto element = find( itemList.begin(),  itemList.end(), item);

	if (element !=  itemList.end()) {
		throw std::domain_error("Item already in room");
	}
	itemList.push_back(item);
}

void Room::removeItem(itemId item) {
	auto element = find( itemList.begin(),  itemList.end(), item);

	/* Tell the calling function that the player is not in the room
	 * and don't try to remove them */
	if (element ==  itemList.end()) {
		throw std::domain_error("Item not in room");
	}
	itemList.erase(element);
}
