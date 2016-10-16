//
// Created by michael on 10/10/16.
//

#include "playerEndpoint.h"
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
    vector< hiberlite::bean_ptr<Player> > v=db.getAllBeans<Player>();
    cout << "found " << v.size() << " players in the database:\n";

    for(size_t j=0;j<v.size();j++){
        cout << "[username = " << v[j]->loginName << "     ";
        cout << "[coordinate = " << v[j]->coordinate << "     ";
        cout << "id = " << v[j]->playerId << "]\n";
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
