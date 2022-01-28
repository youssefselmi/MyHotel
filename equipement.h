#ifndef EQUIPEMENT_H
#define EQUIPEMENT_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>


class Equipement
{
public:
    Equipement();
    Equipement(int,QString,int,int);
    bool ajout();


    QSqlQueryModel * afficher_2();
    bool supprimer_2(int);
    bool modifier_2(int);

    int get_id();
    QString get_type();
     int get_nb();
       int get_idanimation();

    QSqlQueryModel * recherche_2(const QString&);
    QSqlQueryModel * afficherasc_2();
    QSqlQueryModel * afficherdesc_2();
     QVector<double> statistique();


private:
    QString type;
    int id,nb,idanimation;


};

#endif // EQUIPEMENT_H
