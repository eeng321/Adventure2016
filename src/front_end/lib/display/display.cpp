//Menu logic is based off of this website: http://techlister.com/linux/creating-menu-with-ncurses-in-c/1293/
#include "display.h"
#include <iostream>
#include <unistd.h>

int max_x = 0;
int max_y = 0;
WINDOW *loginWindow;
WINDOW *mainWindow;

using namespace std;

void Display::readUserInput(char *command){
    echo();
    wgetnstr(mainWindow, command, MAX_CHAR_LIMIT);
}

void Display::addStringToMainWindow(const char* sentence) {
    wprintw(mainWindow, sentence);
    wprintw(mainWindow, "\n");
    wrefresh(mainWindow);
}

WINDOW* Display::createNewWindow (int height, int width, int startY, int startX) {
    WINDOW *localWindow;
    localWindow = newwin(height, width, startY, startX);
    box(localWindow, 0 , 0);
    wrefresh(localWindow);
    return localWindow;
}

void destroyWindow(WINDOW *localWindow) {
    wrefresh(localWindow);
    delwin(localWindow);
}

void Display::initDisplay() {
    initscr();
    clear();
    wclear(mainWindow);
    curs_set(TRUE);
    getmaxyx(stdscr, max_y, max_x);
    mainWindow = createNewWindow(Display::getScreenHeight()-1, Display::getScreenWidth()-1, WINDOW_START_Y, WINDOW_START_X);
    scrollok(mainWindow, TRUE);
    wrefresh(mainWindow);
}

int Display::getScreenWidth(){
    getmaxyx(stdscr, max_y, max_x);
    return max_x;
}

int Display::getScreenHeight(){
    getmaxyx(stdscr, max_y, max_x);
    return max_y;
}

void Display::clearMainWinDisplay() {
    wclear(mainWindow);
    wrefresh(mainWindow);
}

int Display::createLoginMenu() {
    Display::initDisplay();
    char menuList[NUM_LOGIN_MODES][40] = { "Login", "Make New Account" };
    char item[40];
    int ch, selectedItem = 0;
    loginWindow = createNewWindow(LOGIN_MENU_WINDOW_HEIGHT, LOGIN_MENU_WINDOW_WIDTH, WINDOW_START_Y+1, WINDOW_START_X+1);

    mvwprintw(loginWindow, selectedItem+1, MENU_PADDING_LEFT, "Please choose from the following:");
    for(selectedItem = 0; selectedItem < NUM_LOGIN_MODES; selectedItem++) {
        if(selectedItem == 0)
            wattron(loginWindow, A_STANDOUT);
        else
            wattroff(loginWindow, A_STANDOUT);
        sprintf(item, "%-7s",  menuList[selectedItem]);
        mvwprintw(loginWindow, selectedItem+3, MENU_PADDING_LEFT, "%s", item);
    }

    wrefresh(loginWindow);

    selectedItem = 0;
    noecho();
    keypad(loginWindow, TRUE);
    curs_set( 0 );
    bool isItemSelected = false;

    while ((ch = wgetch(loginWindow)) != QUIT_CHAR) {
        sprintf(item, "%-7s",  menuList[selectedItem]);
        mvwprintw( loginWindow, selectedItem+3, MENU_PADDING_LEFT, "%s", item );
        switch( ch ) {
            case KEY_UP:
                selectedItem--;
                selectedItem = (selectedItem < 0) ? NUM_LOGIN_MODES-1 : selectedItem;
                break;
            case KEY_DOWN:
                selectedItem++;
                selectedItem = (selectedItem > NUM_LOGIN_MODES-1) ? 0 : selectedItem;
                break;
            case '\n':
                isItemSelected = true;
                break;
            default:
                break;
        }

        if (isItemSelected) {
            break;
        }

        // now highlight the next item in the list.
        wattron( loginWindow, A_STANDOUT );

        sprintf(item, "%-7s",  menuList[selectedItem]);
        mvwprintw( loginWindow, selectedItem+3, MENU_PADDING_LEFT, "%s", item);
        wattroff( loginWindow, A_STANDOUT );
    }
    destroyWindow(loginWindow);
    return selectedItem;
}