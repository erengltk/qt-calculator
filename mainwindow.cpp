#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QMessageBox>
#include <QtCore/qglobal.h>
#include <QDebug>
#include <QAbstractButton>
#include<iostream>
double firstNumber;
bool arti=false,eksi=false,carpi=false,bolme=false,userIsTyping=false;
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->pushButton_0,SIGNAL(pressed()),this,SLOT(digit_pressed()));
    connect(ui->pushButton_1,SIGNAL(pressed()),this,SLOT(digit_pressed()));
    connect(ui->pushButton_2,SIGNAL(pressed()),this,SLOT(digit_pressed()));
    connect(ui->pushButton_3,SIGNAL(pressed()),this,SLOT(digit_pressed()));
    connect(ui->pushButton_4,SIGNAL(pressed()),this,SLOT(digit_pressed()));
    connect(ui->pushButton_5,SIGNAL(pressed()),this,SLOT(digit_pressed()));
    connect(ui->pushButton_6,SIGNAL(pressed()),this,SLOT(digit_pressed()));
    connect(ui->pushButton_7,SIGNAL(pressed()),this,SLOT(digit_pressed()));
    connect(ui->pushButton_8,SIGNAL(pressed()),this,SLOT(digit_pressed()));
    connect(ui->pushButton_9,SIGNAL(pressed()),this,SLOT(digit_pressed()));
    connect(ui->pushButton_bolu,SIGNAL(pressed()),this,SLOT(islem_operatoru()));
    connect(ui->pushButton_carpi,SIGNAL(pressed()),this,SLOT(islem_operatoru()));
    connect(ui->pushButton_eksi,SIGNAL(pressed()),this,SLOT(islem_operatoru()));
    connect(ui->pushButton_m_n,SIGNAL(pressed()),this,SLOT(number_operator_pressed()));
    connect(ui->pushButton_plus,SIGNAL(pressed()),this,SLOT(islem_operatoru()));
    connect(ui->pushButton_yuzde,SIGNAL(pressed()),this,SLOT(number_operator_pressed()));
  //  connect(ui->pushButtonCl,SIGNAL(pressed()),this,SLOT(digit_pressed()));
    ui->pushButton_bolu->setCheckable(true);
    ui->pushButton_carpi->setCheckable(true);
    ui->pushButton_eksi->setCheckable(true);
    ui->pushButton_plus->setCheckable(true);

}//esittir ve CE farklı işlem görecek

  //  ui->pushb
MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::digit_pressed()
{

 QPushButton * button =(QPushButton*)sender();
 double labelNumber;
 QString newLabel;
 if((bolme||carpi||eksi||arti)&&!(userIsTyping))
 {
     labelNumber=button->text().toDouble();
     userIsTyping=true;
     newLabel=QString::number(labelNumber,'g',15);
 }
 else
 {
     if(ui->label->text().contains('.')&&button->text()=="0")
     {
         newLabel=ui->label->text()+button->text();
     }
     else {
         labelNumber=(ui->label->text()+button->text()).toDouble();

         newLabel=QString::number(labelNumber,'g',15);
     }

 }


 ui->label->setText(newLabel);
}


void MainWindow::on_pushButton_nokta_released()
{
    if((ui->label->text()).toDouble()==(ui->label->text()).toInt() )
    {
    ui->label->setText(ui->label->text()+".");
    }
    else
    {
        return;
    }
}
 void MainWindow::number_operator_pressed()
 {
    QPushButton * button =(QPushButton*)sender();
    double labelNumber;
    QString newLabel;
    if(button->text()=="+/-")
    {
    labelNumber=(ui->label->text()).toDouble();
    labelNumber=labelNumber*-1;
    newLabel=QString::number(labelNumber,'g',15);
    ui->label->setText(newLabel);
    }
    if(button->text()=="%")
    {
    labelNumber=(ui->label->text()).toDouble();
    labelNumber=labelNumber/100;
    newLabel=QString::number(labelNumber,'g',15);
    ui->label->setText(newLabel);
    }

 }

 void MainWindow::islem_operatoru()
 {
     QPushButton * button =(QPushButton*)sender();
     firstNumber=(ui->label->text()).toDouble();
     button->setChecked(true);// hangi button basıldı bulundu ve true edildi
     if(ui->pushButton_bolu->isChecked()) bolme=true;
     if(ui->pushButton_carpi->isChecked()) carpi=true;
     if(ui->pushButton_eksi->isChecked()) eksi=true;
     if(ui->pushButton_plus->isChecked()) arti=true;

 }


void MainWindow::on_pushButton_equ_released()
{


    double labelNumber, secondnumber;
    QString newLabel;
    secondnumber=ui->label->text().toDouble();
    if(arti)
    {
    labelNumber=firstNumber+secondnumber;
    newLabel=QString::number(labelNumber,'g',15);
    ui->label->setText(newLabel);
    arti=false;
    }

    else if(eksi)
    {
    labelNumber=firstNumber-secondnumber;
    newLabel=QString::number(labelNumber,'g',15);
    ui->label->setText(newLabel);
    eksi=false;
    }

    else if(carpi)
    {
    labelNumber=firstNumber*secondnumber;
    newLabel=QString::number(labelNumber,'g',15);
    ui->label->setText(newLabel);
    carpi=false;
    }

    else if(bolme)
    {
    labelNumber=firstNumber/secondnumber;
    newLabel=QString::number(labelNumber,'g',15);
    ui->label->setText(newLabel);
    bolme=false;
    }
    userIsTyping=false;
}

void MainWindow::on_pushButtonCl_released()
{
    arti=false,eksi=false,carpi=false,bolme=false,userIsTyping=false;
    ui->label->setText("0");
}
