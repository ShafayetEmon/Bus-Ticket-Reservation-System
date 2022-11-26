#include "adminlogin.h"
#include "ui_adminlogin.h"
#include<QMessageBox>

AdminLogin::AdminLogin(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AdminLogin)
{
    ui->setupUi(this);
    setFixedSize(this->geometry().width(), this->geometry().height());

}

AdminLogin::~AdminLogin()
{
    delete ui;
}



void AdminLogin::on_pushButton_Login_clicked()
{
    if(ui->lineEdit_username->text()=="1" && ui->lineEdit_password->text()=="1"){
        hide();
        obj = new adminpanel(this);
        obj->show();
    }
    else{
        QMessageBox ::information(this, "Message", "Username or Password Incorrect");
    }
}
