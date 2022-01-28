#ifndef DIALOGMATERIAUX_H
#define DIALOGMATERIAUX_H

#include <QDialog>
#include "materiaux.h"

namespace Ui {
class dialogMateriaux;
}

class dialogMateriaux : public QDialog
{
    Q_OBJECT

public:
    explicit dialogMateriaux(QWidget *parent = nullptr);
    ~dialogMateriaux();

private slots:
    void on_pushButton_18_clicked();

    void on_pushButton_31_clicked();

    void on_tableView_activated(const QModelIndex &index);

    void on_pushButton_clicked();

    void on_pushButton_28_clicked();

    void on_pushButton_33_clicked();

    void on_pushButton_36_clicked();

private:
    Ui::dialogMateriaux *ui;
    materiaux tmpM ;

};

#endif // DIALOGMATERIAUX_H
