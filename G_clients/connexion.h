#ifndef CONNEXION_H
#define CONNEXION_H


#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include<QDebug>
class Connexion
{ public:

     QSqlDatabase db ;

    Connexion();

    bool createconnect();
    bool ouvrirConnexion()
    {
        db=QSqlDatabase::addDatabase("QODBC");
        db.setDatabaseName("test");
        if (!db.open())
        {
            qDebug()<<("Failed to open Database");
            return false;
        }
        else
           {
            qDebug()<<("Connected..");
            return true;
        }
    }
    void fermerConnexion()
    {
        db.close();
    }
};


#endif // CONNEXION_H
