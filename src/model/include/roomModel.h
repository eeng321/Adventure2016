//room.h
#ifndef ROOM_MODEL_H
#define ROOM_MODEL_H

#pragma once
#include <string>
#include <vector>
//#include "door.h"
#include "../../back_end/lib/hiberlite/include/hiberlite.h"


typedef int id;

class RoomModel {//Tile interface
public:

    friend class hiberlite::access;
    template<class Archive>
    void hibernate(Archive & ar)
    {
        ar & HIBERLITE_NVP(area);
        ar & HIBERLITE_NVP(roomId);
        ar & HIBERLITE_NVP(name);
        /*ar & HIBERLITE_NVP(mainDescription);
       // ar & HIBERLITE_NVP(extendedDescriptions);
       // ar & HIBERLITE_NVP(doors);
        ar & HIBERLITE_NVP(npcList);
        ar & HIBERLITE_NVP(playerList);
        ar & HIBERLITE_NVP(itemList);
        ar & HIBERLITE_NVP(navigable); */
    }

	std::string area;
	id roomId;
	std::string name;
	std::string mainDescription; /*
	//std::vector<description> extendedDescriptions;
	//std::vector<Door> doors;
	std::vector<id> npcList;
	std::vector<std::string> playerList;
	std::vector<id> itemList;
	bool navigable;
*/
};

#endif