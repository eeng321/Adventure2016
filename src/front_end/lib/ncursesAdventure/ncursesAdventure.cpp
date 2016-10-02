#include <ncurses.h>
#include "ncursesAdventure.h"

cursorCoordinates cursor;

void resetCursor() {
    move(0, 0);
    cursor.row = 0;
    cursor.col = 0;
}
void moveCursorDownOneRow() {
    move(cursor.row+1, cursor.col);
    cursor.row+=1;
}
void moveCursorUpOneRow() {
    move(cursor.row-1, cursor.col);
    cursor.row-=1;
}
void moveCursorRightOneColumn() {
    move(cursor.row, cursor.col+1);
    cursor.col+=1;
}
void moveCursorLeftOneColumn() {
    move(cursor.row, cursor.col-1);
    cursor.col-=1;
}
void setCursorCoordinates(int newRow, int newCol) {
    cursor.row = newRow;
    cursor.col = newCol;
    move(cursor.row, cursor.col);
}

void getMaxScreenSize(int* maxRow, int* maxCol) {
    getmaxyx(stdscr, *maxRow, *maxCol);
}

void updateCursorPosition() {
    getyx(stdscr, cursor.row, cursor.col);
}

int getCursorRow() {
    return cursor.row;
}

int getCursorCol() {
    return cursor.col;
}