#include "dialog.h"
#include "ui_dialog.h"
#include "client.h"
#include "reclamation.h"
#include<QMessageBox>
#include<QComboBox>
#include <QString>
#include"connexion.h"
#include<QDebug>
#include"mainwindow.h"
#include<QDateTime>
#include<QDate>
#include <QtWidgets/QMainWindow>
/* #include <QtCharts/QChartView>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QLegend>
#include <QtCharts/QBarCategoryAxis>
#include <QtCharts/QHorizontalStackedBarSeries>
#include <QtCharts/QLineSeries>
#include <QtCharts/QCategoryAxis>
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>
#include "qcustomplot.h"*/
Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    ui->change->setModel(tmpreclamation.afficher_id());
    ui->comboBox_14->setModel(tmpreclamation.afficher_email());
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_pushButton_clicked()
{
     ui->stackedWidget->setCurrentIndex(1);
}

void Dialog::on_pushButton_3_clicked()
{
    //L'ajout
    QString cin = ui->lineEdit->text();
    QString nom= ui->lineEdit_2->text();
    QString prenom= ui->lineEdit_3->text();
    QString adresse=ui->lineEdit_7->text();
    QString pays=ui->comboBox->currentText();
    QString civilite=ui->comboBox_2->currentText();
    QString email=ui->lineEdit_9->text();
    int cp=ui->lineEdit_8->text().toInt();
    int num=ui->lineEdit_10->text().toInt();
    int num2=ui->lineEdit_11->text().toInt();
    QDateTime dat=ui->dateEdit->dateTime();
    bool test1=(controleEmail(email)&&controlenum(num)&&controlenum(num2)&&controleVide(nom)
                &&controleVide(prenom)&&controleVide(adresse));


   Client c(cin ,nom ,prenom,adresse,pays,civilite,
             email, cp,num, num2,dat);
   bool test =c.ajouter();

   if (test&&test1)
   {
       QMessageBox::information(nullptr, QObject::tr("Ajouter un client "),
                                  QObject::tr("client  ajouté.\n"
                                              "Click Cancel to exit."), QMessageBox::Cancel);
   }
   else
   {
       QMessageBox::information(nullptr, QObject::tr("Ajouter un client "),
                                  QObject::tr("client non ajouté, vérifier les champs.\n"
                                              "Click Cancel to exit."), QMessageBox::Cancel);
   }

}


void Dialog::on_pushButton_6_clicked()
{
    //L'AFFICHER l ghalet
    ui->stackedWidget->setCurrentIndex(2);
    Connexion conn;

    QSqlQueryModel * modal= new QSqlQueryModel();
    QSqlQuery* qry= new QSqlQuery(conn.db);
    if(true)
    qry->prepare("select * from client");
    qry->exec();
    modal->setQuery(*qry);
    ui->tableView->setModel(modal);
    conn.fermerConnexion();
    qDebug()<<(modal->rowCount());
}

void Dialog::on_pushButton_15_clicked()
{
     ui->stackedWidget->setCurrentIndex(0);
}

void Dialog::on_pushButton_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);


}

void Dialog::on_pushButton_8_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void Dialog::on_pushButton_10_clicked()
{
    ui->stackedWidget->setCurrentIndex(5);
    Connexion conn;
    QSqlQueryModel * modal= new QSqlQueryModel();
    QSqlQuery* qry= new QSqlQuery(conn.db);
    if(true)
    qry->prepare("select * from reclamation");
    qry->exec();
    modal->setQuery(*qry);
    ui->tableView_2->setModel(modal);
    conn.fermerConnexion();
    qDebug()<<(modal->rowCount());
}

void Dialog::on_pushButton_16_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void Dialog::on_pushButton_14_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);
}


