//
// Created by braden on 24/11/16.
//

#include "spawn.h"
#include "../../include/Controller.h"
#include "display.h"

#include <iostream>

using std::vector;
using std::string;
using question = string;

const question question1 = "Would you prefer to have a) many enemies or b) few enemies? (please answer with \"a\" or \"b\")";
const question question2 = "Do you want to interact with a) wizards and assassins or b) small happy creatures? (please answer with \"a\" or \"b\")";
const question question3 = "Are you interested in guilds? a) Yes, b) No (please answer with \"a\" or \"b\")\n";

const string invalidResponse = "Invalid answer, please respond with a or b";
const string midgaardMessage = "You have spawned into midgaard, a realm of magic and fantasy.\n";
const string smurfMessage = "You have spawned into smurf village, the home of the happy, peaceful smurfs.\n";
const string failedToSpawnMessage = "Sorry, you were unable to spawn. Please try again.";

const roomId midgaardLocation = roomId(3001);
const roomId smurfLocation = roomId(101);

void Spawn::initialSpawn() {
    vector<question> questions;
    questions.push_back(question1);
    questions.push_back(question2);
    questions.push_back(question3);

    int midgaard = 0;
    int smurf = 0;
    Region answer;
    for (const question &q : questions) {
        Display::addStringToMainWindow(q.c_str());
        answer = getAnswer();

        if (answer == Region::midgaard) {
            midgaard++;
        } else {
            smurf++;
        }
    }

    if (midgaard > smurf) {
        spawnPlayer(roomId(midgaardLocation), midgaardMessage);//spawn in midgaar
    } else {
        spawnPlayer(roomId(smurfLocation), smurfMessage);//spawn in smurf
    }
}

void Spawn::spawnPlayer(const roomId& room, const string& message){
    StatusCode returnCode = Controller::moveToRoom(room);
//    TODO status code checking
//    if (returnCode != STATUS_OK) {
//        Display::addStringToMainWindow(failedToSpawnMessage.c_str());
//    } else {
//        Display::addStringToMainWindow(message.c_str());
//    }
    Display::addStringToMainWindow(message.c_str());
}

Region Spawn::getAnswer(){
    char response[MAX_CHAR_LIMIT];
    while(true){//loop till valid input is entered
        Display::readUserInput(response);
        std::string strResponse{response};
        if(strResponse.size() > 1){
            Display::addStringToMainWindow(invalidResponse.c_str());
        } else if (std::tolower(response[0]) == 'a') {
            return Region::midgaard;
        } else if ( std::tolower(response[0]) == 'b'){
            return Region::smurf_village;
        } else {
            Display::addStringToMainWindow(invalidResponse.c_str());
        }
    }
}