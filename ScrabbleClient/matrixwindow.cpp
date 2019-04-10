#include "matrixwindow.h"
#include "ui_matrixwindow.h"
#include <QPixmap>
#include <QMouseEvent>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>

using namespace std;
static string b = "";
static string g [15][15];
static ListNode *listh = new ListNode();
static ListNode *listscore = new ListNode();
static int currentRow = NULL;
static int currentColumn = NULL;

QString qs;

MatrixWindow::MatrixWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MatrixWindow)
{
    ui->setupUi(this);
    ui->Btn1->setStyleSheet("background-color:gray");
    ui->Btn2->setStyleSheet("background-color:gray");
    ui->Btn3->setStyleSheet("background-color:gray");
    ui->Btn4->setStyleSheet("background-color:gray");
    ui->Btn5->setStyleSheet("background-color:gray");
    ui->Btn6->setStyleSheet("background-color:gray");
    ui->Btn7->setStyleSheet("background-color:gray");
    ui->Btn8->setStyleSheet("background-color:gray");
    ui->Btn9->setStyleSheet("background-color:gray");
    ui->Btn10->setStyleSheet("background-color:gray");
    string hum[26] {"a","b","c","d","e","f","g","h","i","j","k","l","m","n","o","p","q","r","s","t","u","v","w","x","y","z"};
    srand(time(NULL));
    ui->Btn1->setText(QString::fromStdString("a"));
    ui->Btn2->setText(QString::fromStdString(hum[rand()%26]));
    ui->Btn3->setText(QString::fromStdString(hum[rand()%26]));
    ui->Btn4->setText(QString::fromStdString(hum[rand()%26]));
    ui->Btn5->setText(QString::fromStdString("a"));
    ui->Btn6->setText(QString::fromStdString(hum[rand()%26]));
    ui->Btn7->setText(QString::fromStdString(hum[rand()%26]));
    ui->Btn8->setText(QString::fromStdString(hum[rand()%26]));
    ui->Btn9->setText(QString::fromStdString("l"));
    ui->Btn10->setText(QString::fromStdString(hum[rand()%26]));
    qs = ui->Lbl1->text();
}

void MatrixWindow::PlayerTurn(){
    if(MatrixWindow::client->turn){
    }else{
        update();
        PlayerTurn();
    }
}

MatrixWindow::~MatrixWindow(){
    delete ui;
}

