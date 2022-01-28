#include "evenement.h"
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>

evenement::evenement()
{
 id=0;
 type="";
 date="";
 nbrE=0;
 }
evenement::evenement(/*int id ,*/QString type ,QString date ,int nbrE)
{
    this->type=type;
    this->date=date;
    this->nbrE=nbrE;
}
//int evenement::get_id(){return id;}
QString evenement::get_type(){return type;}
QString evenement::get_date(){return date;}
int evenement::get_nbrE(){return nbrE;}

bool evenement::ajoutE()
{
    QSqlQuery query;
  //  QString res=QString::number(id);
    QString res1=QString::number(nbrE);
    query.prepare("INSERT INTO EVENEMENT( TYPEEVE ,DATEEVE ,NBEVE) VALUES ( :type , :date ,:nbrE) ");
   // query.bindValue(":id" ,id);
    query.bindValue(":type" ,type);
    query.bindValue(":date" ,date);
    query.bindValue(":nbrE" ,nbrE);
    return query.exec();
}

QSqlQueryModel * evenement::afficherE()
{
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("select * from EVENEMENT");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("id"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("type"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("date"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("nombre"));


    return model;
}

bool evenement::suppE(int idd)
{
    QSqlQuery query;
    QString res=QString::number(idd);
    query.prepare("delete from EVENEMENT where IDEVE= :id");
    query.bindValue(":id",res);
    return query.exec();
}

bool evenement::modifE(int id,QString type,QString date,int nbr)
{
    QSqlQuery query;
    QString res=QString::number(id);
    QString res2=QString::number(nbr);

    query.prepare("update EVENEMENT set TYPEEVE=:type,DATEEVE=:date,NBEVE=:nbr where IDEVE= :id");
    query.bindValue(":id",res);
    query.bindValue(":type",type);
    query.bindValue(":date",date);
    query.bindValue(":nbr",res2);



    return query.exec();
}
