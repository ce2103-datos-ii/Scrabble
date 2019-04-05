#include "listnode.h"


ListNode::ListNode()
{
    m_num_nodes = 0;
    m_head = NULL;
}

void ListNode::add_head(string element, int column, int row)
{
    NodeList *new_node = new NodeList(column, row, element);
    NodeList *temp = m_head;

    if (!m_head) {
        m_head = new_node;
    } else {
        new_node->next = m_head;
        m_head = new_node;

        while (temp) {
            temp = temp->next;
        }
    }
    m_num_nodes++;
}

void ListNode::del_all()
{
    m_head->delete_all();
    m_head = 0;
}

void ListNode::print()
{
    NodeList *temp = m_head;
    if (!m_head) {
        cout << "La Lista está vacía " << endl;
    } else {
        while (temp) {
            temp->print();
            if (!temp->next) cout << "NULL";
            temp = temp->next;
        }
    }
    cout << endl << endl;
}

void ListNode::del_by_data(int column, int row){
    NodeList *temp = m_head;
    NodeList *temp1 = m_head->next;

    int cont = 0;

    if (m_head->row == row && m_head->column==column) {
        m_head = temp->next;
    } else {
        while (temp1) {
            if (temp1->row == row && temp1->column == column) {
                NodeList *aux_node = temp1;
                temp->next = temp1->next;
                delete aux_node;
                cont++;
                m_num_nodes--;
            }
            temp = temp->next;
            temp1 = temp1->next;
        }
    }

    if (cont == 0) {
        cout << "No existe el dato " << endl;
    }
}
