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

using namespace std;

class Client
{
public:
    bool in;
    bool turn;
    int flag;
    int sock;
    const char* dataServ;
    Client(bool in, int flag, bool turn);
    int connection();
    void comunication(const char* word);
private:
    void setData(char* data);
};

#endif // CLIENTSOCKET_H
