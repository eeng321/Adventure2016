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
    bool doesLoginSucceed = false;

    Display::clearMainWinDisplay();
    while (doesLoginSucceed == false) {
        Display::addStringToMainWindow("Please input your username:");
        Display::readUserInput(username);

        Display::addStringToMainWindow("Please input your password:");
        Display::readUserInput(password);

        Display::addStringToMainWindow(username);
        Display::addStringToMainWindow(password);

        if (Controller::logIn(username, password, loginResult) != STATUS_OK) {
            Display::addStringToMainWindow("You have input the wrong username or password. Please try again.");
        } else {
            Display::clearMainWinDisplay();
            Display::addStringToMainWindow("You have logged in!");
            Display::addStringToMainWindow("Welcome to the game world! Type in your commands!");
            doesLoginSucceed = true;
        }
    }
}

void UserInput::createNewPlayerCredentials() {
    char username[MAX_CHAR_LIMIT];
    char password[MAX_CHAR_LIMIT];
    char passwordRepeat[MAX_CHAR_LIMIT];
    bool passwordMatches = false;

    Display::clearMainWinDisplay();
    Display::addStringToMainWindow("Please input your username:");
    Display::readUserInput(username);
    while(passwordMatches == false) {
        Display::addStringToMainWindow("Please input your password:");
        Display::readUserInput(password);

        Display::addStringToMainWindow("Please input your password again:");
        Display::readUserInput(passwordRepeat);

        if(strcmp(password, passwordRepeat) != 0){
            Display::addStringToMainWindow("Your passwords do not match.");
        } else {
            passwordMatches = true;
        }
    }
    //TODO: hook up to register function in Controller
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