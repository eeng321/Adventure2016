//Menu Code based off of example http://techlister.com/linux/creating-menu-with-ncurses-in-c/1293/

#include "../../include/Controller.h"
#include "userInput.h"
#include "Dictionary.h"
#include "Command.h"
#include <iostream>
#include "display.h"
#include <boost/algorithm/string/classification.hpp>
#include <boost/algorithm/string/split.hpp>

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
        }
        else {
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
            }
            else {
                passwordMatches = true;
            }
        }

        StatusCode registrationStatus = Controller::registerAccount(username, password, loginResult);
        if (registrationStatus == STATUS_USER_EXISTS) {
            Display::addStringToMainWindow("Sorry that username is already taken, please try again with a different username.");
        }
        else if (registrationStatus != STATUS_OK) {
            Display::addStringToMainWindow("Sorry, creating a new account did not work. Please try again.");
        }
        else {
            Display::clearMainWinDisplay();
            Display::addStringToMainWindow("You have logged in!");
            Display::addStringToMainWindow("Welcome to the game world! Type in your commands!");
            loggedIn = true;
        }
    }
}

StatusCode UserInput::readBasicInput(Dictionary *dictionary) {
    char commandString[MAX_CHAR_LIMIT];
    Display::readUserInput(commandString);
    std::string commandConverted(commandString);
    // boost string tokenization http://stackoverflow.com/a/5607665
    std::vector<std::string> tokens;
    boost::split(tokens, commandConverted, boost::is_any_of(" "), boost::token_compress_on);

    StatusCode queryReturnCode;
    std::string queryStringResult;
    Display::addStringToMainWindow(tokens[0].c_str());
    Command* con = dictionary->lookup(tokens[0]);
    // get rid of the command name so only the real arguments are passed
    tokens.erase(tokens.begin());
    if(con != NULL) {
        queryReturnCode = con->execute(queryStringResult, tokens);
    } else {
        queryStringResult = "We do not recognize that input, please try again!";
        queryReturnCode = STATUS_COMMAND_NOT_FOUND;
    }

    strcpy(commandString, queryStringResult.c_str());
    Display::addStringToMainWindow(commandString);
    return queryReturnCode;
}