#ifndef RECLAMATION_H
#define RECLAMATION_H
#include <QString>
#include <QSqlQueryModel>
#include <QSqlQuery>
#include<QDate>
class Reclamation
{
public:
     Reclamation();
     Reclamation(int,QString,QString,QString,QString,QString,int,QString);


     bool ajouter ();
     QSqlQueryModel * afficher();
     QSqlQueryModel * afficher_rech(QString);
     QSqlQueryModel * afficher_choix(QString);
     bool supprimer(int);
     bool modifier ();
      QSqlQueryModel * afficher_id();
     QSqlQueryModel * afficher_email();

private :
     QString nom_client,prenom_client,email_client,email_respon,objet,rec;
     int cin_client,identifiant;
     QDate dat;


};

#endif // RECLAMATION_H
