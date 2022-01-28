#ifndef LOGIN_H
#define LOGIN_H

#include <QDialog>
#include "mainwindow.h"

namespace Ui {
class login;
}

class login : public QDialog
{
    Q_OBJECT

public:
    explicit login(QWidget *parent = nullptr);
    ~login();
int verif_login();

private slots:
void on_pushButton_clicked();
 void on_check_mdp_toggled(bool checked);
private:
    Ui::login *ui;
    MainWindow *M;

};

#endif // LOGIN_H