void MatrixWindow::mousePressEvent(QMouseEvent *event){
    this->posX = event->x();
    this->posY = event->y();
    if (posX>37&&posX<75&&posY>37&&posY<75){
        validatespace(0,0,b,*(ui->Lbl1));
    }
    if (posX>75&&posX<113&&posY>37&&posY<75){
        validatespace(1,0,b,*(ui->Lbl2));
    }
    if (posX>113&&posX<151&&posY>37&&posY<75){
        validatespace(2,0,b,*(ui->Lbl3));
    }
    if (posX>151&&posX<189&&posY>37&&posY<75){
        validatespace(3,0,b,*(ui->Lbl4));
    }
    if (posX>189&&posX<227&&posY>37&&posY<75){
        validatespace(4,0,b,*(ui->Lbl5));
    }
    if (posX>227&&posX<265&&posY>37&&posY<75){
        validatespace(5,0,b,*(ui->Lbl6));
    }
    if (posX>265&&posX<303&&posY>37&&posY<75){
        validatespace(6,0,b,*(ui->Lbl7));
    }
    if (posX>303&&posX<341&&posY>37&&posY<75){
        validatespace(7,0,b,*(ui->Lbl8));
    }
    if (posX>341&&posX<379&&posY>37&&posY<75){
        validatespace(8,0,b,*(ui->Lbl9));
    }
    if (posX>379&&posX<417&&posY>37&&posY<75){
        validatespace(9,0,b,*(ui->Lbl10));
    }
    if (posX>417&&posX<455&&posY>37&&posY<75){
        validatespace(10,0,b,*(ui->Lbl11));
    }
    if (posX>455&&posX<493&&posY>37&&posY<75){
        validatespace(11,0,b,*(ui->Lbl12));
    }
    if (posX>493&&posX<531&&posY>37&&posY<75){
        validatespace(12,0,b,*(ui->Lbl13));
    }
    if (posX>531&&posX<569&&posY>37&&posY<75){
        validatespace(13,0,b,*(ui->Lbl14));
    }
    if (posX>569&&posX<607&&posY>37&&posY<75){
        validatespace(14,0,b,*(ui->Lbl15));
    }
    if (posX>37&&posX<75&&posY>75&&posY<113){
        validatespace(0,1,b,*(ui->Lbl16));
    }
    if (posX>75&&posX<113&&posY>75&&posY<113){
        validatespace(1,1,b,*(ui->Lbl17));
    }
    if (posX>113&&posX<151&&posY>75&&posY<113){
        validatespace(2,1,b,*(ui->Lbl18));
    }
    if (posX>151&&posX<189&&posY>75&&posY<113){
        validatespace(3,1,b,*(ui->Lbl19));
    }
    if (posX>189&&posX<227&&posY>75&&posY<113){
        validatespace(4,1,b,*(ui->Lbl20));
    }
    if (posX>227&&posX<265&&posY>75&&posY<113){
        validatespace(5,1,b,*(ui->Lbl21));
    }
    if (posX>265&&posX<303&&posY>75&&posY<113){
        validatespace(6,1,b,*(ui->Lbl22));
    }
    if (posX>303&&posX<341&&posY>75&&posY<113){
        validatespace(7,1,b,*(ui->Lbl23));
    }
    if (posX>341&&posX<379&&posY>75&&posY<113){
        validatespace(8,1,b,*(ui->Lbl24));
    }
    if (posX>379&&posX<417&&posY>75&&posY<113){
        validatespace(9,1,b,*(ui->Lbl25));
    }
    if (posX>417&&posX<455&&posY>75&&posY<113){
        validatespace(10,1,b,*(ui->Lbl26));
    }
    if (posX>455&&posX<493&&posY>75&&posY<113){
        validatespace(11,1,b,*(ui->Lbl27));
    }
    if (posX>493&&posX<531&&posY>75&&posY<113){
        validatespace(12,1,b,*(ui->Lbl28));
    }
    if (posX>531&&posX<569&&posY>75&&posY<113){
        validatespace(13,1,b,*(ui->Lbl29));
    }
    if (posX>569&&posX<607&&posY>75&&posY<113){
        validatespace(14,1,b,*(ui->Lbl30));
    }
    if (posX>37&&posX<75&&posY>113&&posY<151){
        validatespace(0,2,b,*(ui->Lbl31));
    }
    if (posX>75&&posX<113&&posY>113&&posY<151){
        validatespace(1,2,b,*(ui->Lbl32));
    }
    if (posX>113&&posX<151&&posY>113&&posY<151){
        validatespace(2,2,b,*(ui->Lbl33));
    }
    if (posX>151&&posX<189&&posY>113&&posY<151){
        validatespace(3,2,b,*(ui->Lbl34));
    }
    if (posX>189&&posX<227&&posY>113&&posY<151){
        validatespace(4,2,b,*(ui->Lbl35));
    }
    if (posX>227&&posX<265&&posY>113&&posY<151){
        validatespace(5,2,b,*(ui->Lbl36));
    }
    if (posX>265&&posX<303&&posY>113&&posY<151){
        validatespace(6,2,b,*(ui->Lbl37));
    }
    if (posX>303&&posX<341&&posY>113&&posY<151){
        validatespace(7,2,b,*(ui->Lbl38));
    }
    if (posX>341&&posX<379&&posY>113&&posY<151){
        validatespace(8,2,b,*(ui->Lbl39));
    }
    if (posX>379&&posX<417&&posY>113&&posY<151){
        validatespace(9,2,b,*(ui->Lbl40));
    }
    if (posX>417&&posX<455&&posY>113&&posY<151){
        validatespace(10,2,b,*(ui->Lbl41));
    }
    if (posX>455&&posX<493&&posY>113&&posY<151){
        validatespace(11,2,b,*(ui->Lbl42));
    }
    if (posX>493&&posX<531&&posY>113&&posY<151){
        validatespace(12,2,b,*(ui->Lbl43));
    }
    if (posX>531&&posX<569&&posY>113&&posY<151){
        validatespace(13,2,b,*(ui->Lbl44));
    }
    if (posX>569&&posX<607&&posY>113&&posY<151){
        validatespace(14,2,b,*(ui->Lbl45));
    }
    if (posX>37&&posX<75&&posY>151&&posY<189){
        validatespace(0,3,b,*(ui->Lbl46));
    }
    if (posX>75&&posX<113&&posY>151&&posY<189){
        validatespace(1,3,b,*(ui->Lbl47));
    }
    if (posX>113&&posX<151&&posY>151&&posY<189){
        validatespace(2,3,b,*(ui->Lbl48));
    }
    if (posX>151&&posX<189&&posY>151&&posY<189){
        validatespace(3,3,b,*(ui->Lbl49));
    }
    if (posX>189&&posX<227&&posY>151&&posY<189){
        validatespace(4,3,b,*(ui->Lbl50));
    }
    if (posX>227&&posX<265&&posY>151&&posY<189){
        validatespace(5,3,b,*(ui->Lbl51));
    }
    if (posX>265&&posX<303&&posY>151&&posY<189){
        validatespace(6,3,b,*(ui->Lbl52));
    }
    if (posX>303&&posX<341&&posY>151&&posY<189){
        validatespace(7,3,b,*(ui->Lbl53));
    }
    if (posX>341&&posX<379&&posY>151&&posY<189){
        validatespace(8,3,b,*(ui->Lbl54));
    }
    if (posX>379&&posX<417&&posY>151&&posY<189){
        validatespace(9,3,b,*(ui->Lbl55));
    }
    if (posX>417&&posX<455&&posY>151&&posY<189){
        validatespace(10,3,b,*(ui->Lbl56));
    }
    if (posX>455&&posX<493&&posY>151&&posY<189){
        validatespace(11,3,b,*(ui->Lbl57));
    }
    if (posX>493&&posX<531&&posY>151&&posY<189){
        validatespace(12,3,b,*(ui->Lbl58));
    }
    if (posX>531&&posX<569&&posY>151&&posY<189){
        validatespace(13,3,b,*(ui->Lbl59));
    }
    if (posX>569&&posX<607&&posY>151&&posY<189){
        validatespace(14,3,b,*(ui->Lbl60));
    }
    if (posX>37&&posX<75&&posY>189&&posY<227){
        validatespace(0,4,b,*(ui->Lbl61));
    }
    if (posX>75&&posX<113&&posY>189&&posY<227){
        validatespace(1,4,b,*(ui->Lbl62));
    }
    if (posX>113&&posX<151&&posY>189&&posY<227){
        validatespace(2,4,b,*(ui->Lbl63));
    }
    if (posX>151&&posX<189&&posY>189&&posY<227){
        validatespace(3,4,b,*(ui->Lbl64));
    }
    if (posX>189&&posX<227&&posY>189&&posY<227){
        validatespace(4,4,b,*(ui->Lbl65));
    }
    if (posX>227&&posX<265&&posY>189&&posY<227){
        validatespace(5,4,b,*(ui->Lbl66));
    }
    if (posX>265&&posX<303&&posY>189&&posY<227){
        validatespace(6,4,b,*(ui->Lbl67));
    }
    if (posX>303&&posX<341&&posY>189&&posY<227){
        validatespace(7,4,b,*(ui->Lbl68));
    }
    if (posX>341&&posX<379&&posY>189&&posY<227){
        validatespace(8,4,b,*(ui->Lbl69));
    }
    if (posX>379&&posX<417&&posY>189&&posY<227){
        validatespace(9,4,b,*(ui->Lbl70));
    }
    if (posX>417&&posX<455&&posY>189&&posY<227){
        validatespace(10,4,b,*(ui->Lbl71));
    }
    if (posX>455&&posX<493&&posY>189&&posY<227){
        validatespace(11,4,b,*(ui->Lbl72));
    }
    if (posX>493&&posX<531&&posY>189&&posY<227){
        validatespace(12,4,b,*(ui->Lbl73));
    }
    if (posX>531&&posX<569&&posY>189&&posY<227){
        validatespace(13,4,b,*(ui->Lbl74));
    }
    if (posX>569&&posX<607&&posY>189&&posY<227){
        validatespace(14,4,b,*(ui->Lbl75));
    }
    if (posX>37&&posX<75&&posY>227&&posY<265){
        validatespace(0,5,b,*(ui->Lbl76));
    }
    if (posX>75&&posX<113&&posY>227&&posY<265){
        validatespace(1,5,b,*(ui->Lbl77));
    }
    if (posX>113&&posX<151&&posY>227&&posY<265){
        validatespace(2,5,b,*(ui->Lbl78));
    }
    if (posX>151&&posX<189&&posY>227&&posY<265){
        validatespace(3,5,b,*(ui->Lbl79));
    }
    if (posX>189&&posX<227&&posY>227&&posY<265){
        validatespace(4,5,b,*(ui->Lbl80));
    }
    if (posX>227&&posX<265&&posY>227&&posY<265){
        validatespace(5,5,b,*(ui->Lbl81));
    }
    if (posX>265&&posX<303&&posY>227&&posY<265){
        validatespace(6,5,b,*(ui->Lbl82));
    }
    if (posX>303&&posX<341&&posY>227&&posY<265){
        validatespace(7,5,b,*(ui->Lbl83));
    }
    if (posX>341&&posX<379&&posY>227&&posY<265){
        validatespace(8,5,b,*(ui->Lbl84));
    }
    if (posX>379&&posX<417&&posY>227&&posY<265){
        validatespace(9,5,b,*(ui->Lbl85));
    }
    if (posX>417&&posX<455&&posY>227&&posY<265){
        validatespace(10,5,b,*(ui->Lbl86));
    }
    if (posX>455&&posX<493&&posY>227&&posY<265){
        validatespace(11,5,b,*(ui->Lbl87));
    }
    if (posX>493&&posX<531&&posY>227&&posY<265){
        validatespace(12,5,b,*(ui->Lbl88));
    }
    if (posX>531&&posX<569&&posY>227&&posY<265){
        validatespace(13,5,b,*(ui->Lbl89));
    }
    if (posX>569&&posX<607&&posY>227&&posY<265){
        validatespace(14,5,b,*(ui->Lbl90));
    }
    if (posX>37&&posX<75&&posY>265&&posY<303){
        validatespace(0,6,b,*(ui->Lbl91));
    }
    if (posX>75&&posX<113&&posY>265&&posY<303){
        validatespace(1,6,b,*(ui->Lbl92));
    }
    if (posX>113&&posX<151&&posY>265&&posY<303){
        validatespace(2,6,b,*(ui->Lbl93));
    }
    if (posX>151&&posX<189&&posY>265&&posY<303){
        validatespace(3,6,b,*(ui->Lbl94));
    }
    if (posX>189&&posX<227&&posY>265&&posY<303){
        validatespace(4,6,b,*(ui->Lbl95));
    }
    if (posX>227&&posX<265&&posY>265&&posY<303){
        validatespace(5,6,b,*(ui->Lbl96));
    }
    if (posX>265&&posX<303&&posY>265&&posY<303){
        validatespace(6,6,b,*(ui->Lbl97));
    }
    if (posX>303&&posX<341&&posY>265&&posY<303){
        validatespace(7,6,b,*(ui->Lbl98));
    }
    if (posX>341&&posX<379&&posY>265&&posY<303){
        validatespace(8,6,b,*(ui->Lbl99));
    }
    if (posX>379&&posX<417&&posY>265&&posY<303){
        validatespace(9,6,b,*(ui->Lbl100));
    }
    if (posX>417&&posX<455&&posY>265&&posY<303){
        validatespace(10,6,b,*(ui->Lbl101));
    }
    if (posX>455&&posX<493&&posY>265&&posY<303){
        validatespace(11,6,b,*(ui->Lbl102));
    }
    if (posX>493&&posX<531&&posY>265&&posY<303){
        validatespace(12,6,b,*(ui->Lbl103));
    }
    if (posX>531&&posX<569&&posY>265&&posY<303){
        validatespace(13,6,b,*(ui->Lbl104));
    }
    if (posX>569&&posX<607&&posY>265&&posY<303){
        validatespace(14,6,b,*(ui->Lbl105));
    }
    if (posX>37&&posX<75&&posY>303&&posY<341){
        validatespace(0,7,b,*(ui->Lbl106));
    }
    if (posX>75&&posX<113&&posY>303&&posY<341){
        validatespace(1,7,b,*(ui->Lbl107));
    }
    if (posX>113&&posX<151&&posY>303&&posY<341){
        validatespace(2,7,b,*(ui->Lbl108));
    }
    if (posX>151&&posX<189&&posY>303&&posY<341){
        validatespace(3,7,b,*(ui->Lbl109));
    }
    if (posX>189&&posX<227&&posY>303&&posY<341){
        validatespace(4,7,b,*(ui->Lbl110));
    }
    if (posX>227&&posX<265&&posY>303&&posY<341){
        validatespace(5,7,b,*(ui->Lbl111));
    }
    if (posX>265&&posX<303&&posY>303&&posY<341){
        validatespace(6,7,b,*(ui->Lbl112));
    }
    if (posX>303&&posX<341&&posY>303&&posY<341){
        validatespace(7,7,b,*(ui->Lbl113));
    }
    if (posX>341&&posX<379&&posY>303&&posY<341){
        validatespace(8,7,b,*(ui->Lbl114));
    }
    if (posX>379&&posX<417&&posY>303&&posY<341){
        validatespace(9,7,b,*(ui->Lbl115));
    }
    if (posX>417&&posX<455&&posY>303&&posY<341){
        validatespace(10,7,b,*(ui->Lbl116));
    }
    if (posX>455&&posX<493&&posY>303&&posY<341){
        validatespace(11,7,b,*(ui->Lbl117));
    }
    if (posX>493&&posX<531&&posY>303&&posY<341){
        validatespace(12,7,b,*(ui->Lbl118));
    }
    if (posX>531&&posX<569&&posY>303&&posY<341){
        validatespace(13,7,b,*(ui->Lbl119));
    }
    if (posX>569&&posX<607&&posY>303&&posY<341){
        validatespace(14,7,b,*(ui->Lbl120));
    }
    if (posX>37&&posX<75&&posY>341&&posY<379){
        validatespace(0,8,b,*(ui->Lbl121));
    }
    if (posX>75&&posX<113&&posY>341&&posY<379){
        validatespace(1,8,b,*(ui->Lbl122));
    }
    if (posX>113&&posX<151&&posY>341&&posY<379){
        validatespace(2,8,b,*(ui->Lbl123));
    }
    if (posX>151&&posX<189&&posY>341&&posY<379){
        validatespace(3,8,b,*(ui->Lbl124));
    }
    if (posX>189&&posX<227&&posY>341&&posY<379){
        validatespace(4,8,b,*(ui->Lbl125));
    }
    if (posX>227&&posX<265&&posY>341&&posY<379){
        validatespace(5,8,b,*(ui->Lbl126));
    }
    if (posX>265&&posX<303&&posY>341&&posY<379){
        validatespace(6,8,b,*(ui->Lbl127));
    }
    if (posX>303&&posX<341&&posY>341&&posY<379){
        validatespace(7,8,b,*(ui->Lbl128));
    }
    if (posX>341&&posX<379&&posY>341&&posY<379){
        validatespace(8,8,b,*(ui->Lbl129));
    }
    if (posX>379&&posX<417&&posY>341&&posY<379){
        validatespace(9,8,b,*(ui->Lbl130));
    }
    if (posX>417&&posX<455&&posY>341&&posY<379){
        validatespace(10,8,b,*(ui->Lbl131));
    }
    if (posX>455&&posX<493&&posY>341&&posY<379){
        validatespace(11,8,b,*(ui->Lbl132));
    }
    if (posX>493&&posX<531&&posY>341&&posY<379){
        validatespace(12,8,b,*(ui->Lbl133));
    }
    if (posX>531&&posX<569&&posY>341&&posY<379){
        validatespace(13,8,b,*(ui->Lbl134));
    }
    if (posX>569&&posX<607&&posY>341&&posY<379){
        validatespace(14,8,b,*(ui->Lbl135));
    }
    if (posX>37&&posX<75&&posY>379&&posY<417){
        validatespace(0,9,b,*(ui->Lbl136));
    }
    if (posX>75&&posX<113&&posY>379&&posY<417){
        validatespace(1,9,b,*(ui->Lbl137));
    }
    if (posX>113&&posX<151&&posY>379&&posY<417){
        validatespace(2,9,b,*(ui->Lbl138));
    }
    if (posX>151&&posX<189&&posY>379&&posY<417){
        validatespace(3,9,b,*(ui->Lbl139));
    }
    if (posX>189&&posX<227&&posY>379&&posY<417){
        validatespace(4,9,b,*(ui->Lbl140));
    }
    if (posX>227&&posX<265&&posY>379&&posY<417){
        validatespace(5,9,b,*(ui->Lbl141));
    }
    if (posX>265&&posX<303&&posY>379&&posY<417){
        validatespace(6,9,b,*(ui->Lbl142));
    }
    if (posX>303&&posX<341&&posY>379&&posY<417){
        validatespace(7,9,b,*(ui->Lbl143));
    }
    if (posX>341&&posX<379&&posY>379&&posY<417){
        validatespace(8,9,b,*(ui->Lbl144));
    }
    if (posX>379&&posX<417&&posY>379&&posY<417){
        validatespace(9,9,b,*(ui->Lbl145));
    }
    if (posX>417&&posX<455&&posY>379&&posY<417){
        validatespace(10,9,b,*(ui->Lbl146));
    }
    if (posX>455&&posX<493&&posY>379&&posY<417){
        validatespace(11,9,b,*(ui->Lbl147));
    }
    if (posX>493&&posX<531&&posY>379&&posY<417){
        validatespace(12,9,b,*(ui->Lbl148));
    }
    if (posX>531&&posX<569&&posY>379&&posY<417){
        validatespace(13,9,b,*(ui->Lbl149));
    }
    if (posX>569&&posX<607&&posY>379&&posY<417){
        validatespace(14,9,b,*(ui->Lbl150));
    }
    if (posX>37&&posX<75&&posY>417&&posY<455){
        validatespace(0,10,b,*(ui->Lbl151));
    }
    if (posX>75&&posX<113&&posY>417&&posY<455){
        validatespace(1,10,b,*(ui->Lbl152));
    }
    if (posX>113&&posX<151&&posY>417&&posY<455){
        validatespace(2,10,b,*(ui->Lbl153));
    }
    if (posX>151&&posX<189&&posY>417&&posY<455){
        validatespace(3,10,b,*(ui->Lbl154));
    }
    if (posX>189&&posX<227&&posY>417&&posY<455){
        validatespace(4,10,b,*(ui->Lbl155));
    }
    if (posX>227&&posX<265&&posY>417&&posY<455){
        validatespace(5,10,b,*(ui->Lbl156));
    }
    if (posX>265&&posX<303&&posY>417&&posY<455){
        validatespace(6,10,b,*(ui->Lbl157));
    }
    if (posX>303&&posX<341&&posY>417&&posY<455){
        validatespace(7,10,b,*(ui->Lbl158));
    }
    if (posX>341&&posX<379&&posY>417&&posY<455){
        validatespace(8,10,b,*(ui->Lbl159));
    }
    if (posX>379&&posX<417&&posY>417&&posY<455){
        validatespace(9,10,b,*(ui->Lbl160));
    }
    if (posX>417&&posX<455&&posY>417&&posY<455){
        validatespace(10,10,b,*(ui->Lbl161));
    }
    if (posX>455&&posX<493&&posY>417&&posY<455){
        validatespace(11,10,b,*(ui->Lbl162));
    }
    if (posX>493&&posX<531&&posY>417&&posY<455){
        validatespace(12,10,b,*(ui->Lbl163));
    }
    if (posX>531&&posX<569&&posY>417&&posY<455){
        validatespace(13,10,b,*(ui->Lbl164));
    }
    if (posX>569&&posX<607&&posY>417&&posY<455){
        validatespace(14,10,b,*(ui->Lbl165));
    }
    if (posX>37&&posX<75&&posY>455&&posY<493){
        validatespace(0,11,b,*(ui->Lbl166));
    }
    if (posX>75&&posX<113&&posY>455&&posY<493){
        validatespace(1,11,b,*(ui->Lbl167));
    }
    if (posX>113&&posX<151&&posY>455&&posY<493){
        validatespace(2,11,b,*(ui->Lbl168));
    }
    if (posX>151&&posX<189&&posY>455&&posY<493){
        validatespace(3,11,b,*(ui->Lbl169));
    }
    if (posX>189&&posX<227&&posY>455&&posY<493){
        validatespace(4,11,b,*(ui->Lbl170));
    }
    if (posX>227&&posX<265&&posY>455&&posY<493){
        validatespace(5,11,b,*(ui->Lbl171));
    }
    if (posX>265&&posX<303&&posY>455&&posY<493){
        validatespace(6,11,b,*(ui->Lbl172));
    }
    if (posX>303&&posX<341&&posY>455&&posY<493){
        validatespace(7,11,b,*(ui->Lbl173));
    }
    if (posX>341&&posX<379&&posY>455&&posY<493){
        validatespace(8,11,b,*(ui->Lbl174));
    }
    if (posX>379&&posX<417&&posY>455&&posY<493){
        validatespace(9,11,b,*(ui->Lbl175));
    }
    if (posX>417&&posX<455&&posY>455&&posY<493){
        validatespace(10,11,b,*(ui->Lbl176));
    }
    if (posX>455&&posX<493&&posY>455&&posY<493){
        validatespace(11,11,b,*(ui->Lbl177));
    }
    if (posX>493&&posX<531&&posY>455&&posY<493){
        validatespace(12,11,b,*(ui->Lbl178));
    }
    if (posX>531&&posX<569&&posY>455&&posY<493){
        validatespace(13,11,b,*(ui->Lbl179));
    }
    if (posX>569&&posX<607&&posY>455&&posY<493){
        validatespace(14,11,b,*(ui->Lbl180));
    }
    if (posX>37&&posX<75&&posY>493&&posY<531){
        validatespace(0,12,b,*(ui->Lbl181));
    }
    if (posX>75&&posX<113&&posY>493&&posY<531){
        validatespace(1,12,b,*(ui->Lbl182));
    }
    if (posX>113&&posX<151&&posY>493&&posY<531){
        validatespace(2,12,b,*(ui->Lbl183));
    }
    if (posX>151&&posX<189&&posY>493&&posY<531){
        validatespace(3,12,b,*(ui->Lbl184));
    }
    if (posX>189&&posX<227&&posY>493&&posY<531){
        validatespace(4,12,b,*(ui->Lbl185));
    }
    if (posX>227&&posX<265&&posY>493&&posY<531){
        validatespace(5,12,b,*(ui->Lbl186));
    }
    if (posX>265&&posX<303&&posY>493&&posY<531){
        validatespace(6,12,b,*(ui->Lbl187));
    }
    if (posX>303&&posX<341&&posY>493&&posY<531){
        validatespace(7,12,b,*(ui->Lbl188));
    }
    if (posX>341&&posX<379&&posY>493&&posY<531){
        validatespace(8,12,b,*(ui->Lbl189));
    }
    if (posX>379&&posX<417&&posY>493&&posY<531){
        validatespace(9,12,b,*(ui->Lbl190));
    }
    if (posX>417&&posX<455&&posY>493&&posY<531){
        validatespace(10,12,b,*(ui->Lbl191));
    }
    if (posX>455&&posX<493&&posY>493&&posY<531){
        validatespace(11,12,b,*(ui->Lbl192));
    }
    if (posX>493&&posX<531&&posY>493&&posY<531){
        validatespace(12,12,b,*(ui->Lbl193));
    }
    if (posX>531&&posX<569&&posY>493&&posY<531){
        validatespace(13,12,b,*(ui->Lbl194));
    }
    if (posX>569&&posX<607&&posY>493&&posY<531){
        validatespace(14,12,b,*(ui->Lbl195));
    }
    if (posX>37&&posX<75&&posY>531&&posY<569){
        validatespace(0,13,b,*(ui->Lbl196));
    }
    if (posX>75&&posX<113&&posY>531&&posY<569){
        validatespace(1,13,b,*(ui->Lbl197));
    }
    if (posX>113&&posX<151&&posY>531&&posY<569){
        validatespace(2,13,b,*(ui->Lbl198));
    }
    if (posX>151&&posX<189&&posY>531&&posY<569){
        validatespace(3,13,b,*(ui->Lbl199));
    }
    if (posX>189&&posX<227&&posY>531&&posY<569){
        validatespace(4,13,b,*(ui->Lbl200));
    }
    if (posX>227&&posX<265&&posY>531&&posY<569){
        validatespace(5,13,b,*(ui->Lbl201));
    }
    if (posX>265&&posX<303&&posY>531&&posY<569){
        validatespace(6,13,b,*(ui->Lbl202));
    }
    if (posX>303&&posX<341&&posY>531&&posY<569){
        validatespace(7,13,b,*(ui->Lbl203));
    }
    if (posX>341&&posX<379&&posY>531&&posY<569){
        validatespace(8,13,b,*(ui->Lbl204));
    }
    if (posX>379&&posX<417&&posY>531&&posY<569){
        validatespace(9,13,b,*(ui->Lbl205));
    }
    if (posX>417&&posX<455&&posY>531&&posY<569){
        validatespace(10,13,b,*(ui->Lbl206));
    }
    if (posX>455&&posX<493&&posY>531&&posY<569){
        validatespace(11,13,b,*(ui->Lbl207));
    }
    if (posX>493&&posX<531&&posY>531&&posY<569){
        validatespace(12,13,b,*(ui->Lbl208));
    }
    if (posX>531&&posX<569&&posY>531&&posY<569){
        validatespace(13,13,b,*(ui->Lbl209));
    }
    if (posX>569&&posX<607&&posY>531&&posY<569){
        validatespace(14,13,b,*(ui->Lbl210));
    }
    if (posX>37&&posX<75&&posY>569&&posY<607){
        validatespace(0,14,b,*(ui->Lbl211));
    }
    if (posX>75&&posX<113&&posY>569&&posY<607){
        validatespace(1,14,b,*(ui->Lbl212));
    }
    if (posX>113&&posX<151&&posY>569&&posY<607){
        validatespace(2,14,b,*(ui->Lbl213));
    }
    if (posX>151&&posX<189&&posY>569&&posY<607){
        validatespace(3,14,b,*(ui->Lbl214));
    }
    if (posX>189&&posX<227&&posY>569&&posY<607){
        validatespace(4,14,b,*(ui->Lbl215));
    }
    if (posX>227&&posX<265&&posY>569&&posY<607){
        validatespace(5,14,b,*(ui->Lbl216));
    }
    if (posX>265&&posX<303&&posY>569&&posY<607){
        validatespace(6,14,b,*(ui->Lbl217));
    }
    if (posX>303&&posX<341&&posY>569&&posY<607){
        validatespace(7,14,b,*(ui->Lbl218));
    }
    if (posX>341&&posX<379&&posY>569&&posY<607){
        validatespace(8,14,b,*(ui->Lbl219));
    }
    if (posX>379&&posX<417&&posY>569&&posY<607){
        validatespace(9,14,b,*(ui->Lbl220));
    }
    if (posX>417&&posX<455&&posY>569&&posY<607){
        validatespace(10,14,b,*(ui->Lbl221));
    }
    if (posX>455&&posX<493&&posY>569&&posY<607){
        validatespace(11,14,b,*(ui->Lbl222));
    }
    if (posX>493&&posX<531&&posY>569&&posY<607){
        validatespace(12,14,b,*(ui->Lbl223));
    }
    if (posX>531&&posX<569&&posY>569&&posY<607){
        validatespace(13,14,b,*(ui->Lbl224));
    }
    if (posX>569&&posX<607&&posY>569&&posY<607){
        validatespace(14,14,b,*(ui->Lbl225));
    }
}

