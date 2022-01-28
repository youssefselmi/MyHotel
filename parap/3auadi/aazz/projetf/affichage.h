#ifndef AFFICHAGE_H
#define AFFICHAGE_H

#include <QDialog>
#include "demande.h"

namespace Ui {
class Affichage;
}

class Affichage : public QDialog
{
    Q_OBJECT

public:
    explicit Affichage(QWidget *parent = nullptr);
    ~Affichage();

private slots:
    void on_pushButton_clicked();

    void on_tabdemande_activated(const QModelIndex &index);

    void on_supprimer_demande_clicked();

    void on_modifier_demande_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_recherche_demande_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_8_clicked();

private:
    Ui::Affichage *ui;
    demande tmpdemande;
};

#endif // AFFICHAGE_H
