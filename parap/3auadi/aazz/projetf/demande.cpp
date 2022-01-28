#include "demande.h"

demande::demande()
{
    TYPE_DEMANDE="";
    DATEDEBUT="";
    QUANTITE_DEMANDE=0;
    REF_DEMANDE=0;
    CIN=0;
    ETAT=0;
}

demande::demande(int QUANTITE_DEMANDE,int REF_DEMANDE,QString TYPE_DEMANDE,int CIN,int ETAT,QString DATEDEBUT)
{
   this->CIN=CIN;
    this->ETAT=ETAT;
    this->DATEDEBUT=DATEDEBUT;
    this->REF_DEMANDE=REF_DEMANDE;
    this->TYPE_DEMANDE=TYPE_DEMANDE;
    this->QUANTITE_DEMANDE=QUANTITE_DEMANDE;
}
int demande::get_cin(){return CIN;}
int demande::get_etat(){return ETAT;}
int demande::get_ref(){return REF_DEMANDE;}
int demande::get_quantite(){return QUANTITE_DEMANDE;}
QString demande::get_type(){return TYPE_DEMANDE;}
QString demande::get_date(){return DATEDEBUT;}

bool demande::ajouter_demande()
{
    QSqlQuery query;
    QString res=QString::number(CIN);
    query.prepare("INSERT INTO DEMANDE (REF_DEMANDE, QUANTITE_DEMANDE, TYPE_DEMANDE, CIN, ETAT, DATEDEBUT) VALUES (:REF_DEMANDE, :QUANTITE_DEMANDE, :TYPE_DEMANDE, :CIN, :ETAT, :DATEDEBUT)");
    query.bindValue(":QUANTITE_DEMANDE",QUANTITE_DEMANDE);
    query.bindValue(":REF_DEMANDE",REF_DEMANDE);
    query.bindValue(":TYPE_DEMANDE",TYPE_DEMANDE);
    query.bindValue(":CIN",res);
    query.bindValue(":ETAT",ETAT);
    query.bindValue(":DATEDEBUT",DATEDEBUT);
    return  query.exec();
}
QSqlQueryModel * demande::afficher_demande()
{QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("select * from DEMANDE");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("REF_DEMANDE"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("QUANTITE_DEMANDE"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("TYPE_DEMANDE"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("CIN"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("ETAT"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("DATEDEBUT"));

    return model;

}
bool demande::supprimer_demande(int cin)
{
    QSqlQuery query;
    QString res= QString::number(cin);
    query.prepare("delete from demande where CIN = :cin");
    query.bindValue(":cin",res);
    return query.exec();
}
