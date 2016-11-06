//Menu logic is based off of this website: http://techlister.com/linux/creating-menu-with-ncurses-in-c/1293/
#include "../../../back_end/includes/parser.h"
#include "../../../model/include/messageModel.h"
#include "display.h"
#include "Controller.h"
#include <iostream>
#include <unistd.h>


int max_x = 0;
int max_y = 0;
bool gameFinished = false;
WINDOW *loginWindow;
WINDOW *mainWindow;
WINDOW *chatWindow;

using namespace std;

void setGameFinished() {
    gameFinished = true;
}

void Display::readUserInput(char *command) {
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

void Display::destroyWindow(WINDOW *localWindow) {
    wrefresh(localWindow);
    delwin(localWindow);
}

void Display::initDisplay() {
    initscr();
    clear();
    wclear(mainWindow);
    curs_set(TRUE);
    getmaxyx(stdscr, max_y, max_x);
    mainWindow = createNewWindow(Display::getScreenHeight()/2, Display::getScreenWidth()/2, WINDOW_START_Y, WINDOW_START_X);
    scrollok(mainWindow, TRUE);
    wrefresh(mainWindow);
}

int Display::getScreenWidth() {
    getmaxyx(stdscr, max_y, max_x);
    return max_x;
}

int Display::getScreenHeight() {
    getmaxyx(stdscr, max_y, max_x);
    return max_y;
}

void Display::clearMainWinDisplay() {
    wclear(mainWindow);
    wrefresh(mainWindow);
}

void Display::destroyMainWindow() {
    Display::destroyWindow(mainWindow);
    Display::destroyWindow(stdscr);
}

void Display::createChatWindow() {
    chatWindow = createNewWindow((Display::getScreenHeight()/2)+2, (Display::getScreenWidth()/2)-2, WINDOW_START_Y, (Display::getScreenWidth()/2)+2);
    scrollok(chatWindow, TRUE);
    wrefresh(chatWindow);
}

void Display::addStringToChatWindow(const char* sentence) {
    wprintw(chatWindow, sentence);
    wprintw(chatWindow, "\n");
    box(chatWindow, 0, 0);
    wrefresh(chatWindow);
}

void Display::updateChatWindow() {
    while(!gameFinished) {
        sleep(1);
        wclear(chatWindow);
        box(chatWindow, 0, 0);
        wrefresh(chatWindow);
        std::string payload = Controller::getLatestGlobalMessages();
        std::vector<MessageModel> latestChatMessages = parser::messageVectorDeserialize(payload);
        for(auto&msg : latestChatMessages) {
            std::string chatMsg = msg.From+": "+msg.Message;
            const char* chatMsgConverted = chatMsg.c_str();
            addStringToChatWindow(chatMsgConverted);

        }
    }
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
    wclear(loginWindow);
    Display::destroyWindow(loginWindow);
    return selectedItem;
}