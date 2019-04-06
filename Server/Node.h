//
// Created by ivan on 4/6/19.
//

#ifndef SCRABBLE_NODE_H
#define SCRABBLE_NODE_H


#include <iostream>

using namespace std;

template <class T>

class Node
{
public:
    Node();
    Node(T);
    ~Node();

    Node *next;
    T data;

    void delete_all();
    void print();
};


#endif //SCRABBLE_NODE_H
