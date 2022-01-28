#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTabWidget>
#include "personnel.h"
#include <QMessageBox>
#include "dialog.h"
#include "demande.h"
#include "hebergement.h"
#include "materiaux.h"
#include "evenement.h"
#include "hebergement.h"
#include "chambre.h"
#include <QString>
#include <QSqlQuery>
#include <QPixmap>
#include "historique.h"
#include "equipement.h"
#include "qcustomplot.h"
#include"QSqlRecord"
#include"QSqlQuery"
#include "statchambre.h"
#include "notification.h"
#include "mainwindow.h"
//#include "statyoussef.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    trayIcon = new QSystemTrayIcon(QIcon(QPixmap("C:/Users/ASUS/Desktop/youssefselmi/imagees/icon.png")),this);
    trayIcon->setContextMenu(criarMenu());
    trayIcon->show();
    trayIcon->showMessage("Bienvenu", "My Hotel",
                          QSystemTrayIcon::Information, 3000);
    makePolt();
    makePolt1();
    makePolt2();

    ui->tabanim->setModel(tmpanim.afficher());
    ui->tabanime->setModel(tmpanime.afficherasc());
    ui->pushButton_4->setToolTip("Quitter");
        ui->pushButton_5->setToolTip("valider reservation");
            //ui->pushButton_6->setToolTip("afficher reservation");
   ui->tabWidget->setTabText(0,"Hebergement");
      ui->tabWidget->setTabText(1,"Restauration");
         ui->tabWidget->setTabText(2,"Resources humaines");
            ui->tabWidget->setTabText(3,"Evenements");
            ui->tabWidget->setTabText(4,"Loisirs");
ui->tabWidget_2->setTabText(0,"Reservation");
ui->tabWidget_2->setTabText(1,"Hebergement");
ui->tabWidget_3->setTabText(0,"");
ui->tabWidget_3->setTabText(1,"");
ui->tabWidget_4->setTabText(0,"Personnel");
ui->tabWidget_4->setTabText(1,"Demande");
ui->tabWidget_5->setTabText(0,"Materiaux");
ui->tabWidget_5->setTabText(1,"Evenements");
ui->tabWidget_6->setTabText(0,"Animation");
ui->tabWidget_6->setTabText(1,"Equipe");

ui->lineEdit_cin->setPlaceholderText("CIN");
ui->lineEdit_id->setPlaceholderText("IDEQUIPEMENT");
ui->lineEdit_type->setPlaceholderText("TYPEEQUIPEMENT");
ui->lineEdit_nb->setPlaceholderText("NOMBRE");

ui->Num->setPlaceholderText("Numero de chambre");

ui->NbPr->setPlaceholderText("Nombre de personnes");

ui->cin->setPlaceholderText("CIN");

ui->salaire->setPlaceholderText("Salaire");

ui->QUANTITE_DEMANDE->setPlaceholderText("Quantite Demande");
//ui->Ref->setPlaceholderText("Reference");
ui->QNT->setPlaceholderText("Quantité");
ui->etatM->setPlaceholderText("Etat");
//ui->NomEVE->setPlaceholderText("id ");
ui->TypeEVE->setPlaceholderText("Type");
ui->NBpEVE->setPlaceholderText("Nombre de personnes");
/*ui->IdANIM->setPlaceholderText("ID");
ui->LieuANIM->setPlaceholderText("Lieu");
ui->TypeANIM->setPlaceholderText("Type");
ui->IdANIM_2->setPlaceholderText("ID");*/
/*ui->etatANIM->setPlaceholderText("etat");
ui->quantiteANIM->setPlaceholderText("Quantite");
ui->TypeANIM2->setPlaceholderText("Type");
ui->recherche_cin->setPlaceholderText("CIN");*/
    ui->recherche_grade->setPlaceholderText("GRADE");
    ui->recherche_salaire->setPlaceholderText("SALAIRE");
    ui->recherche_date->setPlaceholderText("DATE");
    ui->recherche_presence->setPlaceholderText("PRESENCE");
    ui->ref->setPlaceholderText("REF");
    ui->quantite->setPlaceholderText("QUANTITE");
    ui->type->setPlaceholderText("TYPE");
    ui->cin_2->setPlaceholderText("CIN");
    ui->etat->setPlaceholderText("ETAT");
    ui->date_2->setPlaceholderText("DATE");
    ui->lineEdit_recherche->setPlaceholderText("Recherche");
    ui->lineEdit_idanim->setPlaceholderText("ID");
    ui->lineEdit_typeanim->setPlaceholderText("Lieu");
    ui->lineEdit_lieu->setPlaceholderText("Type");
    ui->lineEdit_duree->setPlaceholderText("DUREE EN MINUTE");
    //ui->lineEdit_dateanim->setPlaceholderText("Date");
    ui->lineEdit_cin->setPlaceholderText("CIN");
    ui->lineEdit_idanim_3->setPlaceholderText("ID");
    ui->lineEdit_typeanim_2->setPlaceholderText("Lieu");
    ui->lineEdit_lieu_2->setPlaceholderText("Type");
    ui->lineEdit_duree_2->setPlaceholderText("DUREE EN MINUTE");
    //ui->lineEdit_dateanim->setPlaceholderText("Date");
    ui->lineEdit_cin_2->setPlaceholderText("CIN");
ui->log->setPlaceholderText("LOGIN");
ui->mdp->setPlaceholderText("MOT DE PASSE");


}

MainWindow::~MainWindow()
{
    delete ui;
}




void MainWindow::on_pushButton_4_clicked()
{
        QApplication::quit();
}

void MainWindow::on_pushButton_7_clicked()
{
        QApplication::quit();
}

void MainWindow::on_pushButton_11_clicked()
{
    QApplication::quit();
}

void MainWindow::on_pushButton_14_clicked()
{
    QApplication::quit();
}

void MainWindow::on_pushButton_17_clicked()
{
    QApplication::quit();

}

void MainWindow::on_pushButton_20_clicked()
{
    QApplication::quit();
}

void MainWindow::on_pushButton_23_clicked()
{
    QApplication::quit();
}

