#ifndef MATRIXWINDOW_H
#define MATRIXWINDOW_H

#include <QDialog>
#include <iostream>
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

private:
    Ui::MatrixWindow *ui;
};


#endif // MATRIXWINDOW_H
