#include "equipement.h"
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QDebug>
#include "qcustomplot.h"


Equipement::Equipement()
{
id=0;
type="";
nb=0;
idanimation=0;
}

Equipement::Equipement(int id,QString type,int nb,int idanimation)
{
this->id=id;
this->type=type;
this->nb=nb;
this->idanimation=idanimation;


}

int Equipement::get_id(){return id;}
int Equipement::get_idanimation(){return idanimation;}
QString Equipement::get_type(){return type;}

int Equipement::get_nb(){return nb;}








bool Equipement::ajout()
{
QSqlQuery query;
QString res= QString::number(id);
query.prepare("INSERT INTO equipement (TYPE, NB, IDANIMATION) "
                    "VALUES (:type, :nb, :idanimation)");
query.bindValue(":id", res);
query.bindValue(":type", type);
query.bindValue(":nb", nb);
query.bindValue(":idanimation", idanimation);

return    query.exec();
}







QSqlQueryModel * Equipement::afficher_2()
{QSqlQueryModel * model= new QSqlQueryModel();
model->setQuery("select * from equipement");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("TYPE "));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("NOMBRE"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("IDANIMATION"));

    return model;
}









bool Equipement::supprimer_2(int idd)
{
QSqlQuery query;
QString res= QString::number(idd);
query.prepare("Delete from equipement where ID = :id ");
query.bindValue(":id", res);
return    query.exec();
}






bool Equipement::modifier_2(int ide)
{
    QSqlQuery query;
    QString res= QString::number(ide);
    query.prepare("UPDATE equipement SET TYPE = :type,NB = :nb,IDANIMATION = :idanimation where ID = :ide");
    query.bindValue(":type",type);
    query.bindValue(":nb",nb);
    query.bindValue(":idanimation",idanimation);
    query.bindValue(":ide", res);
    return    query.exec();
}


QSqlQueryModel * Equipement::recherche_2(const QString &ide)
{
    QSqlQueryModel* model = new QSqlQueryModel();
     model->setQuery("select * from equipement where (ID LIKE '"+ide+"%') ");
     model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
     model->setHeaderData(1, Qt::Horizontal, QObject::tr("TYPE "));
     model->setHeaderData(2, Qt::Horizontal, QObject::tr("NB"));
     model->setHeaderData(5, Qt::Horizontal, QObject::tr("IDANIMATION"));
         return model;
}



QSqlQueryModel * Equipement::afficherdesc_2()
{QSqlQueryModel * model= new QSqlQueryModel();
model->setQuery("select * from equipement order by ID desc");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("TYPE "));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("NOMBRE"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("IDANIMATION"));
    return model;
}

QSqlQueryModel * Equipement::afficherasc_2()
{QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("select * from equipement order by ID asc");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("TYPE "));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("NOMBRE"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("IDANIMATION"));
    return model;
}




QVector<double> Equipement:: statistique()
{
    QSqlQuery q;
    QVector<double> stat(12);
    stat[0]=0;
    stat[1]=0;
    stat[2]=0;
    stat[3]=0;
    stat[4]=0;
    stat[5]=0;
    stat[6]=0;
    stat[7]=0;
    stat[8]=0;
    stat[9]=0;
    stat[10]=0;
    stat[11]=0;

    q.prepare("select * FROM equipement WHERE NB<=100 and 1<=NB");
    q.exec();
    while (q.next())
    {
        stat[0]++;
    }

    q.prepare("select * FROM equipement WHERE 100<=NB and NB<=1");
    q.exec();
    while (q.next())
    {
        stat[1]++;
    }
    q.prepare("select * FROM equipement WHERE NB<=100 and 1<=NB");
     q.exec();
     while (q.next())
     {
         stat[2]++;
     }

    q.prepare("select * FROM equipement WHERE NB<=100 and 1<=NB");
     q.exec();
     while (q.next())
     {
         stat[3]++;
     }

     q.prepare("select * FROM equipement WHERE NB<=100 and 1<=NB");
     q.exec();
     while (q.next())
     {
         stat[4]++;
     }
     q.prepare("select * FROM equipement WHERE NB<=100 and 1<=NB");
     q.exec();
     while (q.next())
     {
         stat[5]++;
     }
     q.prepare("select * FROM equipement WHERE NB<=100 and 1<=NB");
     q.exec();
     while (q.next())
     {
         stat[6]++;
     }
     q.prepare("select * FROM equipement WHERE NB<=100 and 1<=NB");
     q.exec();
     while (q.next())
     {
         stat[7]++;
     }
     q.prepare("select * FROM equipement WHERE NB<=100 and 1<=NB");
     q.exec();
     while (q.next())
     {
         stat[8]++;
     }
     q.prepare("select * FROM equipement WHERE NB<=100 and 1<=NB");
     q.exec();
     while (q.next())
     {
         stat[9]++;
     }
     q.prepare("select * FROM equipement WHERE NB<=100 and 1<=NB");
     q.exec();
     while (q.next())
     {
         stat[10]++;
     }
     q.prepare("select * FROM equipement WHERE NB<=100 and 1<=NB");
     q.exec();
     while (q.next())
     {
         stat[11]++;
     }
     return stat;

}

















