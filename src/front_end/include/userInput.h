#ifndef ADVENTURE2016_USERINPUT_H
#define ADVENTURE2016_USERINPUT_H

#include "Controller.h"

class UserInput {
public:
    static void checkExistingPlayerCredentials();
    static void createNewPlayerCredentials();
    static StatusCode readBasicInput();
};

#endif //ADVENTURE2016_USERINPUT_H