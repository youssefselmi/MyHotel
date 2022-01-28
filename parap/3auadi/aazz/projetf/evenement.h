#ifndef EVENEMENT_H
#define EVENEMENT_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>


class evenement
{
public:
    evenement();
    evenement (int , QString, QString,int );
    int get_id();
    QString get_type();
    QString get_date();
    int get_nbrE();
   bool ajoutE();
   QSqlQueryModel * afficherE();
   bool suppE(int);
   bool modifE(int , QString,QString,int);


private :
   QString type,date ;
   int id,nbrE ;
};

#endif // EVENEMENT_H
