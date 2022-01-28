#include "animation.h"
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QDebug>

Animation::Animation()
{

idanim=0;
typeanim="";
lieu="";
dateanim="";
duree=0;
cin=0;
}


Animation::Animation(int idanim,QString typeanim,QString lieu,QString dateanim,int duree,int cin)
{
this->idanim=idanim;
this->typeanim=typeanim;
this->lieu=lieu;
this->dateanim=dateanim;
this->duree=duree;
this->cin=cin;
}


int Animation::get_idanim(){return idanim;}
QString Animation::get_typeanim(){return typeanim;}
QString Animation::get_lieu(){return lieu;}
QString Animation::get_dateanim(){return dateanim;}
int Animation::get_duree(){return duree;}
int Animation::get_cin(){return cin;}



bool Animation::ajouter()
{
QSqlQuery query;
QString res= QString::number(idanim);
query.prepare("INSERT INTO animation (TYPEANIM, LIEU, DATEANIM, DUREE, CIN) "
                    "VALUES (:typeanim, :lieu, :dateanim, :duree, :cin)");
query.bindValue(":idanim", res);
query.bindValue(":typeanim", typeanim);
query.bindValue(":lieu", lieu);
query.bindValue(":dateanim", dateanim);
query.bindValue(":duree", duree);
query.bindValue(":cin", cin);



return    query.exec();
}


QSqlQueryModel * Animation::afficher()
{QSqlQueryModel * model= new QSqlQueryModel();
model->setQuery("select * from animation");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("IDANIM"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("TYPEANIM "));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("LIEU"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("DATEANIM"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("DUREE"));
model->setHeaderData(5, Qt::Horizontal, QObject::tr("CIN"));
    return model;
}


QSqlQueryModel * Animation::afficherasc()
{QSqlQueryModel * model= new QSqlQueryModel();
model->setQuery("select * from animation order by IDANIM asc");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("IDANIM"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("TYPEANIM "));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("LIEU"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("DATEANIM"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("DUREE"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("CIN"));
    return model;
}





bool Animation::supprimer(int idd)
{
QSqlQuery query;
QString res= QString::number(idd);
query.prepare("Delete from animation where IDANIM = :idanim ");
query.bindValue(":idanim", res);
return    query.exec();
}


bool Animation::modifier(int id)
{
    QSqlQuery query;
    QString res= QString::number(id);
    query.prepare("UPDATE animation SET TYPEANIM = :typeanim,LIEU = :lieu,DATEANIM = :dateanim,DUREE = :duree,CIN = :cin where IDANIM = :id");
    query.bindValue(":typeanim",typeanim);
    query.bindValue(":lieu",lieu);
    query.bindValue(":dateanim",dateanim);
    query.bindValue(":duree",duree);
    query.bindValue(":cin",cin);
    query.bindValue(":id", res);
    return    query.exec();
}



QSqlQueryModel * Animation::recherche(const QString &id)
{
    QSqlQueryModel* model = new QSqlQueryModel();
     model->setQuery("select * from animation where (IDANIM LIKE '"+id+"%') ");
     model->setHeaderData(0, Qt::Horizontal, QObject::tr("IDANIM"));
     model->setHeaderData(1, Qt::Horizontal, QObject::tr("TYPEANIM "));
     model->setHeaderData(2, Qt::Horizontal, QObject::tr("LIEU"));
     model->setHeaderData(3, Qt::Horizontal, QObject::tr("DATEANIM"));
     model->setHeaderData(4, Qt::Horizontal, QObject::tr("DUREE"));
     model->setHeaderData(5, Qt::Horizontal, QObject::tr("CIN"));
         return model;
}



QSqlQueryModel * Animation::afficherdesc()
{QSqlQueryModel * model= new QSqlQueryModel();
model->setQuery("select * from animation order by IDANIM desc");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("IDANIM"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("TYPEANIM "));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("LIEU"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("DATEANIM"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("DUREE"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("CIN"));
    return model;
}





