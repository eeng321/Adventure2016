#ifndef ADVENTURE2016_USERINPUT_H
#define ADVENTURE2016_USERINPUT_H

#include "Controller.h"
#include "Dictionary.h"

class UserInput {
public:
    static void checkExistingPlayerCredentials();
    static void createNewPlayerCredentials();
    static StatusCode readBasicInput(Dictionary* dictionary);
};


#endif //ADVENTURE2016_USERINPUT_H