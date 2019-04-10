//
// Created by ivan on 4/5/19.
//

#include "HashMap.h"

void HashMap::createScoreMap() {

    wordsMap.insert(make_pair("a", 1));
    wordsMap.insert(make_pair("e", 1));
    wordsMap.insert(make_pair("o", 1));
    wordsMap.insert(make_pair("i", 1));
    wordsMap.insert(make_pair("s", 1));
    wordsMap.insert(make_pair("n", 1));
    wordsMap.insert(make_pair("l", 1));
    wordsMap.insert(make_pair("r", 1));
    wordsMap.insert(make_pair("u", 1));
    wordsMap.insert(make_pair("t", 1));
    wordsMap.insert(make_pair("d", 2));
    wordsMap.insert(make_pair("g", 2));
    wordsMap.insert(make_pair("c", 3));
    wordsMap.insert(make_pair("b", 3));
    wordsMap.insert(make_pair("m", 3));
    wordsMap.insert(make_pair("p", 3));
    wordsMap.insert(make_pair("h", 4));
    wordsMap.insert(make_pair("f", 4));
    wordsMap.insert(make_pair("v", 4));
    wordsMap.insert(make_pair("y", 4));
    wordsMap.insert(make_pair("q", 5));
    wordsMap.insert(make_pair("j", 8));
    wordsMap.insert(make_pair("x", 8));
    wordsMap.insert(make_pair("z", 10));
}

void HashMap::createLetterMap() {
    lettersMap.insert(make_pair("a", 12));
    lettersMap.insert(make_pair("b", 2));
    lettersMap.insert(make_pair("c", 4));
    lettersMap.insert(make_pair("d", 5));
    lettersMap.insert(make_pair("e", 12));
    lettersMap.insert(make_pair("f", 1));
    lettersMap.insert(make_pair("g", 2));
    lettersMap.insert(make_pair("h", 2));
    lettersMap.insert(make_pair("i", 6));
    lettersMap.insert(make_pair("j", 1));
    lettersMap.insert(make_pair("l", 4));
    lettersMap.insert(make_pair("m", 2));
    lettersMap.insert(make_pair("n", 5));
    lettersMap.insert(make_pair("o", 9));
    lettersMap.insert(make_pair("p", 2));
    lettersMap.insert(make_pair("q", 1));
    lettersMap.insert(make_pair("r", 5));
    lettersMap.insert(make_pair("s", 6));
    lettersMap.insert(make_pair("t", 4));
    lettersMap.insert(make_pair("u", 5));
    lettersMap.insert(make_pair("v", 1));
    lettersMap.insert(make_pair("x", 1));
    lettersMap.insert(make_pair("z", 1));
}

void HashMap::createLetterList() {
    srand(time(NULL));
    string allLetters[23] = {"a", "b", "c", "d", "e", "f", "g", "h", "i", "j", "l", "m", "n", "o", "p", "q", "r", "s", "t", "u", "v", "x", "z"};
    for (int i = 0; i < 93; i++){
        int randomNum = rand() % 23;
        if (lettersMap.at(allLetters[randomNum]) != 0){
//            cout << lettersList[i] << endl;
//            cout << allLetters[randomNum] + to_string(lettersMap[allLetters[randomNum]]) << endl;
            lettersList[i] = allLetters[randomNum];
            lettersMap[allLetters[randomNum]] --;
        } else {
            i--;
        }
    } cout << *lettersList << endl;
}



int HashMap::checkWordScore(string str) {
    int score = 0;
    createScoreMap();
    for (char &c: str) {
        string s;
        s += c;
        score += wordsMap.at(s);
    }
    return score;
}

//const string *HashMap::getLettersList() const {
//    return lettersList;
//}

string HashMap::lettersArrayToString() {
    string str = "[";
    for (int i = 0; i <= 92; i++) {
        str += lettersList[i] + ", ";
    }
    str += "]";
    return str;
}

string HashMap::lettersToSend(string letters) {
    string str;
    for (int i = 0; i < letters.length(); i++){
        str += lettersList[posLetterList];
        posLetterList++;
    }
    return str;
}

