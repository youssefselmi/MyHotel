#include "pdf.h"
#include "ui_pdf.h"
#include <QTabWidget>
#include "animation.h"
//#include "equipement.h"
#include <QMessageBox>
#include <QPixmap>
#include <QPrintDialog>
#include <QPrinter>
#include <QTextDocument>
#include <QTextStream>
#include"QDate"
#include <iostream>
//#include "statistique.h"
#include "pdf.h"
#include"QSqlRecord"
#include"QSqlQuery"

pdf::pdf(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::pdf)
{
    ui->setupUi(this);
    //on_pdf_clicked();

}

pdf::~pdf()
{
    delete ui;
}



void pdf::pdffonction()
{
        QPrinter printer;
        printer.setOutputFormat(QPrinter::PdfFormat);
        printer.setOutputFileName("F:/projet Qt xteam integration/projetv0/MonPDF.pdf");
        QPainter painter;
        painter.begin(&printer);

        QFont font;
        QString code=ui->lineEdit_code_pdf_3->text();
        QSqlQuery query;
        QString typeanim_pdf,id_pdf,nb_pdf,type_pdf,idanimation_pdf,lieu_pdf,dateanim_pdf,duree_pdf,cin_pdf;


        if (ui->comboBox_type_pdf_3->currentText()=="equipement")
        {
            query.prepare("select * from equipement where id='"+code+"'");
            if (query.exec())
            {
                while (query.next())
                {
                    nb_pdf=query.value(1).toString();
                    type_pdf=query.value(3).toString();
                    idanimation_pdf=query.value(2).toString();

                }
            }
            font.setPixelSize(50);
            painter.setFont(font);
            painter.setPen(Qt::red);
            painter.drawText(350,150,"Equipement");

            font.setPixelSize(35);
            painter.setFont(font);
            painter.setPen(Qt::blue);
            painter.drawText(20,300,"Type: ");
            painter.drawText(20,500,"Nombre:");
            painter.drawText(20,650,"IDanimation:");


            font.setPixelSize(22);
            painter.setFont(font);
            painter.setPen(Qt::black);
            painter.drawText(300,500,type_pdf);
            painter.drawText(300,300,nb_pdf);
            painter.drawText(300,650,idanimation_pdf);

        }
        else
        {
            query.prepare("select * from animation where idanim='"+code+"'");
            if (query.exec())
            {
                while (query.next())
                {
                    typeanim_pdf=query.value(1).toString();
                    lieu_pdf=query.value(2).toString();
                    dateanim_pdf=query.value(3).toString();
                    duree_pdf=query.value(4).toString();
                    cin_pdf=query.value(5).toString();
                }
            }
            font.setPixelSize(50);
            painter.setFont(font);
            painter.setPen(Qt::red);
            painter.drawText(350,150,"Animation");

            font.setPixelSize(35);
            painter.setFont(font);
            painter.setPen(Qt::blue);
            painter.drawText(20,300,"Type de l'animation: ");
            painter.drawText(20,500,"Lieu de l'animation:");
            painter.drawText(20,650,"Date de l'animation:");
            painter.drawText(20,850,"Duree de l'animation:");
            painter.drawText(20,1000,"CIN de l'animateur:");




            font.setPixelSize(22);
            painter.setFont(font);
            painter.setPen(Qt::black);



            painter.drawText(400,500,typeanim_pdf);
            painter.drawText(400,300,lieu_pdf);
            painter.drawText(400,650,dateanim_pdf);
             painter.drawText(400,850,duree_pdf);
             painter.drawText(400,1000,cin_pdf);



            //painter.drawText(150,350,taux_pdf+"%");
        }

        QImage image("C:/Users/ASUS/Desktop/youssefselmi/icon");
        painter.drawImage(-30,-100,image);

        painter.end();
        qDebug()<<"le pdf a ete cree";
        QMessageBox::information(this,"pdf cree","ce pdf a ete cree");
}



void pdf::on_pushButton_imprimer_4_clicked()
{
    pdffonction();
}

























