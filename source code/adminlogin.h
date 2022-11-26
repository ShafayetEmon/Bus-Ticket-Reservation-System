#ifndef ADMINLOGIN_H
#define ADMINLOGIN_H

#include <QDialog>
#include<adminpanel.h>


namespace Ui {
class AdminLogin;
}

class AdminLogin : public QDialog
{
    Q_OBJECT

public:
    explicit AdminLogin(QWidget *parent = nullptr);
    ~AdminLogin();
    //void setLabelText(QString str);

private slots:
    void on_pushButton_Login_clicked();

private:
    Ui::AdminLogin *ui;
    adminpanel *obj;
};

#endif // ADMINLOGIN_H
