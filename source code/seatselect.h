#ifndef SEATSELECT_H
#define SEATSELECT_H

#include <QDialog>
#include<congratz.h>
#include"QButtonGroup"

namespace Ui {
class seatSelect;
}

class seatSelect : public QDialog
{
    Q_OBJECT

public:
    explicit seatSelect(QWidget *parent = nullptr);
    ~seatSelect();

private slots:
    QList<QAbstractButton*> AddSlotsToGroup();

    void onAnySlotButtonClicked(int id);

    //void on_groupBox_clicked();

    void on_pushButton_confirm_clicked();

private:
    Ui::seatSelect *ui;
    congratz *obj;
};

#endif // SEATSELECT_H
