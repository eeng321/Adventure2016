#include "../../model/include/roomModel.h"
#include <string>
#include <parser.h>

void printRoom(RoomModel room);
void createRoomDB();
void printRoomDB();

RoomModel loadRoom(int roomId);
RoomModel addRoom(RoomModel room);
RoomModel modifyRoom(int roomId, RoomModel updateFields);
bool removeRoom(int roomId);