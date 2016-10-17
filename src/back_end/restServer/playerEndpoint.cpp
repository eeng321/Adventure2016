//
// Created by michael on 10/10/16.
//

#include <sstream>
#include <iostream>
#include "playerEndpoint.h"
#include "parser.h"
#include "playerDriver.h"
#include <boost/algorithm/string.hpp>

using namespace std;
using namespace Net;


void PlayerEndpoint::login(const Rest::Request& request, Net::Http::ResponseWriter response) {
    cout << "Request for resource: " << request.method() << request.resource() << endl;

    string accountInfo(request.body());
    vector<string> inputs;
    boost::split(inputs, accountInfo, boost::is_any_of("?=&"));
    //print for testing
    // for(int i = 0; i<inputs.size(); i++){
    //     cout << inputs[i] << endl;
    // }
    // cout << inputs[2] << " " << inputs[4] << endl;
    // Verify credentials with DB.
    PlayerModel player = verifyCredentials(inputs[2], inputs[4]);

    if (player.loginName == inputs[2]) {
        response.send(Http::Code::Ok, parser::playerSerialize(player));
    }
    else {
        response.send(Http::Code::Forbidden);
    }
}

void PlayerEndpoint::registerPlayer(const Rest::Request& request, Net::Http::ResponseWriter response) {
    cout << "Request for resource: " << request.method() << request.resource() << endl;

    string accountInfo(request.body());
    vector<string> inputs;
    boost::split(inputs, accountInfo, boost::is_any_of("?=&"));
    
    PlayerModel player = registerAccount(inputs[2], inputs[4]);

    if (player.loginName == inputs[2]) {
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

    if (modifyPlayer(playerId, updateFields)) {
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
