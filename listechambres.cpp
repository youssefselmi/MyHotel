#include "listechambres.h"
#include "ui_listechambres.h"
#include "ui_mainwindow.h"
#include "QSqlQuery"
#include"qsqlquerymodel.h"
#include "qstring.h"
#include "chambre.h"
#include "hebergement.h"

ListeChambres::ListeChambres(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ListeChambres)
{
    ui->setupUi(this);
}

ListeChambres::~ListeChambres()
{
    delete ui;
}

void ListeChambres::on_tableViewCH_activated(const QModelIndex &index)
{
    QString  val=ui->tableViewCH->model()->data(index).toInt();
    QSqlQuery qry;
    int cin=ui->CIIN_2->text().toInt();
               int nbP=ui->NBpersonnes_2->text().toInt();
               QString TypeC=ui->TypeC->currentText();
               QString TypeP=ui->TypeP_2->currentText();

               QString dateA=ui->dateTimeEdit->date().toString();
               QString dateD=ui->dateTimeEdit_2->date().toString();
               QString Nom=ui->Nom->text();
               QString Prenom=ui->Prenom->text();
    hebergement H();
               bool test=H.ajouterH(val);
               if (test)

            /*   {

                   QMessageBox::critical(nullptr, QObject::tr("database is open"),
                                         QObject::tr("Reservation ajouter.\n"
                                           "Click Cancel to exit."), QMessageBox::Cancel);
                   up.prepare("UPDATE CHAMBRE set ETAT_CHAMBRE='Reserver' where NUM_CHAMBRE=:num");
                   up.bindValue("num",num);
                   up.exec();
               }*/

}

void ListeChambres::on_afficherCH_clicked()
{
    QSqlQueryModel *modal=new QSqlQueryModel();
    QSqlQuery request;
    hebergement H;
    request.prepare("SELECT * FROM CHAMBRE WHERE TYPE_CHAMBRE=:type AND ETAT_CHAMBRE='Non reserver'");
    request.bindValue("type",H.getTYPE());
    modal->setQuery(request);
    ui->tableViewCH->setModel(modal);
}
