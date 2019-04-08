//
// Created by ivan on 3/24/19.
//

#include "JsonParser.h"

HashMap hashMap;

//void JsonParser::jsonSend(const char* json) {
//    Document d1;
//    StringBuffer buffer;
//    d1.Parse(json);
//    assert(d1.IsObject());
//    cout << json << endl;
//    cout << "\ndespués del cambio en el código:\n" << endl;
//    Value& s = d1["score"];
//    s.SetInt(s.GetInt() + 1);
//    Writer<StringBuffer> writer(buffer);
//    d1.Accept(writer);
//    return buffer.GetString();
//}

string JsonParser::jsonReceive(const char* json) {
    Document d1;
    d1.Parse(json);
    if (d1.HasMember("playerCount")){
        players->setPlayerCount(d1["playerCount"].GetInt());
        players->deletePlayers();
        players->setCode(d1["code"].GetInt());
        players->player1->setId(d1["id"].GetString());
        cont += 1;
        // aceptar conexión
    } else if (d1.HasMember("code")) {
        if (d1["code"].GetInt() == players->getCode()) {
            if (cont == 2)
                players->player2->setId(d1["id"].GetString());
            else if (cont == 3)
                players->player3->setId(d1["id"].GetString());
            else if (cont == 4)
                players->player4->setId(d1["id"].GetString());
            //acepta conexión
        } else {
            //no acepta conexión
        }
    }if (d1.HasMember("word")){
        if (fileReader.searchWord(string(json))) {
            d1["score"].SetInt(d1["score"].GetInt() + hashMap.checkWordScore(d1["letters"].GetString()));
            if (players->player1->getId() == d1["id"].GetString())
                players->player1->setId() += d1["score"].GetInt();
            if (players->player2->getId() == d1["id"].GetString())
                players->player2->setId() += d1["score"].GetInt();
            if (players->player3->getId() == d1["id"].GetString())
                players->player3->setId() += d1["score"].GetInt();
            if (players->player4->getId() == d1["id"].GetString())
                players->player4->setId() += d1["score"].GetInt();
            return; //aquí función para pasar el string con el puntaje asociado
        } else {
            return; //devuelve 0 al cliente
        }
    } players->manageTurns();
}
