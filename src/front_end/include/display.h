#ifndef ADVENTURE2016_DISPLAY_H
#define ADVENTURE2016_DISPLAY_H

#include <ncurses.h>

#define MAX_CHAR_LIMIT 1000
#define WINDOW_START_X 0
#define WINDOW_START_Y 0
#define NUM_LOGIN_MODES 2
#define LOGIN_MENU_WINDOW_WIDTH 45
#define LOGIN_MENU_WINDOW_HEIGHT 10
#define MENU_PADDING_LEFT 2

#define LOGIN_MENU_SELECTION 0
#define NEW_ACCOUNT_MENU_SELECTION 1

#define QUIT_CHAR 'q'
#define BACK_CHAR 'b'

class Display {
public:
    static void readUserInput(char *command);
    static void addStringToMainWindow(const char* sentence);
    static int getScreenWidth();
    static int getScreenHeight();
    static int createLoginMenu();
    static void clearMainWinDisplay();
    static void destroyMainWindow();
    static void createChatWindow();
    static void addStringToChatWindow(const char* sentence);
    static void updateChatWindow();
    static void setGameFinished();
    static void createCombatWindow();
    static void addStringToCombatWindow(const char* sentence);

private:
    static WINDOW* createNewWindow(int height, int width, int startY, int startX);
    static void initDisplay();
    static void destroyWindow(WINDOW* localWindow);
};

#endif //ADVENTURE2016_DISPLAY_H