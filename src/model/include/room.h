//room.h
#ifndef ROOM_H
#define ROOM_H

#include <string>
#include <vector>

enum class Direction{north, south, east, west};

typedef int id;

typedef std::string description;

typedef std::string username;

struct Door {
public:
	Direction direction;
	std::vector<std::string> keywords;
	id doorId;
};


class Room {//Tile interface
private:
	std::string area;
	id roomId;
	std::string name;
	description mainDescription;
	std::vector<description> extendedDescriptions;
	std::vector<Door> doors;
	std::vector<id> npcList;
	std::vector<std::string> playerList;
	std::vector<id> objectList;
	bool navigable;

public:

	~Room();

	Room(const std::string& a,
		id rid,
		const std::string& n,
		const description& des,
		const std::vector<description>& ed,
		const std::vector<Door>& d,
		const std::vector<id>& nl,
		const std::vector<std::string> pl,
		const std::vector<id>& ol,
		bool nav);

	Room(const std::string& a,
		const description& d, 
		const std::vector<description>& ed,
		id idIn, 
		const std::string& nameIn,
		const std::vector<Door>& doorsIn);

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
	bool canMove(Direction d);

    /* NPC management */
	void addNpc(id npc);
    void removeNpc(id npc);

    /* Object management */
    void addObject(id object);
    void removeObject(id object);



};//Room class

#endif