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

public:
    string lettersList[94];
//    const string *getLettersList() const;
    void createScoreMap();
    void createLetterMap();
    void createLetterList();
    string arrayToString();
    int checkWordScore(string);

};


#endif //SCRABBLE_HASHMAP_H

