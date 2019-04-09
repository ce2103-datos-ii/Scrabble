#include <iostream>

#include <iostream>
//#include "JsonParser.h"
#include "Server/HashMap.h"
#include "Server/List.h"
#include "Server/Communication.h"
#include "Server/JsonParser.h"

using namespace std;

int main(){
    HashMap hashMap;
    hashMap.createScoreMap();
    hashMap.createLetterMap();
    hashMap.createLetterList();
    JsonParser jsonParser;
    jsonParser.jsonReceive();
    return 0;
}