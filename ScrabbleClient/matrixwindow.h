#ifndef MATRIXWINDOW_H
#define MATRIXWINDOW_H

#include <QDialog>
#include <iostream>
#include <QLabel>
#include "listnode.h"
using namespace std;

namespace Ui {
class MatrixWindow;
}

class MatrixWindow : public QDialog
{
    Q_OBJECT


public:
    int posX;
    int posY;
    explicit MatrixWindow(QWidget *parent = nullptr);
    ~MatrixWindow();

private slots:
    void on_pushButton_2_clicked();
    void on_Btn1_clicked();
    void mousePressEvent(QMouseEvent *ev);
    void validatespace(int column, int row, string element, QLabel &label);
    void validatespaceAux(int column, int row, string element, QLabel &label);
    string transformer(ListNode list, string word);

    void on_Btn2_clicked();

    void on_Btn3_clicked();

    void on_Btn4_clicked();

    void on_Btn5_clicked();

    void on_Btn6_clicked();

    void on_Btn7_clicked();

    void on_Btn8_clicked();

    void on_Btn9_clicked();

    void on_Btn10_clicked();

    void on_pushButton_clicked();

private:
    Ui::MatrixWindow *ui;
};


#endif // MATRIXWINDOW_H
