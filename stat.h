#ifndef STAT_H
#define STAT_H

#include <QDialog>
#include "qcustomplot.h"
#include <QWidget>

#include <QMainWindow>

namespace Ui {
class stat;
}

class stat : public QMainWindow
{
    Q_OBJECT

public:
    explicit stat(QWidget *parent = nullptr);
    ~stat();
    void

private:
    Ui::stat *ui;
};

#endif // STAT_H
