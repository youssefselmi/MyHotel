#include "dialogheberg.h"
#include "ui_dialogheberg.h"
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include "connexion.h"



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



DialogHeberg::DialogHeberg(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogHeberg)
{
    ui->setupUi(this);
}

DialogHeberg::~DialogHeberg()
{
    delete ui;
}

void DialogHeberg::on_pushButton_clicked()
{
    QSqlQueryModel *modal=new QSqlQueryModel();
    QSqlQuery request;
    request.exec("SELECT * FROM HEBERGEMENT");
    modal->setQuery(request);
    ui->tableView1->setModel(modal);
}

void DialogHeberg::on_pushButton_2_clicked()
{

    QString num=ui->Search->text();
    QSqlQuery Drequest;
    Drequest.prepare("DELETE FROM HEBERGEMENT WHERE NUMRES=:num");
    Drequest.bindValue(":num",num);
    Drequest.exec();

}



void DialogHeberg::on_tableView1_activated(const QModelIndex &index)
{
    QString  val=ui->tableView1->model()->data(index).toString();
    QSqlQuery qry;
    qry.prepare("SELECT * FROM HEBERGEMENT WHERE NUMRES=:num");
    qry.bindValue(":num",val);
    if (qry.exec())
    {
        while (qry.next()) {
            ui->lineEdit->setText(qry.value(0).toString());
            ui->lineEdit_2->setText(qry.value(1).toString());
            ui->lineEdit_3->setText(qry.value(2).toString());
            ui->lineEdit_4->setText(qry.value(3).toString());
            ui->lineEdit_5->setText(qry.value(4).toString());
            ui->lineEdit_6->setText(qry.value(5).toString());
            ui->lineEdit_7->setText(qry.value(6).toString());
            ui->lineEdit_8->setText(qry.value(7).toString());
            ui->lineEdit_9->setText(qry.value(8).toString());
        }
    }
}

void DialogHeberg::on_Tri1_clicked()
{

    QSqlQueryModel *modal=new QSqlQueryModel();
    QSqlQuery request;
    request.exec("SELECT * FROM HEBERGEMENT order by DATEARR");
    modal->setQuery(request);
    ui->tableView1->setModel(modal);
}

void DialogHeberg::on_pushButton_4_clicked()
{
    QString demi="demi";
    QSqlQueryModel *modal=new QSqlQueryModel();
    QSqlQuery request;
    request.prepare("SELECT * FROM HEBERGEMENT WHERE TYPERES=:demi");
    request.bindValue(":demi",demi);
    request.exec();
    modal->setQuery(request);
    ui->tableView1->setModel(modal);
}

void DialogHeberg::on_update_clicked()
{
    QSqlQuery query;
    QString num=ui->lineEdit->text();
    QString NBp=ui->lineEdit_2->text();
    QString DateA=ui->lineEdit_3->text();
    QString DateD=ui->lineEdit_4->text();
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

/*void DialogHeberg::on_search_clicked()
{
    QSqlQueryModel *modal=new QSqlQueryModel();
    QSqlQuery request;
    request.exec("SELECT * FROM HEBERGEMENT WHERE ");
    modal->setQuery(request);
    ui->tableView1->setModel(modal);
}*/

/*void DialogHeberg::on_comboBox_currentIndexChanged(const QString &arg1)
{
    QSqlQueryModel *modal=new QSqlQueryModel();
    QSqlQuery request;
   QString type=ui->comboBox->currentText();
   QString val=ui->Linesearch->text();
   if (type=="Numero"){
       request.prepare("SELECT * FROM HEBERGEMENT WHERE NUMRES=:val");
   }else if (type=="nom"){
       request.prepare("SELECT * FROM HEBERGEMENT WHERE NOM=:val");
   }else if (type=="cin"){
       request.prepare("SELECT * FROM HEBERGEMENT WHERE CIN=:val");
   }else if (type=="pention"){
       request.prepare("SELECT * FROM HEBERGEMENT WHERE TYPERES=:val");
   }else if (type=="chambre"){
       request.prepare("SELECT * FROM HEBERGEMENT WHERE TYPECHAMBRE=:val");
   }else if (type=="prenom"){
       request.prepare("SELECT * FROM HEBERGEMENT WHERE PRENOM=:val");
   }

   request.bindValue(":val",val);
   request.exec();
   modal->setQuery(request);
   ui->tableView1->setModel(modal);
}
*/
void DialogHeberg::on_pushButton_3_clicked()
{
    QSqlQueryModel *modal=new QSqlQueryModel();
    QSqlQuery request;
   QString type=ui->comboBox->currentText();
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
   ui->tableView1->setModel(modal);
}

void DialogHeberg::on_pdf_clicked()
{
    QString strStream;
            QTextStream out(&strStream);

            const int rowCount = ui->tableView1->model()->rowCount();
            const int columnCount = ui->tableView1->model()->columnCount();
            for (int column = 0; column < columnCount; column++)
                if (!ui->tableView1->isColumnHidden(column))
                   out << QString("<th>%1<br></th>").arg(ui->tableView1->model()->headerData(column, Qt::Horizontal).toString());

            for (int row = 0; row < rowCount; row++) {
                out << "<tr>";
                for (int column = 0; column < columnCount; column++) {
                    if (!ui->tableView1->isColumnHidden(column)) {
                        QString data =ui->tableView1->model()->data(ui->tableView1->model()->index(row, column)).toString().simplified();
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

void DialogHeberg::on_pushButton_5_clicked()
{
    QString strStream;
            QTextStream out(&strStream);

            const int rowCount = ui->tableView1->model()->rowCount();
            const int columnCount = ui->tableView1->model()->columnCount();
            for (int column = 0; column < columnCount; column++)
                if (!ui->tableView1->isColumnHidden(column))
                    out << QString("<th>%1</th>").arg(ui->tableView1->model()->headerData(column, Qt::Horizontal).toString());
            for (int row = 0; row < rowCount; row++) {
                out << "<tr>";
                for (int column = 0; column < columnCount; column++) {
                    if (!ui->tableView1->isColumnHidden(column)) {
                        QString data =ui->tableView1->model()->data(ui->tableView1->model()->index(row, column)).toString().simplified();
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
