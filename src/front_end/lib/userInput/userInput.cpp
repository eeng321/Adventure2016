//Menu Code based off of example http://techlister.com/linux/creating-menu-with-ncurses-in-c/1293/

#include <display.h>
#include "Controller.h"
#include "userInput.h"
#include <iostream>


void UserInput::checkExistingPlayerCredentials() {
    char username[MAX_CHAR_LIMIT];
    char password[MAX_CHAR_LIMIT];
    _Bool doesLoginSucceed = false;

    Display::clearMainWinDisplay();
    while (doesLoginSucceed == false) {
        Display::addStringToMainWindow("Please input your username:");
        Display::readUserInput(username);

        Display::addStringToMainWindow("Please input your password:");
        Display::readUserInput(password);

        Display::addStringToMainWindow(username);
        Display::addStringToMainWindow(password);

        if (Controller::logIn(username, password) != serverStatus.OK) {
            Display::addStringToMainWindow("You have input the wrong username or password. Please try again.");
        } else {
            Display::addStringToMainWindow("You have input the wrong username or password. Please try again.");
        }
    }
}

void UserInput::createNewPlayerCredentials() {
    char username[MAX_CHAR_LIMIT];
    char password[MAX_CHAR_LIMIT];
    char passwordRepeat[MAX_CHAR_LIMIT];
    _Bool passwordMatches = false;

    Display::clearMainWinDisplay();
    while(passwordMatches == false) {
        Display::addStringToMainWindow("Please input your username:");
        Display::readUserInput(username);

        Display::addStringToMainWindow("Please input your password:");
        Display::readUserInput(password);

        Display::addStringToMainWindow("Please input your password again:");
        Display::readUserInput(password);
    }




}