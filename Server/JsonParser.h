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
#include "Communication.h"
#include <stdio.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <string.h>
#include <iostream>
#include <sys/types.h>
#include <unistd.h>
#include <iostream>
#include <sys/types.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <string.h>
#include <string>

using namespace rapidjson;
using namespace std;

class JsonParser {

private:
    FileReader fileReader;
    int ports[4] = {54001, 54002, 54003, 54003};
    int port1 = 54000;
    int port2 = 53000;
    int portCount = 0;
public:
    int checkJsonSize(string);
//    void charArrayToConstChar(char ch[]);

    int cont = 0;
//    extern Players players;
    static char* json;

//    void jsonSend(const char*);
    void jsonReceive();

    void firstConnection();

    void checkGameState();

    void deleteArray(char arr[], int bytes);

};


#endif //SCRABBLE_SERVER_JSONPARSER_H
