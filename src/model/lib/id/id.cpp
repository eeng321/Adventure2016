#include "id.h"

ID::ID(int id)
:value(id) {}

playerID::playerID(int id)
:ID(id) {}

itemID::itemID(int id)
:ID(id) {}

roomID::roomID(int id)
:ID(id) {}

npcID::npcID(int id)
:ID(id) {}

bool playerID::operator==(const playerID& arg){
	return this->value == arg.value;
}

bool itemID::operator==(const itemID& arg){
	return this->value == arg.value;
}

bool roomID::operator==(const roomID& arg){
	return this->value == arg.value;
}

bool npcID::operator==(const npcID& arg){
	return this->value == arg.value;
}
