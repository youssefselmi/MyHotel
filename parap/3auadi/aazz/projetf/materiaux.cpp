#include "materiaux.h"
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>

materiaux::materiaux()
{
 ref="";
 nbr=0;
 etat="";
}
materiaux::materiaux(QString ref,int nbr ,QString etat)
{
    this->ref=ref;
    this->nbr=nbr;
    this->etat=etat;
}
QString materiaux::get_ref(){return ref;}
int materiaux::get_nbr(){return nbr;}
QString materiaux::get_etat(){return etat;}
bool materiaux::ajout()
{
   QSqlQuery query;
   QString res=QString::number(nbr);
   query.prepare("INSERT INTO MATERIEL(REF_MAT , NBR_MAT ,ETAT_MAT ) VALUES (:ref , :nbr , :etat ) ");
   query.bindValue(":ref" ,ref);
   query.bindValue(":nbr" ,res);
   query.bindValue(":etat" ,etat);

return query.exec();
}
QSqlQueryModel * materiaux::afficher()
{
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("select * from MATERIEL");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("reference"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("nombre disponoble"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("etat du materiel"));

    return model;
}
bool materiaux::supp(int idd)
{
    QSqlQuery query;
    QString res=QString::number(idd);
    query.prepare("delete from MATERIEL where REF_MAT= :id");
    query.bindValue(":id",res);
    return query.exec();
}
bool materiaux::modif(QString id,int nbr)
{
    QSqlQuery query;
    QString res=QString::number(nbr);

    query.prepare("update MATERIEL set NBR_MAT=:bb where REF_MAT= :id");
    query.bindValue(":id",id);
    query.bindValue(":bb",res);


    return query.exec();
}
bool materiaux::modifEtat(QString id, QString etat)
{
    QSqlQuery query;

    query.prepare("update MATERIEL set ETAT_MAT=:aa where REF_MAT= :id");
    query.bindValue(":id",id);
    query.bindValue(":aa",etat);


    return query.exec();
}
