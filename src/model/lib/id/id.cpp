#include "id.h"

Id::Id(int id)
:value(id) {}

playerId::playerId(int id)
:Id(id) {}

itemId::itemId(int id)
:Id(id) {}

roomId::roomId(int id)
:Id(id) {}

npcId::npcId(int id)
:Id(id) {}

bool playerId::operator==(const playerId& arg){
	return this->value == arg.value;
}

bool itemId::operator==(const itemId& arg){
	return this->value == arg.value;
}

bool roomId::operator==(const roomId& arg){
	return this->value == arg.value;
}

bool npcId::operator==(const npcId& arg){
	return this->value == arg.value;
}
