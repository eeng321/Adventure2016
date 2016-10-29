//
// Created by braden on 22/10/16.
//

#ifndef ID_H
#define ID_H

class Id{
public:
	int value;
	Id(int id);
};

class playerId : public Id {
public:
	playerId(int id);
	bool operator==(const playerId& arg);
};

class itemId : public Id {
public:
	itemId(int id);
	bool operator==(const itemId& arg);
};

class npcId : public Id {
public:
	npcId(int id);
	bool operator==(const npcId& arg);
};

class roomId : public Id {
public:
	roomId(int id);
	bool operator==(const roomId& arg);
};


#endif //ID_H
