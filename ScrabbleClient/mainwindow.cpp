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

void MainWindow::on_pushButton_2_clicked()
{
    this->hide();
    Instructions instructionWindow;
    instructionWindow.setModal(true);
    instructionWindow.exec();
    this->show();
}

void MainWindow::on_pushButton_3_clicked()
{
    const char* l = "Connected";
    string a = ui->lineEdit->text().toUtf8().constData(); // nombre
    string b = ui->lineEdit_2->text().toUtf8().constData(); // numero de jugadores
    string c = ui->lineEdit_3->text().toUtf8().constData(); //código del jugador

    client = new Client(true,0,true);
    client->connection();
    client->comunication(l);
    this->hide();
    MatrixWindow matrixWindow;
    matrixWindow.setModal(true);
    matrixWindow.exec();
    this->close();

}
