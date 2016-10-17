//
// Created by michael on 10/10/16.
//

#include <sstream>
#include <iostream>
#include "playerEndpoint.h"
#include "parser.h"
#include "playerDriver.h"

using namespace std;
using namespace Net;


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
    PlayerModel player = verifyCredentials(parseBody[3], parseBody[7]);

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
    PlayerModel player = registerAccount(parseBody[3], parseBody[7]);

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
