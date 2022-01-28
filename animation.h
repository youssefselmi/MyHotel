#ifndef ANIMATION_H
#define ANIMATION_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>


class Animation
{
public:
    Animation();
    Animation(int,QString,QString,QString,int,int);

    int get_idanim();
    QString get_typeanim();
    QString get_lieu();
    QString get_dateanim();
    int get_duree();
    int get_cin();
     bool ajouter();
     QSqlQueryModel * afficher();
     QSqlQueryModel * afficherasc();
     QSqlQueryModel * afficherdesc();

     bool supprimer(int);
     bool modifier(int);
     QSqlQueryModel * recherche(const QString&);




private:
    QString typeanim,lieu,dateanim;
    int idanim,duree,cin;
};

#endif // ANIMATION_H
