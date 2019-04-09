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

const char* JsonParser::jsonReceive() {
    Players::shared_instance().setPorts();
    const char* json = "";
    char buf[4096];
    int clientSocket = communication.connection(54000);
    int bytesRecived = recv(clientSocket, buf, 4096, 0);
    cout<<buf<<endl;
    Document d;
    d.Parse(buf);
    assert(d.IsObject());
    if (d.HasMember("playerCount")){
//        communication.connection(#porthost);
        cout << "int" << endl;
        assert(d["playerCount"].GetInt());
        Players::shared_instance().setPlayerCount(d["playerCount"].GetInt());
        Players::shared_instance().deletePlayers();
        Players::shared_instance().setCode(d["code"].GetInt());
        Players::shared_instance().player1->setId(d["id"].GetString());
        d["port"].SetInt(Players::shared_instance().player1->getPort());
        StringBuffer buffer;
        buffer.Clear();
        Writer<StringBuffer> writer(buffer);
        d.Accept(writer);
        string buffString = buffer.GetString();
        send(clientSocket, buffer.GetString(), checkJsonSize(buffString), 0);
        cout << buffer.GetString() << endl;
        close(clientSocket);
        Players::shared_instance().player1->setPlayerSocket(communication.connection(Players::shared_instance().player1->getPort()));
        JsonParser::cont += 1;

        send(Players::shared_instance().player1->getPlayerSocket(),buffer.GetString(),checkJsonSize(buffString),0);
        // aceptar host y enviar json
    } else if (d.HasMember("code")) {
        if (d["code"].GetInt() == Players::shared_instance().getCode()) {
            if (cont == 2) {
                Players::shared_instance().player2->setId(d["id"].GetString());
                d["port"].SetInt(Players::shared_instance().player2->getPort());
            }
            else if (cont == 3) {
                Players::shared_instance().player3->setId(d["id"].GetString());
                d["port"].SetInt(Players::shared_instance().player3->getPort());
            }
            else if (cont == 4){
                Players::shared_instance().player4->setId(d["id"].GetString());
                d["port"].SetInt(Players::shared_instance().player4->getPort());
            }
            return json;
            // aceptar cliente y enviar json
//            communication.connection(#socketquelemandoelservidoralcliente);
        } else {
            // negar cliente
//            close(communication.connection(#socketquelemandoelservidoralcliente));
        }
    }if (d.HasMember("word")){
        if (fileReader.searchWord(string(json))) {
            d["score"].SetInt(d["score"].GetInt() + hashMap.checkWordScore(d["letters"].GetString()));
            if (Players::shared_instance().player1->getId() == d["id"].GetString())
                Players::shared_instance().player1->setScore(d["score"].GetInt());
            if (Players::shared_instance().player2->getId() == d["id"].GetString())
                Players::shared_instance().player2->setScore(d["score"].GetInt());
            if (Players::shared_instance().player3->getId() == d["id"].GetString())
                Players::shared_instance().player3->setScore(d["score"].GetInt());
            if (Players::shared_instance().player4->getId() == d["id"].GetString())
                Players::shared_instance().player4->setScore(d["score"].GetInt());
//            return; //aquí función para pasar el string con el puntaje asociado
        return json;
        } else {
//            return; //devuelve 0 al cliente
        }
    } Players::shared_instance().manageTurns();
}

int JsonParser::checkJsonSize(string str) {
    int sizeOfWord;
    for (char &c: str)
        sizeOfWord++;
    return sizeOfWord;
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
