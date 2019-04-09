//
// Created by ivan on 4/7/19.
//

#include "Communication.h"

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

using namespace std;

int Communication::connection(int port)
{
    if (port != 54000){
        // Create a socket
        int listening = socket(AF_INET, SOCK_STREAM, 0);
        cout << "1" << endl;
        if (listening == -1) {
            cout << "2" << endl;
            cerr << "Can't create a socket! Quitting" << endl;
            cout << "3" << endl;
            return -1;
        }

        // Bind the ip address and port to a socket
        sockaddr_in hint;
        cout << "4" << endl;
        hint.sin_family = AF_INET;
        cout << "5" << endl;
        hint.sin_port = htons(port);
        cout << "6" << endl;
        inet_pton(AF_INET, "0.0.0.0", &hint.sin_addr);
        cout << "7" << endl;

        bind(listening, (sockaddr *) &hint, sizeof(hint));
        cout << "8" << endl;

        // Tell Winsock the socket is for listening
        listen(listening, SOMAXCONN);
        cout << "9" << endl;

        // Wait for a connection
        sockaddr_in client;
        cout << "10" << endl;
        socklen_t clientSize = sizeof(client);

        cout<<"Holaaa"<<endl;
        int clientSocket = accept(listening, (sockaddr *) &client, &clientSize);
        cout<<"Hola"<<endl;

        char host[NI_MAXHOST];      // Client's remote name
        char service[NI_MAXSERV];   // Service (i.e. port) the client is connect on

        memset(host, 0, NI_MAXHOST); // same as memset(host, 0, NI_MAXHOST);
        memset(service, 0, NI_MAXSERV);

        if (getnameinfo((sockaddr *) &client, sizeof(client), host, NI_MAXHOST, service, NI_MAXSERV, 0) == 0) {
            cout << host << " connected on port " << service << endl;
        } else {
            inet_ntop(AF_INET, &client.sin_addr, host, NI_MAXHOST);
            cout << host << " connected on port " << ntohs(client.sin_port) << endl;
        }

        // Close listening socket
        close(listening);

        return clientSocket;
    }else{
        // Create a socket
        int listening = socket(AF_INET, SOCK_STREAM, 0);
        if (listening == -1) {
            cerr << "Can't create a socket! Quitting" << endl;
            return -1;
        }

        // Bind the ip address and port to a socket
        sockaddr_in hint;
        hint.sin_family = AF_INET;
        hint.sin_port = htons(port);
        inet_pton(AF_INET, "0.0.0.0", &hint.sin_addr);

        bind(listening, (sockaddr *) &hint, sizeof(hint));

        // Tell Winsock the socket is for listening
        listen(listening, SOMAXCONN);

        // Wait for a connection
        sockaddr_in client;
        socklen_t clientSize = sizeof(client);

        int clientSocket = accept(listening, (sockaddr *) &client, &clientSize);

        char host[NI_MAXHOST];      // Client's remote name
        char service[NI_MAXSERV];   // Service (i.e. port) the client is connect on

        memset(host, 0, NI_MAXHOST); // same as memset(host, 0, NI_MAXHOST);
        memset(service, 0, NI_MAXSERV);

        if (getnameinfo((sockaddr *) &client, sizeof(client), host, NI_MAXHOST, service, NI_MAXSERV, 0) == 0) {
            cout << host << " connected on port " << service << endl;
        } else {
            inet_ntop(AF_INET, &client.sin_addr, host, NI_MAXHOST);
            cout << host << " connected on port " << ntohs(client.sin_port) << endl;
        }

        // Close listening socket
        close(listening);
        return clientSocket;
    }
}