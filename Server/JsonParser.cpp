//
// Created by ivan on 3/24/19.
//

#include "JsonParser.h"

HashMap hashMap;
Communication communication;

//void JsonParser::jsonSend(const char* json) {
//    Document d;
//    StringBuffer buffer;
//    d.Parse(json);
//    assert(d.IsObject());
//    cout << json << endl;
//    cout << "\ndespués del cambio en el código:\n" << endl;
//    Value& s = d["score"];
//    s.SetInt(s.GetInt() + 1);
//    Writer<StringBuffer> writer(buffer);
//    d.Accept(writer);
//    return buffer.GetString();
//}

void JsonParser::jsonReceive() {
    Document d;
    char buf[4096];
//    memset(buf,0,4096);
//    cout << Players::shared_instance().checkTurn()->getPort() << endl;
//    cout << Players::shared_instance().player1->getPort() << endl;
//    cout << "btr" << endl;
//    try {
//        int bytesRecived = recv(port1, buf, 4096, 0);
//
//    } catch (exception exception1){
//        cout << exception1 << endl;
//        cout << "no corre" << endl;
//    }
//    sleep(3);
//    const char *jsonStart = "{\n"
//                            "    \"start\": true\n"
//                            "}";
//    string jsonStartString = jsonStart;
//    cout << "sent1" << endl;
//    send(port1, jsonStart, checkJsonSize(jsonStartString), 0);
//    cout << "sent2" << endl;
//    send(port2, jsonStart, checkJsonSize(jsonStartString), 0);
    cout << "player1 id: ";
    cout << Players::shared_instance().player1->getId() << endl;
    cout << "player socket: ";
    cout << Players::shared_instance().checkTurn() << endl;
    int bytesReceived = recv(Players::shared_instance().checkTurn(), buf, 4096, 0);
    cout << "checkTurn: ";
    cout << Players::shared_instance().checkTurn() << endl;
    d.Parse(buf);
    cout << "buf:";
    cout << buf << endl;
    cout << "bytesReceived: ";
    cout << bytesReceived << endl;
    assert(d.IsObject());
    Players::shared_instance().setMatrix(d["matrix"].GetString());
    if (d.HasMember("word")){
        cout << d["word"].GetString() << endl;
        if (fileReader.searchWord(string(d["word"].GetString()))) {
            d["score"].SetInt(d["score"].GetInt() + hashMap.checkWordScore(d["letters"].GetString()));
            cout << d["score"].GetInt() << endl;
            cout << "id: ";
            cout << d["id"].GetString() << endl;
            cout << "player id: ";
            cout << Players::shared_instance().player1->getId() << endl;
            HashMap hashMap;
            Players::shared_instance().setLetters(hashMap.lettersToSend(d["letters"].GetString()));
            if (Players::shared_instance().player1->getId() == d["id"].GetString()) {
                Players::shared_instance().player1->setScore(d["score"].GetInt());
                StringBuffer buffer;
                buffer.Clear();
                Writer<StringBuffer> writer(buffer);
                d.Accept(writer);
                string buffString = buffer.GetString();
                cout << buffer.GetString() << endl;
                Players::shared_instance().manageTurns(buffer.GetString());
//                send(port1, buffer.GetString(), checkJsonSize(buffString), 0);
            }
            else if (Players::shared_instance().player2->getId() == d["id"].GetString())
                Players::shared_instance().player2->setScore(d["score"].GetInt());
            else if (Players::shared_instance().player3->getId() == d["id"].GetString())
                Players::shared_instance().player3->setScore(d["score"].GetInt());
            else if (Players::shared_instance().player4->getId() == d["id"].GetString())
                Players::shared_instance().player4->setScore(d["score"].GetInt());
//            return; //aquí función para pasar el string con el puntaje asociado
//        return json;
        } else {
//            return; //devuelve 0 al cliente
        }
    }
}

int JsonParser::checkJsonSize(string str) {
    int sizeOfWord;
    for (char &c: str)
        sizeOfWord++;
    return sizeOfWord;
}


