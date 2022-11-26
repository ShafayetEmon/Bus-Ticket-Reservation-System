#include "congratz.h"
#include "ui_congratz.h"
#include<mainwindow.h>

congratz::congratz(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::congratz)
{
    ui->setupUi(this);
    setFixedSize(this->geometry().width(), this->geometry().height());

}

congratz::~congratz()
{
    delete ui;
}

void congratz::on_pushButton_clicked()
{
    hide();
    MainWindow *mainWindow = new MainWindow();
    mainWindow->show();
}
