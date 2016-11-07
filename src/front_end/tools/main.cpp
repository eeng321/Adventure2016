#include "RestClient.h"
#include <iostream>
#include <ncurses.h>
#include <thread>
#include "display.h"
#include "Controller.h"
#include "userInput.h"
#include "Dictionary.h"

int main() {
    bool keepPlaying = true;

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
    dictionary.insertIntoLanguageMap("regarde", "look"); //This is french for Look. Will be the test for now
    dictionary.insertIntoLanguageMap("/s", "/s");

    Display::createChatWindow();
    std::thread chat(&Display::updateChatWindow);

    while(keepPlaying) {
       if(UserInput::readBasicInput(&dictionary) == STATUS_QUIT){
           keepPlaying = false;
       }
    }
    Display::setGameFinished();
    chat.join();
    Display::destroyMainWindow();
    endwin();
    return 0;
}
