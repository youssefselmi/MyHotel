#ifndef VERIF_H
#define VERIF_H

#include <QDialog>
#include "mainwindow.h"
namespace Ui {
class verif;
}

class verif : public QDialog
{
    Q_OBJECT

public:
    explicit verif(QWidget *parent = nullptr);
    ~verif();

private slots:
    void on_pushButton_clicked();

private:
    Ui::verif *ui;
    MainWindow *M;
};

#endif // VERIF_H
