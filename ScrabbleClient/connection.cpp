#include "connection.h"
#include "ui_connection.h"
#include "mainwindow.h"

Connection::Connection(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Connection)
{

    ui->setupUi(this);
    ui->label->setText();
}

Connection::~Connection()
{
    delete ui;
}
