#include "../../model/include/roomModel.h"
#include <string>

void printRoom(RoomModel room);
void createRoomDB();
void printRoomDB();

RoomModel loadRoom(int roomId);
RoomModel addRoom(RoomModel room);
//RoomModel modifyPlayer(int playerId, PlayerModel updateFields);
//success removeRoom(int playerId);
