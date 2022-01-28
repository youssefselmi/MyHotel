#include "affichagepersonnel.h"
#include "ui_affichagepersonnel.h"
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

affichagepersonnel::affichagepersonnel(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::affichagepersonnel)
{
    ui->setupUi(this);
    ui->recherche_cin->setPlaceholderText("CIN");
        ui->recherche_grade->setPlaceholderText("GRADE");
        ui->recherche_salaire->setPlaceholderText("SALAIRE");
        ui->recherche_date->setPlaceholderText("DATE");
        ui->recherche_presence->setPlaceholderText("PRESENCE");
}

affichagepersonnel::~affichagepersonnel()
{
    delete ui;
}
void affichagepersonnel::on_pushButton_3_clicked()
{
    ui->tabpersonnel->setModel(tmppersonnel.afficher());
}

void affichagepersonnel::on_pushButton_2_clicked()
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
void affichagepersonnel::on_pushButton_clicked()
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


void affichagepersonnel::on_tabpersonnel_activated(const QModelIndex &index)
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

void affichagepersonnel::on_pushButton_4_clicked()
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

void affichagepersonnel::on_pushButton_5_clicked()
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

void affichagepersonnel::on_pushButton_6_clicked()
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

void affichagepersonnel::on_pushButton_7_clicked()
{
    QSqlQueryModel * modal= new QSqlQueryModel();
    QSqlQuery request;
        request.prepare("select * from PERSONNEL order by PRESENCE DESC");
        request.exec();
        modal->setQuery(request);
        ui->tabpersonnel->setModel(modal);

}

void affichagepersonnel::on_pushButton_8_clicked()
{
    QSqlQueryModel * modal= new QSqlQueryModel();
    QSqlQuery request;
        request.prepare("select * from PERSONNEL order by CIN DESC");
        request.exec();
        modal->setQuery(request);
        ui->tabpersonnel->setModel(modal);
}





