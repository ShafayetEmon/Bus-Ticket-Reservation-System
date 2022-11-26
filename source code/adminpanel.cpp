#include "adminpanel.h"
#include "ui_adminpanel.h"
#include<mainwindow.h>



adminpanel::adminpanel(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::adminpanel)
{
    ui->setupUi(this);
    setFixedSize(this->geometry().width(), this->geometry().height());

}

adminpanel::~adminpanel()
{
    delete ui;
}


void adminpanel::on_pushButton_addroute_clicked()
{
    hide();
    obj= new addroute(this);
    obj->exec();
}

void adminpanel::on_pushButton_addplace_clicked()
{
    hide();
    obj2 = new addplace(this);
    obj2->show();
}

void adminpanel::on_pushButton_addoperator_clicked()
{
    hide();
    obj3 = new addoperator(this);
    obj3->show();
}

void adminpanel::on_pushButton_clicked()
{
    hide();
    MainWindow *mainWindow = new MainWindow();
        mainWindow->show();
}
