#include "client.h"

int sock;

Client::Client(bool in, int flag){
    this->in = in;
    this->flag = flag;
}

int Client::connection(int port){
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1){
        return 1;
    }
    string ipAddress = "192.168.0.30";

    sockaddr_in hint;
    hint.sin_family = AF_INET;
    hint.sin_port = htons(port);
    inet_pton(AF_INET, ipAddress.c_str(), &hint.sin_addr);

    cout << "llegó" << endl;

    while(true){
        int connectRes = connect(sock, (sockaddr*)&hint, sizeof(hint));
        if(connectRes == -1){
        }else {
            return 0;
        }
    }

    cout << "pasó" << endl;
    return 0;
}

void Client::comunication(const char* word){
    newWord = "";
    sizeOfWord = 0;
    for(char &c: string(word)){
        sizeOfWord++;
    }
    char buf[4096];
    //memset(buf, 0, 4096);
    Document d;
    if(in == true){
        if(flag == 0){
            int sendRes = send(this->sock, word, sizeOfWord , 0);
            int bytesReceived = recv(sock, buf, 4096, 0);
            cout<<buf<<endl;
            recv(this->sock,buf,4096,0);
            flag = 1;
            deleteArray(buf,bytesReceived);
        }else{
            if(turn){
                int sendRes = send(this->sock, word, sizeOfWord, 0);
                cout<<"envió en cliente"<<endl;
                memset(buf, 0, 4096);
                int bytesReceived = recv(this->sock, buf, 4096, 0);
                cout<<"recibió en cliente"<<endl;
                newWord = bytesTransformer(bytesReceived,buf,newWord);
                this->dataServ = (newWord).c_str();
                d.Parse(dataServ);
                turn = d["turn"].GetBool();
                deleteArray(buf,bytesReceived);
            }else{
                memset(buf, 0, 4096);
                int bytesReceived = recv(sock, buf, 4096, 0);
                newWord = bytesTransformer(bytesReceived,buf,newWord);
                this->dataServ = (newWord).c_str();
                d.Parse(dataServ);
                turn = d["turn"].GetBool();
                deleteArray(buf,bytesReceived);
            }
        }
    }else{
        if(flag == 0){
            int sendRes = send(sock, word, sizeOfWord , 0);
            int bytesReceived = recv(sock, buf, 4096, 0);
            newWord = bytesTransformer(bytesReceived,buf,newWord);
            this->dataServ = (newWord).c_str();
            cout<<this->dataServ<<endl;
            close(sock);
            d.Parse(dataServ);
            port = d["port"].GetInt();
            this->connection(port);
            recv(sock,buf,4096,0);
            flag=1;
        }else{
            if(turn){
                int sendRes = send(sock, word, sizeOfWord, 0);
                //memset(buf, 0, 4096);
                int bytesReceived = recv(sock, buf, 4096, 0);
                newWord = bytesTransformer(bytesReceived,buf,newWord);
                this->dataServ = (newWord).c_str();
                d.Parse(dataServ);
                turn = d["turn"].GetBool();
            }else{
                memset(buf, 0, 4096);
                int bytesReceived = recv(sock, buf, 4096, 0);
                newWord = bytesTransformer(bytesReceived,buf,newWord);
                this->dataServ = (newWord).c_str();
                d.Parse(dataServ);
                turn = d["turn"].GetBool();
            }
        }
    }
}

string Client::bytesTransformer(int bytesReceived, char  buf[4096], string newWord){
    for(int i = 0; i!=bytesReceived;i++){
        newWord += buf[i];
    }
    return newWord;
}

void Client::deleteArray(char arr[], int bytes) {
    for (int i = 0; i < bytes; i++)
        *&arr[i] = NULL;
}
