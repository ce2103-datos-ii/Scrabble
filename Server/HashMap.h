//
// Created by ivan on 4/5/19.
//

#ifndef SCRABBLE_HASHMAP_H
#define SCRABBLE_HASHMAP_H

#include <iostream>
#include <map>
#include <time.h>


using namespace std;

class HashMap {

private:
    map<string, int> wordsMap;
    map<string, int> lettersMap;
    int posLetterList = 0;

public:
    string lettersList[94];
//    const string *getLettersList() const;
    void createScoreMap();
    void createLetterMap();
    void createLetterList();
    string lettersArrayToString();
    int checkWordScore(string);
    string lettersToSend(string letters);

};


#endif //SCRABBLE_HASHMAP_H

