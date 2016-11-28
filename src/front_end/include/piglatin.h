//
// Created by braden on 14/11/16.
//

#ifndef ADVENTURE2016_PIGLATIN_H
#define ADVENTURE2016_PIGLATIN_H

#include <string>
#include "../../model/include/messageModel.h"

const std::string PIG_LATIN_MESSAGE = "SPELL_PIG_LATIN";

std::string translateToPiglatin(const std::string& s);
int findVowel(const std::string& s);
std::string translateWord(const std::string& s);
bool isPiglatinCommand(const MessageModel& message);
bool hasPunctuation(const std::string& s);

#endif //ADVENTURE2016_PIGLATIN_H
