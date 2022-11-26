#ifndef ADDROUTE_H
#define ADDROUTE_H

#include <QDialog>
#include<routeadded.h>
#include<QtSql>
#include<QDebug>
#include<QFileInfo>

namespace Ui {
class addroute;
}

class addroute : public QDialog
{
    Q_OBJECT

public:

    explicit addroute(QWidget *parent = nullptr);
    ~addroute();

private slots:


    void on_pushButton_Addroute_clicked();

    void on_pushButton_clicked();

private:
    Ui::addroute *ui;
    routeadded *obj;

};

#endif // ADDROUTE_H
