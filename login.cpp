#include "login.h"
#include "ui_login.h"
#include "connexion.h"
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QMessageBox>
#include "mainwindow.h"
login::login(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::login)
{
    ui->setupUi(this);
    on_check_mdp_toggled(false);
}

login::~login()
{
    delete ui;
}
int login::verif_login()
 {
    QSqlQuery qry;

    int test=0;
    QString identifiant = ui->id_edit->text();
    QString MDP = ui->mdp_edit->text();
    qry.prepare(QString("SELECT * FROM LOGIN "));
    if (qry.exec()) // houni chtparkouri l base mte3K
    {

        while (qry.next())
        {
          if ((qry.value(1)==identifiant)&&(qry.value(0)==MDP)){

             test=1;

       }
    }}
    return test;
 }
void login::on_check_mdp_toggled(bool checked)
{

    if(checked){
        ui->mdp_edit->setEchoMode(QLineEdit::Normal);
    }
    else
         ui->mdp_edit->setEchoMode(QLineEdit::Password);
}

void login::on_pushButton_clicked()
{
    QSqlQuery qry;
    QString identifiant = ui->id_edit->text();
    QString MDP = ui->mdp_edit->text();
    int test=0;
    qry.prepare(QString("SELECT * FROM LOGIN "));
    if (qry.exec()) // houni chtparkouri l base mte3K
    {

        while (qry.next())
        {
          if ((qry.value(0)==identifiant)&&(qry.value(1)==MDP)){

           test=1;
           ui->progressBar->setValue(100);
           M =new MainWindow(this);
            M->setWindowTitle("MY HOTEL");
                   M->show();

       }
    }
        if(test!=1) {
            QMessageBox::critical(nullptr, QObject::tr("database is open"),
                        QObject::tr("wrong admin or password.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);
        }
        }

}
