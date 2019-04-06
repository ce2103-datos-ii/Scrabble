#include <iostream>

#include <iostream>
//#include "JsonParser.h"
#include "Server/HashMap.h"
#include "Server/List.h"

using namespace std;

int main(){
    HashMap hashMap;
    hashMap.createScoreMap();
    hashMap.createLetterMap();
    hashMap.createLetterList();
    cout << hashMap.arrayToString() << endl;
    cout << to_string(hashMap.checkWordScore("hola")) << endl;
    return 0;
}