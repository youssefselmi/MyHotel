#ifndef CHAMBRE_H
#define CHAMBRE_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>

class chambre
{
private:
    int NUM,CAPACITE;
    QString TypeChambre,EtatChambre;
public:
    chambre();
    chambre(int,QString,QString,int);
    bool ajouterCH();
};

#endif // CHAMBRE_H
