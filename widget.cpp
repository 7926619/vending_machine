#include "widget.h"
#include "ui_widget.h"
#include <QMessageBox>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    ui->pbCoffee->setEnabled(false);
    ui->pbTea->setEnabled(false);
    ui->pbGongcha->setEnabled(false);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::changeMoney(int n)
{
    money += n;
    ui->lcdNumber->display(QString::number(money));

    if(money >= 100)
        ui->pbCoffee->setEnabled(true);
    else
        ui->pbCoffee->setEnabled(false);

    if(money >= 150)
        ui->pbTea->setEnabled(true);
    else
        ui->pbTea->setEnabled(false);

    if(money >= 200)
        ui->pbGongcha->setEnabled(true);
    else
        ui->pbGongcha->setEnabled(false);
}

void Widget::on_pb10_clicked()
{
    changeMoney(10);
}

void Widget::on_pb50_clicked()
{
    changeMoney(50);
}

void Widget::on_pb100_clicked()
{
   changeMoney(100);
}

void Widget::on_pb500_clicked()
{
    changeMoney(500);
}

void Widget::on_pbCoffee_clicked()
{
    changeMoney(-100);
}

void Widget::on_pbTea_clicked()
{
    changeMoney(-150);
}

void Widget::on_pbGongcha_clicked()
{
    changeMoney(-200);
}

void Widget::on_pbReturnCoin_clicked()
{
    int coins[4] = {500, 100, 50, 10};
    int count[4] = {0, };
    int i = 0;
    QString str;
    QMessageBox msg;

    while(i < 4) {
        if(money >= coins[i]) {
            changeMoney(-coins[i]);
            count[i]++;
        }
        else {
            i++;
        }
    }

    str.sprintf("500won: %d, 100won: %d, 50won: %d, 10won: %d", count[0], count[1], count[2], count[3]);
    msg.information(nullptr, "Return coin", str);
}

