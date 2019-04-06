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

using namespace rapidjson;
using namespace std;

class JsonParser {

private:
    FileReader fileReader;

public:
    static char* json;

    string jsonSend(const char*);
    void jsonReceive(const char*);

};


#endif //SCRABBLE_SERVER_JSONPARSER_H
