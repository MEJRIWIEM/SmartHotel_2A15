#include "client.h"
#include<QMessageBox>
#include <QSqlQuery>
#include"connexion.h"

#include <QSqlQueryModel>

Client::Client()
{
    cin =0;
    nom="";
    prenom="";
}
Client::Client(int cin ,QString nom ,QString prenom,QString adresse,QString pays,QString civilite,
               QString email,int cp,int num,int num2, QDateTime dat)
{
    this->cin=cin;
    this->nom=nom;
    this->prenom=prenom;
    this->adresse=adresse;
    this->pays=pays;
    this->civilite=civilite;
    this->email=email;
    this->cp=cp;
    this->num=num;
    this->num2=num2;
    this->dat=dat;

}
bool Client::ajouter ()
{
    QSqlQuery query ;
    QString res = QString::number(cin);
    query.prepare("INSERT INTO client (cin ,nom, prenom,adresse,email,cp,num,pays,civilite,num2,dat) "
                  "VALUES (:cin,:nom,:prenom,:adresse,:email,:cp,:num,:pays,:civilite,:num2,:dat)");
    query.bindValue(":cin", res);
    query.bindValue(":nom", nom);
    query.bindValue(":prenom", prenom);
    query.bindValue(":adresse", adresse);
    query.bindValue(":email", email);
    query.bindValue(":cp", cp);
    query.bindValue(":num", num);
    query.bindValue(":pays", pays);
    query.bindValue(":civilite", civilite);
    query.bindValue(":num2", num2);
    query.bindValue(":dat", dat);

    return query.exec();

}
/*QSqlQueryModel * Client::afficher()
{
  QSqlQueryModel * model =new QSqlQueryModel();
  model->setQuery("select * client");
  model->setHeaderData(0, Qt::Horizontal , QObject::tr("cin"));
  model->setHeaderData(1, Qt::Horizontal , QObject::tr("nom"));
  model->setHeaderData(2, Qt::Horizontal , QObject::tr("prenom"));
  model->setHeaderData(3, Qt::Horizontal , QObject::tr("adresse"));
  model->setHeaderData(4, Qt::Horizontal , QObject::tr("email"));
  model->setHeaderData(5, Qt::Horizontal , QObject::tr("cp"));
  model->setHeaderData(6, Qt::Horizontal , QObject::tr("num"));
  model->setHeaderData(7, Qt::Horizontal , QObject::tr("pays"));
  model->setHeaderData(8, Qt::Horizontal , QObject::tr("civilite"));
  model->setHeaderData(9, Qt::Horizontal , QObject::tr("num2"));
  return model ;
}*/

bool Client::supprimer(int idd)
{
QSqlQuery query ;
QString res = QString::number(idd);
query.prepare("Delete from client where cin= :cin");
query.bindValue(":cin",res);

return query.exec();
}
bool Client::modifier ()
{
    QSqlQuery query ;
    QString res = QString::number(cin);
    query.prepare("UPDATE client set cin = :cin, nom = :nom,prenom = :prenom,adresse=:adresse,email=:email,cp=:cp,num=:num,pays=:pays,civilite=:civilite,num2=:num2,dat=:dat WHERE cin=:cin");
    query.bindValue(":cin", res);
    query.bindValue(":nom", nom);
    query.bindValue(":prenom", prenom);
    query.bindValue(":adresse", adresse);
    query.bindValue(":email", email);
    query.bindValue(":cp", cp);
     query.bindValue(":num", num);
     query.bindValue(":pays", pays);
     query.bindValue(":civilite", civilite);
     query.bindValue(":num2", num2);
     query.bindValue(":dat",dat);

    return query.exec();
}
QSqlQueryModel * Client::afficher()
{
  QSqlQueryModel * model =new QSqlQueryModel();
  model->setQuery("select * from client");
  model->setHeaderData(0, Qt::Horizontal , QObject::tr("ID"));
  model->setHeaderData(1, Qt::Horizontal , QObject::tr("Nom"));
  model->setHeaderData(2, Qt::Horizontal , QObject::tr("Prénom"));
  model->setHeaderData(3, Qt::Horizontal , QObject::tr("Prénom"));
  return model ;
}

QSqlQueryModel * Client::afficher_rech(QString ch)
{
  QSqlQueryModel * model =new QSqlQueryModel();
  model->setQuery("SELECT * FROM client  where nom='"+ch+"' or prenom='"+ch+"' or pays='"+ch+"' or adresse='"+ch+"' or prenom='"+ch+"' or email='"+ch+"' or civilite='"+ch+"'");
  model->setHeaderData(0, Qt::Horizontal , QObject::tr("ID"));
  model->setHeaderData(1, Qt::Horizontal , QObject::tr("Nom"));
  model->setHeaderData(2, Qt::Horizontal , QObject::tr("Prénom"));
  model->setHeaderData(3, Qt::Horizontal , QObject::tr("Adresse"));
  return model ;
}

QSqlQueryModel * Client::afficher_choix(QString choix)
{
    QSqlQueryModel * model =new QSqlQueryModel();

    if (choix=="Alphabétique")

    {

           model->setQuery("SELECT * FROM client  ORDER BY nom;");

    }
    else if(choix=="Age croissant")
    {
        model->setQuery("SELECT * FROM client  ORDER BY dat DESC;");
    }
    else if(choix=="Age décroissant")
    {
        model->setQuery("SELECT * FROM client  ORDER BY dat ASC;");
    }
    else if (choix=="Choisir")
    {
        model->setQuery("SELECT * FROM client ");
    }
    model->setHeaderData(0, Qt::Horizontal , QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal , QObject::tr("Nom"));
    model->setHeaderData(2, Qt::Horizontal , QObject::tr("Prénom"));
    model->setHeaderData(3, Qt::Horizontal , QObject::tr("Adresse"));


    return model;
}
