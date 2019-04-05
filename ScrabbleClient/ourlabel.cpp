#include "ourlabel.h"

OurLabel::OurLabel(int pos1, int pos2, int pos3, int pos4, QLabel* Ql)
{
    this->x1=pos1;
    this->x2=pos2;
    this->y1=pos3;
    this->y2=pos4;
    this->Lbl=Ql;
}
