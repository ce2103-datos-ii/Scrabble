#include "matrixwindow.h"
#include "ui_matrixwindow.h"
#include <QPixmap>
#include <QMouseEvent>

static string b = "";

MatrixWindow::MatrixWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MatrixWindow)
{
    ui->setupUi(this);
    QPixmap pix("/home/jesquivel/Downloads/MatrixImg.png");
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
    ui->Btn1->setText("A");
}

MatrixWindow::~MatrixWindow()
{
    delete ui;
}



void MatrixWindow::on_pushButton_2_clicked()
{
    QString a = "";
    a = ui->Btn1->text();
    cout << a.toStdString() << endl;
    ui->Btn1->setText("B");
    a = ui->Btn1->text();
    b = a.toStdString();
}

void MatrixWindow::mousePressEvent(QMouseEvent *event){
    this->posX = event->x();
    this->posY = event->y();
    if (posX>37&&posX<75&&posY>37&&posY<75){
        ui->Lbl1->setText(ui->Btn1->text());
    }
    if (posX>75&&posX<113&&posY>37&&posY<75){
        ui->Lbl2->setText(ui->Btn1->text());
    }
    if (posX>113&&posX<151&&posY>37&&posY<75){
        ui->Lbl3->setText(ui->Btn1->text());
    }
    if (posX>151&&posX<189&&posY>37&&posY<75){
        ui->Lbl4->setText(ui->Btn1->text());
    }
    if (posX>189&&posX<227&&posY>37&&posY<75){
        ui->Lbl5->setText(ui->Btn1->text());
    }
    if (posX>227&&posX<265&&posY>37&&posY<75){
        ui->Lbl6->setText(ui->Btn1->text());
    }
    if (posX>265&&posX<303&&posY>37&&posY<75){
        ui->Lbl7->setText(ui->Btn1->text());
    }
    if (posX>303&&posX<341&&posY>37&&posY<75){
        ui->Lbl8->setText(ui->Btn1->text());
    }
    if (posX>341&&posX<379&&posY>37&&posY<75){
        ui->Lbl9->setText(ui->Btn1->text());
    }
    if (posX>379&&posX<417&&posY>37&&posY<75){
        ui->Lbl10->setText(ui->Btn1->text());
    }
    if (posX>417&&posX<455&&posY>37&&posY<75){
        ui->Lbl11->setText(ui->Btn1->text());
    }
    if (posX>455&&posX<493&&posY>37&&posY<75){
        ui->Lbl12->setText(ui->Btn1->text());
    }
    if (posX>493&&posX<531&&posY>37&&posY<75){
        ui->Lbl13->setText(ui->Btn1->text());
    }
    if (posX>531&&posX<569&&posY>37&&posY<75){
        ui->Lbl14->setText(ui->Btn1->text());
    }
    if (posX>569&&posX<607&&posY>37&&posY<75){
        ui->Lbl15->setText(ui->Btn1->text());
    }
    if (posX>37&&posX<75&&posY>75&&posY<113){
        ui->Lbl16->setText(ui->Btn1->text());
    }
    if (posX>75&&posX<113&&posY>75&&posY<113){
        ui->Lbl17->setText(ui->Btn1->text());
    }
    if (posX>113&&posX<151&&posY>75&&posY<113){
        ui->Lbl18->setText(ui->Btn1->text());
    }
    if (posX>151&&posX<189&&posY>75&&posY<113){
        ui->Lbl19->setText(ui->Btn1->text());
    }
    if (posX>189&&posX<227&&posY>75&&posY<113){
        ui->Lbl20->setText(ui->Btn1->text());
    }
    if (posX>227&&posX<265&&posY>75&&posY<113){
        ui->Lbl21->setText(ui->Btn1->text());
    }
    if (posX>265&&posX<303&&posY>75&&posY<113){
        ui->Lbl22->setText(ui->Btn1->text());
    }
    if (posX>303&&posX<341&&posY>75&&posY<113){
        ui->Lbl23->setText(ui->Btn1->text());
    }
    if (posX>341&&posX<379&&posY>75&&posY<113){
        ui->Lbl24->setText(ui->Btn1->text());
    }
    if (posX>379&&posX<417&&posY>75&&posY<113){
        ui->Lbl25->setText(ui->Btn1->text());
    }
    if (posX>417&&posX<455&&posY>75&&posY<113){
        ui->Lbl26->setText(ui->Btn1->text());
    }
    if (posX>455&&posX<493&&posY>75&&posY<113){
        ui->Lbl27->setText(ui->Btn1->text());
    }
    if (posX>493&&posX<531&&posY>75&&posY<113){
        ui->Lbl28->setText(ui->Btn1->text());
    }
    if (posX>531&&posX<569&&posY>75&&posY<113){
        ui->Lbl29->setText(ui->Btn1->text());
    }
    if (posX>569&&posX<607&&posY>75&&posY<113){
        ui->Lbl30->setText(ui->Btn1->text());
    }
    if (posX>37&&posX<75&&posY>113&&posY<151){
        ui->Lbl31->setText(ui->Btn1->text());
    }
    if (posX>75&&posX<113&&posY>113&&posY<151){
        ui->Lbl32->setText(ui->Btn1->text());
    }
    if (posX>113&&posX<151&&posY>113&&posY<151){
        ui->Lbl33->setText(ui->Btn1->text());
    }
    if (posX>151&&posX<189&&posY>113&&posY<151){
        ui->Lbl34->setText(ui->Btn1->text());
    }
    if (posX>189&&posX<227&&posY>113&&posY<151){
        ui->Lbl35->setText(ui->Btn1->text());
    }
    if (posX>227&&posX<265&&posY>113&&posY<151){
        ui->Lbl36->setText(ui->Btn1->text());
    }
    if (posX>265&&posX<303&&posY>113&&posY<151){
        ui->Lbl37->setText(ui->Btn1->text());
    }
    if (posX>303&&posX<341&&posY>113&&posY<151){
        ui->Lbl38->setText(ui->Btn1->text());
    }
    if (posX>341&&posX<379&&posY>113&&posY<151){
        ui->Lbl39->setText(ui->Btn1->text());
    }
    if (posX>379&&posX<417&&posY>113&&posY<151){
        ui->Lbl40->setText(ui->Btn1->text());
    }
    if (posX>417&&posX<455&&posY>113&&posY<151){
        ui->Lbl41->setText(ui->Btn1->text());
    }
    if (posX>455&&posX<493&&posY>113&&posY<151){
        ui->Lbl42->setText(ui->Btn1->text());
    }
    if (posX>493&&posX<531&&posY>113&&posY<151){
        ui->Lbl43->setText(ui->Btn1->text());
    }
    if (posX>531&&posX<569&&posY>113&&posY<151){
        ui->Lbl44->setText(ui->Btn1->text());
    }
    if (posX>569&&posX<607&&posY>113&&posY<151){
        ui->Lbl45->setText(ui->Btn1->text());
    }
    if (posX>37&&posX<75&&posY>151&&posY<189){
        ui->Lbl46->setText(ui->Btn1->text());
    }
    if (posX>75&&posX<113&&posY>151&&posY<189){
        ui->Lbl47->setText(ui->Btn1->text());
    }
    if (posX>113&&posX<151&&posY>151&&posY<189){
        ui->Lbl48->setText(ui->Btn1->text());
    }
    if (posX>151&&posX<189&&posY>151&&posY<189){
        ui->Lbl49->setText(ui->Btn1->text());
    }
    if (posX>189&&posX<227&&posY>151&&posY<189){
        ui->Lbl50->setText(ui->Btn1->text());
    }
    if (posX>227&&posX<265&&posY>151&&posY<189){
        ui->Lbl51->setText(ui->Btn1->text());
    }
    if (posX>265&&posX<303&&posY>151&&posY<189){
        ui->Lbl52->setText(ui->Btn1->text());
    }
    if (posX>303&&posX<341&&posY>151&&posY<189){
        ui->Lbl53->setText(ui->Btn1->text());
    }
    if (posX>341&&posX<379&&posY>151&&posY<189){
        ui->Lbl54->setText(ui->Btn1->text());
    }
    if (posX>379&&posX<417&&posY>151&&posY<189){
        ui->Lbl55->setText(ui->Btn1->text());
    }
    if (posX>417&&posX<455&&posY>151&&posY<189){
        ui->Lbl56->setText(ui->Btn1->text());
    }
    if (posX>455&&posX<493&&posY>151&&posY<189){
        ui->Lbl57->setText(ui->Btn1->text());
    }
    if (posX>493&&posX<531&&posY>151&&posY<189){
        ui->Lbl58->setText(ui->Btn1->text());
    }
    if (posX>531&&posX<569&&posY>151&&posY<189){
        ui->Lbl59->setText(ui->Btn1->text());
    }
    if (posX>569&&posX<607&&posY>151&&posY<189){
        ui->Lbl60->setText(ui->Btn1->text());
    }
    if (posX>37&&posX<75&&posY>189&&posY<227){
        ui->Lbl61->setText(ui->Btn1->text());
    }
    if (posX>75&&posX<113&&posY>189&&posY<227){
        ui->Lbl62->setText(ui->Btn1->text());
    }
    if (posX>113&&posX<151&&posY>189&&posY<227){
        ui->Lbl63->setText(ui->Btn1->text());
    }
    if (posX>151&&posX<189&&posY>189&&posY<227){
        ui->Lbl64->setText(ui->Btn1->text());
    }
    if (posX>189&&posX<227&&posY>189&&posY<227){
        ui->Lbl65->setText(ui->Btn1->text());
    }
    if (posX>227&&posX<265&&posY>189&&posY<227){
        ui->Lbl66->setText(ui->Btn1->text());
    }
    if (posX>265&&posX<303&&posY>189&&posY<227){
        ui->Lbl67->setText(ui->Btn1->text());
    }
    if (posX>303&&posX<341&&posY>189&&posY<227){
        ui->Lbl68->setText(ui->Btn1->text());
    }
    if (posX>341&&posX<379&&posY>189&&posY<227){
        ui->Lbl69->setText(ui->Btn1->text());
    }
    if (posX>379&&posX<417&&posY>189&&posY<227){
        ui->Lbl70->setText(ui->Btn1->text());
    }
    if (posX>417&&posX<455&&posY>189&&posY<227){
        ui->Lbl71->setText(ui->Btn1->text());
    }
    if (posX>455&&posX<493&&posY>189&&posY<227){
        ui->Lbl72->setText(ui->Btn1->text());
    }
    if (posX>493&&posX<531&&posY>189&&posY<227){
        ui->Lbl73->setText(ui->Btn1->text());
    }
    if (posX>531&&posX<569&&posY>189&&posY<227){
        ui->Lbl74->setText(ui->Btn1->text());
    }
    if (posX>569&&posX<607&&posY>189&&posY<227){
        ui->Lbl75->setText(ui->Btn1->text());
    }
    if (posX>37&&posX<75&&posY>227&&posY<265){
        ui->Lbl76->setText(ui->Btn1->text());
    }
    if (posX>75&&posX<113&&posY>227&&posY<265){
        ui->Lbl77->setText(ui->Btn1->text());
    }
    if (posX>113&&posX<151&&posY>227&&posY<265){
        ui->Lbl78->setText(ui->Btn1->text());
    }
    if (posX>151&&posX<189&&posY>227&&posY<265){
        ui->Lbl79->setText(ui->Btn1->text());
    }
    if (posX>189&&posX<227&&posY>227&&posY<265){
        ui->Lbl80->setText(ui->Btn1->text());
    }
    if (posX>227&&posX<265&&posY>227&&posY<265){
        ui->Lbl81->setText(ui->Btn1->text());
    }
    if (posX>265&&posX<303&&posY>227&&posY<265){
        ui->Lbl82->setText(ui->Btn1->text());
    }
    if (posX>303&&posX<341&&posY>227&&posY<265){
        ui->Lbl83->setText(ui->Btn1->text());
    }
    if (posX>341&&posX<379&&posY>227&&posY<265){
        ui->Lbl84->setText(ui->Btn1->text());
    }
    if (posX>379&&posX<417&&posY>227&&posY<265){
        ui->Lbl85->setText(ui->Btn1->text());
    }
    if (posX>417&&posX<455&&posY>227&&posY<265){
        ui->Lbl86->setText(ui->Btn1->text());
    }
    if (posX>455&&posX<493&&posY>227&&posY<265){
        ui->Lbl87->setText(ui->Btn1->text());
    }
    if (posX>493&&posX<531&&posY>227&&posY<265){
        ui->Lbl88->setText(ui->Btn1->text());
    }
    if (posX>531&&posX<569&&posY>227&&posY<265){
        ui->Lbl89->setText(ui->Btn1->text());
    }
    if (posX>569&&posX<607&&posY>227&&posY<265){
        ui->Lbl90->setText(ui->Btn1->text());
    }
    if (posX>37&&posX<75&&posY>265&&posY<303){
        ui->Lbl91->setText(ui->Btn1->text());
    }
    if (posX>75&&posX<113&&posY>265&&posY<303){
        ui->Lbl92->setText(ui->Btn1->text());
    }
    if (posX>113&&posX<151&&posY>265&&posY<303){
        ui->Lbl93->setText(ui->Btn1->text());
    }
    if (posX>151&&posX<189&&posY>265&&posY<303){
        ui->Lbl94->setText(ui->Btn1->text());
    }
    if (posX>189&&posX<227&&posY>265&&posY<303){
        ui->Lbl95->setText(ui->Btn1->text());
    }
    if (posX>227&&posX<265&&posY>265&&posY<303){
        ui->Lbl96->setText(ui->Btn1->text());
    }
    if (posX>265&&posX<303&&posY>265&&posY<303){
        ui->Lbl97->setText(ui->Btn1->text());
    }
    if (posX>303&&posX<341&&posY>265&&posY<303){
        ui->Lbl98->setText(ui->Btn1->text());
    }
    if (posX>341&&posX<379&&posY>265&&posY<303){
        ui->Lbl99->setText(ui->Btn1->text());
    }
    if (posX>379&&posX<417&&posY>265&&posY<303){
        ui->Lbl100->setText(ui->Btn1->text());
    }
    if (posX>417&&posX<455&&posY>265&&posY<303){
        ui->Lbl101->setText(ui->Btn1->text());
    }
    if (posX>455&&posX<493&&posY>265&&posY<303){
        ui->Lbl102->setText(ui->Btn1->text());
    }
    if (posX>493&&posX<531&&posY>265&&posY<303){
        ui->Lbl103->setText(ui->Btn1->text());
    }
    if (posX>531&&posX<569&&posY>265&&posY<303){
        ui->Lbl104->setText(ui->Btn1->text());
    }
    if (posX>569&&posX<607&&posY>265&&posY<303){
        ui->Lbl105->setText(ui->Btn1->text());
    }
    if (posX>37&&posX<75&&posY>303&&posY<341){
        ui->Lbl106->setText(ui->Btn1->text());
    }
    if (posX>75&&posX<113&&posY>303&&posY<341){
        ui->Lbl107->setText(ui->Btn1->text());
    }
    if (posX>113&&posX<151&&posY>303&&posY<341){
        ui->Lbl108->setText(ui->Btn1->text());
    }
    if (posX>151&&posX<189&&posY>303&&posY<341){
        ui->Lbl109->setText(ui->Btn1->text());
    }
    if (posX>189&&posX<227&&posY>303&&posY<341){
        ui->Lbl110->setText(ui->Btn1->text());
    }
    if (posX>227&&posX<265&&posY>303&&posY<341){
        ui->Lbl111->setText(ui->Btn1->text());
    }
    if (posX>265&&posX<303&&posY>303&&posY<341){
        ui->Lbl112->setText(ui->Btn1->text());
    }
    if (posX>303&&posX<341&&posY>303&&posY<341){
        ui->Lbl113->setText(ui->Btn1->text());
    }
    if (posX>341&&posX<379&&posY>303&&posY<341){
        ui->Lbl114->setText(ui->Btn1->text());
    }
    if (posX>379&&posX<417&&posY>303&&posY<341){
        ui->Lbl115->setText(ui->Btn1->text());
    }
    if (posX>417&&posX<455&&posY>303&&posY<341){
        ui->Lbl116->setText(ui->Btn1->text());
    }
    if (posX>455&&posX<493&&posY>303&&posY<341){
        ui->Lbl117->setText(ui->Btn1->text());
    }
    if (posX>493&&posX<531&&posY>303&&posY<341){
        ui->Lbl118->setText(ui->Btn1->text());
    }
    if (posX>531&&posX<569&&posY>303&&posY<341){
        ui->Lbl119->setText(ui->Btn1->text());
    }
    if (posX>569&&posX<607&&posY>303&&posY<341){
        ui->Lbl120->setText(ui->Btn1->text());
    }
    if (posX>37&&posX<75&&posY>341&&posY<379){
        ui->Lbl121->setText(ui->Btn1->text());
    }
    if (posX>75&&posX<113&&posY>341&&posY<379){
        ui->Lbl122->setText(ui->Btn1->text());
    }
    if (posX>113&&posX<151&&posY>341&&posY<379){
        ui->Lbl123->setText(ui->Btn1->text());
    }
    if (posX>151&&posX<189&&posY>341&&posY<379){
        ui->Lbl124->setText(ui->Btn1->text());
    }
    if (posX>189&&posX<227&&posY>341&&posY<379){
        ui->Lbl125->setText(ui->Btn1->text());
    }
    if (posX>227&&posX<265&&posY>341&&posY<379){
        ui->Lbl126->setText(ui->Btn1->text());
    }
    if (posX>265&&posX<303&&posY>341&&posY<379){
        ui->Lbl127->setText(ui->Btn1->text());
    }
    if (posX>303&&posX<341&&posY>341&&posY<379){
        ui->Lbl128->setText(ui->Btn1->text());
    }
    if (posX>341&&posX<379&&posY>341&&posY<379){
        ui->Lbl129->setText(ui->Btn1->text());
    }
    if (posX>379&&posX<417&&posY>341&&posY<379){
        ui->Lbl130->setText(ui->Btn1->text());
    }
    if (posX>417&&posX<455&&posY>341&&posY<379){
        ui->Lbl131->setText(ui->Btn1->text());
    }
    if (posX>455&&posX<493&&posY>341&&posY<379){
        ui->Lbl132->setText(ui->Btn1->text());
    }
    if (posX>493&&posX<531&&posY>341&&posY<379){
        ui->Lbl133->setText(ui->Btn1->text());
    }
    if (posX>531&&posX<569&&posY>341&&posY<379){
        ui->Lbl134->setText(ui->Btn1->text());
    }
    if (posX>569&&posX<607&&posY>341&&posY<379){
        ui->Lbl135->setText(ui->Btn1->text());
    }
    if (posX>37&&posX<75&&posY>379&&posY<417){
        ui->Lbl136->setText(ui->Btn1->text());
    }
    if (posX>75&&posX<113&&posY>379&&posY<417){
        ui->Lbl137->setText(ui->Btn1->text());
    }
    if (posX>113&&posX<151&&posY>379&&posY<417){
        ui->Lbl138->setText(ui->Btn1->text());
    }
    if (posX>151&&posX<189&&posY>379&&posY<417){
        ui->Lbl139->setText(ui->Btn1->text());
    }
    if (posX>189&&posX<227&&posY>379&&posY<417){
        ui->Lbl140->setText(ui->Btn1->text());
    }
    if (posX>227&&posX<265&&posY>379&&posY<417){
        ui->Lbl141->setText(ui->Btn1->text());
    }
    if (posX>265&&posX<303&&posY>379&&posY<417){
        ui->Lbl142->setText(ui->Btn1->text());
    }
    if (posX>303&&posX<341&&posY>379&&posY<417){
        ui->Lbl143->setText(ui->Btn1->text());
    }
    if (posX>341&&posX<379&&posY>379&&posY<417){
        ui->Lbl144->setText(ui->Btn1->text());
    }
    if (posX>379&&posX<417&&posY>379&&posY<417){
        ui->Lbl145->setText(ui->Btn1->text());
    }
    if (posX>417&&posX<455&&posY>379&&posY<417){
        ui->Lbl146->setText(ui->Btn1->text());
    }
    if (posX>455&&posX<493&&posY>379&&posY<417){
        ui->Lbl147->setText(ui->Btn1->text());
    }
    if (posX>493&&posX<531&&posY>379&&posY<417){
        ui->Lbl148->setText(ui->Btn1->text());
    }
    if (posX>531&&posX<569&&posY>379&&posY<417){
        ui->Lbl149->setText(ui->Btn1->text());
    }
    if (posX>569&&posX<607&&posY>379&&posY<417){
        ui->Lbl150->setText(ui->Btn1->text());
    }
    if (posX>37&&posX<75&&posY>417&&posY<455){
        ui->Lbl151->setText(ui->Btn1->text());
    }
    if (posX>75&&posX<113&&posY>417&&posY<455){
        ui->Lbl152->setText(ui->Btn1->text());
    }
    if (posX>113&&posX<151&&posY>417&&posY<455){
        ui->Lbl153->setText(ui->Btn1->text());
    }
    if (posX>151&&posX<189&&posY>417&&posY<455){
        ui->Lbl154->setText(ui->Btn1->text());
    }
    if (posX>189&&posX<227&&posY>417&&posY<455){
        ui->Lbl155->setText(ui->Btn1->text());
    }
    if (posX>227&&posX<265&&posY>417&&posY<455){
        ui->Lbl156->setText(ui->Btn1->text());
    }
    if (posX>265&&posX<303&&posY>417&&posY<455){
        ui->Lbl157->setText(ui->Btn1->text());
    }
    if (posX>303&&posX<341&&posY>417&&posY<455){
        ui->Lbl158->setText(ui->Btn1->text());
    }
    if (posX>341&&posX<379&&posY>417&&posY<455){
        ui->Lbl159->setText(ui->Btn1->text());
    }
    if (posX>379&&posX<417&&posY>417&&posY<455){
        ui->Lbl160->setText(ui->Btn1->text());
    }
    if (posX>417&&posX<455&&posY>417&&posY<455){
        ui->Lbl161->setText(ui->Btn1->text());
    }
    if (posX>455&&posX<493&&posY>417&&posY<455){
        ui->Lbl162->setText(ui->Btn1->text());
    }
    if (posX>493&&posX<531&&posY>417&&posY<455){
        ui->Lbl163->setText(ui->Btn1->text());
    }
    if (posX>531&&posX<569&&posY>417&&posY<455){
        ui->Lbl164->setText(ui->Btn1->text());
    }
    if (posX>569&&posX<607&&posY>417&&posY<455){
        ui->Lbl165->setText(ui->Btn1->text());
    }
    if (posX>37&&posX<75&&posY>455&&posY<493){
        ui->Lbl166->setText(ui->Btn1->text());
    }
    if (posX>75&&posX<113&&posY>455&&posY<493){
        ui->Lbl167->setText(ui->Btn1->text());
    }
    if (posX>113&&posX<151&&posY>455&&posY<493){
        ui->Lbl168->setText(ui->Btn1->text());
    }
    if (posX>151&&posX<189&&posY>455&&posY<493){
        ui->Lbl169->setText(ui->Btn1->text());
    }
    if (posX>189&&posX<227&&posY>455&&posY<493){
        ui->Lbl170->setText(ui->Btn1->text());
    }
    if (posX>227&&posX<265&&posY>455&&posY<493){
        ui->Lbl171->setText(ui->Btn1->text());
    }
    if (posX>265&&posX<303&&posY>455&&posY<493){
        ui->Lbl172->setText(ui->Btn1->text());
    }
    if (posX>303&&posX<341&&posY>455&&posY<493){
        ui->Lbl173->setText(ui->Btn1->text());
    }
    if (posX>341&&posX<379&&posY>455&&posY<493){
        ui->Lbl174->setText(ui->Btn1->text());
    }
    if (posX>379&&posX<417&&posY>455&&posY<493){
        ui->Lbl175->setText(ui->Btn1->text());
    }
    if (posX>417&&posX<455&&posY>455&&posY<493){
        ui->Lbl176->setText(ui->Btn1->text());
    }
    if (posX>455&&posX<493&&posY>455&&posY<493){
        ui->Lbl177->setText(ui->Btn1->text());
    }
    if (posX>493&&posX<531&&posY>455&&posY<493){
        ui->Lbl178->setText(ui->Btn1->text());
    }
    if (posX>531&&posX<569&&posY>455&&posY<493){
        ui->Lbl179->setText(ui->Btn1->text());
    }
    if (posX>569&&posX<607&&posY>455&&posY<493){
        ui->Lbl180->setText(ui->Btn1->text());
    }
    if (posX>37&&posX<75&&posY>493&&posY<531){
        ui->Lbl181->setText(ui->Btn1->text());
    }
    if (posX>75&&posX<113&&posY>493&&posY<531){
        ui->Lbl182->setText(ui->Btn1->text());
    }
    if (posX>113&&posX<151&&posY>493&&posY<531){
        ui->Lbl183->setText(ui->Btn1->text());
    }
    if (posX>151&&posX<189&&posY>493&&posY<531){
        ui->Lbl184->setText(ui->Btn1->text());
    }
    if (posX>189&&posX<227&&posY>493&&posY<531){
        ui->Lbl185->setText(ui->Btn1->text());
    }
    if (posX>227&&posX<265&&posY>493&&posY<531){
        ui->Lbl186->setText(ui->Btn1->text());
    }
    if (posX>265&&posX<303&&posY>493&&posY<531){
        ui->Lbl187->setText(ui->Btn1->text());
    }
    if (posX>303&&posX<341&&posY>493&&posY<531){
        ui->Lbl188->setText(ui->Btn1->text());
    }
    if (posX>341&&posX<379&&posY>493&&posY<531){
        ui->Lbl189->setText(ui->Btn1->text());
    }
    if (posX>379&&posX<417&&posY>493&&posY<531){
        ui->Lbl190->setText(ui->Btn1->text());
    }
    if (posX>417&&posX<455&&posY>493&&posY<531){
        ui->Lbl191->setText(ui->Btn1->text());
    }
    if (posX>455&&posX<493&&posY>493&&posY<531){
        ui->Lbl192->setText(ui->Btn1->text());
    }
    if (posX>493&&posX<531&&posY>493&&posY<531){
        ui->Lbl193->setText(ui->Btn1->text());
    }
    if (posX>531&&posX<569&&posY>493&&posY<531){
        ui->Lbl194->setText(ui->Btn1->text());
    }
    if (posX>569&&posX<607&&posY>493&&posY<531){
        ui->Lbl195->setText(ui->Btn1->text());
    }
    if (posX>37&&posX<75&&posY>531&&posY<569){
        ui->Lbl196->setText(ui->Btn1->text());
    }
    if (posX>75&&posX<113&&posY>531&&posY<569){
        ui->Lbl197->setText(ui->Btn1->text());
    }
    if (posX>113&&posX<151&&posY>531&&posY<569){
        ui->Lbl198->setText(ui->Btn1->text());
    }
    if (posX>151&&posX<189&&posY>531&&posY<569){
        ui->Lbl199->setText(ui->Btn1->text());
    }
    if (posX>189&&posX<227&&posY>531&&posY<569){
        ui->Lbl200->setText(ui->Btn1->text());
    }
    if (posX>227&&posX<265&&posY>531&&posY<569){
        ui->Lbl201->setText(ui->Btn1->text());
    }
    if (posX>265&&posX<303&&posY>531&&posY<569){
        ui->Lbl202->setText(ui->Btn1->text());
    }
    if (posX>303&&posX<341&&posY>531&&posY<569){
        ui->Lbl203->setText(ui->Btn1->text());
    }
    if (posX>341&&posX<379&&posY>531&&posY<569){
        ui->Lbl204->setText(ui->Btn1->text());
    }
    if (posX>379&&posX<417&&posY>531&&posY<569){
        ui->Lbl205->setText(ui->Btn1->text());
    }
    if (posX>417&&posX<455&&posY>531&&posY<569){
        ui->Lbl206->setText(ui->Btn1->text());
    }
    if (posX>455&&posX<493&&posY>531&&posY<569){
        ui->Lbl207->setText(ui->Btn1->text());
    }
    if (posX>493&&posX<531&&posY>531&&posY<569){
        ui->Lbl208->setText(ui->Btn1->text());
    }
    if (posX>531&&posX<569&&posY>531&&posY<569){
        ui->Lbl209->setText(ui->Btn1->text());
    }
    if (posX>569&&posX<607&&posY>531&&posY<569){
        ui->Lbl210->setText(ui->Btn1->text());
    }
    if (posX>37&&posX<75&&posY>569&&posY<607){
        ui->Lbl211->setText(ui->Btn1->text());
    }
    if (posX>75&&posX<113&&posY>569&&posY<607){
        ui->Lbl212->setText(ui->Btn1->text());
    }
    if (posX>113&&posX<151&&posY>569&&posY<607){
        ui->Lbl213->setText(ui->Btn1->text());
    }
    if (posX>151&&posX<189&&posY>569&&posY<607){
        ui->Lbl214->setText(ui->Btn1->text());
    }
    if (posX>189&&posX<227&&posY>569&&posY<607){
        ui->Lbl215->setText(ui->Btn1->text());
    }
    if (posX>227&&posX<265&&posY>569&&posY<607){
        ui->Lbl216->setText(ui->Btn1->text());
    }
    if (posX>265&&posX<303&&posY>569&&posY<607){
        ui->Lbl217->setText(ui->Btn1->text());
    }
    if (posX>303&&posX<341&&posY>569&&posY<607){
        ui->Lbl218->setText(ui->Btn1->text());
    }
    if (posX>341&&posX<379&&posY>569&&posY<607){
        ui->Lbl219->setText(ui->Btn1->text());
    }
    if (posX>379&&posX<417&&posY>569&&posY<607){
        ui->Lbl220->setText(ui->Btn1->text());
    }
    if (posX>417&&posX<455&&posY>569&&posY<607){
        ui->Lbl221->setText(ui->Btn1->text());
    }
    if (posX>455&&posX<493&&posY>569&&posY<607){
        ui->Lbl222->setText(ui->Btn1->text());
    }
    if (posX>493&&posX<531&&posY>569&&posY<607){
        ui->Lbl223->setText(ui->Btn1->text());
    }
    if (posX>531&&posX<569&&posY>569&&posY<607){
        ui->Lbl224->setText(ui->Btn1->text());
    }
    if (posX>569&&posX<607&&posY>569&&posY<607){
        ui->Lbl225->setText(ui->Btn1->text());
    }

}

void MatrixWindow::on_Btn1_clicked(){
    ui->Lbl11->setText(ui->Btn1->text());
}
