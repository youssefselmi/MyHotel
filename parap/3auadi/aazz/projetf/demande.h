#ifndef DEMANDE_H
#define DEMANDE_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>

class demande
{
public:
    demande();
    demande(int,int,QString,int,int,QString);
    int get_cin();
    int get_etat();
    int get_ref();
    int get_quantite();
    QString get_type();
    QString get_date();
    bool ajouter_demande();
    QSqlQueryModel * afficher_demande();
    bool supprimer_demande(int);
private:
    QString TYPE_DEMANDE,DATEDEBUT;
    int QUANTITE_DEMANDE,REF_DEMANDE,CIN,ETAT;

};

#endif // DEMANDE_H
