#include "userInput.h"
#include "RestClient.h"
#include <iostream>
#include <ncurses.h>
#include "display.h"
#include "Controller.h"

int main() {
    bool keepPlaying = true;

    int loginMode = Display::createLoginMenu();
    if(loginMode == LOGIN_MENU_SELECTION) {
        UserInput::checkExistingPlayerCredentials();

    }else if(loginMode == NEW_ACCOUNT_MENU_SELECTION){
       UserInput::createNewPlayerCredentials();
       //TODO: Store credentials somewhere and put them in database to access later
    }

    while(keepPlaying) {
       if(UserInput::readBasicInput() == STATUS_QUIT){
           keepPlaying = false;
       }
    }

    Display::destroyMainWindow();
    endwin();
    return 0;
}
