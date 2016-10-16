//Menu Code based off of example http://techlister.com/linux/creating-menu-with-ncurses-in-c/1293/

#include <display.h>
#include <string.h>
#include <unistd.h>
#include "userInput.h"
#include <iostream>


void UserInput::checkExistingPlayerCredentials() {
    char command[MAX_CHAR_LIMIT];
    char username[MAX_CHAR_LIMIT];
    char password[MAX_CHAR_LIMIT];

    Display::clearMainWinDisplay();

    Display::addStringToMainWindow("Please input your username:");
    Display::readUserInput(command);
    strcpy(username, command);

    Display::addStringToMainWindow("Please input your password:");
    Display::readUserInput(command);
    strcpy(password, command);

    Display::addStringToMainWindow(username);
    Display::addStringToMainWindow(password);
    sleep(3); //TEMPORARY
}

void UserInput::createNewPlayerCredentials() {
    //TODO: Where do we store this information?
    //TODO: How do we pass this information?
}