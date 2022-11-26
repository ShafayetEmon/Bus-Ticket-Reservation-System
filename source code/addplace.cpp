#include "addplace.h"
#include "ui_addplace.h"
#include<mainwindow.h>
#include<adminpanel.h>

addplace::addplace(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::addplace)
{
    ui->setupUi(this);
    setFixedSize(this->geometry().width(), this->geometry().height());

}

addplace::~addplace()
{
    delete ui;
}

void addplace::on_pushButton_clicked()
{
    QString str;
    str=ui->lineEdit->text().toUpper();

    if(str!=NULL){

    MainWindow obj;
    obj.connOpen();

    QSqlQuery qry;

    qry.prepare("insert into addplace(places)values('"+str+"')");
    //qry.bindValue(":places", places);
    //obj.connClose();
    qDebug()<<qry.exec();
    qDebug()<<qry.lastError().text();
    obj.connClose();


    QSqlQueryModel *model= new QSqlQueryModel();
    obj.connOpen();
    QSqlQuery* qry1 = new QSqlQuery(obj.mydb);
        QString line="select *from addplace";
        qry1->prepare(line);
        qry1->exec();
        model->setQuery(*qry1);
        ui->tableView->setModel(model);
        qDebug()<<qry1->exec();
        qDebug()<<qry1->lastError().text();

    }


}

void addplace::on_pushButton_2_clicked()
{
    hide();
    adminpanel obj;
    obj.setModal(true);
    obj.exec();
}
