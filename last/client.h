#ifndef CLIENT_H
#define CLIENT_H
#include <QString>
#include <QSqlQueryModel>
#include <QSqlQuery>
#include<qdatetime.h>

class Client
{
public:
     Client();
     Client(QString,QString,QString,QString,QString,QString,QString,int,int,int, QDateTime);
     QString get_nom();
     QString get_prenom();
     QString get_adresse();
     QString get_pays();
     QString get_civilite();
     QString get_email();
     QString get_date();
     int get_cin();
     int get_num();
     int get_num2();
     bool ajouter ();
     QSqlQueryModel * afficher();
     QSqlQueryModel * afficher_rech(QString);
     QSqlQueryModel * afficher_choix(QString);
     bool supprimer(int);
     bool modifier ();


     //QSqlQueryModel *  afficher_recherche();
private :

     QString nom,prenom,adresse,pays,civilite,email,date,cin;
     int num,num2,cp ;
     QDateTime dat;
};

#endif // CLIENT_H
