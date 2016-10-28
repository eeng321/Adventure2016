//
// Created by braden on 22/10/16.
//

#ifndef ID_H
#define ID_H

class ID{
public:
	int value;
	ID(int id);
};

class playerID : public ID {
public:
	playerID(int id);
	bool operator==(const playerID& arg);
};

class itemID : public ID {
public:
	itemID(int id);
	bool operator==(const itemID& arg);
};

class npcID : public ID {
public:
	npcID(int id);
	bool operator==(const npcID& arg);
};

class roomID : public ID {
public:
	roomID(int id);
	bool operator==(const roomID& arg);
};


#endif //ID_H