void Dialog::on_tableView_activated(const QModelIndex &index)
{


   QString val=ui->tableView->model()->data(index).toString();
   Connexion conn;


   QSqlQuery qry;
   qry.prepare("select * from client where cin='"+val+"'");
   if (qry.exec())
   {
       while(qry.next())
       {
           /*
    int cin = ui->lineEdit->text().toInt();
    QString nom= ui->lineEdit_2->text();
    QString prenom= ui->lineEdit_3->text();
    QString adresse=ui->lineEdit_7->text();
    QString pays=ui->comboBox->currentText();
    QString civilite=ui->comboBox_2->currentText();
    QString email=ui->lineEdit_9->text();
    int cp=ui->lineEdit_8->text().toInt();
    int num=ui->lineEdit_10->text().toInt();
    int num2=ui->lineEdit_11->text().toInt();
    QDateTime dat=ui->dateEdit->dateTime();*/
           ui->stackedWidget->setCurrentIndex(1);
           ui->lineEdit->setText(qry.value(0).toString());//cin
           ui->lineEdit_2->setText(qry.value(1).toString());//nom
             ui->lineEdit_3->setText(qry.value(2).toString());//prenom
             ui->lineEdit_7->setText(qry.value(3).toString());//adresse
             ui->lineEdit_9->setText(qry.value(4).toString());//email
             ui->lineEdit_8->setText(qry.value(5).toString());//cp
             ui->lineEdit_10->setText(qry.value(6).toString());//num
             ui->comboBox->setCurrentText(qry.value(7).toString());//pays
              ui->comboBox_2->setCurrentText(qry.value(8).toString());//civi
               ui->lineEdit_11->setText(qry.value(10).toString());//num2
               ui->dateEdit->setDate(qry.value(9).toDate());



       }
}
}

/*void Dialog::on_pushButton_4_clicked()
{
    int cin = ui->lineEdit_4->text().toInt();
    QString nom= ui->lineEdit_5->text();
    QString prenom= ui->lineEdit_6->text();
    QString adresse=ui->lineEdit_12->text();
    QString pays=ui->comboBox_4->currentText();
    QString civilite=ui->comboBox_3->currentText();
    QString email=ui->lineEdit_14->text();
    int cp=ui->lineEdit_13->text().toInt();
    int num=ui->lineEdit_15->text().toInt();
    int num2=ui->lineEdit_16->text().toInt();
    QDateTime dat=ui->dateEdit_2->dateTime();
   Client c(cin ,nom ,prenom,adresse,pays,civilite,
            email, cp,num, num2,dat);

    bool test = c.modifier();
    if (test)
    {

        QMessageBox::information(nullptr, QObject::tr("modifier un client"),
                                   QObject::tr("client modifié.\n"
                                               "Click Cancel to exit."), QMessageBox::Cancel);
    }

    ui->stackedWidget->setCurrentIndex(1);
}
*/

/*void Dialog::on_pushButton_5_clicked()
{
    int id =ui->lineEdit_4->text().toUInt();
    bool test = tmpclient.supprimer(id);
    if (test)
    {

        QMessageBox::information(nullptr, QObject::tr("supprimer un client "),
                                   QObject::tr("client supprimé.\n"
                                               "Click Cancel to exit."), QMessageBox::Cancel);
    }
    ui->stackedWidget->setCurrentIndex(1);
}*/


void Dialog::on_pushButton_7_clicked()
{
    QString val=ui->lineEdit_17->text();
    if(val!="")
    ui->tableView->setModel(tmpclient.afficher_rech(val));
}

void Dialog::on_comboBox_5_activated(const QString &arg1)
{

    QString choix=ui->comboBox_5->currentText();

    ui->tableView->setModel(tmpclient.afficher_choix(choix));
}

