//room.h


#include <string>
#include <vector>

using std::string;
using std::vector;

enum class Direction{north, south, east, west};

struct ID {
	int value;
};

struct Description {
	string value;
};

struct Door {
	Direction direction;
	vector<string> keywords;
	int id;
};


class Room {//Tile interface
private:
	ID id;
	string name;
	Description description;
	vector<Description> extendedDescriptions;
	vector<ID> npcList;
	vector<string> playerList;
	vector<ID> objectList;
	bool navigable;

	void addPlayer(string username);
	void removePlayer(string username);
	bool indexInRoom(string username);

public:

	~Room();
	Room(const Description& d, 
		const vector<Description>& ed, 
		ID idIn, 
		const string& nameIn, 
		const vector<Door>& doorsIn);

	Room(const Room& r);
	string getDescription() const;
	int getId() const;
	void makeUnnavigable();
	void makeNavigable();
	bool isNavigable() const;
	vector<ID> getNpcList() const;
	vector<ID> getPlayerList() const;

	void enterRoom(string username);
	void exitRoom(string username);
	bool canMove(Direction d);

};//Room class

