//Menu logic is based off of this website: http://techlister.com/linux/creating-menu-with-ncurses-in-c/1293/
#include "../../../back_end/includes/parser.h"
#include "../../../model/include/messageModel.h"
#include "Controller.h"
#include <iostream>
#include <unistd.h>
#include "display.h"
#include <signal.h>
#include "piglatin.h"

static int max_x = 0;
static int max_y = 0;
static WINDOW *loginWindow;
static WINDOW *mainWindow;
static WINDOW *chatWindow;
static WINDOW *combatWindow;
static bool gameFinished = false;

using namespace std;


void Display::setGameFinished() {
    gameFinished = true;
}

void Display::readUserInput(char *command) {
    echo();
    wgetnstr(mainWindow, command, MAX_CHAR_LIMIT);
}

void Display::addStringToMainWindow(const char* sentence) {
    string str = sentence;
    if(GameState::PiglatinIsActive()){
        str = translateToPiglatin(str);
    }
    wprintw(mainWindow, str.c_str());
    wprintw(mainWindow, "\n");
    wprintw(mainWindow, "> ");
    wrefresh(mainWindow);
}

WINDOW* Display::createNewWindow (int height, int width, int startY, int startX) {
    WINDOW *localWindow;
    localWindow = newwin(height, width, startY, startX);
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
    mainWindow = createNewWindow(Display::getScreenHeight()/2+7, (Display::getScreenWidth()/2)-2, WINDOW_START_Y, WINDOW_START_X);
    scrollok(mainWindow, TRUE);
    signal(SIGWINCH, NULL);
    wprintw(mainWindow, "> ");
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
    chatWindow = createNewWindow((Display::getScreenHeight()/2), (Display::getScreenWidth()/2)-2, WINDOW_START_Y, (Display::getScreenWidth()/2)+2);
    scrollok(chatWindow, TRUE);
    wrefresh(chatWindow);
}

void Display::addStringToChatWindow(const char* sentence) {
    string str = sentence;
    if(GameState::PiglatinIsActive()){
        str = translateToPiglatin(str);
    }
    wprintw(chatWindow, str.c_str());
    wprintw(chatWindow, "\n");
    wrefresh(chatWindow);
}

void Display::updateChatWindow() {
    while(!gameFinished) {
        sleep(1);
        if(GameState::PiglatinIsActive()){//decrement piglatin timer every second
            GameState::decrementPiglatinTimer();
        }
        wclear(chatWindow);
        std::string payload = Controller::getLatestGlobalMessages();
        std::vector<MessageModel> latestChatMessages = parser::messageVectorDeserialize(payload);
        for(auto&msg : latestChatMessages) {
            std::string chatMsg = "";
            //TODO time permitting, refactor type of message checking into different class
            if(isPiglatinCommand(msg) && msg.Timestamp > GameState::getPiglatinTimeStamp()) {
                if (msg.To == GameState::getPlayerId()) {
                    GameState::setPiglatinTimeStamp(msg.Timestamp);
                    GameState::initializePiglatinTimer();
                    chatMsg = " " + msg.From + " cast " + msg.Message + " on you";
                } else {
                    chatMsg = " " + msg.Message + " has been cast on " + msg.To;
                }
            /*output the correct message if piglatin was cast on you without updating the piglatin timer logic */
            } else if (isPiglatinCommand(msg) && msg.To == GameState::getPlayerId()) {
                chatMsg = " " + msg.From + " cast " + msg.Message + " on you";
            } else {
                chatMsg = " " + msg.From+": "+msg.Message;
            }
            const char* chatMsgConverted = chatMsg.c_str();
            addStringToChatWindow(chatMsgConverted);
        }
        wrefresh(chatWindow);
    }
}

void Display::createCombatWindow() {
    combatWindow = createNewWindow((Display::getScreenHeight()/2)-2, (Display::getScreenWidth()/2)-2, (Display::getScreenHeight()/2)+1, (Display::getScreenWidth()/2)+2);
    scrollok(combatWindow, TRUE);
    wrefresh(combatWindow);
}

void Display::addStringToCombatWindow(const char* sentence) {
    string str = sentence;
    if(GameState::PiglatinIsActive()){
        str = translateToPiglatin(str);
    }
    wprintw(combatWindow, str.c_str());
    wprintw(combatWindow, "\n");
    wrefresh(combatWindow);
}

void Display::clearCombatWindow() {
    wclear(combatWindow);
}

int Display::createLoginMenu() {
    Display::initDisplay();

    char menuList[NUM_LOGIN_MODES][40] = { "Login", "Make New Account" };
    char item[40];
    int ch, selectedItem = 0;
    loginWindow = createNewWindow(LOGIN_MENU_WINDOW_HEIGHT, LOGIN_MENU_WINDOW_WIDTH, WINDOW_START_Y+1, WINDOW_START_X+1);
    box(loginWindow, 0, 0);
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