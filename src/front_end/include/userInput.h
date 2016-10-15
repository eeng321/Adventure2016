#ifndef ADVENTURE2016_USERINPUT_H
#define ADVENTURE2016_USERINPUT_H

class UserInput {
public:
    static void checkExistingPlayerCredentials(char *command, char *username, char *password);
    static void createNewPlayerCredentials(char *command, char *username, char *password);
};

#endif //ADVENTURE2016_USERINPUT_H