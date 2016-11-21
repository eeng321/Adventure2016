#include "initializeDB.h"

void initializeDB(){
    hiberlite::Database db("AdventureDatabase.db");
    //register bean classes
    db.registerBeanClass<PlayerModel>();
    db.registerBeanClass<Credential>();
    db.registerBeanClass<NpcModel>();
    db.registerBeanClass<ItemModel>();
    db.registerBeanClass<RoomModel>();
    db.registerBeanClass<DoorModel>();
    //drop all tables beans will use
    db.dropModel();
    //create those tables again with proper schema
    db.createModel();
}