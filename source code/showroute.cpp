#include "showroute.h"
#include "ui_showroute.h"
#include<mainwindow.h>
#include<QMessageBox>

showroute::showroute(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::showroute)
{
    ui->setupUi(this);
   // this->setWindowState(Qt::WindowMaximized);
    setFixedSize(this->geometry().width(), this->geometry().height());



}

showroute::~showroute()
{
    delete ui;
}

void showroute::showlist(QString F1, QString F2)
{
    MainWindow obj;

    QSqlQueryModel *model= new QSqlQueryModel();
    obj.connOpen();

    QSqlQuery *qry = new QSqlQuery(obj.mydb);
    QString line="select * from addroute where F='"+F1+"' and T='"+F2+"'";
    qry->prepare(line);
    if(qry->exec()){
        model->setQuery(*qry);
        ui->tableView->setModel(model);
       // ui->tableView->horizontalHeader()->setStretchLastSection(true);
        //ui->tableView->resizeColumnsToContents();


    }
    else
    {
        QMessageBox ::information(this,"Message","No Buses found");
    }
    obj.connClose();
    //qDebug()<<(model->rowCount());
}

void showroute::on_pushButton_clicked()
{
    hide();
    MainWindow *mainWindow = new MainWindow();
        mainWindow->show();
}

void showroute::on_tableView_activated(const QModelIndex &index)
{
    hide();
    obj = new seatSelect(this);
    obj->show();
}
