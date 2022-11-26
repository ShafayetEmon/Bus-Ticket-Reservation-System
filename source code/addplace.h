#ifndef ADDPLACE_H
#define ADDPLACE_H

#include <QDialog>
#include<QDebug>

namespace Ui {
class addplace;
}

class addplace : public QDialog
{
    Q_OBJECT

public:
    explicit addplace(QWidget *parent = nullptr);
    ~addplace();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::addplace *ui;
};

#endif // ADDPLACE_H
