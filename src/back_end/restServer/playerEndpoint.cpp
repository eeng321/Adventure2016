//
// Created by michael on 10/10/16.
//

#include <sstream>
#include <iostream>
#include "playerEndpoint.h"
#include "credential.h"
#include "parser.h"

using namespace std;
using namespace Net;

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
	createDB();
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

    // editPlayer->loginName = updateFields.loginName;
    // editPlayer->id = updateFields.id;
    editPlayer->coordinate = updateFields.coordinate;
	editPlayer->health = updateFields.health;
	return loadPlayer(playerId); //this will print the player
}

void removePlayer(int playerId){
	hiberlite::Database db("player.db");
	hiberlite::bean_ptr<PlayerModel> player = db.loadBean<PlayerModel>(playerId);
	player.destroy();
    printDB();
}

Player verifyCredentials(string username, string pw){
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
    Player player;
    return player; //will give error
}

Player registerAccount(string username, string pw){
    hiberlite::Database db("player.db");
    db.registerBeanClass<Credential>();

    Credential account;
    Player newPlayer;
    newPlayer.coordinate = 0;
    newPlayer.loginName = username;
    newPlayer.health = 100;
    account.player = addPlayer(newPlayer);
    account.password = pw;
    //add account to Credential table
    hiberlite::bean_ptr<Credential> p=db.copyBean(account);

    return account.player;
}

void PlayerEndpoint::login(const Rest::Request& request, Net::Http::ResponseWriter response) {
    cout << "Request for resource: " << request.method() << request.resource() << endl;

    istringstream accountInfo(request.body());
    cout << request.body() << endl;
    int length = 8; //8 lines for 2 inputs (4 lines per input)
    string parseBody[length]; 
    for(int i = 0; i<length; i++){
        getline(accountInfo, parseBody[i]);
    }
    // Verify credentials with DB.
    //username = parseBody[3], password = parseBody[7]
    cout << parseBody[3] << "  " << parseBody[7] << endl;
    Player player = verifyCredentials(parseBody[3], parseBody[7]);

    if (player.loginName == parseBody[3]) {
        response.send(Http::Code::Ok, parser::playerSerialize(player));
    }
    else {
        response.send(Http::Code::Forbidden);
    }
}

void PlayerEndpoint::registerPlayer(const Rest::Request& request, Net::Http::ResponseWriter response) {
    cout << "Request for resource: " << request.method() << request.resource() << endl;

    istringstream accountInfo(request.body());
    cout << request.body() << endl;
    int length = 8; //8 lines for 2 inputs (4 lines per input)
    string parseBody[length]; 
    for(int i = 0; i<length; i++){
        getline(accountInfo, parseBody[i]);
    }
    // Verify credentials with DB.
    //username = parseBody[3], password = parseBody[7]
    cout << parseBody[3] << "  " << parseBody[7] << endl;
    Player player = registerAccount(parseBody[3], parseBody[7]);

    if (player.loginName == parseBody[3]) {
        response.send(Http::Code::Ok, parser::playerSerialize(player));
    }
    else {
        response.send(Http::Code::Forbidden);
    }
}

void PlayerEndpoint::createPlayer(const Rest::Request& request, Net::Http::ResponseWriter response) {
    cout << "Request for resource: " << request.method() << request.resource() << endl;

    // Parse body to grab player arguments
    PlayerModel player;
    player = parser::playerDeserialize(request.body());

    addPlayer(player);
    auto success = true;
    if (success) {
        response.send(Http::Code::Created, parser::playerSerialize(player));
    }
    else {
        response.send(Http::Code::Bad_Request);
    }
}

void PlayerEndpoint::retrievePlayer(const Rest::Request& request, Net::Http::ResponseWriter response) {
    cout << "Request for resource: " << request.method() << request.resource() << endl;

    auto playerId = request.param(":id").as<int>();

    PlayerModel player;
    player.loginName = "";
    player = loadPlayer(playerId);
    //string player = to_string(demo.playerId) + ", " + demo.loginName + ", " + to_string(demo.health) + "\n ";

    if (player.loginName != "") {
        response.send(Http::Code::Ok, parser::playerSerialize(player));
    }
    else {
        response.send(Http::Code::Bad_Request);
    }
}

void PlayerEndpoint::updatePlayer(const Rest::Request& request, Net::Http::ResponseWriter response) {
    cout << "Request for resource: " << request.method() << request.resource() << endl;

    auto playerId = request.param(":id").as<int>();
    PlayerModel updateFields = parser::playerDeserialize(request.body());
    PlayerModel player;
    player.health = -999;
    player = modifyPlayer(playerId, updateFields);

    if (player.health != -999) {
        response.send(Http::Code::Ok, parser::playerSerialize(player));
    }
    else {
        response.send(Http::Code::Bad_Request);
    }
}

void PlayerEndpoint::deletePlayer(const Rest::Request& request, Net::Http::ResponseWriter response) {
    cout << "Request for resource: " << request.method() << request.resource() << endl;

    auto playerId = request.param(":id").as<int>();
    removePlayer(playerId);

    auto success = true;
    if (success) {
        response.send(Http::Code::Ok);
    }
    else {
        response.send(Http::Code::Bad_Request);
    }
}
