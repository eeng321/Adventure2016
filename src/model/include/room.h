//room.h
#ifndef ROOM_H
#define ROOM_H

#include <string>
#include <vector>
#include <memory>

#include "door.h"
#include "id.h"
#include "extendedDescription.h"

class RoomModel;

class Room {
private:
	std::string area;
	roomId id;
	std::string name;
	std::vector<std::string> mainDescription;
	std::vector<extendedDescription> extendedDescriptions;
	std::vector<Door> doors;
	std::vector<npcId> npcList;
	std::vector<std::string> playerList;
	std::vector<itemId> itemList;
	bool navigable;

public:

	Room();

	Room(const std::string& areaIn,
		 const roomId& idIn,
		 const std::string& nameIn,
		 const std::vector<std::string>& descriptionIn,
		 const std::vector<extendedDescription>& extendedDescriptionsIn,
		 const std::vector<Door>& doorsIn,
		 const std::vector<npcId>& npcListIn,
		 const std::vector<std::string>& playerListIn,
		 const std::vector<itemId>& itemListIn,
		 bool navigabilityIn);

	Room(const std::string& areaIn,
		 const roomId& idIn,
		 const std::string& nameIn,
		 const std::vector<std::string>& descriptionIn,
		 const std::vector<extendedDescription>& extendedDescriptionsIn,
		 const std::vector<Door>& doorsIn);

	void build(const std::string& areaIn,
			   const roomId& idIn,
			   const std::string& nameIn,
			   const std::vector<std::string>& descriptionIn,
			   const std::vector<extendedDescription>& extendedDescriptionIn,
			   const std::vector<Door>& doorsIn,
			   const std::vector<npcId>& npcListIn,
			   const std::vector<std::string>& playerListIn,
			   const std::vector<itemId>& itemListIn,
			   bool navigabilityIn);

	void build(const std::string& areaIn,
			   const roomId& idIn,
			   const std::string& nameIn,
			   const std::vector<std::string>& descriptionIn,
			   const std::vector<extendedDescription>& extendedDescriptionIn,
			   const std::vector<Door>& doorsIn,
			   bool navigabilityIn);

	void setModel(const Room& model);
	Room getModel() const;

	std::string getArea() const;
	std::vector<std::string> getDescription() const;
	roomId getId() const;
	std::string getName() const;
	std::vector<extendedDescription> getExtendedDescriptions() const;
	std::vector<std::string> getExtendedDescriptionByKey(std::string key) const;
	std::vector<Door> getDoors() const;
	std::vector<npcId> getNpcList() const;
	std::vector<std::string> getPlayerList() const;
	std::vector<itemId> getItemList() const;

	/* Navigation management */
	void makeUnnavigable();
	void makeNavigable();
	bool isNavigable() const;

	/* Player Management */
	void addPlayer(std::string player);
	void removePlayer(std::string player);

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