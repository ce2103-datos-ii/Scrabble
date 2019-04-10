#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "instructions.h"
#include "matrixwindow.h"


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
    string name = ui->lineEdit->text().toUtf8().constData(); // nombre
    string playerCount = ui->lineEdit_2->text().toUtf8().constData(); // numero de jugadores
    string code = ui->lineEdit_3->text().toUtf8().constData(); //código del jugador
    const char* jsonPlayerHost = "{\n"
                                 "    \"playerCount\": 0,\n"
                                 "    \"code\": null,\n"
                                 "    \"id\": 3,\n"
                                 "    \"port\": 0\n"
                                 "}";
    rapidjson::Document d;
    d.Parse(jsonPlayerHost);
    d["id"].SetString(name.data(), name.size(), d.GetAllocator());
    d["playerCount"].SetInt(atoi(playerCount.c_str()));
    d["code"].SetInt(atoi(code.c_str()));
    StringBuffer buffer;
    buffer.Clear();
    Writer<StringBuffer> writer(buffer);
    d.Accept(writer);
    client = new Client(true,0);
    client->connection(54000);
    client->comunication(buffer.GetString());
    client->turn = true;
    this->hide();
    MatrixWindow matrixWindow;
    this->client = matrixWindow.client;
    matrixWindow.setModal(true);
    matrixWindow.exec();
    this->close();

}

void MainWindow::on_pushButton_4_clicked()
{
    string name = ui->lineEdit->text().toUtf8().constData(); // nombre
    string code = ui->lineEdit_3->text().toUtf8().constData(); //código del jugador
    const char* jsonPlayerClient = "{\n"
                                   "    \"code\": null,\n"
                                   "    \"id\": 3,\n"
                                   "    \"port\": 0\n"
                                   "}";
    rapidjson::Document d;
    d.Parse(jsonPlayerClient);
    d["id"].SetString(name.data(), name.size(), d.GetAllocator());
    d["code"].SetInt(atoi(code.c_str()));
    StringBuffer buffer;
    buffer.Clear();
    Writer<StringBuffer> writer(buffer);
    d.Accept(writer);
    client = new Client(false, 0);
    client->connection(54000);
    client->comunication(buffer.GetString());
    client->turn = false;
    if(d["access"].GetString() != "no"){
        this->hide();
        MatrixWindow matrixWindow;
        this->client = matrixWindow.client;
        matrixWindow.setModal(true);
        matrixWindow.exec();
        this->close();
    }
}
