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

class Room {
private:
//	std::unique_ptr<RoomModel> model;
	std::string area;
	roomId id;
	std::string name;
	description mainDescription;
	std::vector<description> extendedDescriptions;
	std::vector<Door> doors;
	std::vector<npcId> npcList;
	std::vector<username> playerList;
	std::vector<itemId> itemList;
	bool navigable;

public:

	~Room();

	Room();

	Room(const std::string& areaIn,
		 const roomId& idIn,
		 const std::string& nameIn,
		 const description& descriptionIn,
		 const std::vector<description>& extendedDescriptionsIn,
		 const std::vector<Door>& doorsIn,
		 const std::vector<npcId>& npcListIn,
		 const std::vector<username>& playerListIn,
		 const std::vector<itemId>& itemListIn,
		 bool navigabilityIn);

	Room(const std::string& areaIn,
		 const roomId& idIn,
		 const std::string& nameIn,
		 const description& descriptionIn,
		 const std::vector<description>& extendedDescriptionsIn,
		 const std::vector<Door>& doorsIn);

	void build(const std::string& areaIn,
			   const roomId& idIn,
			   const std::string& nameIn,
			   const description& descriptionIn,
			   const std::vector<description>& extendedDescriptionIn,
			   const std::vector<Door>& doorsIn,
			   const std::vector<npcId>& npcListIn,
			   const std::vector<username>& playerListIn,
			   const std::vector<itemId>& itemListIn,
			   bool navigabilityIn);

	void build(const std::string& areaIn,
			   const roomId& idIn,
			   const std::string& nameIn,
			   const description& descriptionIn,
			   const std::vector<description>& extendedDescriptionIn,
			   const std::vector<Door>& doorsIn,
			   bool navigabilityIn);

	void setModel(const RoomModel& model);
	RoomModel getModel() const;

	/* Getters */
	std::string getArea() const;
	description getDescription() const;
	roomId getId() const;
	std::string getName() const;
	std::vector<description> getExtendedDescriptions() const;
	std::vector<Door> getDoors() const;
	std::vector<npcId> getNpcList() const;
	std::vector<username> getPlayerList() const;
	std::vector<itemId> getItemList() const;

	/* Navigation management */
	void makeUnnavigable();
	void makeNavigable();
	bool isNavigable() const;

	/* Player Management */
	void addPlayer(username player);
	void removePlayer(username player);

	roomId getRoomInDirection(Direction d) const;
	Door getDoor(Direction d) const;

	/* NPC management */
	void addNpc(npcId npc);
	void removeNpc(npcId npc);

	/* Object management */
	void addItem(itemId item);
	void removeItem(itemId item);

};//Room class

#endif