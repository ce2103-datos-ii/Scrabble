#include "nodelist.h"

NodeList::NodeList(int column, int row, string element){
    this->column = column;
    this->row = row;
    this->element = element;
    next = NULL;
}

void NodeList::print(){
    cout << "Column: " << column << endl;
    cout << "Row: " << row << endl;
    cout << "Element: " << element << endl;
}

void NodeList::delete_all(){
    if (next)
        next->delete_all();
    delete this;
}
