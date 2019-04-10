#ifndef CLIENTSOCKET_H
#define CLIENTSOCKET_H
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <string.h>
#include <string>
#include <iostream>
#include "rapidjson/rapidjson.h"
#include "rapidjson/document.h"
#include "rapidjson/stringbuffer.h"
#include "rapidjson/writer.h"

using namespace rapidjson;
using namespace std;

class Client
{
public:
    bool in;
    bool turn = true;
    int flag;
    int sock;
    int port;
    const char* dataServ;
    int sizeOfWord;
    string newWord;
    Client(bool in, int flag);
    int connection(int port);
    void comunication(const char* word);
private:
    void setData(char* data);
    string bytesTransformer(int bytesReceived, char buf[4096], string newWord);
};

#endif // CLIENTSOCKET_H
