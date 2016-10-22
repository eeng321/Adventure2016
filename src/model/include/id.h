//
// Created by braden on 22/10/16.
//

#ifndef ID_H
#define ID_H

class playerID {
public:
	playerID(int id);
	int value;
	bool operator==(const playerID& arg);
};

class itemID {
public:
	itemID(int id);
	int value;
	bool operator==(const itemID& arg);
};

class npcID {
public:
	npcID(int id);
	int value;
	bool operator==(const npcID& arg);
};

class roomID {
public:
	roomID(int id);
	int value;
	bool operator==(const roomID& arg);
};


#endif //ID_H
