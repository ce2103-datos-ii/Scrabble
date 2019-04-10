#include <iostream>
#include "rapidjson/rapidjson.h"
#include "rapidjson/document.h"
#include "rapidjson/stringbuffer.h"
#include "rapidjson/writer.h"

using namespace std;

#ifndef NODELIST_H
#define NODELIST_H


class NodeList
{
public:
    int column;
    int row;
    string element;
    NodeList *next;
    NodeList(int column, int row, string element);
    void print();
    void delete_all();

};

#endif // NODELIST_H
