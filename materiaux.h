#ifndef MATERIAUX_H
#define MATERIAUX_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>


class materiaux
{
public:
    materiaux();
    materiaux(int,QString,int);
    int get_eve();
    int get_nbr();
    QString get_etat();
    bool ajout();
    QSqlQueryModel * afficher();
    bool supp(int);
    bool modif(QString ,int);
    bool modifEtat(QString ,QString);



private:
    QString ref,etat;
    int nbr,eve;
};

#endif // MATERIAUX_H
