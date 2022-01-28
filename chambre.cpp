#include "chambre.h"

chambre::chambre()
{
NUM=0;
EtatChambre="";
TypeChambre="";
CAPACITE=0;
}
chambre::chambre(int num,QString etat,QString type,int cap)
{
NUM=num;
EtatChambre=etat;
TypeChambre=type;
CAPACITE=cap;
}
bool chambre::ajouterCH(){

QSqlQuery query;
QString Num= QString::number(NUM);
QString Cap= QString::number(CAPACITE);
query.prepare("INSERT INTO CHAMBRE(NUM_CHAMBRE,TYPE_CHAMBRE,ETAT_CHAMBRE,CAPACITE)"
              " VALUES (:num,:typeC,:etat,:cap)");
query.bindValue(":num",Num);
query.bindValue(":typeC",TypeChambre);
query.bindValue(":etat",EtatChambre);
query.bindValue(":cap",CAPACITE);


return query.exec();
}
