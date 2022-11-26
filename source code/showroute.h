#ifndef SHOWROUTE_H
#define SHOWROUTE_H

#include <QDialog>
#include<QtSql>
#include<QtDebug>
#include<QFileInfo>
#include<seatselect.h>

namespace Ui {
class showroute;
}

class showroute : public QDialog
{
    Q_OBJECT

public:
    explicit showroute(QWidget *parent = nullptr);
    ~showroute();


    void showlist(QString F1, QString F2);

private slots:
    void on_pushButton_clicked();

    void on_tableView_activated(const QModelIndex &index);

private:
    Ui::showroute *ui;
    seatSelect *obj;
};

#endif // SHOWROUTE_H
