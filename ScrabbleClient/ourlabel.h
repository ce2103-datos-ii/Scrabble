#include <QLabel>
#ifndef OURLABEL_H
#define OURLABEL_H


class OurLabel
{
public:
    int x1;
    int x2;
    int y1;
    int y2;
    QLabel* Lbl;
    OurLabel(int pos1, int pos2, int pos3, int pos4, QLabel* Ql);
};

#endif // OURLABEL_H
