#ifndef ADMINPANEL_H
#define ADMINPANEL_H

#include <QDialog>
#include<addroute.h>
#include<addplace.h>
#include<addoperator.h>

namespace Ui {
class adminpanel;
}

class adminpanel : public QDialog
{
    Q_OBJECT

public:
    explicit adminpanel(QWidget *parent = nullptr);
    ~adminpanel();

private slots:
    void on_pushButton_addroute_clicked();

    void on_pushButton_addplace_clicked();

    void on_pushButton_addoperator_clicked();

    void on_pushButton_clicked();

private:
    Ui::adminpanel *ui;
    addroute *obj;
    addplace *obj2;
    addoperator *obj3;


};

#endif // ADMINPANEL_H
