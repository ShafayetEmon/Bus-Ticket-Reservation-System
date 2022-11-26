#ifndef CONGRATZ_H
#define CONGRATZ_H

#include <QDialog>

namespace Ui {
class congratz;
}

class congratz : public QDialog
{
    Q_OBJECT

public:
    explicit congratz(QWidget *parent = nullptr);
    ~congratz();

private slots:
    void on_pushButton_clicked();

private:
    Ui::congratz *ui;
};

#endif // CONGRATZ_H
