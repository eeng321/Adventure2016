//
// Created by michael on 10/10/16.
//

#include "playerEndpoint.h"
#include <sstream>
#include <iostream>
#include "../lib/pistache/include/client.h"
#include "../lib/pistache/include/endpoint.h"
#include "../lib/hiberlite/include/hiberlite.h"
#include "../../model/include/player.h"

using namespace std;
using namespace Net;


void createDB(){
    hiberlite::Database db("player.db");
    //register bean classes
    db.registerBeanClass<Player>();
    //drop all tables beans will use
    db.dropModel();
    //create those tables again with proper schema
    db.createModel();

    const char* names[5]={"Stanley", "Kyle", "Eric", "Kenny", "Michael"};

    for(unsigned int i=0;i<5;i++) {
        Player demo;
        demo.login_name=names[i%5];
        demo.id = i+1;
        demo.health = 100;

        hiberlite::bean_ptr<Player> p=db.copyBean(demo);   //create a managed copy of the object
    }
}

void printDB(){

    hiberlite::Database db("player.db");

    cout << string(15,'=')+"\nreading the DB\n";
    vector< hiberlite::bean_ptr<Player> > v=db.getAllBeans<Player>();
    cout << "found " << v.size() << " players in the database:\n";

    for(size_t j=0;j<v.size();j++){
        cout << "[username = " << v[j]->login_name << "     ";
        cout << "id = " << v[j]->id << "]\n";
    }
}

Player loadPlayer(int playerId){
	
    hiberlite::Database db("player.db");
    hiberlite::bean_ptr<Player> demo = db.loadBean<Player>(playerId);

    Player player;
    player.id = demo->id;
    player.login_name = demo->login_name;
    player.health = demo->health;
    return player;
}

Player addPlayer(int playerId, string name){
	createDB();
	hiberlite::Database db("player.db");

	Player player;
	player.id = playerId;
	player.login_name = name;
	player.health = 100;
	hiberlite::bean_ptr<Player> p=db.copyBean(player);
	printDB();

	return player;
}

Player modifyPlayer(int playerId, int newHealth){
	hiberlite::Database db("player.db");
	hiberlite::bean_ptr<Player> editPlayer = db.loadBean<Player>(playerId);

	editPlayer->health = newHealth;
	return loadPlayer(playerId);
}

void removePlayer(int playerId){
	hiberlite::Database db("player.db");
	hiberlite::bean_ptr<Player> player = db.loadBean<Player>(playerId);
	player.destroy();
}

void PlayerEndpoint::login(const Rest::Request& request, Net::Http::ResponseWriter response) {
    cout << "Request for resource: " << request.method() << request.resource() << endl;

    // Verify credentials with DB.

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

    istringstream playerParams(request.body());
    int len = 8; //lines in request body
    string parseBody[len];
    //parse request.body() into string array
    for(int i = 0; i<len; i++){
    	getline(playerParams, parseBody[i]);
    }
    //index 3 and 7 contain the parameters (every 4th line)
    Player demo = addPlayer(stoi(parseBody[3]), parseBody[7]);
    cout << "Printing newly added player: \n";
    cout << demo.id << endl;
    cout << demo.login_name << endl;
    cout << demo.health << endl;
    
    
    auto success = true;
    if (success) {
        response.send(Http::Code::Created, "Success. Returns Created Player Yaml.");
    }
    else {
        response.send(Http::Code::Bad_Request);
    }
}

void PlayerEndpoint::retrievePlayer(const Rest::Request& request, Net::Http::ResponseWriter response) {
    cout << "Request for resource: " << request.method() << request.resource() << endl;

    auto playerId = request.param(":id").as<int>();

    Player demo = loadPlayer(playerId);
    string player = to_string(demo.id) + ", " + demo.login_name + ", " + to_string(demo.health) + "\n ";

    auto success = true;

    if (success) {
        response.send(Http::Code::Ok, player);
    }
    else {
        response.send(Http::Code::Bad_Request);
    }
}

void PlayerEndpoint::updatePlayer(const Rest::Request& request, Net::Http::ResponseWriter response) {
    cout << "Request for resource: " << request.method() << request.resource() << endl;

    auto playerId = request.param(":id").as<int>();
    int parsedHealth = 90; //parse health input from request.body()
    //no yaml parser yet
   	Player player = modifyPlayer(playerId, parsedHealth);

    auto success = true;
    if (success) {
        response.send(Http::Code::Ok, "Success. Returns Updated Player Yaml.");
    }
    else {
        response.send(Http::Code::No_Content);
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
        response.send(Http::Code::No_Content);
    }
}