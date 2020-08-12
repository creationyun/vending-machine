#include "widget.h"
#include "ui_widget.h"
#include <QMessageBox>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    setBeverageStatus();
}

Widget::~Widget()
{
    delete ui;
}

void Widget::changeCoin(int coin)
{
    amount += coin;
    ui->lcdNumber->display(amount);
    setBeverageStatus();
}

void Widget::setBeverageStatus()
{
    ui->pbCoffee->setEnabled(amount >= 100);
    ui->pbTea->setEnabled(amount >= 150);
    ui->pbMilk->setEnabled(amount >= 200);
}

void Widget::on_pb10_clicked()
{
    changeCoin(10);
}

void Widget::on_pb50_clicked()
{
    changeCoin(50);
}

void Widget::on_pb100_clicked()
{
    changeCoin(100);
}

void Widget::on_pb500_clicked()
{
    changeCoin(500);
}

void Widget::on_pbCoffee_clicked()
{
    changeCoin(-100);
}

void Widget::on_pbTea_clicked()
{
    changeCoin(-150);
}

void Widget::on_pbMilk_clicked()
{
    changeCoin(-200);
}

void Widget::on_pbReset_clicked()
{
    QMessageBox m;
    m.information(this, "Changes", QStringLiteral("Changes: %1").arg(amount));
    changeCoin(-amount);
}
