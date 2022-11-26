#include "addroute.h"
#include "ui_addroute.h"
#include<ctype.h>
#include<mainwindow.h>
#include<QMessageBox>

addroute::addroute(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::addroute)
{
    ui->setupUi(this);
    setFixedSize(this->geometry().width(), this->geometry().height());



    MainWindow conn;
    conn.connOpen();
    QString line1="select distinct places from addplace";
    QString line2="select distinct operator from addoperator";
    QSqlQuery qry1,qry2;
    QSqlQueryModel *model= new QSqlQueryModel();
    QSqlQueryModel *model2= new QSqlQueryModel();

    if(qry1.exec(line1) && qry2.exec(line2))
    {
        while(qry1.next() && qry2.next())
        {
            model->setQuery(qry1);
            model2->setQuery(qry2);

        }
    }

    ui->comboBox_from->setModel(model);
    ui->comboBox_to->setModel(model);
    ui->comboBox_operator->setModel(model2);
    conn.connClose();
}

addroute::~addroute()
{
    delete ui;
}



void addroute::on_pushButton_Addroute_clicked()
{
    QString F, T, OpName, BusNo,Fare, S;
    F=ui->comboBox_from->currentText();
    T=ui->comboBox_to->currentText();
    OpName=ui->comboBox_operator->currentText();
    BusNo=ui->lineEdit_BusNo->text();
    Fare = ui->lineEdit_Fare->text();
    S = "SELECT";


    MainWindow conn;
    conn.connOpen();
    QSqlQuery qry;
    qry.prepare("insert into addroute(F,T,OpName,BusNo,Fare, S)values(:F,:T,:OpName,:BusNo,:Fare, :S)");

    qry.bindValue(":F", F);
    qry.bindValue(":T", T);
    qry.bindValue(":OpName", OpName);
    qry.bindValue(":BusNo", BusNo);
    qry.bindValue(":Fare", Fare);
    qry.bindValue(":S", S);


    qDebug()<<qry.exec();
    conn.connClose();


    if(BusNo!=NULL && Fare!=NULL)
    {     
            QSqlQueryModel *model= new QSqlQueryModel();
            conn.connOpen();
            QSqlQuery* qry1 = new QSqlQuery(conn.mydb);
            QString line="select *from addroute";
            qry1->prepare(line);
            if(qry1->exec())
            {
                model->setQuery(*qry1);
                ui->tableView->setModel(model);
            }
            conn.connClose();
    }

}

void addroute::on_pushButton_clicked()
{
    hide();
    adminpanel obj;
    obj.setModal(true);
    obj.exec();
}
