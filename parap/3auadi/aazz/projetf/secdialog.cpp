#include "secdialog.h"
#include "ui_secdialog.h"
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include "connexion.h"

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

SecDialog::SecDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SecDialog)
{
    ui->setupUi(this);
}

SecDialog::~SecDialog()
{
    delete ui;
}



void SecDialog::on_pushButton_clicked()
{
    QSqlQueryModel *modal=new QSqlQueryModel();
    QSqlQuery request;
    request.exec("SELECT * FROM CHAMBRE");
    modal->setQuery(request);
    ui->tableView->setModel(modal);
    //qDebug() <<(modal->rowCount());
}

void SecDialog::on_delete_2_clicked()
{
    QString num=ui->search->text();
    QSqlQuery Drequest;
    Drequest.prepare("DELETE FROM CHAMBRE WHERE NUM_CHAMBRE=:num");
    Drequest.bindValue(":num",num);
    Drequest.exec();
}

void SecDialog::on_tableView_activated(const QModelIndex &index)
{
    QString  val=ui->tableView->model()->data(index).toString();
    QSqlQuery qry;
    qry.prepare("SELECT * FROM CHAMBRE WHERE NUM_CHAMBRE=:num");
    qry.bindValue(":num",val);
    if (qry.exec())
    {
        while (qry.next()) {
            ui->lineEdit->setText(qry.value(0).toString());
            ui->lineEdit_2->setText(qry.value(1).toString());
            ui->lineEdit_3->setText(qry.value(2).toString());
            ui->lineEdit_4->setText(qry.value(3).toString());
        }

    }
}

void SecDialog::on_update_clicked()
{
    QSqlQuery query;
    QString num=ui->lineEdit->text();
    QString type=ui->lineEdit_2->text();
    QString etat=ui->lineEdit_3->text();
    QString capacite=ui->lineEdit_4->text();
    query.prepare("update CHAMBRE set TYPE_CHAMBRE=:TC,ETAT_CHAMBRE=:EC,CAPACITE=:C  where NUM_CHAMBRE= :Num");
    query.bindValue(":TC",type);
    query.bindValue(":EC",etat);
    query.bindValue(":C",capacite);
    query.bindValue(":Num",num);
    query.exec();
}

void SecDialog::on_tri_clicked()
{
    QSqlQueryModel *modal=new QSqlQueryModel();
    QSqlQuery request;
    request.exec("SELECT * FROM CHAMBRE order by CAPACITE");
    modal->setQuery(request);
    ui->tableView->setModel(modal);
}

void SecDialog::on_Csearch_clicked()
{
    QSqlQueryModel *modal=new QSqlQueryModel();
    QSqlQuery request;
   QString type=ui->comboBox->currentText();
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
   ui->tableView->setModel(modal);
}

void SecDialog::on_print_clicked()
{
    QString strStream;
            QTextStream out(&strStream);

            const int rowCount = ui->tableView->model()->rowCount();
            const int columnCount = ui->tableView->model()->columnCount();
            for (int column = 0; column < columnCount; column++)
                if (!ui->tableView->isColumnHidden(column))
                    out << QString("<th>%1</th>").arg(ui->tableView->model()->headerData(column, Qt::Horizontal).toString());
            for (int row = 0; row < rowCount; row++) {
                out << "<tr>";
                for (int column = 0; column < columnCount; column++) {
                    if (!ui->tableView->isColumnHidden(column)) {
                        QString data =ui->tableView->model()->data(ui->tableView->model()->index(row, column)).toString().simplified();
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

void SecDialog::on_pdf_clicked()
{
    QString strStream;
            QTextStream out(&strStream);

            const int rowCount = ui->tableView->model()->rowCount();
            const int columnCount = ui->tableView->model()->columnCount();
            for (int column = 0; column < columnCount; column++)
                if (!ui->tableView->isColumnHidden(column))
                   out << QString("<th>%1<br></th>").arg(ui->tableView->model()->headerData(column, Qt::Horizontal).toString());

            for (int row = 0; row < rowCount; row++) {
                out << "<tr>";
                for (int column = 0; column < columnCount; column++) {
                    if (!ui->tableView->isColumnHidden(column)) {
                        QString data =ui->tableView->model()->data(ui->tableView->model()->index(row, column)).toString().simplified();
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

void SecDialog::on_video_clicked()
{
video=new MainWindowvideo(this);
video->show();
}

void SecDialog::on_pushButton_2_clicked()
{
    statCH=new StatChambre(this);
    statCH->show();
}
