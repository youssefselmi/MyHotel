#ifndef STATEVENEMENT_H
#define STATEVENEMENT_H

#include <QDialog>
#include"connexion.h"
#include "qcustomplot.h"
#include <QWidget>
namespace Ui {
class statevenement;
}

class statevenement : public QDialog
{
    Q_OBJECT

public:
    explicit statevenement(QWidget *parent = nullptr);
    ~statevenement();
    void makePolt();

private:
    Ui::statevenement *ui;
};

#endif // STATEVENEMENT_H
