#include "affichage.h"
#include "ui_affichage.h"
#include <QMessageBox>
#include <QTabWidget>
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QMessageBox>
#include <QSqlQueryModel>
#include <QTextDocument>
#include <QTextStream>
#include <QtPrintSupport/QPrintDialog>
#include<QtPrintSupport/QPrinter>
#include <QtWidgets>
#include <QItemSelectionModel>
#include <QModelIndexList>
#include <QStringList>
#ifndef QT_NO_PRINTER
#include <QPrinter>
#include <QCalendar>
#endif
Affichage::Affichage(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Affichage)
{
    ui->setupUi(this);
    ui->ref->setPlaceholderText("REF");
    ui->quantite->setPlaceholderText("QUANTITE");
    ui->type->setPlaceholderText("TYPE");
    ui->cin->setPlaceholderText("CIN");
    ui->etat->setPlaceholderText("ETAT");
    ui->date->setPlaceholderText("DATE");
    ui->lineEdit_recherche->setPlaceholderText("Recherche");
}

Affichage::~Affichage()
{
    delete ui;
}

void Affichage::on_pushButton_clicked()
{
     ui->tabdemande->setModel(tmpdemande.afficher_demande());
}

void Affichage::on_tabdemande_activated(const QModelIndex &index)
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
            ui->cin->setText(qry.value(3).toString());
            ui->etat->setText(qry.value(4).toString());
            ui->date->setText(qry.value(5).toString());

        }
    }
}

void Affichage::on_supprimer_demande_clicked()
{
    int cin = ui->cin->text().toInt();
    bool test=tmpdemande.supprimer_demande(cin);
    if (test)
    {ui->tabdemande->setModel(tmpdemande.afficher_demande());//refresh
        QMessageBox::critical(nullptr, QObject::tr("database is open"),
                              QObject::tr("demande supprimer.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
}
}

void Affichage::on_modifier_demande_clicked()
{
    int cin,ref,quantite,etat;
    QString type,date;
    cin=ui->cin->text().toInt();
    type=ui->type->text();
    ref=ui->ref->text().toInt();
    etat=ui->etat->text().toInt();
    quantite=ui->quantite->text().toInt();
    date=ui->date->text();
    QSqlQuery qry;
    qry.prepare("update demande set QUANTITE_DEMANDE=:Quantite,TYPE_DEMANDE=:Type,ETAT=:Etat,DATEDEBUT=:Date where CIN=:cin ");
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

void Affichage::on_pushButton_2_clicked()
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

void Affichage::on_pushButton_3_clicked()
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

void Affichage::on_recherche_demande_clicked()
{
    QSqlQueryModel *modal=new QSqlQueryModel();
            QSqlQuery request;
           QString type=ui->comboBox->currentText();
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

void Affichage::on_pushButton_4_clicked()
{
    int cin,ref,quantite,etat;
    QString type,date;
    cin=ui->cin->text().toInt();
    type=ui->type->text();
    ref=ui->ref->text().toInt();
    etat=ui->etat->text().toInt();
    quantite=ui->quantite->text().toInt();
    date=ui->date->text();
    QSqlQuery qry;
    qry.prepare("update demande set ETAT=1 where CIN=:cin ");
    qry.bindValue(":cin",cin);
     qry.bindValue(":ref",ref);
    qry.bindValue(":Quantite",quantite);
    qry.bindValue(":Type",type);
    qry.bindValue(":Etat",etat);
    qry.bindValue(":Date",date);
            QMessageBox::critical(nullptr, QObject::tr("database is open"),
                                  QObject::tr("demande accepter.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);
    qry.exec();
    ui->tabdemande->setModel(tmpdemande.afficher_demande());//refresh
}

void Affichage::on_pushButton_5_clicked()
{
    int cin,ref,quantite,etat;
    QString type,date;
    cin=ui->cin->text().toInt();
    type=ui->type->text();
    ref=ui->ref->text().toInt();
    etat=ui->etat->text().toInt();
    quantite=ui->quantite->text().toInt();
    date=ui->date->text();
    QSqlQuery qry;
    qry.prepare("update demande set ETAT=-1 where CIN=:cin ");
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

void Affichage::on_pushButton_6_clicked()
{
    QSqlQueryModel * modal= new QSqlQueryModel();
    QSqlQuery request;
        request.prepare("select * from demande order by ETAT DESC");
        request.exec();
        modal->setQuery(request);
        ui->tabdemande->setModel(modal);

}

void Affichage::on_pushButton_7_clicked()
{
    QSqlQueryModel * modal= new QSqlQueryModel();
    QSqlQuery request;
        request.prepare("select * from demande order by CIN DESC");
        request.exec();
        modal->setQuery(request);
        ui->tabdemande->setModel(modal);

}

