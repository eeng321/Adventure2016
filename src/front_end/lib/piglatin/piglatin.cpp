//
// Created by braden on 14/11/16.
//

#include <string>
#include <boost/algorithm/string/classification.hpp>
#include <boost/algorithm/string/split.hpp>

#include "piglatin.h"

using std::string;
using std::vector;

/* Rules of Piglatin as stated in Wikipedia:
 * https://en.wikipedia.org/wiki/Pig_Latin
 *
 * For words that begin with consonant sounds, all letters before the initial vowel are placed at the end of
 * the word sequence. Then, "ay".
 *
 * For words that begin with vowel sounds, one just adds "way" to the end. */

const string VOWELS = "aeiou";
const string VOWEL_START_ENDING = "way";
const string CONSONANT_START_ENDING = "ay";

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

string translateWord(const string& s) {
    int indexOfVowel = findVowel(s);
    if (indexOfVowel != 0) {
        string vowelAndAfter = s.substr(indexOfVowel);
        string beforeVowel = s.substr(0, indexOfVowel);
        return vowelAndAfter + beforeVowel + CONSONANT_START_ENDING;
    }
    return s + VOWEL_START_ENDING;
}

