#ifndef PDF_H
#define PDF_H

#include <QDialog>
#include <QMainWindow>
#include "animation.h"
#include "equipement.h"
//#include "update.h"
#include <QPrintDialog>
#include <QPrinter>
#include <QSystemTrayIcon>
#include "qcustomplot.h"
//#include "modif.h"

namespace Ui {
class pdf;
}

class pdf : public QDialog
{
    Q_OBJECT

public:
    explicit pdf(QWidget *parent = nullptr);
    ~pdf();
     void pdffonction();

private slots:
     void on_pushButton_imprimer_4_clicked();

private:
    Ui::pdf *ui;

};

#endif // PDF_H
