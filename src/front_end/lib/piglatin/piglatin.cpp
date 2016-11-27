//
// Created by braden on 14/11/16.
//

#include <string>
#include <boost/algorithm/string/classification.hpp>
#include <boost/algorithm/string/split.hpp>
#include <boost/algorithm/string.hpp>
#include "../../../model/include/messageModel.h"

#include "GameState.h"
#include "piglatin.h"

using std::string;
using std::vector;

/* Rules of Piglatin as stated in Wikipedia:
 * https://en.wikipedia.org/wiki/Pig_Latin
 *
 * For words that begin with consonant sounds, all letters before the initial vowel are placed at the end of
 * the word sequence. Then, "ay".
 *
 * For words that begin with vowel sounds, one just adds "way" to the end.
 *
 * TODO Note: This translation does not currently take into account punctuation or leading capitals, do this time permitting */


const string VOWELS = "aeiouAEIOU";
const string VOWEL_START_ENDING = "way";//the ending for a word that starts with a vowel
const string CONSONANT_START_ENDING = "ay";//the ending for a word that starts with a consonant 

string translateToPiglatin(const string& s){
//    string trimmedStr = s;
//    boost::trim_right(trimmedStr);
    vector<string> words;
    boost::split(words, s, boost::is_any_of(" "), boost::token_compress_on);
    string translatedString = "";
    for (const string& word : words){
        translatedString = translatedString + " " + translateWord(word);
    }
    return translatedString;
}

int findVowel(const string& s) {
    return s.find_first_of(VOWELS);
}

string translateWord(const string& s) {
    int indexOfVowel = findVowel(s);
    if(indexOfVowel == string::npos){//no vowel was found
        return "";
    }
    if (indexOfVowel != 0) {//starts with a consonant
        string vowelAndAfter = s.substr(indexOfVowel);
        string beforeVowel = s.substr(0, indexOfVowel);
        return vowelAndAfter + beforeVowel + CONSONANT_START_ENDING;
    }
    return s + VOWEL_START_ENDING;
}

bool isPiglatinCommand(const MessageModel& message){
    return message.To != "global" && message.Message == PIG_LATIN_MESSAGE;
}
