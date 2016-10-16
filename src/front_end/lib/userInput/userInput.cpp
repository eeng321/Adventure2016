//Menu Code based off of example http://techlister.com/linux/creating-menu-with-ncurses-in-c/1293/

#include <ncurses.h>
#include <display.h>
#include "Controller.h"
#include "userInput.h"
#include <iostream>

void checkExistingPlayerCredentials() {
    _Bool doesLoginSucceed = false;
    while (doesLoginSucceed == false) {
        Display::clearMainWinDisplay();

        Display::addStringToMainWindow("Please input your username:");
        Display::readUserInput(username);

        Display::addStringToMainWindow("Please input your password:");
        Display::readUserInput(password);

        Display::addStringToMainWindow(username);
        Display::addStringToMainWindow(password);

        if(Controller::logIn(username, password) != serverStatus.OK) {
            Display::addStringToMainWindow("You have input the wrong username or password. Please try again.");
        } else {
            
        }

    }
}

void createNewPlayerCredentials(char *command, char *username, char *password) {
    //TODO: Where do we store this information?
    //TODO: How do we pass this information?
}