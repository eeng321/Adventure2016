//
// Created by braden on 24/11/16.
//

#ifndef ADVENTURE2016_SPAWN_H
#define ADVENTURE2016_SPAWN_H

#include "../../model/include/id.h"

enum class Region{midgaard, smurf_village};

void determineSpawnLocation();
Region getAnswer();
void spawnPlayer(const roomId& id, const std::string& message);

#endif //ADVENTURE2016_SPAWN_H
