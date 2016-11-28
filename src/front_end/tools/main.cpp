#include "RestClient.h"
#include <iostream>
#include <ncurses.h>
#include <thread>
#include "display.h"
#include "Controller.h"
#include "userInput.h"
#include "Dictionary.h"
#include <stdio.h>
#include "irrKlang/include/irrKlang.h"
using namespace irrklang;
#pragma comment(lib, "irrKlang.lib") // link with irrKlang.dll

int main(int argc, char *argv[]) {


    bool keepPlaying = true;

    //Controller ctrlr = Controller();
    if (argc >= 3) {
         Controller::server = "http://" + std::string(argv[1]) + ":" + std::string(argv[2]) + "/";
    }

    // TODO: We should have a check right away whether the user is connected to a server

    int loginMode = Display::createLoginMenu();
    if(loginMode == LOGIN_MENU_SELECTION) {
        UserInput::checkExistingPlayerCredentials();

    }else if(loginMode == NEW_ACCOUNT_MENU_SELECTION){
        UserInput::createNewPlayerCredentials();
    }

    //TODO: 100% faking the language parsing until actual parsing is done
    Dictionary dictionary;
    dictionary.insertIntoLanguageMap("north", "north");
    dictionary.insertIntoLanguageMap("south", "south");
    dictionary.insertIntoLanguageMap("west", "west");
    dictionary.insertIntoLanguageMap("east", "east");
    dictionary.insertIntoLanguageMap("help", "help");
    dictionary.insertIntoLanguageMap("who", "who");
    dictionary.insertIntoLanguageMap("where", "where");
    dictionary.insertIntoLanguageMap("take", "take");
    dictionary.insertIntoLanguageMap("look", "look");
    dictionary.insertIntoLanguageMap("talk", "talk");
    dictionary.insertIntoLanguageMap("regarde", "look"); //This is french for Look. Will be the test for now
    dictionary.insertIntoLanguageMap("/s", "/s");
    dictionary.insertIntoLanguageMap("move", "move");
    dictionary.insertIntoLanguageMap("engage", "engage");
    dictionary.insertIntoLanguageMap("attack", "attack");
    dictionary.insertIntoLanguageMap("spell", "spell");
    dictionary.insertIntoLanguageMap("piglatin", "piglatin");

    Display::createChatWindow();
    Display::createCombatWindow();
    std::thread chat(&Display::updateChatWindow);
    
    // start the sound engine with default parameters
	ISoundEngine* engine = createIrrKlangDevice();
	engine->play2D("bin/midgaard.ogg", true); //play music
	
    while(keepPlaying) {
       if(UserInput::readBasicInput(&dictionary) == STATUS_QUIT){
           keepPlaying = false;
       }
    }
    engine->drop(); // delete engine
    Display::setGameFinished();
    chat.join();
    Display::destroyMainWindow();
    endwin();
    return 0;
}
