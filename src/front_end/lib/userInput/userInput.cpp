//Menu Code based off of example http://techlister.com/linux/creating-menu-with-ncurses-in-c/1293/

#include <ncurses.h>
#include <display.h>
#include <string.h>
#include <unistd.h>
#include "userInput.h"
#include <iostream>

using namespace std;


void checkExistingPlayerCredentials(char *command, char *username, char *password) {
    Display_clearDisplay();

    Display_addStringToMainWindow("Please input your username:");
    Display_getUserInput(command);
    strcpy(username, command);

    Display_addStringToMainWindow("Please input your password:");
    Display_getUserInput(command);
    strcpy(password, command);

    Display_addStringToMainWindow(username);
    Display_addStringToMainWindow(password);
    sleep(3); //TEMPORARY
}

void createNewPlayerCredentials(char *command, char *username, char *password) {
    //TODO: Where do we store this information?
    //TODO: How do we pass this information?
}