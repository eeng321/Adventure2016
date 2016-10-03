#include <ncurses.h>
#include "userInput.h"
#include "display.h"

int
main() {
    char command[MAX_CHAR_LIMIT];
    char username[MAX_CHAR_LIMIT];
    char password[MAX_CHAR_LIMIT];

    int loginMode = Display_createLoginMenu();
    if(loginMode == LOGIN_MENU_SELECTION) {
        checkExistingPlayerCredentials(command, username, password);
        //TODO: Now that we have the credentials, check to see if they are in the database
    }else if(loginMode == NEW_ACCOUNT_MENU_SELECTION){
        createNewPlayerCredentials(command, username, password);
        //TODO: Store credentials somewhere and put them in database to access later
    }

    endwin();
    return 0;
}
