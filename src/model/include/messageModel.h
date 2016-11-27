//
// Created by michael on 31/10/16.
//

#ifndef ADVENTURE2016_MESSAGEMODEL_H
#define ADVENTURE2016_MESSAGEMODEL_H

#include <string>
#include <ctime>
#include <chrono>

class MessageModel {
public:
    std::string To;
    std::string From;
    std::string Message;
    long Timestamp;
};

#endif //ADVENTURE2016_MESSAGEMODEL_H
