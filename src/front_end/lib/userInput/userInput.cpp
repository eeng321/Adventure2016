//Menu Code based off of example http://techlister.com/linux/creating-menu-with-ncurses-in-c/1293/

#include "../../include/Controller.h"
#include <display.h>
#include "userInput.h"
#include <iostream>

void UserInput::checkExistingPlayerCredentials() {

    char username[MAX_CHAR_LIMIT];
    char password[MAX_CHAR_LIMIT];
    std::string loginResult;
    std::string message;
    bool loggedIn = false;


    Display::clearMainWinDisplay();
    while (!loggedIn) {
        Display::addStringToMainWindow("Please input your username:");
        Display::readUserInput(username);

        Display::addStringToMainWindow("Please input your password:");
        Display::readUserInput(password);

        if (Controller::logIn(username, password, loginResult) != STATUS_OK) {
            Display::addStringToMainWindow("You have input the wrong username or password. Please try again.");
        } else {
            Display::clearMainWinDisplay();
            Display::addStringToMainWindow("You have logged in!");
            Display::addStringToMainWindow("Welcome to the game world! Type in your commands!");
            loggedIn = true;
        }
    }
}

void UserInput::createNewPlayerCredentials() {
    char username[MAX_CHAR_LIMIT];
    char password[MAX_CHAR_LIMIT];
    char passwordRepeat[MAX_CHAR_LIMIT];
    bool passwordMatches = false;
    bool loggedIn = false;
    std::string loginResult;

    while (!loggedIn) {
        Display::clearMainWinDisplay();
        Display::addStringToMainWindow("Please input your username:");
        Display::readUserInput(username);
        while (!passwordMatches) {
            Display::addStringToMainWindow("Please input your password:");
            Display::readUserInput(password);

            Display::addStringToMainWindow("Please input your password again:");
            Display::readUserInput(passwordRepeat);

            if (strcmp(password, passwordRepeat) != 0) {
                Display::addStringToMainWindow("Your passwords do not match.");
            } else {
                passwordMatches = true;
            }
        }
        if(Controller::registerAccount(username, password, loginResult) == STATUS_USER_EXISTS) {
            Display::addStringToMainWindow("Sorry that username is already taken, please try again with a different username.");
        } else if(Controller::registerAccount(username, password, loginResult) != STATUS_OK) {
            Display::addStringToMainWindow("Sorry, creating a new account did not work. Please try again.");
        } else {
            Display::clearMainWinDisplay();
            Display::addStringToMainWindow("You have logged in!");
            Display::addStringToMainWindow("Welcome to the game world! Type in your commands!");
            loggedIn = true;
        }
    }

}

StatusCode UserInput::readBasicInput() {
    char command[MAX_CHAR_LIMIT];
    std::string queryStringResult;
    Display::readUserInput(command);
    std::string commandConverted(command);
    StatusCode queryReturnCode = Controller::parseCommand(commandConverted, queryStringResult);
    strcpy(command, queryStringResult.c_str());
    Display::addStringToMainWindow(command);
    return queryReturnCode;
}