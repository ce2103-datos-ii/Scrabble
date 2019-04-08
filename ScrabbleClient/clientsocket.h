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

class clientSocket
{
public:
    clientSocket(bool in);
    int connection();
private:
    void setData(char* data);
    bool in;
    int sock;
};

#endif // CLIENTSOCKET_H
