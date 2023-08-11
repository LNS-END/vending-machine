#include "widget.h"
#include "ui_widget.h"
#include <QMessageBox>
#include <QString>
#include <sstream>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    buttonAl();

}

Widget::~Widget()
{
    delete ui;
}
void Widget::changeMoney(int diff){
    money+=diff;
    ui->lcdNumber->display(money);
}
void Widget::buttonAl(){
    if(money<100){ui->pbCoffe->setEnabled(false);}
    if(money>=100){ui->pbCoffe->setEnabled(true);}
    if(money<150){ui->pbTea->setEnabled(false);}
    if(money>=150){ui->pbTea->setEnabled(true);}
    if(money<200){ui->pbMilk->setEnabled(false);}
    if(money>=200){ui->pbMilk->setEnabled(true);}
}

void Widget::on_pb10_clicked()
{
    changeMoney(10);
    buttonAl();
}


void Widget::on_pb100_clicked()
{
    changeMoney(100);
    buttonAl();
}


void Widget::on_pb500_clicked()
{
    changeMoney(500);
    buttonAl();
}


void Widget::on_pbCoffe_clicked()
{
    changeMoney(-100);
    buttonAl();
}


void Widget::on_pbTea_clicked()
{
    changeMoney(-150);
    buttonAl();
}


void Widget::on_pbMilk_clicked()
{
    changeMoney(-200);
    buttonAl();
}


void Widget::on_pbReset_clicked()
{
    QMessageBox mb;
    std::stringstream ss;

    int t1,t5,t10,t50,tmp;
    tmp=money;
    t50=tmp/500;
    tmp=tmp%500;
    t10=tmp/100;
    tmp=tmp%100;
    t5=tmp/50;
    tmp=tmp%50;
    t1=tmp/10;

    ss << "This is change \n" << "500won:"<<t50<<"\n100won:"<<t10<<"\n50won:"<<t5<<"\n10won:"<<t1;

    mb.information(this, "Title", QString::fromStdString(ss.str()));

    money = 0;
    buttonAl();
    ui->lcdNumber->display(money);

}


void Widget::on_pb50_clicked()
{
    changeMoney(50);
    buttonAl();
}

