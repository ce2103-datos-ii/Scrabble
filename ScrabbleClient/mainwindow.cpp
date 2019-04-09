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
    const char* name = ui->lineEdit->text().toUtf8().constData(); // nombre
    const char* numPlayers = ui->lineEdit_2->text().toUtf8().constData(); // numero de jugadores
    const char* code = ui->lineEdit_3->text().toUtf8().constData(); //código del jugador
    const char* jsonPlayerHost = "{\n"
                                 "    \"id\": 3\n"
                                 "    \"numPlayers\": 0\n"
                                 "    \"code\": null\n"
                                 "}";
    Document d;
    d.Parse(jsonPlayerHost);
    d["id"].SetString(StringRef(name));
    d["numPlayer"].SetString(StringRef(numPlayers));
    d["code"].SetString(StringRef(code));
    client = new Client(true,0,true);
    client->connection(54000);
    client->comunication(jsonPlayerHost);
    this->hide();
    MatrixWindow matrixWindow;
    matrixWindow.setModal(true);
    matrixWindow.exec();
    this->close();

}

void MainWindow::on_pushButton_4_clicked()
{
    const char* name = ui->lineEdit->text().toUtf8().constData(); // nombre
    const char* code = ui->lineEdit_3->text().toUtf8().constData(); //código del jugador
    client = new Client(true,0,true);
    const char* jsonPlayerClient = "{\n"
                                   "    \"id\": 3\n"
                                   "    \"code\": null\n"
                                   "}";
    Document d;
    d.Parse(jsonPlayerClient);
    d["id"].SetString(StringRef(name));
    d["code"].SetString(StringRef(code));
    client->connection(54000);
    client->comunication(jsonPlayerClient);
    if(d["access"].GetString() != "no"){
        this->hide();
        MatrixWindow matrixWindow;
        matrixWindow.setModal(true);
        matrixWindow.exec();
        this->close();
    }
}
