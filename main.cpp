#include <iostream>

#include <iostream>
//#include "JsonParser.h"
#include "Server/HashMap.h"
#include "Server/List.h"
#include "Server/Communication.h"
#include "Server/JsonParser.h"

using namespace std;

int main(){
    JsonParser jsonParser;
    Players::shared_instance().setPorts();
    HashMap hashMap;
    hashMap.createScoreMap();
    hashMap.createLetterMap();
    hashMap.createLetterList();
    FileReader fileReader;
    string word = "gato";
    cout << "word: ";
    cout << fileReader.searchWord(word) << endl;
    cout << "score: ";
    cout << hashMap.checkWordScore(word) << endl;
    cout << "letters list: ";
    cout << hashMap.lettersArrayToString() << endl;
    while (true)
        jsonParser.checkGameState();
    return 0;
}