//
// Created by william on 11/11/16.
//

#ifndef ADVENTURE2016_ETLJOB_H
#define ADVENTURE2016_ETLJOB_H

#include "npcDriver.h"
#include "parser.h"
#include "roomDriver.h"
#include "itemDriver.h"

namespace etl{
    void createDB();
    void LoadRoomsToDB();
    void LoadNPCsToDB();
    void LoadItemsToDB();
};


#endif //ADVENTURE2016_ETLJOB_H
