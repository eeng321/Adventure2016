#include "userInput.h"
#include "RestClient.h"
#include <iostream>
#include <ncurses.h>
#include "display.h"
#include "Controller.h"

int
main() {
    char command[MAX_CHAR_LIMIT];
    char username[MAX_CHAR_LIMIT];
    char password[MAX_CHAR_LIMIT];

    auto loginMode = Display::createLoginMenu();
    if(loginMode == LOGIN_MENU_SELECTION) {
        UserInput::checkExistingPlayerCredentials(command, username, password);
        //TODO: Now that we have the credentials, check to see if they are in the database
    }else if(loginMode == NEW_ACCOUNT_MENU_SELECTION){
        UserInput::createNewPlayerCredentials(command, username, password);
        //TODO: Store credentials somewhere and put them in database to access later
    }

    endwin();
    return 0;
}
