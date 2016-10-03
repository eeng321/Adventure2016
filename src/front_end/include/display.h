#define MAX_CHAR_LIMIT 500
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

void Display_getUserInput(char*);
void Display_addStringToMainWindow(const char*);
void Display_initDisplay();
int Display_getScreenWidth();
int Display_getScreenHeight();
void Display_clearDisplay();
int Display_createLoginMenu();

