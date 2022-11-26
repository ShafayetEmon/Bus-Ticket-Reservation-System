#include "addoperator.h"
#include "ui_addoperator.h"
#include<mainwindow.h>



addoperator::addoperator(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::addoperator)
{
    ui->setupUi(this);

    setFixedSize(this->geometry().width(), this->geometry().height());

}

addoperator::~addoperator()
{
    delete ui;
}

void addoperator::on_pushButton_clicked()
{
    QString str;
    str=ui->lineEdit_operator->text();
    if(str!=NULL)
    {
        MainWindow obj;
        obj.connOpen();
        QSqlQuery qry;

        qry.prepare("insert into addoperator (operator) values('"+str+"')");
        qDebug()<<qry.exec();
        qDebug()<<qry.lastError().text();

        QSqlQueryModel *model= new QSqlQueryModel();
        obj.connOpen();
        QSqlQuery* qry1 = new QSqlQuery(obj.mydb);
            QString line="select *from addoperator";
            qry1->prepare(line);
            qry1->exec();
            model->setQuery(*qry1);
            ui->tableView->setModel(model);
            qDebug()<<qry1->exec();
            qDebug()<<qry1->lastError().text();

    }

}

void addoperator::on_pushButton_2_clicked()
{
    hide();
    adminpanel obj;
    obj.setModal(true);
    obj.exec();


}
