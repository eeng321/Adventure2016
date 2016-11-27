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
const string PUNCTUATION = ".!?:;,";
const string VOWEL_START_ENDING = "way";//the ending for a word that starts with a vowel
const string CONSONANT_START_ENDING = "ay";//the ending for a word that starts with a consonant 

string translateToPiglatin(const string& s){
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

bool hasPunctuation(const string& s){
    return s.find_first_of(PUNCTUATION) != s.npos;
}

string translateWord(const string& s) {
    int indexOfVowel = findVowel(s);
    if(indexOfVowel == string::npos){//no vowel was found
        return "";
    }
    if (indexOfVowel != 0) {//starts with a consonant
        if(hasPunctuation(s)){
            string vowelAndAfter = s.substr(indexOfVowel, s.size()-indexOfVowel-1);//the end index changes depending on the location of the vowel
            string beforeVowel = s.substr(0, indexOfVowel);
            string punctuation = s.substr(s.size()-1);
            return vowelAndAfter + beforeVowel + CONSONANT_START_ENDING + punctuation;
//            return vowelAndAfter;

        } else {
            string vowelAndAfter = s.substr(indexOfVowel);
            string beforeVowel = s.substr(0, indexOfVowel);
            return vowelAndAfter + beforeVowel + CONSONANT_START_ENDING;
        }
    } else {//starts with a vowel
        if(hasPunctuation(s)){
            string beforePunctuation = s.substr(0, s.size()-1);
            string punctuation = s.substr(s.size()-1);
            return beforePunctuation + VOWEL_START_ENDING + punctuation;
        } else {
            return s + VOWEL_START_ENDING;
        }
    }
}

bool isPiglatinCommand(const MessageModel& message){
    return message.To != "global" && message.Message == PIG_LATIN_MESSAGE;
}
