#include "client.h"

int sock;

Client::Client(bool in, int flag, bool turn){
    this->in = in;
    this->flag = flag;
    this->turn = turn;
}

int Client::connection(){
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1){
        return 1;
    }

    int port = 54000;
    string ipAddress = "192.168.0.29";

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

void Client::comunication(const char* word){
    char buf[4096];
    if(in == true){
        if(flag == 0){
            int sendRes = send(sock, word, sizeof(word) + 1, 0);
            int bytesReceived = recv(sock, buf, 4096, 0);
            flag=1;
        }else{
            if(turn){
                int sendRes = send(sock, word, sizeof(word) + 1, 0);
                if (sendRes == -1){
                    cout << "Could not send to server! \r\n";
                }
                memset(buf, 0, 4096);
                int bytesReceived = recv(sock, buf, 4096, 0);
                if (bytesReceived == -1){
                    cout << "There was an error getting response from server\r\n";
                }
                this->dataServ = buf;
            }else{
                memset(buf, 0, 4096);
                int bytesReceived = recv(sock, buf, 4096, 0);
                if (bytesReceived == -1){
                    cout << "There was an error getting response from server\r\n";
                }
                this->dataServ = buf;
            }
        }
    }else{
        if(flag == 0){
            int sendRes = send(sock, word, sizeof(word) + 1, 0);
            int bytesReceived = recv(sock, buf, 4096, 0);
            flag=1;
        }else{
            if(turn){
                int sendRes = send(sock, word, sizeof(word) + 1, 0);
                if (sendRes == -1){
                    cout << "Could not send to server! \r\n";
                }
                memset(buf, 0, 4096);
                int bytesReceived = recv(sock, buf, 4096, 0);
                if (bytesReceived == -1){
                    cout << "There was an error getting response from server\r\n";
                }
                this->dataServ = buf;
            }else{
                memset(buf, 0, 4096);
                int bytesReceived = recv(sock, buf, 4096, 0);
                if (bytesReceived == -1){
                    cout << "There was an error getting response from server\r\n";
                }
                this->dataServ = buf;
            }
        }
    }
}
