#include "seatselect.h"
#include "ui_seatselect.h"
#include<QMessageBox>
#include<mainwindow.h>


seatSelect::seatSelect(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::seatSelect)
{
    ui->setupUi(this);
    setFixedSize(this->geometry().width(), this->geometry().height());

    MainWindow obj;


    QList<QAbstractButton*> button_list = AddSlotsToGroup();
    for(int i = 0; i<36; i++)
    {
        QString num = QString::number(i+1);
        QSqlQuery qry;
        obj.connOpen();
        qry.prepare("select distinct from seat");
        if(qry.next())
            button_list[i]->setStyleSheet("background-color: rgb(255, 0, 0);");
        else
            button_list[i]->setStyleSheet("background-color: rgb(85, 0, 255);");
    }
}

seatSelect::~seatSelect()
{
    delete ui;
}

QList<QAbstractButton*> seatSelect::AddSlotsToGroup()
{
    QButtonGroup* slotsGroup = new QButtonGroup(this);
    slotsGroup->addButton(ui->pushButton, 1);
    slotsGroup->addButton(ui->pushButton_2, 2);
    slotsGroup->addButton(ui->pushButton_3, 3);
    slotsGroup->addButton(ui->pushButton_4, 4);
    slotsGroup->addButton(ui->pushButton_5, 5);
    slotsGroup->addButton(ui->pushButton_6, 6);
    slotsGroup->addButton(ui->pushButton_7, 7);
    slotsGroup->addButton(ui->pushButton_8, 8);
    slotsGroup->addButton(ui->pushButton_9, 9);
    slotsGroup->addButton(ui->pushButton_10, 10);
    slotsGroup->addButton(ui->pushButton_11, 11);
    slotsGroup->addButton(ui->pushButton_12, 12);
    slotsGroup->addButton(ui->pushButton_13, 13);
    slotsGroup->addButton(ui->pushButton_14, 14);
    slotsGroup->addButton(ui->pushButton_15, 15);
    slotsGroup->addButton(ui->pushButton_16, 16);
    slotsGroup->addButton(ui->pushButton_17, 17);
    slotsGroup->addButton(ui->pushButton_18, 18);
    slotsGroup->addButton(ui->pushButton_19, 19);
    slotsGroup->addButton(ui->pushButton_20, 20);
    slotsGroup->addButton(ui->pushButton_21, 21);
    slotsGroup->addButton(ui->pushButton_22, 22);
    slotsGroup->addButton(ui->pushButton_23, 23);
    slotsGroup->addButton(ui->pushButton_24, 24);
    slotsGroup->addButton(ui->pushButton_25, 25);
    slotsGroup->addButton(ui->pushButton_26, 26);
    slotsGroup->addButton(ui->pushButton_27, 27);
    slotsGroup->addButton(ui->pushButton_28, 29);
    slotsGroup->addButton(ui->pushButton_29, 29);
    slotsGroup->addButton(ui->pushButton_30, 30);
    slotsGroup->addButton(ui->pushButton_31, 31);
    slotsGroup->addButton(ui->pushButton_32, 32);
    slotsGroup->addButton(ui->pushButton_33, 33);
    slotsGroup->addButton(ui->pushButton_34, 34);
    slotsGroup->addButton(ui->pushButton_35, 35);
    slotsGroup->addButton(ui->pushButton_36, 36);

    connect(slotsGroup, SIGNAL(buttonClicked(int)), this, SLOT(onAnySlotButtonClicked(int)));
    QList<QAbstractButton*> button_list = slotsGroup->buttons();
    return button_list;
}

void seatSelect::onAnySlotButtonClicked(int id)
{
    QList<QAbstractButton*> buttonList = AddSlotsToGroup();
    buttonList[id-1]->setStyleSheet("background-color: rgb(255, 0, 0);");
    MainWindow conn;
    conn.connOpen();

     QString num = QString::number(id);
     QSqlQuery qry;

     qry.prepare("insert into seat(seatNo)values('"+num+"')");
     qDebug()<<qry.exec();

     qDebug()<<qry.lastError().text();
     conn.connClose();

}


void seatSelect::on_pushButton_confirm_clicked()
{

    if(ui->lineEdit_name->text().isEmpty() || ui->lineEdit_nid->text().isEmpty() || ui->lineEdit_mobile->text().isEmpty() || ui->lineEdit_email->text().isEmpty() )
    {
        QMessageBox :: information(this,"Message", "Please select your seat and insert your information");
        return;

    }
    else
    {
        hide();
        obj = new congratz(this);
        obj->show();
    }
}



