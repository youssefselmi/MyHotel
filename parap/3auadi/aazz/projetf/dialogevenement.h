#ifndef DIALOGEVENEMENT_H
#define DIALOGEVENEMENT_H

#include <QDialog>
#include "evenement.h"
#include "statevenement.h"
namespace Ui {
class DialogEvenement;
}

class DialogEvenement : public QDialog
{
    Q_OBJECT

public:
    explicit DialogEvenement(QWidget *parent = nullptr);
    ~DialogEvenement();

private slots:
    void on_pushButton_21_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_29_clicked();

    void on_pushButton_30_clicked();

    void on_pushButton_36_clicked();

    void on_pushButton_33_clicked();

    void on_tableView_2_activated(const QModelIndex &index);

    void on_pushButton_clicked();

private:
    Ui::DialogEvenement *ui;
    evenement tmpE ;
       statevenement *secPage;

};

#endif // DIALOGEVENEMENT_H
