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
public:
    map<string, int> wordsMap;
    map<string, int> lettersMap;
    string lettersList[94];
//    const string *getLettersList() const;
    void createScoreMap();
    void createLetterMap();
    void createLetterList();
    string lettersArrayToString();
    int checkWordScore(string);
    string lettersToSend(string letters);

//public:
//    static HashMap &shared_instance() {static HashMap hashMap; return hashMap;}
//
//private:
//    // Make constructor private. Only shared_instance() method will create an instance.
//    HashMap() {/*whatever initialisation you need*/}

};


#endif //SCRABBLE_HASHMAP_H

