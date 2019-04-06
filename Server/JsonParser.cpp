//
// Created by ivan on 3/24/19.
//

#include "JsonParser.h"

Players players;


string JsonParser::jsonSend(const char* json) {
    json = "{\n"
           "    \"turn\": false,\n"
           "    \"score\": 3\n"
           "}";
    Document d;
    StringBuffer buffer;
    d.Parse(json);
    assert(d.IsObject());
    assert(d.HasMember("score"));
    assert(d["score"].IsNumber());
    cout << json << endl;
    cout << "\ndespués del cambio en el código:\n" << endl;
    Value& s = d["score"];
    s.SetInt(s.GetInt() + 1);
    Writer<StringBuffer> writer(buffer);
    d.Accept(writer);
    return buffer.GetString();
}

void JsonParser::jsonReceive(const char* json) {
    Document d;
    d.Parse(json);
    if (d.HasMember("word")){
        if (fileReader.searchWord(string(json)))
            return; //aquí función para pasar el string con el puntaje asociado
        else
            return; //devuelve 0 al cliente

    }
    if (d["id"] == 1){
        players.player1.setScore(d["score"].GetInt());
        players.player1.setTurn(false);
        players.player2.setTurn(true);
    } else if (d["id"] == 2){
        players.player2.setScore(d["score"].GetInt());
        players.player2.setTurn(false);
        players.player3.setTurn(true);
    } else if (d["id"] == 3){
        players.player3.setScore(d["score"].GetInt());
        players.player3.setTurn(false);
        players.player4.setTurn(true);
    } else if (d["id"] == 4){
        players.player4.setScore(d["score"].GetInt());
        players.player4.setTurn(false);
        players.player1.setTurn(true);
    }
}
