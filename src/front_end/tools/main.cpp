#include "userInput.h"
#include "RestClient.h"
#include <iostream>
#include <ncurses.h>

#define MAX_CHAR_LIMIT 500

struct screenCoordinates {
    int row;
    int col;
} window;

int
main() {

    auto test = new Rest::RestClient();
    std::cout << "Response: " << test->Get("http://localhost:8080/test") << std::endl;
//
//    initscr();
//    scrollok(stdscr, TRUE); //allows for screen scrolling
////    keypad(stdstr, TRUE);  //only needed if needs special keys
//
//    getmaxyx(stdscr, window.row, window.col);
//
//    printw("Please input a command\n");
//    refresh();
//
//    char command[MAX_CHAR_LIMIT];
//    getUserInput(command);
//
//    mvprintw(window.row/2, window.col/2, command);
//    refresh();
//
//    getch();
//    endwin();
    return 0;
}

