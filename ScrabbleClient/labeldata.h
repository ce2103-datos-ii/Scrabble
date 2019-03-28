#ifndef LABELDATA_H
#define LABELDATA_H

#include <QLabel>

class labelData
{
public:
    int x1;
    int x2;
    int y1;
    int y2;
    QLabel la;
    labelData(QLabel l, int x1, int x2, int y1, int y2);
};

#endif // LABELDATA_H
