//room.h
#ifndef ROOM_H
#define ROOM_H

#include <string>
#include <vector>

using std::string;
using std::vector;

enum class Direction{north, south, east, west};

// class ID {
// public:
// 	int value;
// 	ID(){}
// 	ID(const ID& in):value(in.value){}
// };
typedef int id;

typedef string description;

typedef string username;

// class Description {
// public:
// 	string value;
// 	Description();
// 	Description(const Description& d):value(d.value){}
// };

class Door {
public:
	Direction direction;
	vector<string> keywords;
	id doorId;
	Door(){}
	Door(const Door& d):direction(d.direction), keywords(d.keywords), doorId(d.doorId){}
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

	void addPlayer(username player);
	void removePlayer(username player);
	int indexInRoom(username player);

public:

	~Room();
	Room(const description& d, 
		const vector<description>& ed, 
		id idIn, 
		const string& nameIn, 
		const vector<Door>& doorsIn);

	string getArea() const;
	description getDescription() const;
	id getId() const;
	string getName() const;
	vector<description> getExtendedDescriptions() const;
	vector<Door> getDoors() const;
	vector<id> getNpcList() const;
	vector<username> getPlayerList() const;
	vector<id> getObjectList() const;


	void makeUnnavigable();
	void makeNavigable();
	bool isNavigable() const;


	void enterRoom(username player);
	void exitRoom(username player);
	bool canMove(Direction d);

};//Room class

#endif