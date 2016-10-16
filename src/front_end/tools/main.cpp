#include "userInput.h"
#include "RestClient.h"
#include <iostream>
#include <ncurses.h>
#include "display.h"
#include "Controller.h"

int main() {
    auto loginMode = Display::createLoginMenu();
    if(loginMode == LOGIN_MENU_SELECTION) {
        UserInput::checkExistingPlayerCredentials();
        //TODO: Now that we have the credentials, check to see if they are in the database
    }else if(loginMode == NEW_ACCOUNT_MENU_SELECTION){
        UserInput::createNewPlayerCredentials();
        //TODO: Store credentials somewhere and put them in database to access later
    }

    endwin();
    return 0;
}