void Dialog::on_pushButton_9_clicked()
{
    int identifiant = ui->lineEdit_18->text().toInt();
    QString nom_client= ui->lineEdit_19->text();
    QString prenom_client= ui->lineEdit_20->text();
    QString email_client=ui->lineEdit_22->text();
    QString email_respon=ui->comboBox_14->currentText();
    QString objet=ui->lineEdit_24->text();
    int cin_client=ui->change->currentText().toUInt();
    QString rec=ui->lineEdit_25->text();
   Reclamation r(identifiant,nom_client,prenom_client, email_client,
                 email_respon,objet, cin_client, rec);
   bool test1=(controleEmail(email_respon)&&controleEmail(email_client)&&controlenum(identifiant)&&controlenum(cin_client)&&controleVide(prenom_client)&&controleVide(nom_client)
               &&controleVide(rec)&&controleVide(objet));

   bool test =r.ajouter();

   if (test&&test1)
   {   ui->tableView_2->setModel(tmpreclamation.afficher());
       QMessageBox::information(nullptr, QObject::tr("Ajouter une réclamation "),
                                  QObject::tr("reclamation  ajoutée.\n"
                                              "Click Cancel to exit."), QMessageBox::Cancel);
   }
   else
   {
       {   ui->tableView_2->setModel(tmpreclamation.afficher());
           QMessageBox::information(nullptr, QObject::tr("Ajouter une réclamation "),
                                      QObject::tr("reclamation non ajoutée, vérifiez les champs.\n"
                                                  "Click Cancel to exit."), QMessageBox::Cancel);
       }
   }
}

void Dialog::on_pushButton_13_clicked()
{

    QString val=ui->lineEdit_34->text();
    if(val!="")
    ui->tableView_2->setModel(tmpreclamation.afficher_rech(val));
}


void Dialog::on_comboBox_6_activated(const QString &arg1)
{
    QString choix=ui->comboBox_6->currentText();

    ui->tableView_2->setModel(tmpreclamation.afficher_choix(choix));
}

void Dialog::on_tableView_2_activated(const QModelIndex &index)
{
    QString val=ui->tableView_2->model()->data(index).toString();
    Connexion conn;


    QSqlQuery qry;
    qry.prepare("select * from reclamation where identifiant='"+val+"'");
    if (qry.exec())
    {
        while(qry.next())
        {
            /*int identifiant = ui->lineEdit_18->text().toInt();
    QString nom_client= ui->lineEdit_19->text();
    QString prenom_client= ui->lineEdit_20->text();
    QString email_client=ui->lineEdit_22->text();
    QString email_respon=ui->lineEdit_23->text();
    QString objet=ui->combo->text();
    int cin_client=ui->lineEdit_21->text().toInt();
    QString rec=ui->lineEdit_25->text();*/
            ui->stackedWidget->setCurrentIndex(4);
            ui->lineEdit_18->setText(qry.value(0).toString());//iden
            ui->lineEdit_19->setText(qry.value(1).toString());//nom
              ui->lineEdit_20->setText(qry.value(2).toString());//prenom
              ui->lineEdit_22->setText(qry.value(3).toString());//emailClient
              ui->comboBox_14->setCurrentText(qry.value(4).toString());//emailRes
              ui->lineEdit_24->setText(qry.value(5).toString());//objet
              ui->change->setCurrentText(qry.value(6).toString());//cinclient
              ui->lineEdit_25->setText(qry.value(7).toString());//rec




        }
}
}


/*void Dialog::on_pushButton_11_clicked()
{
    int identifiant = ui->lineEdit_26->text().toInt();
    QString nom_client= ui->lineEdit_27->text();
    QString prenom_client= ui->lineEdit_28->text();
    QString email_client=ui->lineEdit_30->text();
    QString email_respon=ui->comboBox_14->currentText();;
    QString objet=ui->lineEdit_32->text();
    int cin_client=ui->comboBox_13->currentText().toUInt();
    QString rec=ui->lineEdit_33->text();

    Reclamation r(identifiant,nom_client,prenom_client, email_client,
                  email_respon,objet, cin_client, rec);

    bool test = r.modifier();
    if (test)
    {

        QMessageBox::information(nullptr, QObject::tr("Modifier une réclamation "),
                                   QObject::tr("Réclamation modifiée.\n"
                                               "Click Cancel to exit."), QMessageBox::Cancel);
    }

    ui->stackedWidget->setCurrentIndex(4);
}
*/
/*void Dialog::on_pushButton_12_clicked()
{
    int id =ui->lineEdit_26->text().toUInt();
    bool test = tmpreclamation.supprimer(id);
    if (test)
    {

        QMessageBox::information(nullptr, QObject::tr("supprimer une reclamation "),
                                   QObject::tr("reclamation supprimé.\n"
                                               "Click Cancel to exit."), QMessageBox::Cancel);
    }
    ui->stackedWidget->setCurrentIndex(4);
}*/

