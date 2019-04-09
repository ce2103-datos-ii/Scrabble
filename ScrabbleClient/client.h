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
#include "rapidjson.h"
#include "document.h"
#include "writer.h"
#include "stringbuffer.h"

using namespace rapidjson;
using namespace std;

class Client
{
public:
    bool in;
    bool turn;
    int flag;
    int sock;
    int port;
    const char* dataServ;
    Client(bool in, int flag, bool turn);
    int connection(int port);
    void comunication(const char* word);
private:
    void setData(char* data);
};

#endif // CLIENTSOCKET_H
