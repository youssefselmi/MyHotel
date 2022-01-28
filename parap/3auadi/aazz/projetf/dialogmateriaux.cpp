#include "dialogmateriaux.h"
#include "ui_dialogmateriaux.h"
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
#endif

dialogMateriaux::dialogMateriaux(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::dialogMateriaux)
{
    ui->setupUi(this);
}

dialogMateriaux::~dialogMateriaux()
{
    delete ui;
}

void dialogMateriaux::on_pushButton_18_clicked()
{
    ui->tableView->setModel(tmpM.afficher());
}

void dialogMateriaux::on_pushButton_31_clicked()
{
    QString ref=ui->Ref_3->text();
    int nbr = ui->QNT_3->text().toInt();
    QString etat = ui->etatM_3->text();
    materiaux M(ref,nbr,etat);
    bool test=M.modif(ref,nbr);
    bool test2=M.modifEtat(ref,etat);
    if (test || test2)
    {
                QMessageBox::information(nullptr, QObject::tr("database is open"),
                            QObject::tr("materiel modifier.\n"
                                        "Click Cancel to exit."), QMessageBox::Cancel);
    }
}

void dialogMateriaux::on_tableView_activated(const QModelIndex &index)
{
    QString  val=ui->tableView->model()->data(index).toString();
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

void dialogMateriaux::on_pushButton_clicked()
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

void dialogMateriaux::on_pushButton_28_clicked()
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

void dialogMateriaux::on_pushButton_33_clicked()
{
    QString strStream;
        QTextStream out(&strStream);

        const int rowCount = ui->tableView->model()->rowCount();
        const int columnCount = ui->tableView->model()->columnCount();
        for (int column = 0; column < columnCount; column++)
            if (!ui->tableView->isColumnHidden(column))
               out << QString("<th>%1</th>").arg(ui->tableView->model()->headerData(column, Qt::Horizontal).toString());

        for (int row = 0; row < rowCount; row++) {
            for (int column = 0; column < columnCount; column++) {
                if (!ui->tableView->isColumnHidden(column)) {
                    QString data =ui->tableView->model()->data(ui->tableView->model()->index(row, column)).toString().simplified();
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

void dialogMateriaux::on_pushButton_36_clicked()
{
    QSqlQueryModel *modal=new QSqlQueryModel();
        QSqlQuery request;
       QString type=ui->comboBox->currentText();
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
       ui->tableView->setModel(modal);
}
