#include "id.h"

playerID::playerID(int id){
	value = id;
}

itemID::itemID(int id) {
	value = id;
}

roomID::roomID(int id) {
	value = id;
}

npcID::npcID(int id) {
	value = id;
}

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
