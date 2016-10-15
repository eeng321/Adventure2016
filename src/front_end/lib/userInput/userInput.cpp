//Menu Code based off of example http://techlister.com/linux/creating-menu-with-ncurses-in-c/1293/

#include <display.h>
#include <string.h>
#include <unistd.h>
#include "userInput.h"
#include <iostream>


void UserInput::checkExistingPlayerCredentials(char *command, char *username, char *password) {
    Display::clearMainWinDisplay();

    Display::addStringToMainWindow("Please input your username:");
    Display::getUserInput(command);
    strcpy(username, command);

    Display::addStringToMainWindow("Please input your password:");
    Display::getUserInput(command);
    strcpy(password, command);

    Display::addStringToMainWindow(username);
    Display::addStringToMainWindow(password);
    sleep(3); //TEMPORARY
}

void UserInput::createNewPlayerCredentials(char *command, char *username, char *password) {
    //TODO: Where do we store this information?
    //TODO: How do we pass this information?
}