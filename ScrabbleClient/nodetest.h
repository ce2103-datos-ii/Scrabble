#include <QLabel>
#ifndef NODETEST_H
#define NODETEST_H


class NodeTest
{
public:
    int x1;
    int x2;
    int y1;
    int y2;
    QLabel* qLabel;
    NodeTest(int x1, int x2,int y1, int y2, QLabel* qLabel);
};

#endif // NODETEST_H
