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
    HashMap::shared_instance().createLetterMap();
    HashMap::shared_instance().createScoreMap();
    HashMap::shared_instance().createLetterList();
    FileReader fileReader;
//    hashMap.createScoreMap();
//    hashMap.createLetterMap();
//    hashMap.createLetterList();
//    cout << hashMap.lettersArrayToString() << endl;
    Players::shared_instance().setPlayerTurns();
    while(true){
        jsonParser.checkGameState();
    }
    return 0;
}