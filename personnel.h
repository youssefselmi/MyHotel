#ifndef PERSONNEL_H
#define PERSONNEL_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>

class PERSONNEL
{
public:
    PERSONNEL();
    PERSONNEL(int,QString,int,int,QString);
    int get_cin();
    QString get_grade();
    int get_presence();
    int get_salaire();
    QString get_date();
    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer (int);


private:
    QString grade,date;
    int presence,salaire;
    int cin;


};

#endif // PERSONNEL_H