void MatrixWindow::validatespace(int column, int row, string element, QLabel &label){
    if(listh->m_head == NULL){
        if(label.text() != qs){
            listh->add_head(label.text().toUtf8().constData(), column, row);
        }else{
            validatespaceAux(column, row, element, label);
        }
    }
    else if (listh->m_head->next == NULL) {
        if((listh->m_head->row) + 1 == row && (listh->m_head->column) == column){
            if(label.text() != qs){
                listh->add_head(label.text().toUtf8().constData(), column, row);
            }else{
                validatespaceAux(column, row, element, label);
            }
            currentRow = 1;
        }
        else if((listh->m_head->row) - 1 == row && (listh->m_head->column) == column){
            if(label.text() != qs){
                listh->add_head(label.text().toUtf8().constData(), column, row);
            }else{
                validatespaceAux(column, row, element, label);
            }
            currentRow = -1;
        }
        else if ((listh->m_head->column + 1 == column && listh->m_head->row == row )){
            if(label.text() != qs){
                listh->add_head(label.text().toUtf8().constData(), column, row);
            }else{
                validatespaceAux(column, row, element, label);
            }
            currentColumn = 1;
        }
        else if(listh->m_head->column - 1 == column && listh->m_head->row == row ){
            if(label.text() != qs){
                listh->add_head(label.text().toUtf8().constData(), column, row);
            }else{
                validatespaceAux(column, row, element, label);
            }
            currentColumn = -1;
        }
        else if(listh->m_head->row == row && column == listh->m_head->column){
            validatespaceAux(column, row, element, label);
        }
    }
    else if(listh->m_head->next != NULL){
        if(listh->m_head->row == row && column == listh->m_head->column){
            validatespaceAux(column, row, element, label);
        }
        else if(currentRow == 1 && row == listh->m_head->row + 1 && column == listh->m_head->column){
            if(label.text() != qs){
                listh->add_head(label.text().toUtf8().constData(), column, row);

            }else{
                validatespaceAux(column, row, element, label);
            }
        }else if (currentRow == -1 && row == listh->m_head->row -1 && column == listh->m_head->column) {
            if(label.text() != qs){
                listh->add_head(label.text().toUtf8().constData(), column, row);
            }else{
                validatespaceAux(column, row, element, label);
            }
        }
        else if(currentColumn == 1 && column == listh->m_head->column +1 && row == listh->m_head->row){
            if(label.text() != qs){
                listh->add_head(label.text().toUtf8().constData(), column, row);
            }else{
                validatespaceAux(column, row, element, label);
            }
        }else if (currentColumn == -1 && column == listh->m_head->column -1 && row == listh->m_head->row) {
            if(label.text() != qs){
                listh->add_head(label.text().toUtf8().constData(), column, row);
            }else{
                validatespaceAux(column, row, element, label);
            }
        }
    }
}

