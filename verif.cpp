#include "verif.h"
#include "ui_verif.h"
#include <QMessageBox>
verif::verif(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::verif)
{
    ui->setupUi(this);
}

verif::~verif()
{
    delete ui;
}

void verif::on_pushButton_clicked()
{
    QString log = ui->lineEdit->text();
        QString mdp = ui->lineEdit_2->text();
        if (log=="admin" && mdp=="admin")
        {
           /* int cin,ref,quantite,etat;
            QString type,date;
            cin=ui->cin->text().toInt();
            type=ui->type->text();
            ref=ui->ref->text().toInt();
            etat=ui->etat->text().toInt();
            quantite=ui->quantite->text().toInt();
            date=ui->date_2->text();
            QSqlQuery qry;
            QSqlQuery update;*/
            if (type=="Augmentation de salaire")
              {
                update.prepare("update PERSONNEL set SALAIRE=SALAIRE+:Quantite where CIN=:cin ");
              //update.prepare("update DEMANDE set ETAT=1 where REF_DEMANDE=:ref");
             /* update.bindValue(":cin",cin);
              update.bindValue(":ref",ref);
              update.bindValue(":Quantite",quantite);
              update.bindValue(":Type",type);
             update.bindValue(":Etat",etat);
              update.bindValue(":Date",date);
              update.exec();*/
              }
            //else{
                qry.prepare("update DEMANDE set ETAT=1 where REF_DEMANDE=:ref ");
          /*  qry.bindValue(":cin",cin);
             qry.bindValue(":ref",ref);
            qry.bindValue(":Quantite",quantite);
            qry.bindValue(":Type",type);
            qry.bindValue(":Etat",etat);
            qry.bindValue(":Date",date);*/
        // }
                    QMessageBox::critical(nullptr, QObject::tr("database is open"),
                                          QObject::tr("demande accepter.\n"
                                            "Click Cancel to exit."), QMessageBox::Cancel);
            qry.exec();
          //  ui->tabdemande->setModel(tmpdemande.afficher_demande());//refresh
            M =new MainWindow(this);
            M->show();

        }
        else
        {
            QMessageBox::critical(nullptr, QObject::tr("database is open"),
                        QObject::tr("wrong admin or password.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);
    }
}
