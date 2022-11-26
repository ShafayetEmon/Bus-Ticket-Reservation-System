#ifndef ADDOPERATOR_H
#define ADDOPERATOR_H

#include <QDialog>
#include<QDebug>




namespace Ui {
class addoperator;
}

class addoperator : public QDialog
{
    Q_OBJECT

public:


    explicit addoperator(QWidget *parent = nullptr);
    ~addoperator();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::addoperator *ui;


};

#endif // ADDOPERATOR_H
