#include "reclamation.h"
#include <QSqlQueryModel>
#include<QMessageBox>
#include <QSqlQuery>
Reclamation::Reclamation()
{
    cin_client=0;

}

Reclamation::Reclamation(int identifiant,QString nom_client,QString prenom_client,QString email_client,QString email_respon,QString objet,int cin_client,QString rec)
{
    this->identifiant=identifiant;
    this->nom_client=nom_client;
    this->prenom_client=prenom_client;
    this->email_client=email_client;
    this->email_respon=email_respon;
    this->objet=objet;
    this->cin_client=cin_client;
    this->rec=rec;
}

 bool Reclamation::ajouter ()
 {
     QSqlQuery query ;
     QString res = QString::number(identifiant);
     query.prepare("INSERT INTO reclamation (identifiant,nom_client,prenom_client,email_client,email_respon,objet,cin_client,rec) "
                   "VALUES (:identifiant,:nom_client,:prenom_client,:email_client,:email_respon,:objet,:cin_client,:rec)");
     query.bindValue(":identifiant", res);
     query.bindValue(":nom_client", nom_client);
     query.bindValue(":prenom_client", prenom_client);
     query.bindValue(":email_client", email_client);
     query.bindValue(":email_respon", email_respon);
     query.bindValue(":objet",objet);
     query.bindValue(":cin_client", cin_client);
     query.bindValue(":rec", rec);
     return query.exec();
 }

 bool Reclamation::supprimer(int idd)
 {
     QSqlQuery query ;
     QString res = QString::number(idd);
     query.prepare("Delete from reclamation where identifiant= :identifiant");
     query.bindValue(":identifiant",res);
     return query.exec();
 }
 bool  Reclamation::modifier()
 {
     QSqlQuery query ;
     QString res = QString::number(identifiant);
     query.prepare("UPDATE reclamation set identifiant=:identifiant ,nom_client=:nom_client,prenom_client=:prenom_client,email_client=:email_client,email_respon=:email_respon,objet=:objet,cin_client=:cin_client,rec=:rec where identifiant=:identifiant");
     query.bindValue(":identifiant", res);
     query.bindValue(":nom_client", nom_client);
     query.bindValue(":prenom_client", prenom_client);
     query.bindValue(":email_client", email_client);
     query.bindValue(":email_respon", email_respon);
     query.bindValue(":objet", objet);
     query.bindValue(":cin_client", cin_client);
     query.bindValue(":rec", rec);
     return query.exec();
 }
 QSqlQueryModel * Reclamation::afficher()
 {
   QSqlQueryModel * model =new QSqlQueryModel();
   model->setQuery("select * from reclamation");
   model->setHeaderData(0, Qt::Horizontal , QObject::tr("Identifiant "));
   model->setHeaderData(1, Qt::Horizontal , QObject::tr("Nom client"));
   model->setHeaderData(2, Qt::Horizontal , QObject::tr("Prénom client"));
   model->setHeaderData(3, Qt::Horizontal , QObject::tr("Email client"));
   return model ;
 }

 QSqlQueryModel * Reclamation::afficher_rech(QString ch)
 {
     QSqlQueryModel * model =new QSqlQueryModel();
     model->setQuery("SELECT * FROM reclamation  where nom_client='"+ch+"' or prenom_client='"+ch+"' or email_client='"+ch+"' or email_respon='"+ch+"' or objet='"+ch+"' ");
     model->setHeaderData(0, Qt::Horizontal , QObject::tr("Identifiant"));
     model->setHeaderData(1, Qt::Horizontal , QObject::tr("Nom client"));
     model->setHeaderData(2, Qt::Horizontal , QObject::tr("Prénom client"));
     model->setHeaderData(3, Qt::Horizontal , QObject::tr("Email client"));
     return model ;
 }

 QSqlQueryModel * Reclamation::afficher_choix(QString choix)
 {
     QSqlQueryModel * model =new QSqlQueryModel();

     if (choix=="Alphabétique")

     {

            model->setQuery("SELECT * FROM reclamation  ORDER BY nom_client;");

     }
     else if (choix=="Choisir")
     {
         model->setQuery("SELECT * FROM reclamation ");
     }
     model->setHeaderData(0, Qt::Horizontal , QObject::tr("Identifiant"));
     model->setHeaderData(1, Qt::Horizontal , QObject::tr("Nom client"));
     model->setHeaderData(2, Qt::Horizontal , QObject::tr("Prénom client"));
     model->setHeaderData(3, Qt::Horizontal , QObject::tr("Email client"));


     return model;
 }
 QSqlQueryModel * Reclamation::afficher_id()
 {
      QSqlQueryModel * model =new QSqlQueryModel();
      model->setQuery("select cin from client");
      return model ;

 }
 QSqlQueryModel * Reclamation::afficher_email()
 {
      QSqlQueryModel * model =new QSqlQueryModel();
      model->setQuery("select email from employes where id_departement=1");
      return model ;

 }

