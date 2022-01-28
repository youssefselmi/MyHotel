#include "hebergement.h"

hebergement::hebergement()
{
    CIN=0;
    NB_personnes=0;
    Nom="";
    Prenom="";
    DateDEPART="";
    DateARRIVEE="";
    TypeChambre="";
    TypeReservation="";
    NumChambre=0;
}


hebergement::hebergement(int numChambre,int cin,int nb_perso,QString date_depart,QString date_arrive,QString typeChambre, QString typeReservation,QString Nom,QString Prenom){
 this->NB_personnes=nb_perso;
    this->DateDEPART=date_depart;
  this->DateARRIVEE=date_arrive;
    this->TypeChambre=typeChambre;
    this->TypeReservation=typeReservation;
    this->CIN=cin;
    this->Nom=Nom;
    this->Prenom=Prenom;
    this->NumChambre=numChambre;
}


bool hebergement::ajouterH(){

QSqlQuery query;
QString cin= QString::number(CIN);
QString NB_p= QString::number(NB_personnes);
QString N_chambre= QString::number(NumChambre);
query.prepare("INSERT INTO HEBERGEMENT(NBRPERSONNES,DATEARR,DATEDEP,TYPERES,TYPECHAMBRE,CIN,NOM,PRENOM,NUM_CHAMBRE)"
              " VALUES (:nbp,:DA,:DD,:TypeR,:TypeC,:cin,:nom,:prenom,:num)");
query.bindValue(":nbp",NB_p);
query.bindValue(":DA",DateARRIVEE);
query.bindValue(":DD",DateDEPART);
query.bindValue(":TypeC",TypeChambre);
query.bindValue(":TypeR",TypeReservation);
query.bindValue(":cin",CIN);
query.bindValue(":nom",Nom);
query.bindValue(":prenom",Prenom);
query.bindValue(":num",NumChambre);
return query.exec();
}
