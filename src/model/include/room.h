//room.h
#ifndef ROOM_H
#define ROOM_H

#include <string>
#include <vector>
#include <memory>
#include "door.h"

using description = std::string;
using username = std::string;

class RoomModel;

class Room {//Tile interface
private:
//	std::string area;
//	id roomId;
//	std::string name;
//	description mainDescription;
//	std::vector<description> extendedDescriptions;
//	std::vector<Door> doors;
//	std::vector<id> npcList;
//	std::vector<std::string> playerList;
//	std::vector<id> objectList;
//	bool navigable;

	std::unique_ptr<RoomModel> model;

public:

	~Room();

	Room();

	Room(const std::string &areaIn,
		 id roomIdIn,
		 const std::string &nameIn,
		 const description &descriptionIn,
		 const std::vector<description> &extendedDescriptionIn,
		 const std::vector<Door> &doorsIn,
		 const std::vector<id> &npcListIn,
		 const std::vector<username> playerListIn,
		 const std::vector<id> &itemListIn,
		 bool navigabilityIn);

	Room(const std::string &areaIn,
		 const description &descriptionIn,
		 const std::vector<description> &extendedDescriptionIn,
		 id roomIdIn,
		 const std::string &nameIn,
		 const std::vector<Door> &doorsIn);

//	void build(const std::string &a,
//		 id rid,
//		 const std::string &n,
//		 const description &des,
//		 const std::vector<description> &ed,
//		 const std::vector<Door> &d,
//		 const std::vector<id> &nl,
//		 const std::vector<std::string> pl,
//		 const std::vector<id> &ol,
//		 bool nav);
//
//	void build(const std::string &a,
//		 const description &d,
//		 const std::vector<description> &ed,
//		 id idIn,
//		 const std::string &nameIn,
//		 const std::vector<Door> &doorsIn);

	/* Getters */
	std::string getArea() const;
	description getDescription() const;
	id getId() const;
	std::string getName() const;
	std::vector<description> getExtendedDescriptions() const;
	std::vector<Door> getDoors() const;
	std::vector<id> getNpcList() const;
	std::vector<username> getPlayerList() const;
	std::vector<id> getObjectList() const;

	/* Navigation management */
	void makeUnnavigable();
	void makeNavigable();
	bool isNavigable() const;

	/* Player Management */
	void addPlayer(username player);
	void removePlayer(username player);

//	bool canMove(Direction d);
	id getDoorId(Direction d);

	/* NPC management */
	void addNpc(id npc);
	void removeNpc(id npc);

	/* Object management */
	void addObject(id object);
	void removeObject(id object);


};//Room class

#endif