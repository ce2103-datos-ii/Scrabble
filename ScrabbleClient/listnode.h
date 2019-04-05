#include <iostream>
#include "nodelist.h"

using namespace std;

#ifndef LISTNODE_H
#define LISTNODE_H


class ListNode
{
public:
    NodeList *m_head;
    void add_head(string element, int column, int row);
    void List();
    void del_all();
    void print();
    ListNode();
    void del_by_data(int column, int row);
private:
    int m_num_nodes;
};

#endif // LISTNODE_H
