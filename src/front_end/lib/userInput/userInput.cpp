//Menu Code based off of example http://techlister.com/linux/creating-menu-with-ncurses-in-c/1293/

#include <ncurses.h>
#include <ncursesAdventure.h>
#include <string.h>
#include "userInput.h"


void getUserInput(char* command) {
    getnstr(command, 500);
}

void checkPlayerCredentials(char* command, char* username, char* password) {
    clear();
    resetCursor();

    printw("Please input your username\n");
    refresh();
    getUserInput(command);
    strcpy(username, command);

    printw("Please input your password\n");
    refresh();
    getUserInput(command);
    strcpy(password, command);

    clear();
    mvprintw(getCursorRow(), getCursorCol(), username);
    moveCursorDownOneRow();
    mvprintw(getCursorRow(), getCursorCol(), password);
    refresh();
}

void accountOrLoginMenu(char* command) {
    clear();
    resetCursor();

}