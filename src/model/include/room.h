//room.h
#ifndef ROOM_H
#define ROOM_H

#include <string>
#include <vector>
#include <memory>
#include "door.h"
#include "id.h"

using description = std::string;
using username = std::string;

class RoomModel;

class Room {//Tile interface
private:
	std::unique_ptr<RoomModel> model;

public:

	~Room();

	Room();

	Room(const std::string& areaIn,
		 const roomID& idIn,
		 const std::string& nameIn,
		 const description& descriptionIn,
		 const std::vector<description>& extendedDescriptionIn,
		 const std::vector<Door>& doorsIn,
		 const std::vector<npcID>& npcListIn,
		 const std::vector<username>& playerListIn,
		 const std::vector<itemID>& itemListIn,
		 bool navigabilityIn);

	Room(const std::string& areaIn,
		 const roomID& idIn,
		 const std::string& nameIn,
		 const description& descriptionIn,
		 const std::vector<description>& extendedDescriptionIn,
		 const std::vector<Door>& doorsIn);

	void build(const std::string& areaIn,
			   const roomID& idIn,
			   const std::string& nameIn,
			   const description& descriptionIn,
			   const std::vector<description>& extendedDescriptionIn,
			   const std::vector<Door>& doorsIn,
			   const std::vector<npcID>& npcListIn,
			   const std::vector<username>& playerListIn,
			   const std::vector<itemID>& itemListIn,
			   bool navigabilityIn);

	void build(const std::string& areaIn,
			   const roomID& idIn,
			   const std::string& nameIn,
			   const description& descriptionIn,
			   const std::vector<description>& extendedDescriptionIn,
			   const std::vector<Door>& doorsIn);

	/* Getters */
	std::string getArea() const;
	description getDescription() const;
	roomID getId() const;
	std::string getName() const;
	std::vector<description> getExtendedDescriptions() const;
	std::vector<Door> getDoors() const;
	std::vector<npcID> getNpcList() const;
	std::vector<username> getPlayerList() const;
	std::vector<itemID> getItemList() const;

	/* Navigation management */
	void makeUnnavigable();
	void makeNavigable();
	bool isNavigable() const;

	/* Player Management */
	void addPlayer(username player);
	void removePlayer(username player);

	roomID getRoomInDirection(Direction d) const;
	Door getDoor(Direction d) const;

	/* NPC management */
	void addNpc(npcID npc);
	void removeNpc(npcID npc);

	/* Object management */
	void addItem(itemID item);
	void removeItem(itemID item);

};//Room class

#endif