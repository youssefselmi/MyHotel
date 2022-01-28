#include "dialogevenement.h"
#include "ui_dialogevenement.h"
#include "evenement.h"
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

DialogEvenement::DialogEvenement(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogEvenement)
{
    ui->setupUi(this);
}

DialogEvenement::~DialogEvenement()
{
    delete ui;
}

void DialogEvenement::on_pushButton_21_clicked()
{
    ui->tableView_2->setModel(tmpE.afficherE());

}

void DialogEvenement::on_pushButton_3_clicked()
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

void DialogEvenement::on_pushButton_29_clicked()
{
    QString strStream;
        QTextStream out(&strStream);

        const int rowCount = ui->tableView_2->model()->rowCount();
        const int columnCount = ui->tableView_2->model()->columnCount();
        for (int column = 0; column < columnCount; column++)
            if (!ui->tableView_2->isColumnHidden(column))
               out << QString("<th>%1</th>").arg(ui->tableView_2->model()->headerData(column, Qt::Horizontal).toString());

        for (int row = 0; row < rowCount; row++) {
           // out << "<tr>";
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

void DialogEvenement::on_pushButton_30_clicked()
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

void DialogEvenement::on_pushButton_36_clicked()
{
    QSqlQueryModel *modal=new QSqlQueryModel();
        QSqlQuery request;
       QString type=ui->comboBox->currentText();
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
       ui->tableView_2->setModel(modal);
}

void DialogEvenement::on_pushButton_33_clicked()
{
    int id = ui->idEVE_3->text().toInt();
    QString type = ui->TypeEVE_3->text();
    QString date =ui->calendarWidget_8->selectedDate().toString();
    int nbrE = ui->NBpEVE_3->text().toInt();
    evenement E(id,type,date,nbrE);
    bool test = E.modifE(id,type,date,nbrE);
    if (test)
    {
                QMessageBox::information(nullptr, QObject::tr("database is open"),
                            QObject::tr("evenement modifiée.\n"
                                        "Click Cancel to exit."), QMessageBox::Cancel);
    }

}

void DialogEvenement::on_tableView_2_activated(const QModelIndex &index)
{
    QString  val=ui->tableView_2->model()->data(index).toString();
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

void DialogEvenement::on_pushButton_clicked()
{
    secPage =new statevenement(this);
        secPage->show();
}
