#include "widget.h"
#include "ui_widget.h"
#include <QMessageBox>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    setButtonStatus();
}

Widget::~Widget()
{
    delete ui;
}

void Widget::changeCoin(int coin)
{
    amount += coin;
    ui->lcdNumber->display(amount);
    setButtonStatus();
}

void Widget::setButtonStatus()
{
    ui->pbCoffee->setEnabled(amount >= 100);
    ui->pbTea->setEnabled(amount >= 150);
    ui->pbMilk->setEnabled(amount >= 200);
    ui->pbReset->setEnabled(amount > 0);
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

    int coins[4] = {500, 100, 50, 10};
    int coin_count[4];
    int num_coins = 4;
    int remain = amount;
    QString format = QString("Changes: %1\n\n500: %2\n100: %3\n50: %4\n10: %5").arg(amount);

    for (int i = 0; i < num_coins; i++) {
        coin_count[i] = remain / coins[i];
        remain -= coin_count[i] * coins[i];

        format = format.arg(coin_count[i]);
    }

    m.information(this, "Reset", format);
    changeCoin(-amount);
}
