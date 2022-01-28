#ifndef LISTECHAMBRES_H
#define LISTECHAMBRES_H

#include <QDialog>

namespace Ui {
class ListeChambres;
}

class ListeChambres : public QDialog
{
    Q_OBJECT

public:
    explicit ListeChambres(QWidget *parent = nullptr);
    ~ListeChambres();

private slots:
    void on_tableViewCH_activated(const QModelIndex &index);

    void on_afficherCH_clicked();

private:
    Ui::ListeChambres *ui;
};

#endif // LISTECHAMBRES_H
