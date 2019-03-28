#ifndef DATALABEL_H
#define DATALABEL_H

#import <QLabel>

class dataLabel
{
public:
    int x1;
    int x2;
    int y1;
    int y2;
    QLabel l;
    dataLabel(QLabel l, int x1, int x2, int y1, int y2);
};

#endif // DATALABEL_H
