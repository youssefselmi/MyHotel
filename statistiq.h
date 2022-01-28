#ifndef STATISTIQ_H
#define STATISTIQ_H

#include <QDialog>
#include "qcustomplot.h"
#include <QWidget>

#include <QMainWindow>

namespace Ui {
class statistiq;
}

class statistiq : public QDialog
{
    Q_OBJECT

public:
    explicit statistiq(QWidget *parent = nullptr);
    ~statistiq();
    void makePolt();

private slots:
  //  void on_deconecterr_clicked();

private:
    Ui::statistiq *ui;
};

#endif // STATISTIQ_H
