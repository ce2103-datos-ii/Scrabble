//
// Created by ivan on 3/24/19.
//

#ifndef SCRABBLE_SERVER_JSONPARSER_H
#define SCRABBLE_SERVER_JSONPARSER_H

#include <iostream>

#include "../rapidjson/document.h"
#include "../rapidjson/writer.h"
#include "../rapidjson/stringbuffer.h"
#include "Player.h"
#include "FileReader.h"
#include "Players.h"
#include "HashMap.h"

using namespace rapidjson;
using namespace std;

class JsonParser {

private:
    FileReader fileReader;

public:
    static int cont;
    static Players* players = new Players();
    static char* json;

//    void jsonSend(const char*);
    string jsonReceive(const char*);

};


#endif //SCRABBLE_SERVER_JSONPARSER_H