void JsonParser::firstConnection() {
    char buf[4096];
    int clientSocket;
    const char* json = "";
    memset(buf, 0, 4096);
    cout << "portCount: ";
    cout << portCount << endl;
    if (portCount == 0) {
        clientSocket = communication.connection(port1);
        Players::shared_instance().player1->setPlayerSocket(clientSocket);
        cout << "port1" << endl;
        portCount++;
    } else {
        clientSocket = communication.connection(port2);
        Players::shared_instance().player2->setPlayerSocket(clientSocket);
        cout << "port 2" << endl;
    }
    int bytesRecived = recv(clientSocket, buf, 4096, 0);
    Document d;
    d.Parse(buf);
    cout << "buf:";
    cout << buf << endl;
    assert(d.IsObject());
    if (d.HasMember("playerCount")){
//        communication.connection(#porthost);
        cout << "int" << endl;
        assert(d["playerCount"].GetInt());
        cout << "playerCount before change: ";
        cout << Players::shared_instance().getPlayerCount() << endl;
        Players::shared_instance().setPlayerCount(d["playerCount"].GetInt());
        cout << "playerCount after change: ";
        cout << Players::shared_instance().getPlayerCount() << endl;
        Players::shared_instance().deletePlayers();
        Players::shared_instance().setCode(d["code"].GetInt());
        Players::shared_instance().player1->setId(d["id"].GetString());
//        d["port"].SetInt(Players::shared_instance().player1->getPort());
//        cout << d["port"].GetInt() << endl;
        StringBuffer buffer;
        buffer.Clear();
        Writer<StringBuffer> writer(buffer);
        d.Accept(writer);
        string buffString = buffer.GetString();
        send(clientSocket, buffer.GetString(), checkJsonSize(buffString) + 1, 0);
        cout << buffer.GetString() << endl;
//        close(clientSocket);
        cont += 1;
//        send(Players::shared_instance().checkTurn(),buffer.GetString(),checkJsonSize(buffString),0);
    } else if (d.HasMember("code")) {
        if (d["code"].GetInt() == Players::shared_instance().getCode()) {
            cout << "code" << endl;
            if (cont == 1) {
                Players::shared_instance().player2->setId(d["id"].GetString());
//                d["port"].SetInt(Players::shared_instance().player2->getPort());
                StringBuffer buffer;
                buffer.Clear();
                Writer<StringBuffer> writer(buffer);
                d.Accept(writer);
                string buffString = buffer.GetString();
                cout << "adf" << endl;
                cout << buffer.GetString() << endl;
                send(clientSocket, buffer.GetString(), checkJsonSize(buffString) + 1, 0);
//                close(clientSocket);
                cont++;
            } else if (cont == 2) {
                Players::shared_instance().player3->setId(d["id"].GetString());
                d["port"].SetInt(Players::shared_instance().player3->getPort());
            } else if (cont == 3) {
                Players::shared_instance().player4->setId(d["id"].GetString());
                d["port"].SetInt(Players::shared_instance().player4->getPort());
            }
            if (cont == Players::shared_instance().getPlayerCount()) {
                const char *jsonStart = "{\n"
                                        "    \"start\": true\n"
                                        "}";
                string jsonStartString = jsonStart;
                send(port1, jsonStart, checkJsonSize(jsonStartString), 0);
                send(port2, jsonStart, checkJsonSize(jsonStartString), 0);
            }
//            return json;
            // aceptar cliente y enviar json
//            communication.connection(#socketquelemandoelservidoralcliente);
        } else {
            // negar cliente
//            close(communication.connection(#socketquelemandoelservidoralcliente));
        }
    }deleteArray(buf, bytesRecived);
}


void JsonParser::checkGameState() {
    if (cont == 0 || !(cont == Players::shared_instance().getPlayerCount())){
        cout << "first" << endl;
        cout << "cont: ";
        cout << cont << endl;
        cout << "playerCount: ";
        cout << Players::shared_instance().getPlayerCount() << endl;
        firstConnection();
    } else {
        jsonReceive();
    }
}

void JsonParser::deleteArray(char arr[], int bytes) {
    for (int i = 0; i < bytes; i++)
        arr[i] = NULL;
}



//const char *JsonParser::charArrayToConstChar(char ch[]) {
//    const char* json;
//    for (int i = 0; i < ch.)
//    return nullptr;
//}

//string JsonParser::charToString(const char * ch) {
//    string str;
//    for (int i = 0; i!= sizeof(ch), i++)
//        str +=
//    return std::__cxx11::string();
//}