void MainWindow::on_pushButton_27_clicked()
{
    QApplication::quit();
}
QMenu *MainWindow::criarMenu()
{
  auto menu = new QMenu("Menu de icone", this);
  menu->addAction("youssef selmi", [this] {show();});
  menu->addAction("youssef selmi", [this] {hide();});
  menu->addSeparator();
  //menu->addAction("sai", [this] {qApp->quit();});
  return  menu;
}
void MainWindow::on_pushButton_10_clicked()
{
    int CIN = ui->cin->text().toInt();
    QString GRADE = ui->grade->currentText();
    QString cin = ui->cin->text();
    if (GRADE=="Veilleur de nuit") ui->salaire->setText("800");
    else if (GRADE=="Directeur d'hôtel") ui->salaire->setText("2000");
    else if (GRADE=="Directeur d'hébergement") ui->salaire->setText("1400");
    int SALAIRE = ui->salaire->text().toInt();
    QString DATECONTRAT = ui->date->selectedDate().toString();
    if ((CIN/1)!=0 && !GRADE.isEmpty() && (SALAIRE/1)!=0 && !DATECONTRAT.isEmpty()){
        if (cin.size()!=8 )
        {
            QMessageBox::critical(nullptr, QObject::tr("Erreur"),
                                  QObject::tr("CIN doit comporter 8 chiffres.\n"
                                    ), QMessageBox::Cancel);
        }
    else{
    PERSONNEL p(CIN,GRADE,0,SALAIRE,DATECONTRAT);
    bool test=p.ajouter();
    if (test)
    {

        QMessageBox::information(nullptr, QObject::tr("database is open"),
                              QObject::tr("personnel ajouter.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
        QSqlQueryModel * modal= new QSqlQueryModel();
        QSqlQuery request;
        request.prepare("select CIN from PERSONNEL");
        request.exec();
        modal->setQuery(request);
        ui->comboBox_3->setModel(modal);
    }
    else
     {  qDebug()<<"test";
        notification n("ERREUR","Personnel existe déja");
        n.afficher();
        }
    }
    }
    else {
        QMessageBox::critical(nullptr, QObject::tr("Erreur"),
                              QObject::tr("Tous les champs sont obligatoires.\n"
                                ), QMessageBox::Cancel);
    }
}






void MainWindow::on_pushButton_13_clicked()
{

  int CIN = ui->comboBox_3->currentText().toInt();
  QString TYPE_DEMANDE = ui->TYPE_DEMANDE->currentText();
  int QUANTITE_DEMANDE = ui->QUANTITE_DEMANDE->text().toInt();
   QString DATEDEBUT = ui->DATEDEBUT->selectedDate().toString();
   if ((CIN/1)!=0 && !TYPE_DEMANDE.isEmpty() && (QUANTITE_DEMANDE/1)!=0 && !DATEDEBUT.isEmpty())
 {
   demande d(QUANTITE_DEMANDE,TYPE_DEMANDE,CIN,0,DATEDEBUT);
   bool test=d.ajouter_demande();

   if (test)
   {

       QMessageBox::information(nullptr, QObject::tr("database is open"),
                             QObject::tr("demande ajouter.\n"
                               "Click Cancel to exit."), QMessageBox::Cancel);
   }
}
   else {
       QMessageBox::critical(nullptr, QObject::tr("Erreur"),
                             QObject::tr("Tous les champs sont obligatoires.\n"
                               ), QMessageBox::Cancel);
   }

}





void MainWindow::on_pushButton_16_clicked()
{

    int nbr = ui->QNT->text().toInt();
    QString etat = ui->etatM->text();
    int eve=ui->Ref_Eve->currentText().toInt();
        materiaux M(nbr,etat,eve);
    bool test=M.ajout();
    if (test)
    {
                QMessageBox::information(nullptr, QObject::tr("database is open"),
                            QObject::tr("materiel ajouteé.\n"
                                        "Click Cancel to exit."), QMessageBox::Cancel);
    }
}

void MainWindow::on_pushButton_19_clicked()
{

    QString type = ui->TypeEVE->text();
    QString date =ui->calendarWidget_5->selectedDate().toString();
    int nbrE = ui->NBpEVE->text().toInt();
       evenement E(/*id,*/type,date,nbrE);
    bool test = E.ajoutE();
    if (test)
    {
                QMessageBox::information(nullptr, QObject::tr("database is open"),
                            QObject::tr("evenement ajouteé.\n"
                                        "Click Cancel to exit."), QMessageBox::Cancel);
    }

}



void MainWindow::on_pushButton_5_clicked()
{
    QSqlQuery RP,up;
    int num=0;
    int cin=ui->CIIN_2->text().toInt();
            int nbP=ui->NBpersonnes_2->text().toInt();
            QString TypeC=ui->TypeC->currentText();
            QString TypeP=ui->TypeP_2->currentText();

            QString dateA=ui->dateTimeEdit->date().toString();
            QString dateD=ui->dateTimeEdit_2->date().toString();
            QString Nom=ui->Nom->text();
            QString Prenom=ui->Prenom->text();
            RP.prepare("select NUM_CHAMBRE from(select NUM_CHAMBRE from  chambre where ETAT_CHAMBRE='Non reserver ' AND TYPE_CHAMBRE=:type) where rownum <2;" );
            RP.bindValue(":type",TypeC);
            if(RP.exec()){
                while (RP.next()){
                    num=RP.value(0).toInt();
                }
                if (!dateA.isEmpty()&&!dateA.isEmpty()&&!Nom.isEmpty()&&!Prenom.isEmpty()&&(nbP/1)!=0 && ((cin/1)!=0)){
                   if (num!=0){
            hebergement H(num,cin,nbP,dateA,dateD,TypeC,TypeP,Nom,Prenom);
            bool test=H.ajouterH();
            up.prepare("UPDATE CHAMBRE SET ETAT_CHAMBRE='Reserver' where NUM_CHAMBRE=:num");
            up.bindValue(":num",num);
            up.exec();
            if (test)
            {

                QMessageBox::information(nullptr, QObject::tr("database is open"),
                                      QObject::tr("Reservation ajouter.\n"
                                        "Click Cancel to exit."), QMessageBox::Cancel);

            }
                                }
                   else {
                       QMessageBox::critical(nullptr, QObject::tr("Erreur"),
                                             QObject::tr("Aucune chambre disponible.\n"
                                               ), QMessageBox::Cancel);
                   }
                }
                else {
                    QMessageBox::critical(nullptr, QObject::tr("Erreur"),
                                          QObject::tr("Tous les champs sont obligatoires.\n"
                                            ), QMessageBox::Cancel);
                }
                if(dateA<dateD){
                    QMessageBox::critical(nullptr, QObject::tr("Erreur"),
                                          QObject::tr("date départ doit être supérieur a date d'arrivée .\n"
                                            ), QMessageBox::Cancel);
                }
            }
}




void MainWindow::on_pushButton_9_clicked()
{
    int  num=ui->Num->text().toInt();
            QString type=ui->Type->currentText();
            QString etat=ui->Etat->currentText();
            int  cap=ui->NbPr->text().toInt();
            if (!type.isEmpty()&&!etat.isEmpty()&&(cap/1)!=0&&(num/1)!=0){
            chambre CH(num,etat,type,cap);
            bool test=CH.ajouterCH();
            if (test)
            {

                QMessageBox::information(nullptr, QObject::tr("database is open"),
                                      QObject::tr("Chambre ajouter.\n"
                                        "Click Cancel to exit."), QMessageBox::Cancel);
            }
            }
            else {
                QMessageBox::critical(nullptr, QObject::tr("database is open"),
                                      QObject::tr("Tous les champs sont obligatoires.\n"
                                        ), QMessageBox::Cancel);
            }
}

void MainWindow::on_pushButton_33_clicked()
{
     ui->tabpersonnel->setModel(tmppersonnel.afficher());
}

void MainWindow::on_pushButton_2_clicked()
{
    int cin = ui->recherche_cin->text().toInt();
    bool test=tmppersonnel.supprimer(cin);
    if (test)
    {ui->tabpersonnel->setModel(tmppersonnel.afficher());//refresh
        QMessageBox::critical(nullptr, QObject::tr("database is open"),
                              QObject::tr("personnel supprimer.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
}
}

void MainWindow::on_pushButton_3_clicked()
{
    int cin,presence,salaire;
    QString grade,date;
    cin=ui->recherche_cin->text().toInt();
    grade=ui->recherche_grade->text();
    presence=ui->recherche_presence->text().toInt();
    salaire=ui->recherche_salaire->text().toInt();
    date=ui->recherche_date->text();
    QSqlQuery qry;
    qry.prepare("update PERSONNEL set GRADE=:Grade,PRESENCE=:Presence,SALAIRE=:Salaire,DATECONTRAT=:Date where CIN=:cin ");
    qry.bindValue(":cin",cin);
    qry.bindValue(":Grade",grade);
    qry.bindValue(":Presence",presence);
    qry.bindValue(":Salaire",salaire);
    qry.bindValue(":Date",date);
            QMessageBox::critical(nullptr, QObject::tr("database is open"),
                                  QObject::tr("personnel modifier.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);
    qry.exec();
    ui->tabpersonnel->setModel(tmppersonnel.afficher());//refresh
}
void MainWindow::on_tabpersonnel_activated(const QModelIndex &index)
{
    QString val=ui->tabpersonnel->model()->data(index).toString();
    QSqlQuery qry;
    qry.prepare("select * from PERSONNEL where CIN=:val or GRADE=:val or PRESENCE=:val or SALAIRE=:val or DATECONTRAT=:val");
    qry.bindValue(":val",val);
    if (qry.exec())
    {
        while (qry.next())
        {
            ui->recherche_cin->setText(qry.value(0).toString());
            ui->recherche_grade->setText(qry.value(1).toString());
            ui->recherche_presence->setText(qry.value(2).toString());
            ui->recherche_salaire->setText(qry.value(3).toString());
            ui->recherche_date->setText(qry.value(4).toString());

        }
    }


}

void MainWindow::on_pushButton_30_clicked()
{
    QString strStream;
            QTextStream out(&strStream);
            const int rowCount = ui->tabpersonnel->model()->rowCount();
            const int columnCount = ui->tabpersonnel->model()->columnCount();
            for (int column = 0; column < columnCount; column++)
                if (!ui->tabpersonnel->isColumnHidden(column))
                    out << QString("<th>%1</th>").arg(ui->tabpersonnel->model()->headerData(column, Qt::Horizontal).toString());
            for (int row = 0; row < rowCount; row++) {
                out << "<tr>";
                for (int column = 0; column < columnCount; column++) {
                    if (!ui->tabpersonnel->isColumnHidden(column)) {
                        QString data =ui->tabpersonnel->model()->data(ui->tabpersonnel->model()->index(row, column)).toString().simplified();
                        out << QString("<td bkcolor=0>%1</td>").arg((!data.isEmpty()) ? data : QString("&nbsp;"));
                    }
                }
            }
            QTextDocument *document = new QTextDocument();
            document->setHtml(strStream);
    QPrinter printer ;
           QPrintDialog *daddy = new QPrintDialog(&printer, NULL);
            if (daddy->exec() == QDialog::Accepted) {
                document->print(&printer);
            }
            delete document;
}

void MainWindow::on_pushButton_28_clicked()
{
    QString strStream;
            QTextStream out(&strStream);
            const int rowCount = ui->tabpersonnel->model()->rowCount();
            const int columnCount = ui->tabpersonnel->model()->columnCount();
            for (int column = 0; column < columnCount; column++)
                if (!ui->tabpersonnel->isColumnHidden(column))
                   out << QString("<th>%1</th>").arg(ui->tabpersonnel->model()->headerData(column, Qt::Horizontal).toString());
            for (int row = 0; row < rowCount; row++) {
                for (int column = 0; column < columnCount; column++) {
                    if (!ui->tabpersonnel->isColumnHidden(column)) {
                        QString data =ui->tabpersonnel->model()->data(ui->tabpersonnel->model()->index(row, column)).toString().simplified();
                        out << QString("<td bkcolor=0>%1</td>").arg((!data.isEmpty()) ? data : QString("&nbsp;"));
                    }
                }
            }
           QTextDocument *document = new QTextDocument();
           document->setHtml(strStream);
           QString fileName = QFileDialog::getSaveFileName((QWidget* )0, "Export PDF", QString(), ".pdf");
           if (QFileInfo(fileName).suffix().isEmpty()) { fileName.append(".txt.pdf"); }
           QPrinter printer(QPrinter::PrinterResolution);
           printer.setOutputFormat(QPrinter::PdfFormat);
           printer.setPaperSize(QPrinter::A4);
           printer.setOutputFileName(fileName);
           QTextDocument doc;
           doc.setHtml(document->toPlainText());
            doc.print(&printer);
}

void MainWindow::on_pushButton_31_clicked()
{
    QSqlQueryModel *modal=new QSqlQueryModel();
            QSqlQuery request;
           QString type=ui->comboBox->currentText();
           QString val=ui->lineEdit->text();
           val="%"+val+"%";
           if (type=="CIN"){
               request.prepare("SELECT * FROM PERSONNEL WHERE CIN LIKE:val order by CIN");
           }else if (type=="GRADE"){
               request.prepare("SELECT * FROM PERSONNEL WHERE GRADE LIKE:val");
           }else if (type=="SALAIRE"){
               request.prepare("SELECT * FROM PERSONNEL WHERE SALAIRE LIKE:val");
           }else if (type=="DATE CONTRAT"){
               request.prepare("SELECT * FROM PERSONNEL WHERE DATECONTRAT LIKE:val");
           }
           request.bindValue(":val",val);
           request.exec();
           modal->setQuery(request);
           ui->tabpersonnel->setModel(modal);
}

void MainWindow::on_pushButton_29_clicked()
{
    QSqlQueryModel * modal= new QSqlQueryModel();
    QSqlQuery request;
        request.prepare("select * from PERSONNEL order by PRESENCE DESC");
        request.exec();
        modal->setQuery(request);
        ui->tabpersonnel->setModel(modal);
}

void MainWindow::on_pushButton_32_clicked()
{
    QSqlQueryModel * modal= new QSqlQueryModel();
    QSqlQuery request;
        request.prepare("select * from PERSONNEL order by CIN DESC");
        request.exec();
        modal->setQuery(request);
        ui->tabpersonnel->setModel(modal);
}



void MainWindow::on_pushButton_36_clicked()
{
     ui->tabdemande->setModel(tmpdemande.afficher_demande());
}

void MainWindow::on_tabdemande_activated(const QModelIndex &index)
{
    QString val=ui->tabdemande->model()->data(index).toString();
    QSqlQuery qry;
    qry.prepare("select * from demande where REF_DEMANDE=:val ");
    qry.bindValue(":val",val);
    if (qry.exec())
    {
        while (qry.next())
        {
            ui->ref->setText(qry.value(0).toString());
            ui->quantite->setText(qry.value(1).toString());
            ui->type->setText(qry.value(2).toString());
            ui->cin_2->setText(qry.value(3).toString());
            ui->etat->setText(qry.value(4).toString());
            ui->date_2->setText(qry.value(5).toString());

        }
    }
}
void MainWindow::on_supprimer_demande_clicked()
{
    int ref = ui->ref->text().toInt();
    bool test=tmpdemande.supprimer_demande(ref);
    if (test)
    {ui->tabdemande->setModel(tmpdemande.afficher_demande());//refresh
        QMessageBox::critical(nullptr, QObject::tr("database is open"),
                              QObject::tr("demande supprimer.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
}
}

void MainWindow::on_modifier_demande_clicked()
{
    int cin,ref,quantite,etat;
    QString type,date;
    cin=ui->cin->text().toInt();
    type=ui->type->text();
    ref=ui->ref->text().toInt();
    etat=ui->etat->text().toInt();
    quantite=ui->quantite->text().toInt();
    date=ui->date_2->text();
    QSqlQuery qry;
    qry.prepare("update demande set QUANTITE_DEMANDE=:Quantite,TYPE_DEMANDE=:Type,ETAT=:Etat,DATEDEBUT=:Date where REF_DEMANDE=:ref ");
    qry.bindValue(":cin",cin);
     qry.bindValue(":ref",ref);
    qry.bindValue(":Quantite",quantite);
    qry.bindValue(":Type",type);
    qry.bindValue(":Etat",etat);
    qry.bindValue(":Date",date);
            QMessageBox::critical(nullptr, QObject::tr("database is open"),
                                  QObject::tr("demande modifier.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);
    qry.exec();
    ui->tabdemande->setModel(tmpdemande.afficher_demande());//refresh
}

void MainWindow::on_pushButton_38_clicked()
{
    QString strStream;
            QTextStream out(&strStream);
            const int rowCount = ui->tabdemande->model()->rowCount();
            const int columnCount = ui->tabdemande->model()->columnCount();
            for (int column = 0; column < columnCount; column++)
                if (!ui->tabdemande->isColumnHidden(column))
                    out << QString("<th>%1</th>").arg(ui->tabdemande->model()->headerData(column, Qt::Horizontal).toString());
            for (int row = 0; row < rowCount; row++) {
                out << "<tr>";
                for (int column = 0; column < columnCount; column++) {
                    if (!ui->tabdemande->isColumnHidden(column)) {
                        QString data =ui->tabdemande->model()->data(ui->tabdemande
                                                                    ->model()->index(row, column)).toString().simplified();
                        out << QString("<td bkcolor=0>%1</td>").arg((!data.isEmpty()) ? data : QString("&nbsp;"));
                    }
                }
            }
            QTextDocument *document = new QTextDocument();
            document->setHtml(strStream);
    QPrinter printer ;
           QPrintDialog *daddy = new QPrintDialog(&printer, NULL);
            if (daddy->exec() == QDialog::Accepted) {
                document->print(&printer);
            }
            delete document;
}

void MainWindow::on_pushButton_35_clicked()
{
    QString strStream;
            QTextStream out(&strStream);
            const int rowCount = ui->tabdemande->model()->rowCount();
            const int columnCount = ui->tabdemande->model()->columnCount();
            for (int column = 0; column < columnCount; column++)
                if (!ui->tabdemande->isColumnHidden(column))
                   out << QString("<th>%1</th>").arg(ui->tabdemande->model()->headerData(column, Qt::Horizontal).toString());
            for (int row = 0; row < rowCount; row++) {
                for (int column = 0; column < columnCount; column++) {
                    if (!ui->tabdemande->isColumnHidden(column)) {
                        QString data =ui->tabdemande->model()->data(ui->tabdemande->model()->index(row, column)).toString().simplified();
                        out << QString("<td bkcolor=0>%1</td>").arg((!data.isEmpty()) ? data : QString("&nbsp;"));
                    }
                }
            }
           QTextDocument *document = new QTextDocument();
           document->setHtml(strStream);
           QString fileName = QFileDialog::getSaveFileName((QWidget* )0, "Export PDF", QString(), ".pdf");
           if (QFileInfo(fileName).suffix().isEmpty()) { fileName.append(".txt.pdf"); }
           QPrinter printer(QPrinter::PrinterResolution);
           printer.setOutputFormat(QPrinter::PdfFormat);
           printer.setPaperSize(QPrinter::A4);
           printer.setOutputFileName(fileName);
           QTextDocument doc;
           doc.setHtml(document->toPlainText());
            doc.print(&printer);
}

void MainWindow::on_recherche_demande_clicked()
{
    QSqlQueryModel *modal=new QSqlQueryModel();
            QSqlQuery request;
           QString type=ui->comboBox_212->currentText();
           QString val=ui->lineEdit_recherche->text();
           val="%"+val+"%";
           if (type=="TYPE"){
               request.prepare("SELECT * FROM demande WHERE TYPE_DEMANDE LIKE:val ");
           }else if (type=="ETAT"){
               request.prepare("SELECT * FROM demande WHERE ETAT LIKE:val");
           }else if (type=="CIN"){
               request.prepare("SELECT * FROM demande WHERE CIN LIKE:val");
           }else if (type=="DATE"){
               request.prepare("SELECT * FROM demande WHERE DATEDEBUT LIKE:val");
           }
           request.bindValue(":val",val);
           request.exec();
           modal->setQuery(request);
           ui->tabdemande->setModel(modal);
}

void MainWindow::on_pushButton_40_clicked()
{
    int cin,ref,quantite,etat;
    QString type,date,log,mdp;
    cin=ui->cin->text().toInt();
    type=ui->type->text();
    ref=ui->ref->text().toInt();
    etat=ui->etat->text().toInt();
    quantite=ui->quantite->text().toInt();
    date=ui->date_2->text();
    log=ui->log->text();
    mdp=ui->mdp->text();
    QSqlQuery qry;
    QSqlQuery update;
    if (log=="admin" && mdp=="admin")
    {
    if (type=="Augmentation de salaire")
      {
        update.prepare("update PERSONNEL set SALAIRE=SALAIRE+:Quantite where CIN=:cin ");
      update.prepare("update DEMANDE set ETAT=1 where REF_DEMANDE=:ref");
      update.bindValue(":cin",cin);
      update.bindValue(":ref",ref);
      update.bindValue(":Quantite",quantite);
      update.bindValue(":Type",type);
     update.bindValue(":Etat",etat);
      update.bindValue(":Date",date);
      update.exec();
      }
    else{
        qry.prepare("update DEMANDE set ETAT=1 where REF_DEMANDE=:ref ");
    qry.bindValue(":cin",cin);
     qry.bindValue(":ref",ref);
    qry.bindValue(":Quantite",quantite);
    qry.bindValue(":Type",type);
    qry.bindValue(":Etat",etat);
    qry.bindValue(":Date",date);
 }
            QMessageBox::critical(nullptr, QObject::tr("database is open"),
                                  QObject::tr("demande accepter.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);
    qry.exec();
    ui->tabdemande->setModel(tmpdemande.afficher_demande());//refresh
    }
    else
      {
          QMessageBox::critical(nullptr, QObject::tr("database is open"),
                      QObject::tr("wrong admin or password.\n"
                                  "Click Cancel to exit."), QMessageBox::Cancel);
  }
}

void MainWindow::on_pushButton_37_clicked()
{
    int cin,ref,quantite,etat;
    QString type,date;
    cin=ui->cin->text().toInt();
    type=ui->type->text();
    ref=ui->ref->text().toInt();
    etat=ui->etat->text().toInt();
    quantite=ui->quantite->text().toInt();
    date=ui->date_2->text();
    QSqlQuery qry;
    qry.prepare("update demande set ETAT=-1 where REF_DEMANDE=:ref  ");
    qry.bindValue(":cin",cin);
     qry.bindValue(":ref",ref);
    qry.bindValue(":Quantite",quantite);
    qry.bindValue(":Type",type);
    qry.bindValue(":Etat",etat);
    qry.bindValue(":Date",date);
            QMessageBox::critical(nullptr, QObject::tr("database is open"),
                                  QObject::tr("demande refuser.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);
    qry.exec();
    ui->tabdemande->setModel(tmpdemande.afficher_demande());//refresh
}

void MainWindow::on_pushButton_39_clicked()
{
    QSqlQueryModel * modal= new QSqlQueryModel();
    QSqlQuery request;
        request.prepare("select * from demande order by ETAT DESC");
        request.exec();
        modal->setQuery(request);
        ui->tabdemande->setModel(modal);

}

void MainWindow::on_pushButton_34_clicked()
{
    QSqlQueryModel * modal= new QSqlQueryModel();
    QSqlQuery request;
        request.prepare("select * from demande order by CIN DESC");
        request.exec();
        modal->setQuery(request);
        ui->tabdemande->setModel(modal);
}







void MainWindow::on_pushButton_12_clicked()
{
    QSqlQueryModel *modal=new QSqlQueryModel();
    QSqlQuery request;
    request.exec("SELECT * FROM HEBERGEMENT");
    modal->setQuery(request);
    ui->tabhebergement->setModel(modal);
}

void MainWindow::on_pushButton_41_clicked()
{
    QString num=ui->Search->text();
    QSqlQuery Drequest;
    Drequest.prepare("DELETE FROM HEBERGEMENT WHERE NUMRES=:num");
    Drequest.bindValue(":num",num);
    Drequest.exec();

}
void MainWindow::on_tabhebergement_activated(const QModelIndex &index)
{
    QString  val=ui->tabhebergement->model()->data(index).toString();
    QSqlQuery qry;
    qry.prepare("SELECT * FROM HEBERGEMENT WHERE NUMRES=:num");
    qry.bindValue(":num",val);
    if (qry.exec())
    {
        while (qry.next()) {
            ui->lineEdit_4->setText(qry.value(0).toString());
            ui->lineEdit_2->setText(qry.value(1).toString());
            ui->lineEdit_3->setText(qry.value(2).toString());
            ui->lineEdit_10->setText(qry.value(3).toString());
            ui->lineEdit_5->setText(qry.value(4).toString());
            ui->lineEdit_6->setText(qry.value(5).toString());
            ui->lineEdit_7->setText(qry.value(6).toString());
            ui->lineEdit_8->setText(qry.value(7).toString());
            ui->lineEdit_9->setText(qry.value(8).toString());

        }
    }
}

void MainWindow::on_Tri1_clicked()
{
    QSqlQueryModel *modal=new QSqlQueryModel();
    QSqlQuery request;
    request.exec("SELECT * FROM HEBERGEMENT order by DATEARR");
    modal->setQuery(request);
    ui->tabhebergement->setModel(modal);
}

void MainWindow::on_pushButton_43_clicked()
{
    QString demi="demi";
    QSqlQueryModel *modal=new QSqlQueryModel();
    QSqlQuery request;
    request.prepare("SELECT * FROM HEBERGEMENT WHERE TYPERES=:demi");
    request.bindValue(":demi",demi);
    request.exec();
    modal->setQuery(request);
    ui->tabhebergement->setModel(modal);
}

void MainWindow::on_update_clicked()
{
    QSqlQuery query;
    QString num=ui->lineEdit_4->text();
    QString NBp=ui->lineEdit_2->text();
    QString DateA=ui->lineEdit_3->text();
    QString DateD=ui->lineEdit_10->text();
    QString TypeR=ui->lineEdit_5->text();
    QString TypeC=ui->lineEdit_6->text();
    QString cin=ui->lineEdit_7->text();
    QString nom=ui->lineEdit_8->text();
    QString prenom=ui->lineEdit_9->text();
    query.prepare("update HEBERGEMENT set NBRPERSONNES=:NB,DATEARR=:DA,DATEDEP=:DD,TYPERES=:TR,TYPECHAMBRE=:TC,CIN=:C,NOM=:nom,PRENOM=:PR  where NUMRES= :Num");
    query.bindValue(":NB",NBp);
    query.bindValue(":DA",DateA);
    query.bindValue(":DD",DateD);
    query.bindValue(":TR",TypeR);
    query.bindValue(":TC",TypeC);
    query.bindValue(":C",cin);
    query.bindValue(":nom",nom);
    query.bindValue(":PR",prenom);
    query.bindValue(":Num",num);
    query.exec();
}

void MainWindow::on_pushButton_15_clicked()
{
    QSqlQueryModel *modal=new QSqlQueryModel();
    QSqlQuery request;
   QString type=ui->comboBox_4->currentText();
   QString val=ui->Linesearch->text();
   val="%"+val+"%";
   if (type=="Numero"){
       request.prepare("SELECT * FROM HEBERGEMENT WHERE NUMRES LIKE:val");
   }else if (type=="nom"){
       request.prepare("SELECT * FROM HEBERGEMENT WHERE NOM LIKE:val");
   }else if (type=="cin"){
       request.prepare("SELECT * FROM HEBERGEMENT WHERE CIN LIKE:val");
   }else if (type=="pention"){
       request.prepare("SELECT * FROM HEBERGEMENT WHERE TYPERES LIKE:val");
   }else if (type=="chambre"){
       request.prepare("SELECT * FROM HEBERGEMENT WHERE TYPECHAMBRE LIKE:val");
   }else if (type=="prenom"){
       request.prepare("SELECT * FROM HEBERGEMENT WHERE PRENOM LIKE:val");
   }
   request.bindValue(":val",val);
   request.exec();
   modal->setQuery(request);
   ui->tabhebergement->setModel(modal);
}

void MainWindow::on_pdf_clicked()
{
    QString strStream;
            QTextStream out(&strStream);

            const int rowCount = ui->tabhebergement->model()->rowCount();
            const int columnCount = ui->tabhebergement->model()->columnCount();
            for (int column = 0; column < columnCount; column++)
                if (!ui->tabhebergement->isColumnHidden(column))
                   out << QString("<th>%1<br></th>").arg(ui->tabhebergement->model()->headerData(column, Qt::Horizontal).toString());

            for (int row = 0; row < rowCount; row++) {
                out << "<tr>";
                for (int column = 0; column < columnCount; column++) {
                    if (!ui->tabhebergement->isColumnHidden(column)) {
                        QString data =ui->tabhebergement->model()->data(ui->tabhebergement->model()->index(row, column)).toString().simplified();
                        out << QString("<td bkcolor=0>%1<br></td>").arg((!data.isEmpty()) ? data : QString("&nbsp;"));
                    }
                }
            }
           QTextDocument *document=new QTextDocument();
           document->setHtml(strStream);

           QString fileName = QFileDialog::getSaveFileName((QWidget*)0, "Export PDF", QString(), ".pdf");
           if (QFileInfo(fileName).suffix().isEmpty()) { fileName.append(".txt.pdf"); }

           QPrinter printer(QPrinter::PrinterResolution);
           printer.setOutputFormat(QPrinter::PdfFormat);
           printer.setPaperSize(QPrinter::A4);
           printer.setOutputFileName(fileName);

           QTextDocument doc;

           doc.setHtml(document->toPlainText());
            doc.print(&printer);
}

void MainWindow::on_pushButton_42_clicked()
{
    QString strStream;
            QTextStream out(&strStream);

            const int rowCount = ui->tabhebergement->model()->rowCount();
            const int columnCount = ui->tabhebergement->model()->columnCount();
            for (int column = 0; column < columnCount; column++)
                if (!ui->tabhebergement->isColumnHidden(column))
                    out << QString("<th>%1</th>").arg(ui->tabhebergement->model()->headerData(column, Qt::Horizontal).toString());
            for (int row = 0; row < rowCount; row++) {
                out << "<tr>";
                for (int column = 0; column < columnCount; column++) {
                    if (!ui->tabhebergement->isColumnHidden(column)) {
                        QString data =ui->tabhebergement->model()->data(ui->tabhebergement->model()->index(row, column)).toString().simplified();
                        out << QString("<td bkcolor=0>%1</td>").arg((!data.isEmpty()) ? data : QString("&nbsp;"));
                    }
                }
            }
            QTextDocument *document = new QTextDocument();
            document->setHtml(strStream);

    QPrinter printer ;
           QPrintDialog *daddy = new QPrintDialog(&printer, NULL);
            if (daddy->exec() == QDialog::Accepted) {
                document->print(&printer);

            }

            delete document;
}

void MainWindow::on_pushButton_45_clicked()
{
    QSqlQueryModel *modal=new QSqlQueryModel();
    QSqlQuery request;
    request.exec("SELECT * FROM CHAMBRE");
    modal->setQuery(request);
    ui->tablefiras->setModel(modal);
    //qDebug() <<(modal->rowCount());
}

void MainWindow::on_delete_2_clicked()
{
    QString num=ui->search->text();
    QSqlQuery Drequest;
    Drequest.prepare("DELETE FROM CHAMBRE WHERE NUM_CHAMBRE=:num");
    Drequest.bindValue(":num",num);
    Drequest.exec();
}

void MainWindow::on_tablefiras_activated(const QModelIndex &index)
{
    QString  val=ui->tablefiras->model()->data(index).toString();
    QSqlQuery qry;
    qry.prepare("SELECT * FROM CHAMBRE WHERE NUM_CHAMBRE=:num");
    qry.bindValue(":num",val);
    if (qry.exec())
    {
        while (qry.next()) {
            ui->lineEdit_11->setText(qry.value(0).toString());
            ui->lineEdit_14->setText(qry.value(1).toString());
            ui->lineEdit_13->setText(qry.value(2).toString());
            ui->lineEdit_12->setText(qry.value(3).toString());
        }

    }
}

void MainWindow::on_update_2_clicked()
{
    QSqlQuery query;
    QString num=ui->lineEdit_11->text();
    QString type=ui->lineEdit_14->text();
    QString etat=ui->lineEdit_13->text();
    QString capacite=ui->lineEdit_12->text();
    query.prepare("update CHAMBRE set TYPE_CHAMBRE=:TC,ETAT_CHAMBRE=:EC,CAPACITE=:C  where NUM_CHAMBRE= :Num");
    query.bindValue(":TC",type);
    query.bindValue(":EC",etat);
    query.bindValue(":C",capacite);
    query.bindValue(":Num",num);
    query.exec();
}

void MainWindow::on_tri_clicked()
{
    QSqlQueryModel *modal=new QSqlQueryModel();
    QSqlQuery request;
    request.exec("SELECT * FROM CHAMBRE order by CAPACITE");
    modal->setQuery(request);
    ui->tablefiras->setModel(modal);
}

void MainWindow::on_Csearch_clicked()
{
    QSqlQueryModel *modal=new QSqlQueryModel();
    QSqlQuery request;
   QString type=ui->comboBox_5->currentText();
   QString val=ui->combo->text();
   val="%"+val+"%";
   if (type=="Numero"){
       request.prepare("SELECT * FROM CHAMBRE WHERE NUM_CHAMBRE LIKE:val");
   }else if (type=="etat"){
       request.prepare("SELECT * FROM CHAMBRE WHERE ETAT_CHAMBRE LIKE:val");
   }else if (type=="type"){
       request.prepare("SELECT * FROM CHAMBRE WHERE TYPE_CHAMBRE LIKE:val");
   }
   request.bindValue(":val",val);
   request.exec();
   modal->setQuery(request);
   ui->tablefiras->setModel(modal);
}

void MainWindow::on_print_clicked()
{
    QString strStream;
            QTextStream out(&strStream);

            const int rowCount = ui->tablefiras->model()->rowCount();
            const int columnCount = ui->tablefiras->model()->columnCount();
            for (int column = 0; column < columnCount; column++)
                if (!ui->tablefiras->isColumnHidden(column))
                    out << QString("<th>%1</th>").arg(ui->tablefiras->model()->headerData(column, Qt::Horizontal).toString());
            for (int row = 0; row < rowCount; row++) {
                out << "<tr>";
                for (int column = 0; column < columnCount; column++) {
                    if (!ui->tablefiras->isColumnHidden(column)) {
                        QString data =ui->tablefiras->model()->data(ui->tablefiras->model()->index(row, column)).toString().simplified();
                        out << QString("<td bkcolor=0>%1</td>").arg((!data.isEmpty()) ? data : QString("&nbsp;"));
                    }
                }
            }
            QTextDocument *document = new QTextDocument();
            document->setHtml(strStream);

    QPrinter printer ;
           QPrintDialog *daddy = new QPrintDialog(&printer, NULL);
            if (daddy->exec() == QDialog::Accepted) {
                document->print(&printer);

            }

            delete document;
}

void MainWindow::on_pdf_2_clicked()
{
    QString strStream;
            QTextStream out(&strStream);

            const int rowCount = ui->tablefiras->model()->rowCount();
            const int columnCount = ui->tablefiras->model()->columnCount();
            for (int column = 0; column < columnCount; column++)
                if (!ui->tablefiras->isColumnHidden(column))
                   out << QString("<th>%1<br></th>").arg(ui->tablefiras->model()->headerData(column, Qt::Horizontal).toString());

            for (int row = 0; row < rowCount; row++) {
                out << "<tr>";
                for (int column = 0; column < columnCount; column++) {
                    if (!ui->tablefiras->isColumnHidden(column)) {
                        QString data =ui->tablefiras->model()->data(ui->tablefiras->model()->index(row, column)).toString().simplified();
                        out << QString("<td bkcolor=0>%1<br></td>").arg((!data.isEmpty()) ? data : QString("&nbsp;"));
                    }
                }
            }
           QTextDocument *document=new QTextDocument();
           document->setHtml(strStream);

           QString fileName = QFileDialog::getSaveFileName((QWidget*)0, "Export PDF", QString(), ".pdf");
           if (QFileInfo(fileName).suffix().isEmpty()) { fileName.append(".txt.pdf"); }

           QPrinter printer(QPrinter::PrinterResolution);
           printer.setOutputFormat(QPrinter::PdfFormat);
           printer.setPaperSize(QPrinter::A4);
           printer.setOutputFileName(fileName);

           QTextDocument doc;

           doc.setHtml(document->toPlainText());
            doc.print(&printer);
}

void MainWindow::on_video_clicked()
{
    video=new MainWindowvideo(this);
    video->show();
}

void MainWindow::on_pushButton_44_clicked()
{
    statCH=new StatChambre(this);
    statCH->show();
}
void MainWindow::on_tableView_2_activated(const QModelIndex &index)
{
    QString  val=ui->tableView_2->model()->data(index).toString();
        QSqlQuery qry;
        qry.prepare("SELECT * FROM MATERIEL WHERE REF_MAT=:num");
        qry.bindValue(":num",val);
        if (qry.exec())
        {
            while (qry.next()) {
                ui->Ref_3->setText(qry.value(0).toString());
                ui->QNT_3->setText(qry.value(1).toString());
                ui->etatM_3->setText(qry.value(2).toString());
                }

        }
}

void MainWindow::on_pushButton_47_clicked()
{
     ui->tableView_2->setModel(tmpM.afficher());
}

void MainWindow::on_pushButton_46_clicked()
{
    QString ref=ui->Ref_3->text();
    int nbr = ui->QNT_3->text().toInt();
    QString etat = ui->etatM_3->text();
    int eve =ui->Ref_Eve->currentText().toInt();
    materiaux M(nbr,etat,eve);
    bool test=M.modif(ref,nbr);
    bool test2=M.modifEtat(ref,etat);
    if (test || test2)
    {
                QMessageBox::information(nullptr, QObject::tr("database is open"),
                            QObject::tr("materiel modifier.\n"
                                        "Click Cancel to exit."), QMessageBox::Cancel);
    }
}

void MainWindow::on_pushButton_49_clicked()
{
    int id = ui->idMS->text().toInt();
    bool test = tmpM.supp(id);
    if (test)
    {
        QMessageBox::information(nullptr, QObject::tr("database is open"),
                    QObject::tr("materiaux supprimer.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }
}

void MainWindow::on_pushButton_48_clicked()
{
    QString strStream;
        QTextStream out(&strStream);

        const int rowCount = ui->tableView_2->model()->rowCount();
        const int columnCount = ui->tableView_2->model()->columnCount();
        for (int column = 0; column < columnCount; column++)
            if (!ui->tableView_2->isColumnHidden(column))
                out << QString("<th>%1</th>").arg(ui->tableView_2->model()->headerData(column, Qt::Horizontal).toString());
        for (int row = 0; row < rowCount; row++) {
            out << "<tr>";
            for (int column = 0; column < columnCount; column++) {
                if (!ui->tableView_2->isColumnHidden(column)) {
                    QString data =ui->tableView_2->model()->data(ui->tableView_2->model()->index(row, column)).toString().simplified();
                    out << QString("<td bkcolor=0>%1</td>").arg((!data.isEmpty()) ? data : QString("&nbsp;"));
                }
            }
        }
        QTextDocument *document = new QTextDocument();
        document->setHtml(strStream);

       QPrinter printer ;
       QPrintDialog *daddy = new QPrintDialog(&printer, NULL);
        if (daddy->exec() == QDialog::Accepted) {
            document->print(&printer);
        }

        delete document;


}

void MainWindow::on_pushButton_51_clicked()
{
    QString strStream;
        QTextStream out(&strStream);

        const int rowCount = ui->tableView_2->model()->rowCount();
        const int columnCount = ui->tableView_2->model()->columnCount();
        for (int column = 0; column < columnCount; column++)
            if (!ui->tableView_2->isColumnHidden(column))
               out << QString("<th>%1</th>").arg(ui->tableView_2->model()->headerData(column, Qt::Horizontal).toString());

        for (int row = 0; row < rowCount; row++) {
            for (int column = 0; column < columnCount; column++) {
                if (!ui->tableView_2->isColumnHidden(column)) {
                    QString data =ui->tableView_2->model()->data(ui->tableView_2->model()->index(row, column)).toString().simplified();
                    out << QString("<td bkcolor=0>%1</td>").arg((!data.isEmpty()) ? data : QString("&nbsp;"));
                }
            }
        }
       QTextDocument *document = new QTextDocument();
       document->setHtml(strStream);

       QString fileName = QFileDialog::getSaveFileName((QWidget* )0, "Export PDF", QString(), ".pdf");
       if (QFileInfo(fileName).suffix().isEmpty()) { fileName.append(".txt.pdf"); }

       QPrinter printer(QPrinter::PrinterResolution);
       printer.setOutputFormat(QPrinter::PdfFormat);
       printer.setPaperSize(QPrinter::A4);
       printer.setOutputFileName(fileName);

       QTextDocument doc;

       doc.setHtml(document->toPlainText());
        doc.print(&printer);
}

void MainWindow::on_pushButton_50_clicked()
{
    QSqlQueryModel *modal=new QSqlQueryModel();
        QSqlQuery request;
       QString type=ui->comboBox_6->currentText();
       QString val=ui->rechercheM->text();
       val="%"+val+"%";
       if (type=="reference"){
           request.prepare("SELECT * FROM MATERIEL WHERE REF_MAT LIKE:val order by REF_MAT");
       }else if (type=="nbr"){
           request.prepare("SELECT * FROM MATERIEL WHERE NBR_MAT LIKE:val order by NBR_MAT");
       }else if (type=="etat"){
           request.prepare("SELECT * FROM MATERIEL WHERE ETAT_MAT LIKE:val order by ETAT_MAT");
       }

       request.bindValue(":val",val);
       request.exec();
       modal->setQuery(request);
       ui->tableView_2->setModel(modal);
}

void MainWindow::on_pushButton_56_clicked()
{
    ui->tableView_3->setModel(tmpE.afficherE());
}

void MainWindow::on_pushButton_55_clicked()
{
    int id = ui->idES_2->text().toInt();
    bool test = tmpE.suppE(id);
    if (test)
    {
        QMessageBox::information(nullptr, QObject::tr("database is open"),
                    QObject::tr("evenement supprimer.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }
}

void MainWindow::on_pushButton_54_clicked()
{
    QString strStream;
        QTextStream out(&strStream);

        const int rowCount = ui->tableView_3->model()->rowCount();
        const int columnCount = ui->tableView_3->model()->columnCount();
        for (int column = 0; column < columnCount; column++)
            if (!ui->tableView_3->isColumnHidden(column))
               out << QString("<th>%1</th>").arg(ui->tableView_3->model()->headerData(column, Qt::Horizontal).toString());

        for (int row = 0; row < rowCount; row++) {
           // out << "<tr>";
            for (int column = 0; column < columnCount; column++) {
                if (!ui->tableView_3->isColumnHidden(column)) {
                    QString data =ui->tableView_3->model()->data(ui->tableView_3->model()->index(row, column)).toString().simplified();
                    out << QString("<td bkcolor=0>%1</td>").arg((!data.isEmpty()) ? data : QString("&nbsp;"));
                }
            }
        }
       QTextDocument *document = new QTextDocument();
       document->setHtml(strStream);

       QString fileName = QFileDialog::getSaveFileName((QWidget* )0, "Export PDF", QString(), ".pdf");
       if (QFileInfo(fileName).suffix().isEmpty()) { fileName.append(".txt.pdf"); }

       QPrinter printer(QPrinter::PrinterResolution);
       printer.setOutputFormat(QPrinter::PdfFormat);
       printer.setPaperSize(QPrinter::A4);
       printer.setOutputFileName(fileName);

       QTextDocument doc;

       doc.setHtml(document->toPlainText());
        doc.print(&printer);
}

void MainWindow::on_pushButton_53_clicked()
{
    QString strStream;
        QTextStream out(&strStream);

        const int rowCount = ui->tableView_3->model()->rowCount();
        const int columnCount = ui->tableView_3->model()->columnCount();
        for (int column = 0; column < columnCount; column++)
            if (!ui->tableView_3->isColumnHidden(column))
                out << QString("<th>%1</th>").arg(ui->tableView_3->model()->headerData(column, Qt::Horizontal).toString());
        for (int row = 0; row < rowCount; row++) {
            out << "<tr>";
            for (int column = 0; column < columnCount; column++) {
                if (!ui->tableView_3->isColumnHidden(column)) {
                    QString data =ui->tableView_3->model()->data(ui->tableView_3->model()->index(row, column)).toString().simplified();
                    out << QString("<td bkcolor=0>%1</td>").arg((!data.isEmpty()) ? data : QString("&nbsp;"));
                }
            }
        }
        QTextDocument *document = new QTextDocument();
        document->setHtml(strStream);

QPrinter printer ;
       QPrintDialog *daddy = new QPrintDialog(&printer, NULL);
        if (daddy->exec() == QDialog::Accepted) {
            document->print(&printer);

        }

        delete document;


}



void MainWindow::on_pushButton_52_clicked()
{
    QSqlQueryModel *modal=new QSqlQueryModel();
        QSqlQuery request;
       QString type=ui->comboBox_7->currentText();
       QString val=ui->rechercheM_3->text();
       val="%"+val+"%";
       if (type=="id"){
           request.prepare("SELECT * FROM EVENEMENT WHERE IDEVE LIKE:val order by IDEVE");
       }else if (type=="type"){
           request.prepare("SELECT * FROM EVENEMENT WHERE TYPEEVE LIKE:val order by TYPEEVE");
       }else if (type=="date"){
           request.prepare("SELECT * FROM EVENEMENT WHERE DATEEVE LIKE:val order by DATEEVE");
       }else if (type=="nbr"){
           request.prepare("SELECT * FROM EVENEMENT WHERE NBEVE LIKE:val order by NBEVE");
       }

       request.bindValue(":val",val);
       request.exec();
       modal->setQuery(request);
       ui->tableView_3->setModel(modal);
}

void MainWindow::on_pushButton_58_clicked()
{
    int id = ui->idEVE_3->text().toInt();
    QString type = ui->TypeEVE_3->text();
    QString date =ui->calendarWidget_8->selectedDate().toString();
    int nbrE = ui->NBpEVE_3->text().toInt();
    evenement E(type,date,nbrE);
       bool test = E.modifE(id,type,date,nbrE);
    if (test)
    {
                QMessageBox::information(nullptr, QObject::tr("database is open"),
                            QObject::tr("evenement modifiée.\n"
                                        "Click Cancel to exit."), QMessageBox::Cancel);
    }
}

void MainWindow::on_tableView_3_activated(const QModelIndex &index)
{
    QString  val=ui->tableView_3->model()->data(index).toString();
        QSqlQuery qry;
        qry.prepare("SELECT * FROM EVENEMENT WHERE IDEVE=:num");
        qry.bindValue(":num",val);
        if (qry.exec())
        {
            while (qry.next()) {
                ui->idEVE_3->setText(qry.value(0).toString());
                ui->TypeEVE_3->setText(qry.value(1).toString());
                ui->NBpEVE_3->setText(qry.value(3).toString());
                }

        }
}
void MainWindow::on_pushButton_57_clicked()
{
    secPa =new statevenement(this);
        secPa->show();
}

void MainWindow::on_pb_ajouter_clicked()
{
    historique h;
      QString textajouter;


    int id = ui->lineEdit_idanim->text().toInt();
    QString typeanim= ui->lineEdit_typeanim->text();
    QString lieu= ui->lineEdit_lieu->text();
    QString dateanim= ui->lineEdit_dateanim->text();
    int duree= ui->lineEdit_duree->text().toInt();
    int cin= ui->lineEdit_cin->text().toInt();






    int x=0;




            if (typeanim=="" )
            {
                qDebug () <<"problem d ajout dans le base ";
                      QMessageBox::critical(this,"Enregister","verifier le type");
                      x++;

            }

            if (lieu=="" )
            {
                qDebug () <<"problem d ajout dans le base ";
                      QMessageBox::critical(this,"Enregister","verifier le lieu");
                      x++;

            }

            if (duree < 0 )
            {
                qDebug () <<"problem d ajout dans le base ";
                      QMessageBox::critical(this,"Enregister","verifier la duree");
                      x++;

            }


            if (cin<10000000 || cin>99999999 )
            {
                qDebug () <<"problem d ajout dans le base ";
                      QMessageBox::critical(this,"Enregister","verifier la cin");
                      x++;


}

if(x==0)

{
  Animation e(id,typeanim,lieu,dateanim,duree,cin);
  bool test=e.ajouter();
  if(test)
{  ui->tabanim->setModel(tmpanim.afficher());//refresh
      //ui->tabanime->setModel(tmpanime.afficherasc());//refresh

       //ui->tabanime->setModel(tmpanime.afficherdesc());//refresh
QMessageBox::information(nullptr, QObject::tr("Ajouter une animation"),
                  QObject::tr("Animation ajouté.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);
}
  else
      QMessageBox::critical(nullptr, QObject::tr("Ajouter une animation"),

                            QObject::tr("Erreur !.\n"

                              "Click Cancel to exit."), QMessageBox::Cancel);






  textajouter="L'ajout dans la base de donnees animation de LIEU:"+lieu+"  a ete effectuee avec succees";
  h.write(textajouter);

  trayIcon->showMessage("Ajouter Animation", "Nouvelle Animation de LIEU:"+lieu+"    Ajoutée avec sucees dans la base de donnée",
                        QSystemTrayIcon::Information, 3000);


}
}

void MainWindow::on_resaisir_clicked()
{
    //reset champ
    ui->lineEdit_idanim->clear();
    ui->lineEdit_typeanim->clear();
    ui->lineEdit_lieu->clear();
    ui->lineEdit_dateanim->clear();
    ui->lineEdit_duree->clear();
    ui->lineEdit_cin->clear();

}

void MainWindow::on_pb_supprimer_5_clicked()
{
    historique h;

    int verif=0;



    int idanim = ui->x2_2->currentText().toInt();
    qDebug()<< idanim ;
    qDebug()<< idanim ;
    verif= QMessageBox::question( this, "Confimation De la Suppression", "Vouler vous Supprimer l'dentifiant"+QString::number(idanim)+"", QMessageBox::No | QMessageBox::Yes  );


    qDebug()<< verif ;



    if(verif==16384)
    {

bool test=tmpanim.supprimer(idanim);
if(test)
{ui->tabanim->setModel(tmpanim.afficher());//refresh
    QMessageBox::information(nullptr, QObject::tr("Supprimer une animation"),
                QObject::tr("Animation supprimé.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);

}
else
    QMessageBox::critical(nullptr, QObject::tr("Supprimer une animation"),
                QObject::tr("Erreur !.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);



    }

 else if(verif==65536)
    {

        QMessageBox::information(nullptr, QObject::tr("Suppression est annulée"),
                    QObject::tr("Suppression est annulée.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);


}
    QString textajouter;
       QModelIndex  modele =ui->tabanim->currentIndex().sibling(ui->tabanim->currentIndex().row(),0);
       QString value=modele.data().toString();
         qDebug () << value;
       textajouter="L'suppresion dans la base de donnees animation ID:"+QString::number(idanim)+" a ete effectuee avec succees";
       h.write(textajouter);

       trayIcon->showMessage("Suprimer Animation", "Nouvelle Animation ID:"+QString::number(idanim)+" a ete suprimé avec sucees dans la base de donnée",
                             QSystemTrayIcon::Information, 3000);
}

void MainWindow::on_Actualiser_3_clicked()
{
    ui->tabanim->setModel(tmpanim.afficher());
    QSqlQueryModel *model= new QSqlQueryModel();
    model->setQuery(("select idanim from animation"));

    ui->x2_2->setModel(model);
}

void MainWindow::on_imprimer_paie_clicked()
{
    QString strStream;
            QTextStream out(&strStream);

            const int rowCount = ui->tabanim->model()->rowCount();
            const int columnCount = ui->tabanim->model()->columnCount();
            QString TT = QDate::currentDate().toString("yyyy/MM/dd");
            out <<"<html>\n"
                  "<head>\n"
                   "<meta Content=\"Text/html; charset=Windows-1251\">\n"
                << "<title>ERP - COMmANDE LIST<title>\n "
                << "</head>\n"
                "<body bgcolor=#ffffff link=#5000A0>\n"
                "<h1 style=\"text-align: center;\"><strong> *****LISTE DES Factures ***** "+TT+"</strong></h1>"
                "<table style=\"text-align: center; font-size: 20px;\" border=1>\n "
                  "</br> </br>";
            // headers
            out << "<thead><tr bgcolor=#d6e5ff>";
            for (int column = 0; column < columnCount; column++)
                if (!ui->tabanim->isColumnHidden(column))
                    out << QString("<th>%1</th>").arg(ui->tabanim->model()->headerData(column, Qt::Horizontal).toString());
            out << "</tr></thead>\n";

            // data table
            for (int row = 0; row < rowCount; row++) {
                out << "<tr>";
                for (int column = 0; column < columnCount; column++) {
                    if (!ui->tabanim->isColumnHidden(column)) {
                        QString data =ui->tabanim->model()->data(ui->tabanim->model()->index(row, column)).toString().simplified();
                        out << QString("<td bkcolor=0>%1</td>").arg((!data.isEmpty()) ? data : QString("&nbsp;"));
                    }
                }
                out << "</tr>\n";
            }
            out <<  "</table>\n"
                "</body>\n"
                "</html>\n";

            QTextDocument *document = new QTextDocument();
            document->setHtml(strStream);

            QPrinter printer;

            QPrintDialog *baba = new QPrintDialog(&printer, NULL);
            if (baba->exec() == QDialog::Accepted) {
                document->print(&printer);
            }

            delete document;
}



void MainWindow::on_expot_clicked()
{
    QPixmap pix(ui->tabanim->size());
          QPainter painter(&pix);
         ui->tabanim->render(&painter);
          painter.end();
          QPrinter printer(QPrinter::HighResolution);
          printer.setOrientation(QPrinter::Landscape);
          printer.setOutputFormat(QPrinter::PdfFormat);
          printer.setPaperSize(QPrinter::A4);
          printer.setOutputFileName("F:/projet Qt xteam integration/projetv0/Animation.pdf"); // will be in build folder

          painter.begin(&printer);
          double xscale = printer.pageRect().width() / double(pix.width());
          double yscale = printer.pageRect().height() / double(pix.height());
          double scale = qMin(xscale, yscale);
          painter.translate(printer.paperRect().x() + printer.pageRect().width() / 2,
                            printer.paperRect().y() + printer.pageRect().height() / 2);
          painter.scale(scale, scale);
          painter.translate(-ui->tabanim->width() / 2, -ui->tabanim->height() / 2);
          painter.drawPixmap(0, 0, pix);

        QTextDocument doc;

        doc.setHtml("htmlcontent");
        doc.drawContents(&painter);

          painter.end();
}

void MainWindow::on_pdf_3_clicked()
{
    go = new pdf(this);
    go->show();
}

void MainWindow::on_pb_modifier_clicked()
{
    historique h;
    QString textajouter;
    int id = ui->lineEdit_idanim_3->text().toInt();
    QString typeanim= ui->lineEdit_typeanim_2->text();
    QString lieu= ui->lineEdit_lieu_2->text();
     QString dateanim= ui->lineEdit_dateanim_2->text();
      int duree= ui->lineEdit_duree_2->text().toInt();
      int cin= ui->lineEdit_cin_2->text().toInt();

    Animation anim(id,typeanim,lieu,dateanim,duree,cin);
  bool test=anim.modifier(id);
  if(test)
{ui->tabanim->setModel(tmpanim.afficher());
     ui->tabanime->setModel(tmpanime.afficherasc());
     ui->tabanime->setModel(tmpanime.afficherdesc());

QMessageBox::information(nullptr, QObject::tr("Modifier une animation"),
                  QObject::tr("Animation modifié.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}
  else
      QMessageBox::critical(nullptr, QObject::tr("Modifier une animation"),
                  QObject::tr("Erreur !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);


  //QModelIndex  modele =ui->tabanime->currentIndex().sibling(ui->tabanime->currentIndex().row(),0);
    //QString value=modele.data().toString();
      //qDebug () << value;
  textajouter="La modification dans la base de donnees animation de LIEU:"+typeanim+" a ete effectuee avec succees";
    h.write(textajouter);

    trayIcon->showMessage("Modifier Animation", "Nouvelle Animation de LIEU:"+typeanim+" a été modifié avec sucees dans la base de donnée",
                          QSystemTrayIcon::Information, 3000);

}

void MainWindow::on_trie_asc_clicked()
{
    ui->tabanime->setModel(tmpanime.afficherasc());
}





void MainWindow::on_Rechercher_2_clicked()
{
    QString id=ui->lineEdit_id_3->text();
    ui->tab_ab_rech_2->setModel(tmpanime.recherche(id));
}

void MainWindow::on_trie_desc_clicked()
{
     ui->tabanime->setModel(tmpanime.afficherdesc());
}

void MainWindow::on_tabanime_activated(const QModelIndex &index)
{
    QString val=ui->tabanime->model()->data(index).toString();
    QSqlQuery q;
    q.prepare("select * from animation where idanim='"+val+"'");
  if(q.exec())
      while (q.next()) {
            ui->lineEdit_idanim_3->setText(q.value(0).toString());
                  ui->lineEdit_typeanim_2->setText(q.value(1).toString());
                  ui->lineEdit_lieu_2->setText(q.value(2).toString());
                  ui->lineEdit_dateanim_2->setText(q.value(3).toString());

                     ui->lineEdit_duree_2->setText(q.value(4).toString());
                        ui->lineEdit_cin_2->setText(q.value(5).toString());
                        }

}

void MainWindow::on_pb_ajout_clicked()
{
    historique h;
    QString textajouter;


        int id = ui->lineEdit_id->text().toInt();
        QString type= ui->lineEdit_type->text();
        int nb= ui->lineEdit_nb->text().toInt();
        //int idanimation= ui->lineEdit_idanimation->text().toInt();

       // int idanimation= ui->lineEdit_idanimation->text().toInt();
        int idanimation = ui->x3->currentText().toInt();
    int x=0;




            if (type=="" )
            {
                qDebug () <<"problem d ajout dans le base ";
                      QMessageBox::critical(this,"Enregister","verifier le type");
                      x++;

            }

            if (nb < 0 )
            {
                qDebug () <<"problem d ajout dans le base ";
                      QMessageBox::critical(this,"Enregister","verifier le nombre");
                      x++;

            }


            if (idanimation==0 )
            {
                qDebug () <<"problem d ajout dans le base ";
                      QMessageBox::critical(this,"Enregister","verifier l identifiant de l animation");
                      x++;

            }





    if(x==0)
    {

        Equipement e(id,type,nb,idanimation);
      bool test=e.ajout();
      if(test)
    {

         ui->tabequip->setModel(tmpequip.afficher_2());//refresh
         //  ui->tabanime->setModel(tmpanime.afficherasc());//refresh

           //ui->tabanime->setModel(tmpanime.afficherdesc());//refresh
        // MainWindow::makePlot();
    QMessageBox::information(nullptr, QObject::tr("Ajouter un equipement"),
                      QObject::tr("Equipement ajouté.\n"
                                  "Click Cancel to exit."), QMessageBox::Cancel);

    }
      else
          QMessageBox::critical(nullptr, QObject::tr("Ajouter un equipement"),
                      QObject::tr("Erreur !.\n"
                                  "Click Cancel to exit."), QMessageBox::Cancel);

        }

    textajouter="L'ajout dans la base de donnees equipement :"+type+"  a ete effectuee avec succees";
    h.write(textajouter);

    trayIcon->showMessage("Ajouter Equipement", "Nouveau Equipement :"+type+"  a été ajouté avec sucees dans la base de donnée",
                          QSystemTrayIcon::Information, 3000);


}

void MainWindow::on_actualiser_3_clicked()
{
    ui->tabanim->setModel(tmpanim.afficher());
    QSqlQueryModel *model= new QSqlQueryModel();
    model->setQuery(("select idanim from animation"));

    ui->x3->setModel(model);
}

void MainWindow::on_pb_supprimer_3_clicked()
{
    historique h;

    int verif=0;



    int id = ui->x2->currentText().toInt();
    qDebug()<< id ;
    qDebug()<< id ;
    verif= QMessageBox::question( this, "Confimation De la Suppression", "Vouler vous Supprimer l'dentifiant"+QString::number(id)+"", QMessageBox::No | QMessageBox::Yes  );
    qDebug()<< verif ;


    if(verif==16384)
    {



    bool test=tmpequip.supprimer_2(id);
    if(test)
    {ui->tabequip->setModel(tmpequip.afficher_2());//refresh
      //  MainWindow::makePlot();
        QMessageBox::information(nullptr, QObject::tr("Supprimer un equipement"),
                    QObject::tr("Equipement supprimé.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Supprimer un equipement"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);


    }
    else if(verif==65536)
       {

           QMessageBox::information(nullptr, QObject::tr("Suppression est annulée"),
                       QObject::tr("Suppression est annulée.\n"
                                   "Click Cancel to exit."), QMessageBox::Cancel);


    }
       QString textajouter;
       QModelIndex  modele =ui->tabanim->currentIndex().sibling(ui->tabanim->currentIndex().row(),0);
       QString value=modele.data().toString();
         qDebug () << value;
         textajouter="L'suppresion dans la base de donnees equipement ID:"+QString::number(id)+" a ete effectuee avec succees";
            h.write(textajouter);

            trayIcon->showMessage("Suprimer Equipement", "Nouveau Equipement ID:"+QString::number(id)+" a été suprimé avec sucees dans la base de donnée",
                                  QSystemTrayIcon::Information, 3000);
}

void MainWindow::on_Actualiser_2_clicked()
{
    ui->tabequip->setModel(tmpequip.afficher_2());
    QSqlQueryModel *model= new QSqlQueryModel();
    model->setQuery(("select id from equipement"));

    ui->x2->setModel(model);
}

void MainWindow::on_pdf_4_clicked()
{
    go = new pdf(this);
    go->show();
}

void MainWindow::on_exporter_clicked()
{
    QPrinter printer;
    printer.setOutputFormat(QPrinter::PdfFormat);
    printer.setOutputFileName("F:/projet Qt xteam integration/projetv0/Exporter.pdf");
    QPainter painter;
    painter.begin(&printer);

    QFont font;
    QSqlQuery query;
    QString id,type,nb,idanimation;


        int i=0,ligne1=250,ligne2=300,ligne3=350,ligne4=400,ligne5=420;
        query.prepare("select * from EQUIPEMENT");
        if (query.exec())
        {
            while (query.next())
            {
                id=query.value(0).toString();
                type=query.value(1).toString();
                nb=query.value(2).toString();
                idanimation=query.value(3).toString();
                i++;
                if(i>=2)
                {
                ligne1+=200;
                ligne2+=200;
                ligne3+=200;
                ligne4+=200;
                ligne5+=200;
                }
                qDebug()<< i ;

            font.setPixelSize(50);
            painter.setFont(font);
            painter.setPen(Qt::red);
            painter.drawText(350,150,"Equipement");

            font.setPixelSize(35);
            painter.setFont(font);
            painter.setPen(Qt::blue);
            painter.drawText(20,ligne1,"id: ");
            painter.drawText(20,ligne2,"type: ");
            painter.drawText(20,ligne3,"nb:");
            painter.drawText(20,ligne4,"idanimation:");


            font.setPixelSize(22);
            painter.setFont(font);
            painter.setPen(Qt::black);
            painter.drawText(250,ligne1,id);
            painter.drawText(250,ligne2,type);
            painter.drawText(250,ligne3,nb);
            painter.drawText(250,ligne4,idanimation);
            painter.drawText(0,ligne5,"--------------------------------------------------------------------------------------------------");

}
}
}

void MainWindow::on_pb_modifier_2_clicked()
{
    historique h;
      QString textajouter;

    int ide = ui->lineEdit_idmodif_3->text().toInt();
    QString type= ui->lineEdit_typemodif->text();
     int nb= ui->lineEdit_nbmodif->text().toInt();

    int idanimation= ui->lineEdit_idanimationmodif->text().toInt();
  //  int idanimation = ui->x2->currentText().toInt();



    Equipement equip(ide,type,nb,idanimation);
    bool test=equip.modifier_2(ide);
  if(test)
{
      ui->tabequip->setModel(tmpequip.afficher_2());

      ui->tabequip->setModel(tmpequip.afficherasc_2());
      ui->tabequip->setModel(tmpequip.afficherdesc_2());


   // MainWindow::makePlot();
QMessageBox::information(nullptr, QObject::tr("Modifier un equipement"),
                  QObject::tr("Equipement modifié.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}
  else
      QMessageBox::critical(nullptr, QObject::tr("Modifier un equipement"),
                  QObject::tr("Erreur !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

  textajouter="La modification dans la base de donnees equipement :"+type+" a ete effectuee avec succees";
     h.write(textajouter);

     trayIcon->showMessage("Modifier Equipement", "Nouveau Equipement :"+type+" a été modifié avec sucees dans la base de donnée",
                           QSystemTrayIcon::Information, 3000);

}

void MainWindow::on_trie_asc_2_clicked()
{
      ui->tabequipement->setModel(tmpequipement.afficherasc_2());
}

void MainWindow::on_trie_desc_2_clicked()
{
    ui->tabequipement->setModel(tmpequipement.afficherdesc_2());
}

void MainWindow::on_Rechercher_3_clicked()
{
    QString ide=ui->lineEdit_idrechercher->text();
    ui->tab_ab_rech_3->setModel(tmpequip.recherche_2(ide));
}

void MainWindow::on_tabequipement_activated(const QModelIndex &index)
{
    QString val=ui->tabequipement->model()->data(index).toString();
    QSqlQuery q;
    q.prepare("select * from equipement where id='"+val+"'");
  if(q.exec())
      while (q.next()) {
                  ui->lineEdit_typemodif->setText(q.value(1).toString());
                  ui->lineEdit_nbmodif->setText(q.value(2).toString());
                  ui->lineEdit_idanimationmodif->setText(q.value(3).toString());
                    ui->lineEdit_idmodif_3->setText(q.value(0).toString());


                        }
}



void MainWindow::on_statistique_clicked()
{

    /*statYO=new statistiq(this);
    statYO->show();*/
    statistiq *a=new statistiq();
           a->show();
}


void MainWindow::makePolt()
{
    QLinearGradient gradient(0, 0, 0, 400);
    gradient.setColorAt(0, QColor(90, 90, 90));
    gradient.setColorAt(0.38, QColor(105, 105, 105));
    gradient.setColorAt(1, QColor(70, 70, 70));
    ui->customPlot->setBackground(QBrush(gradient));
    QCPBars *regen = new QCPBars(ui->customPlot->xAxis, ui->customPlot->yAxis);
    regen->setAntialiased(false);
    regen->setStackingGap(1);
    regen->setName("Stat pandoud");
    regen->setPen(QPen(QColor(0, 168, 140).lighter(130)));
    regen->setBrush(QColor(0, 168, 140));


    // prepare x axis with country labels:
    QVector<double> ticks;
    QVector<QString> labels;
    ticks << 1 << 2 ;

    labels << ">1500 DT/M" << "<1500 DT/M" ;
    QSharedPointer<QCPAxisTickerText> textTicker(new QCPAxisTickerText);
    textTicker->addTicks(ticks, labels);
    ui->customPlot->xAxis->setTicker(textTicker);
    ui->customPlot->xAxis->setTickLabelRotation(60);
    ui->customPlot->xAxis->setSubTicks(false);
    ui->customPlot->xAxis->setTickLength(0, 4);
    ui->customPlot->xAxis->setRange(0, 8);
    ui->customPlot->xAxis->setBasePen(QPen(Qt::white));
    ui->customPlot->xAxis->setTickPen(QPen(Qt::white));
    ui->customPlot->xAxis->grid()->setVisible(true);
    ui->customPlot->xAxis->grid()->setPen(QPen(QColor(130, 130, 130), 0, Qt::DotLine));
    ui->customPlot->xAxis->setTickLabelColor(Qt::white);
    ui->customPlot->xAxis->setLabelColor(Qt::white);

    // prepare y axis:
    ui->customPlot->yAxis->setRange(0,20);
    ui->customPlot->yAxis->setPadding(5); // a bit more space to the left border
    ui->customPlot->yAxis->setBasePen(QPen(Qt::white));
    ui->customPlot->yAxis->setTickPen(QPen(Qt::white));
    ui->customPlot->yAxis->setSubTickPen(QPen(Qt::white));
    ui->customPlot->yAxis->grid()->setSubGridVisible(true);
    ui->customPlot->yAxis->setTickLabelColor(Qt::white);
    ui->customPlot->yAxis->setLabelColor(Qt::white);
    ui->customPlot->yAxis->grid()->setPen(QPen(QColor(130, 130, 130), 0, Qt::SolidLine));
    ui->customPlot->yAxis->grid()->setSubGridPen(QPen(QColor(130, 130, 130), 0, Qt::DotLine));

    // Add data:
    QVector<double> regenData;
int nbr;
int he;
QSqlQuery query1("select count(*) from PERSONNEL where SALAIRE > 1500 ");
while (query1.next()) {

                        he = query1.value(0).toInt();

                                                    }

    QSqlQuery query2("select count(*) from PERSONNEL where SALAIRE < 1500 ");
    while (query2.next()) {
                           nbr = query2.value(0).toInt();

                             }
    regenData << he << nbr ;
    regen->setData(ticks, regenData);

    // setup legend:
    ui->customPlot->legend->setVisible(true);
    ui->customPlot->axisRect()->insetLayout()->setInsetAlignment(0, Qt::AlignTop|Qt::AlignHCenter);
    ui->customPlot->legend->setBrush(QColor(255, 255, 255, 100));
    ui->customPlot->legend->setBorderPen(Qt::NoPen);
    QFont legendFont = font();
    legendFont.setPointSize(10);
    ui->customPlot->legend->setFont(legendFont);
    ui->customPlot->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom);


}
void MainWindow::makePolt1()
{
    QLinearGradient gradient(0, 0, 0, 400);
    gradient.setColorAt(0, QColor(90, 90, 90));
    gradient.setColorAt(0.38, QColor(105, 105, 105));
    gradient.setColorAt(1, QColor(70, 70, 70));
    ui->customPlot_2->setBackground(QBrush(gradient));
    QCPBars *regen = new QCPBars(ui->customPlot_2->xAxis, ui->customPlot_2->yAxis);
    regen->setAntialiased(false);
    regen->setStackingGap(1);
    regen->setName("Stat pandoud");
    regen->setPen(QPen(QColor(0, 168, 140).lighter(130)));
    regen->setBrush(QColor(0, 168, 140));


    // prepare x axis with country labels:
    QVector<double> ticks;
    QVector<QString> labels;
    ticks << 1 << 2 << 3 ;

    labels << "Suite" << "Simple" << "Double" ;
    QSharedPointer<QCPAxisTickerText> textTicker(new QCPAxisTickerText);
    textTicker->addTicks(ticks, labels);
    ui->customPlot_2->xAxis->setTicker(textTicker);
    ui->customPlot_2->xAxis->setTickLabelRotation(60);
    ui->customPlot_2->xAxis->setSubTicks(false);
    ui->customPlot_2->xAxis->setTickLength(0, 4);
    ui->customPlot_2->xAxis->setRange(0, 8);
    ui->customPlot_2->xAxis->setBasePen(QPen(Qt::white));
    ui->customPlot_2->xAxis->setTickPen(QPen(Qt::white));
    ui->customPlot_2->xAxis->grid()->setVisible(true);
    ui->customPlot_2->xAxis->grid()->setPen(QPen(QColor(130, 130, 130), 0, Qt::DotLine));
    ui->customPlot_2->xAxis->setTickLabelColor(Qt::white);
    ui->customPlot_2->xAxis->setLabelColor(Qt::white);

    // prepare y axis:
    ui->customPlot_2->yAxis->setRange(0,20);
    ui->customPlot_2->yAxis->setPadding(5); // a bit more space to the left border
    ui->customPlot_2->yAxis->setBasePen(QPen(Qt::white));
    ui->customPlot_2->yAxis->setTickPen(QPen(Qt::white));
    ui->customPlot_2->yAxis->setSubTickPen(QPen(Qt::white));
    ui->customPlot_2->yAxis->grid()->setSubGridVisible(true);
    ui->customPlot_2->yAxis->setTickLabelColor(Qt::white);
    ui->customPlot_2->yAxis->setLabelColor(Qt::white);
    ui->customPlot_2->yAxis->grid()->setPen(QPen(QColor(130, 130, 130), 0, Qt::SolidLine));
    ui->customPlot_2->yAxis->grid()->setSubGridPen(QPen(QColor(130, 130, 130), 0, Qt::DotLine));

    // Add data:
    QVector<double> regenData;
int suite,simple,doubl;
QSqlQuery query1("select count(*) from CHAMBRE where TYPE_CHAMBRE='suite'");
while (query1.next()) {

                        suite = query1.value(0).toInt();

                                                    }

    QSqlQuery query2("select count(*) from CHAMBRE where  TYPE_CHAMBRE='simple'");
    while (query2.next()) {
                           simple = query2.value(0).toInt();

                             }
    QSqlQuery query3("select count(*) from CHAMBRE where  TYPE_CHAMBRE='double'");
    while (query3.next()) {
                           doubl = query3.value(0).toInt();

                             }
    regenData << suite << simple << doubl;
    regen->setData(ticks, regenData);

    // setup legend:
    ui->customPlot_2->legend->setVisible(true);
    ui->customPlot_2->axisRect()->insetLayout()->setInsetAlignment(0, Qt::AlignTop|Qt::AlignHCenter);
    ui->customPlot_2->legend->setBrush(QColor(255, 255, 255, 100));
    ui->customPlot_2->legend->setBorderPen(Qt::NoPen);
    QFont legendFont = font();
    legendFont.setPointSize(10);
    ui->customPlot_2->legend->setFont(legendFont);
    ui->customPlot_2->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom);


}

void MainWindow::on_pushButton_6_clicked()
{


                QSqlQueryModel * modal= new QSqlQueryModel();
                        QSqlQuery request;
                        request.prepare("select IDEVE from EVENEMENT");
                        request.exec();
                        modal->setQuery(request);
                        ui->Ref_Eve->setModel(modal);

}

void MainWindow::makePolt2()
{
    QLinearGradient gradient(0, 0, 0, 400);
    gradient.setColorAt(0, QColor(90, 90, 90));
    gradient.setColorAt(0.38, QColor(105, 105, 105));
    gradient.setColorAt(1, QColor(70, 70, 70));
    ui->customPlot_3->setBackground(QBrush(gradient));
    QCPBars *regen = new QCPBars(ui->customPlot_3->xAxis, ui->customPlot_3->yAxis);
    regen->setAntialiased(false);
    regen->setStackingGap(1);
    regen->setName("Stat pandoud");
    regen->setPen(QPen(QColor(0, 168, 140).lighter(130)));
    regen->setBrush(QColor(0, 168, 140));


    // prepare x axis with country labels:
    QVector<double> ticks;
    QVector<QString> labels;
    ticks << 1 << 2 ;

    labels << ">100 per" << "<100 per" ;
    QSharedPointer<QCPAxisTickerText> textTicker(new QCPAxisTickerText);
    textTicker->addTicks(ticks, labels);
    ui->customPlot_3->xAxis->setTicker(textTicker);
    ui->customPlot_3->xAxis->setTickLabelRotation(60);
    ui->customPlot_3->xAxis->setSubTicks(false);
    ui->customPlot_3->xAxis->setTickLength(0, 4);
    ui->customPlot_3->xAxis->setRange(0, 8);
    ui->customPlot_3->xAxis->setBasePen(QPen(Qt::white));
    ui->customPlot_3->xAxis->setTickPen(QPen(Qt::white));
    ui->customPlot_3->xAxis->grid()->setVisible(true);
    ui->customPlot_3->xAxis->grid()->setPen(QPen(QColor(130, 130, 130), 0, Qt::DotLine));
    ui->customPlot_3->xAxis->setTickLabelColor(Qt::white);
    ui->customPlot_3->xAxis->setLabelColor(Qt::white);

    // prepare y axis:
    ui->customPlot_3->yAxis->setRange(0,20);
    ui->customPlot_3->yAxis->setPadding(5); // a bit more space to the left border
    ui->customPlot_3->yAxis->setBasePen(QPen(Qt::white));
    ui->customPlot_3->yAxis->setTickPen(QPen(Qt::white));
    ui->customPlot_3->yAxis->setSubTickPen(QPen(Qt::white));
    ui->customPlot_3->yAxis->grid()->setSubGridVisible(true);
    ui->customPlot_3->yAxis->setTickLabelColor(Qt::white);
    ui->customPlot_3->yAxis->setLabelColor(Qt::white);
    ui->customPlot_3->yAxis->grid()->setPen(QPen(QColor(130, 130, 130), 0, Qt::SolidLine));
    ui->customPlot_3->yAxis->grid()->setSubGridPen(QPen(QColor(130, 130, 130), 0, Qt::DotLine));

    // Add data:
    QVector<double> regenData;
int nbr;
int he;
QSqlQuery query1("select count(*) from EVENEMENT where NBEVE > 100 ");
while (query1.next()) {

                        he = query1.value(0).toInt();

                                                    }

    QSqlQuery query2("select count(*) from EVENEMENT where NBEVE < 100 ");
    while (query2.next()) {
                           nbr = query2.value(0).toInt();

                             }
    regenData << he << nbr ;
    regen->setData(ticks, regenData);

    // setup legend:
    ui->customPlot_3->legend->setVisible(true);
    ui->customPlot_3->axisRect()->insetLayout()->setInsetAlignment(0, Qt::AlignTop|Qt::AlignHCenter);
    ui->customPlot_3->legend->setBrush(QColor(255, 255, 255, 100));
    ui->customPlot_3->legend->setBorderPen(Qt::NoPen);
    QFont legendFont = font();
    legendFont.setPointSize(10);
    ui->customPlot_3->legend->setFont(legendFont);
    ui->customPlot_3->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom);

}


void MainWindow::on_actualiser_amine_clicked()
{
    QSqlQueryModel * modal= new QSqlQueryModel();
            QSqlQuery request;
            request.prepare("select CIN from PERSONNEL");
            request.exec();
            modal->setQuery(request);
            ui->comboBox_3->setModel(modal);
}

void MainWindow::on_excel1_clicked()
{
    QTableView *table;
               table = ui->tabequip;
               QString filters("CSV files (*.csv);;All files (*.*)");
               QString defaultFilter("CSV files (*.csv)");
               QString fileName = QFileDialog::getSaveFileName(0, "Save file", QCoreApplication::applicationDirPath(),
                                  filters, &defaultFilter);
               QFile file(fileName);
               QAbstractItemModel *model =  table->model();
               if (file.open(QFile::WriteOnly | QFile::Truncate)) {
                   QTextStream data(&file);
                   QStringList strList;
                   for (int i = 0; i < model->columnCount(); i++) {
                       if (model->headerData(i, Qt::Horizontal, Qt::DisplayRole).toString().length() > 0)
                           strList.append("\"" + model->headerData(i, Qt::Horizontal, Qt::DisplayRole).toString() + "\"");
                       else
                           strList.append("");
                   }
                   data << strList.join(";") << "\n";
                   for (int i = 0; i < model->rowCount(); i++) {
                       strList.clear();
                       for (int j = 0; j < model->columnCount(); j++) {
                           if (model->data(model->index(i, j)).toString().length() > 0)
                               strList.append("\"" + model->data(model->index(i, j)).toString() + "\"");
                           else
                               strList.append("");
                       }
                       data << strList.join(";") + "\n";
                   }
                   file.close();
                   QMessageBox::information(this,"Exporter To Excel","Exporter En Excel Avec Succées ");
               }
}

void MainWindow::on_excel2_clicked()
{
    QTableView *table;
               table = ui->tabanim;
               QString filters("CSV files (*.csv);;All files (*.*)");
               QString defaultFilter("CSV files (*.csv)");
               QString fileName = QFileDialog::getSaveFileName(0, "Save file", QCoreApplication::applicationDirPath(),
                                  filters, &defaultFilter);
               QFile file(fileName);
               QAbstractItemModel *model =  table->model();
               if (file.open(QFile::WriteOnly | QFile::Truncate)) {
                   QTextStream data(&file);
                   QStringList strList;
                   for (int i = 0; i < model->columnCount(); i++) {
                       if (model->headerData(i, Qt::Horizontal, Qt::DisplayRole).toString().length() > 0)
                           strList.append("\"" + model->headerData(i, Qt::Horizontal, Qt::DisplayRole).toString() + "\"");
                       else
                           strList.append("");
                   }
                   data << strList.join(";") << "\n";
                   for (int i = 0; i < model->rowCount(); i++) {
                       strList.clear();
                       for (int j = 0; j < model->columnCount(); j++) {
                           if (model->data(model->index(i, j)).toString().length() > 0)
                               strList.append("\"" + model->data(model->index(i, j)).toString() + "\"");
                           else
                               strList.append("");
                       }
                       data << strList.join(";") + "\n";
                   }
                   file.close();
                   QMessageBox::information(this,"Exporter To Excel","Exporter En Excel Avec Succées ");
               }
               }
