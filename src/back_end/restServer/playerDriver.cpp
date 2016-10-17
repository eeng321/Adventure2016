#include "playerDriver.h"
#include "credential.h"
#include <iostream>

using namespace std;

void printPlayer(PlayerModel player){
    cout << "NAME: " << player.loginName << endl;
    cout << "ID: " << player.playerId << endl;
    cout << "COORDINATE: " << player.coordinate << endl;
    cout << "HEALTH: " << player.health << endl;
}

void createDB(){
    hiberlite::Database db("player.db");
    //register bean classes
    db.registerBeanClass<PlayerModel>();
    db.registerBeanClass<Credential>();
    //drop all tables beans will use
    db.dropModel();
    //create those tables again with proper schema
    db.createModel();

    const char* names[5]={"Stanley", "Kyle", "Eric", "Kenny", "Michael"};

    for(unsigned int i=0;i<5;i++) {
        PlayerModel demo;
        demo.loginName=names[i%5];
        demo.playerId = i+1;
        demo.coordinate = 0;
        demo.health = 100;

        hiberlite::bean_ptr<PlayerModel> p=db.copyBean(demo);   //create a managed copy of the object
    }
}

void printDB(){

    hiberlite::Database db("player.db");

    cout << string(15,'=')+"\nreading the DB\n";

    vector< hiberlite::bean_ptr<PlayerModel> > listPlayers=db.getAllBeans<PlayerModel>();
    cout << "found " << listPlayers.size() << " players in the database:\n";

    for(size_t j=0;j<listPlayers.size();j++){
        cout << "[username = " << listPlayers[j]->loginName << "     ";
        cout << "[coordinate = " << listPlayers[j]->coordinate << "     ";
        cout << "id = " << listPlayers[j]->playerId << "]\n";
    }
}

PlayerModel loadPlayer(int playerId){

    hiberlite::Database db("player.db");
    hiberlite::bean_ptr<PlayerModel> demo = db.loadBean<PlayerModel>(playerId);

    PlayerModel player;
    player.playerId = demo->playerId;
    player.loginName = demo->loginName;
    player.coordinate = demo->coordinate;
    player.health = demo->health;
    printPlayer(player);
    return player;
}

PlayerModel addPlayer(PlayerModel player){
	hiberlite::Database db("player.db");

    hiberlite::bean_ptr<PlayerModel> p=db.copyBean(player);
    p->playerId = p.get_id();
    player.playerId = p.get_id();
	printDB();

	return player;
}

PlayerModel modifyPlayer(int playerId, PlayerModel updateFields){
	hiberlite::Database db("player.db");
	hiberlite::bean_ptr<PlayerModel> editPlayer = db.loadBean<PlayerModel>(playerId);

    editPlayer->coordinate = updateFields.coordinate;
	editPlayer->health = updateFields.health;
    editPlayer.save();

	return loadPlayer(playerId);
}

void removePlayer(int playerId){
	hiberlite::Database db("player.db");
	hiberlite::bean_ptr<PlayerModel> player = db.loadBean<PlayerModel>(playerId);
	player.destroy();
    printDB();
}

PlayerModel verifyCredentials(string username, string pw){
    hiberlite::Database db("player.db");
    db.registerBeanClass<Credential>();

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
    return player; //will give error
}

PlayerModel registerAccount(string username, string pw){
    hiberlite::Database db("player.db");
    db.registerBeanClass<Credential>();

    Credential account;
    PlayerModel newPlayer;
    newPlayer.coordinate = 0;
    newPlayer.loginName = username;
    newPlayer.health = 100;
    account.player = addPlayer(newPlayer);
    account.password = pw;
    //add account to Credential table
    hiberlite::bean_ptr<Credential> p=db.copyBean(account);

    return account.player;
}
