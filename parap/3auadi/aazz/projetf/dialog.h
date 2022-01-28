#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include "personnel.h"

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = nullptr);
    ~Dialog();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_tabpersonnel_activated(const QModelIndex &index);

    void on_pushButton_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_8_clicked();





    void on_pushButton_9_clicked();

    void on_pushButton_11_clicked();

    void on_pushButton_91_clicked();

private:
    Ui::Dialog *ui;

    PERSONNEL tmppersonnel;

};

#endif // DIALOG_H
