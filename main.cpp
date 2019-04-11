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
    while(true){
        jsonParser.checkGameState();
    }
    return 0;
}