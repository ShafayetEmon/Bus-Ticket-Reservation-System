#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QMessageBox>
#include<ctype.h>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    setFixedSize(this->geometry().width(), this->geometry().height());


        connOpen();
        QString line1="select distinct F from addroute";
        QString line2="select distinct T from addroute ";
        QSqlQuery qry1,qry2;
        QSqlQueryModel *model= new QSqlQueryModel();
        QSqlQueryModel *model2= new QSqlQueryModel();

        if(qry1.exec(line1)&& qry2.exec(line2))
        {
            while(qry1.next() && qry2.next())
            {
                model->setQuery(qry1);
                model2->setQuery(qry2);
            }
        }
        ui->comboBox_From->setModel(model);
        ui->comboBox_to->setModel(model2);
        connClose();




}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{

        hide();
        obj = new AdminLogin(this);
        obj->show();

}

void MainWindow::on_comboBox_From_currentIndexChanged(const QString &arg1)

{
    F=ui->comboBox_From->currentText();
    //qDebug()<<F;
}

void MainWindow::on_comboBox_to_currentIndexChanged(const QString &arg1)
{
    T=ui->comboBox_to->currentText();
    //qDebug()<<T;
}

void MainWindow::on_pushButton_2_clicked()
{

            if(F!=T){
                hide();
                obj2 = new showroute(this);
                obj2->show();
                obj2->showlist(F,T);
            }

            QString time = ui->dateEdit->text();
}


void MainWindow::on_pushButton_3_clicked()
{
    close();
}
