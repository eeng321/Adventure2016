#include "playerDriver.h"
#include "credential.h"
#include "../../model/include/npcModel.h"
#include "../../model/include/itemModel.h"
//#include "../../model/include/npcModel.h"
#include <iostream>

using namespace std;
//hiberlite::Database db("AdventureDatabase.db");


void printPlayer(PlayerModel player){
    cout << "NAME: " << player.loginName << endl;
    cout << "ID: " << player.playerId << endl;
    cout << "COORDINATE: " << player.roomId << endl;
    cout << "HEALTH: " << player.health << endl;
}

void createPlayerDB(){
    hiberlite::Database db("AdventureDatabase.db");
    //register bean classes
    db.registerBeanClass<PlayerModel>();
    db.registerBeanClass<Credential>();
    db.registerBeanClass<NpcModel>();
    db.registerBeanClass<ItemModel>();
    //drop all tables beans will use
    db.dropModel();
    //create those tables again with proper schema
    db.createModel();
}

void printPlayerDB(){

    hiberlite::Database db("AdventureDatabase.db");

    cout << string(15,'=')+"\nreading the DB\n";

    vector< hiberlite::bean_ptr<PlayerModel> > listPlayers=db.getAllBeans<PlayerModel>();
    cout << "found " << listPlayers.size() << " players in the database:\n";

    for(size_t j=0;j<listPlayers.size();j++){
        cout << "[username = " << listPlayers[j]->loginName << "     ";
        cout << "[coordinate = " << listPlayers[j]->roomId << "     ";
        cout << "id = " << listPlayers[j]->playerId << "]\n";
    }
}

// void printPlayer(PlayerModel player){
//     cout << "NAME: " << player.loginName << endl;
//     cout << "ID: " << player.playerId << endl;
//     cout << "COORDINATE: " << player.roomId << endl;
//     cout << "HEALTH: " << player.health << endl;
// }

// void createPlayerDB(){
//     hiberlite::Database db("AdventureDatabase.db");
//     //register bean classes
//     db.registerBeanClass<PlayerModel>();
//     db.registerBeanClass<Credential>();
//     db.registerBeanClass<NpcModel>();
//     //drop all tables beans will use
//     db.dropModel();
//     //create those tables again with proper schema
//     db.createModel();
// }

// void printPlayerDB(){

//     hiberlite::Database db("AdventureDatabase.db");

//     cout << string(15,'=')+"\nreading the DB\n";

//     vector< hiberlite::bean_ptr<PlayerModel> > listPlayers=db.getAllBeans<PlayerModel>();
//     cout << "found " << listPlayers.size() << " players in the database:\n";

//     for(size_t j=0;j<listPlayers.size();j++){
//         cout << "[username = " << listPlayers[j]->loginName << "     ";
//         cout << "[coordinate = " << listPlayers[j]->roomId << "     ";
//         cout << "id = " << listPlayers[j]->playerId << "]\n";
//     }
// }


PlayerModel loadPlayer(int playerId){

    hiberlite::Database db;
    db.open("AdventureDatabase.db");
    hiberlite::bean_ptr<PlayerModel> loadedPlayer = db.loadBean<PlayerModel>(playerId);

    PlayerModel player;
    player.playerId = loadedPlayer->playerId;
    player.loginName = loadedPlayer->loginName;
    player.roomId = loadedPlayer->roomId;
    player.health = loadedPlayer->health;
    db.close();
    //printPlayer(player);
    return player;
}

PlayerModel addPlayer(PlayerModel player){
    hiberlite::Database db;
    db.open("AdventureDatabase.db");

    hiberlite::bean_ptr<PlayerModel> p = db.copyBean(player);
    p->playerId = p.get_id();
    player.playerId = p.get_id();
    p.save();
    db.close();
    return player;
}

PlayerModel modifyPlayer(int playerId, PlayerModel updateFields){
    hiberlite::Database db;
    db.open("AdventureDatabase.db");
    hiberlite::bean_ptr<PlayerModel> editPlayer = db.loadBean<PlayerModel>(playerId);

    editPlayer->roomId = updateFields.roomId;
    editPlayer->health = updateFields.health;
    editPlayer.save();
    db.close();
    return loadPlayer(playerId);
}

success removePlayer(int playerId){
    hiberlite::Database db;
    db.open("AdventureDatabase.db");
    hiberlite::bean_ptr<PlayerModel> player = db.loadBean<PlayerModel>(playerId);
    hiberlite::bean_ptr<Credential> account = db.loadBean<Credential>(playerId);
    vector< hiberlite::bean_ptr<PlayerModel> > listPlayers=db.getAllBeans<PlayerModel>();
    int numOfPlayers = listPlayers.size();
    player.destroy();
    account.destroy();
    db.close();
    //printPlayerDB();
    //return true if number of players in db changes after deleting
    return (numOfPlayers != listPlayers.size());
    
}

PlayerModel verifyCredentials(string username, string pw){
    hiberlite::Database db;
    db.open("AdventureDatabase.db");
    //db.registerBeanClass<Credential>();

    vector< hiberlite::bean_ptr<Credential> > listAccounts = db.getAllBeans<Credential>();

    //go through credentials return player if a match is found
    for(size_t j=0;j<listAccounts.size();j++){
        if(listAccounts[j]->player.loginName == username){
            if(listAccounts[j]->password == pw){
                return loadPlayer(listAccounts[j]->player.playerId);
            }
        }
    }
    PlayerModel player;
    player.loginName = "";
    db.close();
    return player; //will give error
}

PlayerModel registerAccount(string username, string pw){
    hiberlite::Database db;
    db.open("AdventureDatabase.db");
    //db.registerBeanClass<Credential>();
    //create player model to be added into database
    Credential account;
    PlayerModel newPlayer;
    newPlayer.loginName = "";
    //check if username already exists
    vector< hiberlite::bean_ptr<Credential> > listAccounts = db.getAllBeans<Credential>();
    for(size_t j=0;j<listAccounts.size();j++){
        if(listAccounts[j]->player.loginName == username){
            //found existing user with same name
            return newPlayer; //return empty player object will return http error
        }
    }
    newPlayer.roomId = 0;
    newPlayer.loginName = username;
    newPlayer.health = 100;
    //username unused, create player
    account.player = addPlayer(newPlayer);
    account.password = pw;
    //add account to Credential table
    hiberlite::bean_ptr<Credential> p=db.copyBean(account);
    db.close();
    return account.player;
}
