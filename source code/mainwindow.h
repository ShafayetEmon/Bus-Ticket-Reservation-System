#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<adminlogin.h>
#include<QtSql>
#include<QtDebug>
#include<QFileInfo>
#include<showroute.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    QString F,T;
    QSqlDatabase mydb;
    void connClose()
    {
        mydb.close();
        mydb.removeDatabase(QSqlDatabase::defaultConnection);
    }
    bool connOpen()
    {

        QString path = QDir(QCoreApplication::applicationDirPath()).filePath("addroute.db");
        mydb=QSqlDatabase::addDatabase("QSQLITE");
        mydb.setDatabaseName(path);
        if(!mydb.open())
        {
            qDebug()<<("Failed");
            return false;
        }
        else
        {
            qDebug()<<("Connected");
            return true;
        }
    }



public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:


    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_comboBox_From_currentIndexChanged(const QString &arg1);

    void on_comboBox_to_currentIndexChanged(const QString &arg1);

    void on_pushButton_3_clicked();

private:
    Ui::MainWindow *ui;
    AdminLogin *obj;
    showroute *obj2;
};

#endif // MAINWINDOW_H
