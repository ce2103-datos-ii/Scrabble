#include "client.h"


Client::Client(bool in, int flag){
    this->in = in;
    this->flag = flag;
}

int Client::connection(int port){
    this->sock = socket(AF_INET, SOCK_STREAM, 0);
    if (this->sock == -1){
        return 1;
    }
    string ipAddress = "192.168.0.30";

    sockaddr_in hint;
    hint.sin_family = AF_INET;
    hint.sin_port = htons(port);
    inet_pton(AF_INET, ipAddress.c_str(), &hint.sin_addr);

    cout << "llegó" << endl;

    int connectRes = connect(this->sock, (sockaddr*)&hint, sizeof(hint));
    if (connectRes == -1){
        return 1;
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
    memset(buf, 0, 4096);
    Document d;
    if(in == true){
        if(flag == 0){
            int sendRes = send(this->sock, word, sizeOfWord , 0);
            int bytesReceived = recv(this->sock, buf, 4096, 0);
            newWord = bytesTransformer(bytesReceived,buf,newWord);
            this->dataServ = (newWord).c_str();
            close(this->sock);
            d.Parse(dataServ);
            cout << dataServ << endl;
            port = d["port"].GetInt();
            this->connection(port);
            recv(this->sock, buf, 4096, 0);
            flag = 1;
            deleteArray(buf, bytesReceived);
        }else{
            if(turn){
                int sendRes = send(this->sock, word, sizeof(word) + 1, 0);
                int bytesReceived = recv(this->sock, buf, 4096, 0);
                newWord = bytesTransformer(bytesReceived,buf,newWord);
                this->dataServ = (newWord).c_str();
                d.Parse(dataServ);
                turn = d["turn"].GetBool();
                deleteArray(buf, bytesReceived);
            }else{
                int bytesReceived = recv(this->sock, buf, 4096, 0);
                newWord = bytesTransformer(bytesReceived,buf,newWord);
                this->dataServ = (newWord).c_str();
                d.Parse(dataServ);
                turn = d["turn"].GetBool();
                deleteArray(buf, bytesReceived);
            }
        }
    }else{
        if(flag == 0){
            int sendRes = send(this->sock, word, sizeOfWord , 0);
            int bytesReceived = recv(this->sock, buf, 4096, 0);
            cout << bytesReceived << endl;
            newWord = bytesTransformer(bytesReceived,buf,newWord);
            this->dataServ = (newWord).c_str();
            close(this->sock);
            d.Parse(dataServ);
            cout << dataServ << endl;
            this->port = d["port"].GetInt();
            cout << "hojk" << endl;
            this->connection(port);
            recv(this->sock,buf,4096,0);
            cout << "hojk" << endl;
            flag=1;
            deleteArray(buf, bytesReceived);
        }else{
            if(turn){
                int sendRes = send(this->sock, word, sizeof(word) + 1, 0);
                int bytesReceived = recv(this->sock, buf, 4096, 0);
                newWord = bytesTransformer(bytesReceived,buf,newWord);
                this->dataServ = (newWord).c_str();
                d.Parse(dataServ);
                turn = d["turn"].GetBool();
                deleteArray(buf, bytesReceived);
            }else{
                cout << "1" <<endl;
                int bytesReceived = recv(this->sock, buf, 4096, 0);
                                cout << buf << endl;
                cout << "2" <<endl;
                newWord = bytesTransformer(bytesReceived,buf,newWord);
                cout << newWord << endl;
                cout << "3" <<endl;
                this->dataServ = (newWord).c_str();
                d.Parse(dataServ);
                turn = d["turn"].GetBool();
                deleteArray(buf, bytesReceived);
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
