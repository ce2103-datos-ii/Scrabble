#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "matrixwindow.h"
#include "instructions.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    this->hide();
    MatrixWindow matrixWindow;
    matrixWindow.setModal(true);
    matrixWindow.exec();
    this->close();
}

void MainWindow::on_pushButton_2_clicked()
{
    this->hide();
    Instructions instructionWindow;
    instructionWindow.setModal(true);
    instructionWindow.exec();
    this->show();
}
