#include <ncurses.h>
#include "userInput.h"

#define MAX_CHAR_LIMIT 500

int
main() {
    initscr();
    scrollok(stdscr, TRUE); //allows for screen scrolling
//    keypad(stdstr, TRUE);  //only needed if needs special keys

    char command[MAX_CHAR_LIMIT];

    char username[MAX_CHAR_LIMIT];
    char password[MAX_CHAR_LIMIT];


    //accountOrLoginMenu(command);
    //TODO:
    //Create an actual menu for the login screen
    checkPlayerCredentials(command, username, password);
    //TODO:
    // Now that we have the credentials, check to see if they are in the database


    getch();
    endwin();
    return 0;
}