void Dialog::on_pushButton_33_clicked()
{
    //new modifier reclamation
    int identifiant = ui->lineEdit_18->text().toUInt();
    QString nom_client= ui->lineEdit_19->text();
    QString prenom_client= ui->lineEdit_20->text();
    QString email_client=ui->lineEdit_22->text();
    QString email_respon=ui->comboBox_14->currentText();
    QString objet=ui->lineEdit_24->text();
    int cin_client=ui->change->currentText().toUInt();
    QString rec=ui->lineEdit_25->text();


    Reclamation r(identifiant,nom_client,prenom_client, email_client,
                  email_respon,objet, cin_client, rec);
    bool test1=(controleEmail(email_respon)&&controleEmail(email_client)&&controlenum(identifiant)&&controlenum(cin_client)&&controleVide(prenom_client)&&controleVide(nom_client)
                &&controleVide(rec)&&controleVide(objet));
    bool test = r.modifier();
    if (test&&test1)
    {

        QMessageBox::information(nullptr, QObject::tr("Modifier une réclamation "),
                                   QObject::tr("Réclamation modifiée.\n"
                                               "Click Cancel to exit."), QMessageBox::Cancel);
    }
    else
    {
        QMessageBox::information(nullptr, QObject::tr("Modifier une réclamation "),
                                   QObject::tr("Réclamation non modifiée, vérifiez les champs.\n"
                                               "Click Cancel to exit."), QMessageBox::Cancel);
    }

    ui->stackedWidget->setCurrentIndex(4);
}

void Dialog::on_pushButton_34_clicked()
{
    //new supprimer reclamation
    int id =ui->lineEdit_18->text().toUInt();
    bool test = tmpreclamation.supprimer(id);
    if (test)
    {

        QMessageBox::information(nullptr, QObject::tr("supprimer une reclamation "),
                                   QObject::tr("reclamation supprimé.\n"
                                               "Click Cancel to exit."), QMessageBox::Cancel);
    }
    ui->stackedWidget->setCurrentIndex(4);
}

void Dialog::on_pushButton_35_clicked()
{

    //modifier client new
    QString cin = ui->lineEdit->text();
    QString nom= ui->lineEdit_2->text();
    QString prenom= ui->lineEdit_3->text();
    QString adresse=ui->lineEdit_7->text();
    QString pays=ui->comboBox->currentText();
    QString civilite=ui->comboBox_2->currentText();
    QString email=ui->lineEdit_9->text();
    int cp=ui->lineEdit_8->text().toInt();
    int num=ui->lineEdit_10->text().toInt();
    int num2=ui->lineEdit_11->text().toInt();
    QDateTime dat=ui->dateEdit->dateTime();
   Client c(cin ,nom ,prenom,adresse,pays,civilite,
             email, cp,num, num2,dat);

   bool test1=(controleEmail(email)&&controlenum(num)&&controlenum(num2)&&controleVide(nom)
               &&controleVide(prenom)&&controleVide(adresse));

    bool test = c.modifier();
    if (test&&test1)
    {

        QMessageBox::information(nullptr, QObject::tr("modifier un client"),
                                   QObject::tr("client modifié.\n"
                                               "Click Cancel to exit."), QMessageBox::Cancel);
    }
    else
    {
        QMessageBox::information(nullptr, QObject::tr("modifier un client"),
                                   QObject::tr("client non modifié, vérifier les champs.\n"
                                               "Click Cancel to exit."), QMessageBox::Cancel);
    }



}

void Dialog::on_pushButton_36_clicked()
{
    //supprimer client new
    int id =ui->lineEdit->text().toUInt();
    bool test = tmpclient.supprimer(id);
    if (test)
    {

        QMessageBox::information(nullptr, QObject::tr("supprimer un client "),
                                   QObject::tr("client supprimé.\n"
                                               "Click Cancel to exit."), QMessageBox::Cancel);
    }

}

