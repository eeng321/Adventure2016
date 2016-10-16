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

void printPlayer(Player player){
    cout << "NAME: " << player.loginName << endl;
    cout << "ID: " << player.playerId << endl;
    cout << "COORDINATE: " << player.coordinate << endl;
    cout << "HEALTH: " << player.health << endl;
}

void createDB(){
    hiberlite::Database db("player.db");
    //register bean classes
    db.registerBeanClass<Player>();
    db.registerBeanClass<Credential>();
    //drop all tables beans will use
    db.dropModel();
    //create those tables again with proper schema
    db.createModel();

    const char* names[5]={"Stanley", "Kyle", "Eric", "Kenny", "Michael"};

    for(unsigned int i=0;i<5;i++) {
        Player demo;
        demo.loginName=names[i%5];
        demo.playerId = i+1;
        demo.coordinate = 0;
        demo.health = 100;

        hiberlite::bean_ptr<Player> p=db.copyBean(demo);   //create a managed copy of the object
    }
}

void printDB(){

    hiberlite::Database db("player.db");

    cout << string(15,'=')+"\nreading the DB\n";
    vector< hiberlite::bean_ptr<Player> > listPlayers=db.getAllBeans<Player>();
    cout << "found " << listPlayers.size() << " players in the database:\n";

    for(size_t j=0;j<listPlayers.size();j++){
        cout << "[username = " << listPlayers[j]->loginName << "     ";
        cout << "[coordinate = " << listPlayers[j]->coordinate << "     ";
        cout << "id = " << listPlayers[j]->playerId << "]\n";
    }
}

Player loadPlayer(int playerId){

    hiberlite::Database db("player.db");
    hiberlite::bean_ptr<Player> demo = db.loadBean<Player>(playerId);

    Player player;
    player.playerId = demo->playerId;
    player.loginName = demo->loginName;
    player.coordinate = demo->coordinate;
    player.health = demo->health;
    printPlayer(player);
    return player;
}

Player addPlayer(Player player){
	createDB();
	hiberlite::Database db("player.db");

	hiberlite::bean_ptr<Player> p=db.copyBean(player);
    p->playerId = p.get_id();
    player.playerId = p.get_id();
	printDB();

	return player;
}

Player modifyPlayer(int playerId, Player updateFields){
	hiberlite::Database db("player.db");
	hiberlite::bean_ptr<Player> editPlayer = db.loadBean<Player>(playerId);

    // editPlayer->loginName = updateFields.loginName;
    // editPlayer->id = updateFields.id;
    editPlayer->coordinate = updateFields.coordinate;
	editPlayer->health = updateFields.health;
	return loadPlayer(playerId); //this will print the player
}

void removePlayer(int playerId){
	hiberlite::Database db("player.db");
	hiberlite::bean_ptr<Player> player = db.loadBean<Player>(playerId);
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
        response.send(Http::Code::Ok, "Success. Returns the retrieved player YAML");
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

    auto success = true;
    if (success) {
        response.send(Http::Code::Ok, "Success. Returns the retrieved player YAML");
    }
    else {
        response.send(Http::Code::Forbidden);
    }
}

void PlayerEndpoint::createPlayer(const Rest::Request& request, Net::Http::ResponseWriter response) {
    cout << "Request for resource: " << request.method() << request.resource() << endl;

    // Parse body to grab player arguments
    Player player;
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

    Player demo = loadPlayer(playerId);
    string player = to_string(demo.playerId) + ", " + demo.loginName + ", " + to_string(demo.health) + "\n ";

    auto success = true;

    if (success) {
        response.send(Http::Code::Ok, "yes");
    }
    else {
        response.send(Http::Code::Bad_Request);
    }
}

void PlayerEndpoint::updatePlayer(const Rest::Request& request, Net::Http::ResponseWriter response) {
    cout << "Request for resource: " << request.method() << request.resource() << endl;

    auto playerId = request.param(":id").as<int>();
    Player updateFields = parser::playerDeserialize(request.body());
   	Player player = modifyPlayer(playerId, updateFields);

    auto success = true;
    if (success) {
        response.send(Http::Code::Ok, "Success. Returns Updated Player Yaml.");
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
