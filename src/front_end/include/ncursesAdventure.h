struct cursorCoordinates {
    int row;
    int col;
};

void resetCursor();
void moveCursorDownOneRow();
void moveCursorUpOneRow();
void moveCursorRightOneColumn();
void moveCursorLeftOneColumn();
void setCursorCoordinates(int, int);
void getMaxScreenSize(int*, int*);
void updateCursorPosition();
int getCursorRow();
int getCursorCol();