void Dialog::on_pushButton_39_clicked()
{
     ui->stackedWidget->setCurrentIndex(0);
}

void Dialog::on_pushButton_37_clicked()
{
     ui->stackedWidget->setCurrentIndex(0);
}





/*
void Dialog::on_comboBox_13_currentIndexChanged(const QString &arg1)
{

    QSqlQueryModel * modal= new QSqlQueryModel();
    QSqlQuery* qry= new QSqlQuery(conn.db);
    if(true)
    qry->prepare("select * from client");
    qry->exec();
    modal->setQuery(*qry);
    ui->tableView->setModel(modal);
    conn.fermerConnexion();
    qDebug()<<(modal->rowCount())
    Connexion conn;
    QString n=ui->comboBox_13->currentText();
    QSqlQueryModel * modal= new QSqlQueryModel();
    QSqlQuery* qry= new QSqlQuery(conn.db);
    if(true)

    qry->prepare("select * from client where name='"+n+"'");
    qry->exec();
    modal->setQuery(*qry);
    ui->comboBox_13->setModel(modal);
    if(qry->exec())
    {
        while(qry->next())
        {
            ui->stackedWidget->setCurrentIndex(4);
            ui->lineEdit_18->setText(qry->value(0).toString());//iden
            ui->lineEdit_19->setText(qry->value(1).toString());//nom
              ui->lineEdit_20->setText(qry->value(2).toString());//prenom
              ui->lineEdit_22->setText(qry->value(3).toString());//emailClient
              ui->lineEdit_23->setText(qry->value(4).toString());//emailRes
              ui->lineEdit_24->setText(qry->value(5).toString());//objet
              ui->lineEdit_21->setText(qry->value(6).toString());//cinclient
              ui->lineEdit_25->setText(qry->value(6).toString());//rec
        }
    }
}
*/


void Dialog::on_pushButton_40_clicked()
{
    Smtp* smtp = new Smtp(ui->uname->text(), ui->paswd->text(), ui->server->text(), ui->port->text().toUShort());
        connect(smtp, SIGNAL(status(QString)), this, SLOT(mailSent(QString)));


        smtp->sendMail(ui->uname->text(), ui->lineEdit_23->text() , ui->lineEdit_24->text(),ui->lineEdit_25->text());
    QString status;

}
bool Dialog::controleEmail(QString test)
{
    for(int i=0;i<test.length();i++)
    {
        if (test.at(i)=='@')
        {
            return true;
        }
    }
    return false;
}
bool Dialog::controlenum(int test)
{
    QString tel= QString::number(test);
    for(int i=0;i<tel.length();i++)
    {
        if (tel.length()==8)
        {
            return true;
        }
    }
    return false;
}
bool Dialog::controleVide(QString test)
{
    if(test!="")
        return  true;
    return false;

}

void Dialog::on_comboBox_13_currentIndexChanged(int index)
{

}

/*void Dialog::on_comboBox_13_currentIndexChanged(const QString &arg1)
{

    QString name=ui->change->currentText();
    Connexion conn;

    QSqlQuery qry;
    qry.prepare("select nom from client where cin='"+name+"'");
    qDebug()<<"Failed to open DataBase";
    if(qry.exec())
    {
        while(qry.next())
        {
            ui->lineEdit_19->setText(qry.value(1).toString());
                   /*  ui->lineEdit_20->setText(qry.value(2).toString());
                     ui->lineEdit_22->setText(qry.value(3).toString());*/









void Dialog::on_change_currentIndexChanged(const QString &arg1)
{
    QString name=ui->change->currentText();
    Connexion conn;

    QSqlQuery qry;
    qry.prepare("select * from client where cin='"+name+"'");

    if(qry.exec())
    {
        while(qry.next())
        {
                     ui->lineEdit_19->setText(qry.value(1).toString());
                     ui->lineEdit_20->setText(qry.value(2).toString());
                     ui->lineEdit_22->setText(qry.value(3).toString());

        }

    }

}
