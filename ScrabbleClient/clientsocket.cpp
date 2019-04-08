#include "clientsocket.h"
//PlayerCount y code

//static char* dataHost;
char* dataC;
char* dataS;
//static char* dataCode;
static int flag = 0;
int sock;
bool in;

clientSocket::clientSocket(bool in){
    this->in = in;
}

int connection(){
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1){
        return 1;
    }

    int port = 54000;
    string ipAddress = "127.0.0.1";

    sockaddr_in hint;
    hint.sin_family = AF_INET;
    hint.sin_port = htons(port);
    inet_pton(AF_INET, ipAddress.c_str(), &hint.sin_addr);

    int connectRes = connect(sock, (sockaddr*)&hint, sizeof(hint));
    if (connectRes == -1){
        return 1;
    }
    return 0;
}

void comunication(char* word){
    char buf[4096];
    if(in == true){
        if(flag == 0){
            int sendRes = send(sock, word, sizeof(word) + 1, 0);
            flag=1;
        }else{
            int sendRes = send(sock, word, sizeof(word) + 1, 0);
            if (sendRes == -1){
                cout << "Could not send to server! \r\n";
            }

            memset(buf, 0, 4096);
            int bytesReceived = recv(sock, buf, 4096, 0);
            if (bytesReceived == -1){
                cout << "There was an error getting response from server\r\n";
            }
            dataS = buf;
        }
    }else{
        if(flag == 0){
            int sendRes = send(sock, word, sizeof(word) + 1, 0);
            flag=1;
        }else{
            int sendRes = send(sock, dataC, sizeof(dataC) + 1, 0);
            if (sendRes == -1){
                cout << "Could not send to server! \r\n";
            }

            memset(buf, 0, 4096);
            int bytesReceived = recv(sock, buf, 4096, 0);
            if (bytesReceived == -1){
                cout << "There was an error getting response from server\r\n";
            }
            dataS = buf;
        }
    }
}