void MatrixWindow::update(){
    bool letter = false;
    int i = 0;
    int n = 0;
    string Matrix[15][15];
    MatrixWindow::client->comunication("");
    Document d;
    d.Parse(MatrixWindow::client->dataServ);
    string MatrixString = d["matrix"].GetString();
    while (i < 15){
        while (n < 15){
            for (char &c: (MatrixString)) {
                string s(1, c);
                if (s == "{")
                    letter = true;
                else if (i == 15)
                    return;
                if (letter == true){
                    Matrix[i][n] = s;
                    letter = false;
                    n++;
                    if (n == 15){
                        i++;
                        n = 0;
                    }
                }
            }
        }
    }
    for(i = 0; i<15;i++){
        for(n = 0; n<15; n++){
            g[i][n] = Matrix[i][n];
        }
    }
    ui->Lbl1->setText(QString::fromStdString(Matrix[0][0]));
    ui->Lbl2->setText(QString::fromStdString(Matrix[0][1]));
    ui->Lbl3->setText(QString::fromStdString(Matrix[0][2]));
    ui->Lbl4->setText(QString::fromStdString(Matrix[0][3]));
    ui->Lbl5->setText(QString::fromStdString(Matrix[0][4]));
    ui->Lbl6->setText(QString::fromStdString(Matrix[0][5]));
    ui->Lbl7->setText(QString::fromStdString(Matrix[0][6]));
    ui->Lbl8->setText(QString::fromStdString(Matrix[0][7]));
    ui->Lbl9->setText(QString::fromStdString(Matrix[0][8]));
    ui->Lbl10->setText(QString::fromStdString(Matrix[0][9]));
    ui->Lbl11->setText(QString::fromStdString(Matrix[0][10]));
    ui->Lbl12->setText(QString::fromStdString(Matrix[0][11]));
    ui->Lbl13->setText(QString::fromStdString(Matrix[0][12]));
    ui->Lbl14->setText(QString::fromStdString(Matrix[0][13]));
    ui->Lbl15->setText(QString::fromStdString(Matrix[0][14]));
    ui->Lbl16->setText(QString::fromStdString(Matrix[1][0]));
    ui->Lbl17->setText(QString::fromStdString(Matrix[1][1]));
    ui->Lbl18->setText(QString::fromStdString(Matrix[1][2]));
    ui->Lbl19->setText(QString::fromStdString(Matrix[1][3]));
    ui->Lbl20->setText(QString::fromStdString(Matrix[1][4]));
    ui->Lbl21->setText(QString::fromStdString(Matrix[1][5]));
    ui->Lbl22->setText(QString::fromStdString(Matrix[1][6]));
    ui->Lbl23->setText(QString::fromStdString(Matrix[1][7]));
    ui->Lbl24->setText(QString::fromStdString(Matrix[1][8]));
    ui->Lbl25->setText(QString::fromStdString(Matrix[1][9]));
    ui->Lbl26->setText(QString::fromStdString(Matrix[1][10]));
    ui->Lbl27->setText(QString::fromStdString(Matrix[1][11]));
    ui->Lbl28->setText(QString::fromStdString(Matrix[1][12]));
    ui->Lbl29->setText(QString::fromStdString(Matrix[1][13]));
    ui->Lbl30->setText(QString::fromStdString(Matrix[1][14]));
    ui->Lbl31->setText(QString::fromStdString(Matrix[2][0]));
    ui->Lbl32->setText(QString::fromStdString(Matrix[2][1]));
    ui->Lbl33->setText(QString::fromStdString(Matrix[2][2]));
    ui->Lbl34->setText(QString::fromStdString(Matrix[2][3]));
    ui->Lbl35->setText(QString::fromStdString(Matrix[2][4]));
    ui->Lbl36->setText(QString::fromStdString(Matrix[2][5]));
    ui->Lbl37->setText(QString::fromStdString(Matrix[2][6]));
    ui->Lbl38->setText(QString::fromStdString(Matrix[2][7]));
    ui->Lbl39->setText(QString::fromStdString(Matrix[2][8]));
    ui->Lbl40->setText(QString::fromStdString(Matrix[2][9]));
    ui->Lbl41->setText(QString::fromStdString(Matrix[2][10]));
    ui->Lbl42->setText(QString::fromStdString(Matrix[2][11]));
    ui->Lbl43->setText(QString::fromStdString(Matrix[2][12]));
    ui->Lbl44->setText(QString::fromStdString(Matrix[2][13]));
    ui->Lbl45->setText(QString::fromStdString(Matrix[2][14]));
    ui->Lbl46->setText(QString::fromStdString(Matrix[3][0]));
    ui->Lbl47->setText(QString::fromStdString(Matrix[3][1]));
    ui->Lbl48->setText(QString::fromStdString(Matrix[3][2]));
    ui->Lbl49->setText(QString::fromStdString(Matrix[3][3]));
    ui->Lbl50->setText(QString::fromStdString(Matrix[3][4]));
    ui->Lbl51->setText(QString::fromStdString(Matrix[3][5]));
    ui->Lbl52->setText(QString::fromStdString(Matrix[3][6]));
    ui->Lbl53->setText(QString::fromStdString(Matrix[3][7]));
    ui->Lbl54->setText(QString::fromStdString(Matrix[3][8]));
    ui->Lbl55->setText(QString::fromStdString(Matrix[3][9]));
    ui->Lbl56->setText(QString::fromStdString(Matrix[3][10]));
    ui->Lbl57->setText(QString::fromStdString(Matrix[3][11]));
    ui->Lbl58->setText(QString::fromStdString(Matrix[3][12]));
    ui->Lbl59->setText(QString::fromStdString(Matrix[3][13]));
    ui->Lbl60->setText(QString::fromStdString(Matrix[3][14]));
    ui->Lbl61->setText(QString::fromStdString(Matrix[4][0]));
    ui->Lbl62->setText(QString::fromStdString(Matrix[4][1]));
    ui->Lbl63->setText(QString::fromStdString(Matrix[4][2]));
    ui->Lbl64->setText(QString::fromStdString(Matrix[4][3]));
    ui->Lbl65->setText(QString::fromStdString(Matrix[4][4]));
    ui->Lbl66->setText(QString::fromStdString(Matrix[4][5]));
    ui->Lbl67->setText(QString::fromStdString(Matrix[4][6]));
    ui->Lbl68->setText(QString::fromStdString(Matrix[4][7]));
    ui->Lbl69->setText(QString::fromStdString(Matrix[4][8]));
    ui->Lbl70->setText(QString::fromStdString(Matrix[4][9]));
    ui->Lbl71->setText(QString::fromStdString(Matrix[4][10]));
    ui->Lbl72->setText(QString::fromStdString(Matrix[4][11]));
    ui->Lbl73->setText(QString::fromStdString(Matrix[4][12]));
    ui->Lbl74->setText(QString::fromStdString(Matrix[4][13]));
    ui->Lbl75->setText(QString::fromStdString(Matrix[4][14]));
    ui->Lbl76->setText(QString::fromStdString(Matrix[5][0]));
    ui->Lbl77->setText(QString::fromStdString(Matrix[5][1]));
    ui->Lbl78->setText(QString::fromStdString(Matrix[5][2]));
    ui->Lbl79->setText(QString::fromStdString(Matrix[5][3]));
    ui->Lbl80->setText(QString::fromStdString(Matrix[5][4]));
    ui->Lbl81->setText(QString::fromStdString(Matrix[5][5]));
    ui->Lbl82->setText(QString::fromStdString(Matrix[5][6]));
    ui->Lbl83->setText(QString::fromStdString(Matrix[5][7]));
    ui->Lbl84->setText(QString::fromStdString(Matrix[5][8]));
    ui->Lbl85->setText(QString::fromStdString(Matrix[5][9]));
    ui->Lbl86->setText(QString::fromStdString(Matrix[5][10]));
    ui->Lbl87->setText(QString::fromStdString(Matrix[5][11]));
    ui->Lbl88->setText(QString::fromStdString(Matrix[5][12]));
    ui->Lbl89->setText(QString::fromStdString(Matrix[5][13]));
    ui->Lbl90->setText(QString::fromStdString(Matrix[5][14]));
    ui->Lbl91->setText(QString::fromStdString(Matrix[6][0]));
    ui->Lbl92->setText(QString::fromStdString(Matrix[6][1]));
    ui->Lbl93->setText(QString::fromStdString(Matrix[6][2]));
    ui->Lbl94->setText(QString::fromStdString(Matrix[6][3]));
    ui->Lbl95->setText(QString::fromStdString(Matrix[6][4]));
    ui->Lbl96->setText(QString::fromStdString(Matrix[6][5]));
    ui->Lbl97->setText(QString::fromStdString(Matrix[6][6]));
    ui->Lbl98->setText(QString::fromStdString(Matrix[6][7]));
    ui->Lbl99->setText(QString::fromStdString(Matrix[6][8]));
    ui->Lbl100->setText(QString::fromStdString(Matrix[6][9]));
    ui->Lbl101->setText(QString::fromStdString(Matrix[6][10]));
    ui->Lbl102->setText(QString::fromStdString(Matrix[6][11]));
    ui->Lbl103->setText(QString::fromStdString(Matrix[6][12]));
    ui->Lbl104->setText(QString::fromStdString(Matrix[6][13]));
    ui->Lbl105->setText(QString::fromStdString(Matrix[6][14]));
    ui->Lbl106->setText(QString::fromStdString(Matrix[7][0]));
    ui->Lbl107->setText(QString::fromStdString(Matrix[7][1]));
    ui->Lbl108->setText(QString::fromStdString(Matrix[7][2]));
    ui->Lbl109->setText(QString::fromStdString(Matrix[7][3]));
    ui->Lbl110->setText(QString::fromStdString(Matrix[7][4]));
    ui->Lbl111->setText(QString::fromStdString(Matrix[7][5]));
    ui->Lbl112->setText(QString::fromStdString(Matrix[7][6]));
    ui->Lbl113->setText(QString::fromStdString(Matrix[7][7]));
    ui->Lbl114->setText(QString::fromStdString(Matrix[7][8]));
    ui->Lbl115->setText(QString::fromStdString(Matrix[7][9]));
    ui->Lbl116->setText(QString::fromStdString(Matrix[7][10]));
    ui->Lbl117->setText(QString::fromStdString(Matrix[7][11]));
    ui->Lbl118->setText(QString::fromStdString(Matrix[7][12]));
    ui->Lbl119->setText(QString::fromStdString(Matrix[7][13]));
    ui->Lbl120->setText(QString::fromStdString(Matrix[7][14]));
    ui->Lbl121->setText(QString::fromStdString(Matrix[8][0]));
    ui->Lbl122->setText(QString::fromStdString(Matrix[8][1]));
    ui->Lbl123->setText(QString::fromStdString(Matrix[8][2]));
    ui->Lbl124->setText(QString::fromStdString(Matrix[8][3]));
    ui->Lbl125->setText(QString::fromStdString(Matrix[8][4]));
    ui->Lbl126->setText(QString::fromStdString(Matrix[8][5]));
    ui->Lbl127->setText(QString::fromStdString(Matrix[8][6]));
    ui->Lbl128->setText(QString::fromStdString(Matrix[8][7]));
    ui->Lbl129->setText(QString::fromStdString(Matrix[8][8]));
    ui->Lbl130->setText(QString::fromStdString(Matrix[8][9]));
    ui->Lbl131->setText(QString::fromStdString(Matrix[8][10]));
    ui->Lbl132->setText(QString::fromStdString(Matrix[8][11]));
    ui->Lbl133->setText(QString::fromStdString(Matrix[8][12]));
    ui->Lbl134->setText(QString::fromStdString(Matrix[8][13]));
    ui->Lbl135->setText(QString::fromStdString(Matrix[8][14]));
    ui->Lbl136->setText(QString::fromStdString(Matrix[9][0]));
    ui->Lbl137->setText(QString::fromStdString(Matrix[9][1]));
    ui->Lbl138->setText(QString::fromStdString(Matrix[9][2]));
    ui->Lbl139->setText(QString::fromStdString(Matrix[9][3]));
    ui->Lbl140->setText(QString::fromStdString(Matrix[9][4]));
    ui->Lbl141->setText(QString::fromStdString(Matrix[9][5]));
    ui->Lbl142->setText(QString::fromStdString(Matrix[9][6]));
    ui->Lbl143->setText(QString::fromStdString(Matrix[9][7]));
    ui->Lbl144->setText(QString::fromStdString(Matrix[9][8]));
    ui->Lbl145->setText(QString::fromStdString(Matrix[9][9]));
    ui->Lbl146->setText(QString::fromStdString(Matrix[9][10]));
    ui->Lbl147->setText(QString::fromStdString(Matrix[9][11]));
    ui->Lbl148->setText(QString::fromStdString(Matrix[9][12]));
    ui->Lbl149->setText(QString::fromStdString(Matrix[9][13]));
    ui->Lbl150->setText(QString::fromStdString(Matrix[9][14]));
    ui->Lbl151->setText(QString::fromStdString(Matrix[10][0]));
    ui->Lbl152->setText(QString::fromStdString(Matrix[10][1]));
    ui->Lbl153->setText(QString::fromStdString(Matrix[10][2]));
    ui->Lbl154->setText(QString::fromStdString(Matrix[10][3]));
    ui->Lbl155->setText(QString::fromStdString(Matrix[10][4]));
    ui->Lbl156->setText(QString::fromStdString(Matrix[10][5]));
    ui->Lbl157->setText(QString::fromStdString(Matrix[10][6]));
    ui->Lbl158->setText(QString::fromStdString(Matrix[10][7]));
    ui->Lbl159->setText(QString::fromStdString(Matrix[10][8]));
    ui->Lbl160->setText(QString::fromStdString(Matrix[10][9]));
    ui->Lbl161->setText(QString::fromStdString(Matrix[10][10]));
    ui->Lbl162->setText(QString::fromStdString(Matrix[10][11]));
    ui->Lbl163->setText(QString::fromStdString(Matrix[10][12]));
    ui->Lbl164->setText(QString::fromStdString(Matrix[10][13]));
    ui->Lbl165->setText(QString::fromStdString(Matrix[10][14]));
    ui->Lbl166->setText(QString::fromStdString(Matrix[11][0]));
    ui->Lbl167->setText(QString::fromStdString(Matrix[11][1]));
    ui->Lbl168->setText(QString::fromStdString(Matrix[11][2]));
    ui->Lbl169->setText(QString::fromStdString(Matrix[11][3]));
    ui->Lbl170->setText(QString::fromStdString(Matrix[11][4]));
    ui->Lbl171->setText(QString::fromStdString(Matrix[11][5]));
    ui->Lbl172->setText(QString::fromStdString(Matrix[11][6]));
    ui->Lbl173->setText(QString::fromStdString(Matrix[11][7]));
    ui->Lbl174->setText(QString::fromStdString(Matrix[11][8]));
    ui->Lbl175->setText(QString::fromStdString(Matrix[11][9]));
    ui->Lbl176->setText(QString::fromStdString(Matrix[11][10]));
    ui->Lbl177->setText(QString::fromStdString(Matrix[11][11]));
    ui->Lbl178->setText(QString::fromStdString(Matrix[11][12]));
    ui->Lbl179->setText(QString::fromStdString(Matrix[11][13]));
    ui->Lbl180->setText(QString::fromStdString(Matrix[11][14]));
    ui->Lbl181->setText(QString::fromStdString(Matrix[12][0]));
    ui->Lbl182->setText(QString::fromStdString(Matrix[12][1]));
    ui->Lbl183->setText(QString::fromStdString(Matrix[12][2]));
    ui->Lbl184->setText(QString::fromStdString(Matrix[12][3]));
    ui->Lbl185->setText(QString::fromStdString(Matrix[12][4]));
    ui->Lbl186->setText(QString::fromStdString(Matrix[12][5]));
    ui->Lbl187->setText(QString::fromStdString(Matrix[12][6]));
    ui->Lbl188->setText(QString::fromStdString(Matrix[12][7]));
    ui->Lbl189->setText(QString::fromStdString(Matrix[12][8]));
    ui->Lbl190->setText(QString::fromStdString(Matrix[12][9]));
    ui->Lbl191->setText(QString::fromStdString(Matrix[12][10]));
    ui->Lbl192->setText(QString::fromStdString(Matrix[12][11]));
    ui->Lbl193->setText(QString::fromStdString(Matrix[12][12]));
    ui->Lbl194->setText(QString::fromStdString(Matrix[12][13]));
    ui->Lbl195->setText(QString::fromStdString(Matrix[12][14]));
    ui->Lbl196->setText(QString::fromStdString(Matrix[13][0]));
    ui->Lbl197->setText(QString::fromStdString(Matrix[13][1]));
    ui->Lbl198->setText(QString::fromStdString(Matrix[13][2]));
    ui->Lbl199->setText(QString::fromStdString(Matrix[13][3]));
    ui->Lbl200->setText(QString::fromStdString(Matrix[13][4]));
    ui->Lbl201->setText(QString::fromStdString(Matrix[13][5]));
    ui->Lbl202->setText(QString::fromStdString(Matrix[13][6]));
    ui->Lbl203->setText(QString::fromStdString(Matrix[13][7]));
    ui->Lbl204->setText(QString::fromStdString(Matrix[13][8]));
    ui->Lbl205->setText(QString::fromStdString(Matrix[13][9]));
    ui->Lbl206->setText(QString::fromStdString(Matrix[13][10]));
    ui->Lbl207->setText(QString::fromStdString(Matrix[13][11]));
    ui->Lbl208->setText(QString::fromStdString(Matrix[13][12]));
    ui->Lbl209->setText(QString::fromStdString(Matrix[13][13]));
    ui->Lbl210->setText(QString::fromStdString(Matrix[13][14]));
    ui->Lbl211->setText(QString::fromStdString(Matrix[14][0]));
    ui->Lbl212->setText(QString::fromStdString(Matrix[14][1]));
    ui->Lbl213->setText(QString::fromStdString(Matrix[14][2]));
    ui->Lbl214->setText(QString::fromStdString(Matrix[14][3]));
    ui->Lbl215->setText(QString::fromStdString(Matrix[14][4]));
    ui->Lbl216->setText(QString::fromStdString(Matrix[14][5]));
    ui->Lbl217->setText(QString::fromStdString(Matrix[14][6]));
    ui->Lbl218->setText(QString::fromStdString(Matrix[14][7]));
    ui->Lbl219->setText(QString::fromStdString(Matrix[14][8]));
    ui->Lbl220->setText(QString::fromStdString(Matrix[14][9]));
    ui->Lbl221->setText(QString::fromStdString(Matrix[14][10]));
    ui->Lbl222->setText(QString::fromStdString(Matrix[14][11]));
    ui->Lbl223->setText(QString::fromStdString(Matrix[14][12]));
    ui->Lbl224->setText(QString::fromStdString(Matrix[14][13]));
    ui->Lbl225->setText(QString::fromStdString(Matrix[14][14]));
}

