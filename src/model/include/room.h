//room.h
#ifndef ROOM_H
#define ROOM_H

#include <string>
#include <vector>

using std::string;
using std::vector;

enum class Direction{north, south, east, west};

typedef int id;

typedef string description;

typedef string username;

struct Door {
public:
	Direction direction;
	vector<string> keywords;
	id doorId;
};


class Room {//Tile interface
private:
	string area;
	id roomId;
	string name;
	description mainDescription;
	vector<description> extendedDescriptions;
	vector<Door> doors;
	vector<id> npcList;
	vector<string> playerList;
	vector<id> objectList;
	bool navigable;


	int indexPlayer(username player);
    int indexObject(id object);
    int indexNpc(id npc);

public:

	~Room();

	Room(const string& a,
		id rid,
		const string& n,
		const description& des,
		const vector<description>& ed,
		const vector<Door>& d,
		const vector<id>& nl,
		const vector<string> pl,
		const vector<id>& ol,
		bool nav);

	Room(const string& a,
		const description& d, 
		const vector<description>& ed, 
		id idIn, 
		const string& nameIn, 
		const vector<Door>& doorsIn);

    /* Getters */
	string getArea() const;
	description getDescription() const;
	id getId() const;
	string getName() const;
	vector<description> getExtendedDescriptions() const;
	vector<Door> getDoors() const;
	vector<id> getNpcList() const;
	vector<username> getPlayerList() const;
	vector<id> getObjectList() const;

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