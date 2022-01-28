#include "personnel.h"

PERSONNEL::PERSONNEL()
{
cin=0;
grade="";
presence=0;
salaire=0;
date="";
}
PERSONNEL::PERSONNEL(int cin,QString grade,int presence,int salaire,QString date)
{
  this->cin=cin;
    this->grade=grade;
    this->presence=presence;
    this->salaire=salaire;
    this->date=date;
}
int PERSONNEL::get_cin(){return cin;}
QString PERSONNEL::get_grade(){return grade;}
int PERSONNEL::get_presence(){return presence;}
int PERSONNEL::get_salaire(){return salaire;}
QString PERSONNEL::get_date(){return date;}
bool PERSONNEL::ajouter()
{
    QSqlQuery query;
    QString res= QString::number(cin);
    query.prepare("INSERT INTO PERSONNEL (CIN ,GRADE,PRESENCE,SALAIRE,DATECONTRAT) VALUES (:cin,:grade,:presence,:salaire,:date)");
    query.bindValue(":cin",res);
    query.bindValue(":grade",grade);
    query.bindValue(":presence",presence);
    query.bindValue(":salaire",salaire);
    query.bindValue(":date",date);
    return  query.exec();

}
QSqlQueryModel * PERSONNEL::afficher()
{QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("select * from PERSONNEL");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("CIN"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("GRADE"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("PRESENCE"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("SALAIRE"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("DATECONTRAT"));

    return model;

}
bool PERSONNEL::supprimer(int cin)
{
    QSqlQuery query;
    QString res= QString::number(cin);
    query.prepare("delete from PERSONNEL where CIN = :cin");
    query.bindValue(":cin",res);
    return query.exec();
}