void MatrixWindow::validatespaceAux(int column, int row, string element, QLabel &label){
    if (g[row][column] == "" && element != ""){
        if(listh->m_head != NULL){
            listh->del_by_data(column,row);
        }
        if(listscore->m_head != NULL){
            listscore->del_by_data(column,row);
        }
        listscore->add_head(element,column,row);
        listh->add_head(element,column,row);
        cout << "list h" << endl;
        listh->print();
        cout << "list score" << endl;
        listscore->print();
        label.setText(QString::fromStdString(b));
        b = "";
    }
}

string MatrixWindow::transformerWord(ListNode list, string word){
    while(list.m_head != NULL){
        word =list.m_head->element + word;
        list.m_head = list.m_head->next;
    }
    return word;
}

string MatrixWindow::transformerLetters(string letters){
    NodeList *temp = listscore->m_head;
    while(temp != NULL){
        letters = temp->element + letters;
        temp = temp->next;
    }
    return letters;
}

void MatrixWindow::on_EndTurn_clicked(){
    string gAux = "[{";
    string word = transformerWord(*listh, "");
    string letters = transformerLetters("");
    NodeList *tempNode = listh->m_head;
    while(tempNode != NULL){
        g[tempNode->row][tempNode->column] = tempNode->element;
        tempNode = tempNode->next;
    }
    for (int i = 0; i < 15; i++){
        for (int n = 0; n < 15; n++){
            gAux += g[i][n];
            if (n == 14)
                gAux += "}, {";
            else
                gAux += ",";
        }
        if (i == 14)
            gAux += "}]";
    }
    const char* jsonClient = "{\n"
                             "    \"id\": 0,\n"
                             "    \"score\": 0,\n"
                             "    \"word\": 0,\n"
                             "    \"letters\": null,\n"
                             "    \"turn\": true,\n"
                             "    \"matrix\": 0\n"
                             "}";
    Document d;
    d.Parse(jsonClient);
    cout << "1" << endl;
    assert(d.IsObject());
    cout << "2" << endl;
    d["word"].SetString(word.data(), word.size(), d.GetAllocator());
    cout << "3" << endl;
    d["letters"].SetString(letters.data(), letters.size(), d.GetAllocator());
    cout << "4" << endl;
    d["matrix"].SetString(gAux.data(), gAux.size(), d.GetAllocator());
    cout << "5" << endl;
    d["id"].SetString(this->id.data(), this->id.size(), d.GetAllocator());
    cout << "6" << endl;
    d["score"].SetInt(this->score);
    cout << "7" << endl;
    StringBuffer buffer;
    buffer.Clear();
    Writer<StringBuffer> writer(buffer);
    d.Accept(writer);
    cout << "8" << endl;
    cout << buffer.GetString() << endl;
    MatrixWindow::client->comunication(buffer.GetString());
    listh->del_all();
    listscore->del_all();

}







void MatrixWindow::on_Btn1_clicked(){
    b = ui->Btn1->text().toUtf8().constData();
}

void MatrixWindow::on_Btn2_clicked(){
    b = ui->Btn2->text().toUtf8().constData();
}

void MatrixWindow::on_Btn3_clicked(){
    b = ui->Btn3->text().toUtf8().constData();
}

void MatrixWindow::on_Btn4_clicked(){
    b = ui->Btn4->text().toUtf8().constData();
}

void MatrixWindow::on_Btn5_clicked(){
    b = ui->Btn5->text().toUtf8().constData();
}

void MatrixWindow::on_Btn6_clicked(){
    b = ui->Btn6->text().toUtf8().constData();
}

void MatrixWindow::on_Btn7_clicked(){
    b = ui->Btn7->text().toUtf8().constData();
}

void MatrixWindow::on_Btn8_clicked(){
    b = ui->Btn8->text().toUtf8().constData();
}

void MatrixWindow::on_Btn9_clicked(){
    b = ui->Btn9->text().toUtf8().constData();
}

void MatrixWindow::on_Btn10_clicked(){
    b = ui->Btn10->text().toUtf8().constData();
}
