#ifndef DIALOG_H
#define DIALOG_H
#include"client.h"
#include <QMainWindow>
#include"reclamation.h"
#include <QDialog>
#include "smtp.h"
namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = nullptr);
    ~Dialog();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_15_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_10_clicked();

    void on_pushButton_16_clicked();

    void on_pushButton_14_clicked();

    void on_tableView_activated(const QModelIndex &index);

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_7_clicked();

    void on_comboBox_5_activated(const QString &arg1);

    void on_pushButton_9_clicked();

    void on_pushButton_13_clicked();

    void on_comboBox_6_activated(const QString &arg1);

    void on_tableView_2_activated(const QModelIndex &index);

    void on_pushButton_11_clicked();

    void on_pushButton_12_clicked();

    void on_pushButton_33_clicked();

    void on_pushButton_34_clicked();

    void on_pushButton_35_clicked();

    void on_pushButton_36_clicked();

    void on_pushButton_39_clicked();

    void on_pushButton_37_clicked();

    void on_comboBox_13_activated(const QString &arg1);

    void on_comboBox_13_currentIndexChanged(const QString &arg1);

    void on_comboBox_13_currentIndexChanged(int index);

    void on_pushButton_40_clicked();
    bool controlenum(int test);
    bool controleVide(QString test);
    bool controleEmail(QString test);

    void on_change_currentIndexChanged(const QString &arg1);

private:
    Ui::Dialog *ui;
    Client tmpclient;
    Reclamation tmpreclamation;
};

#endif // DIALOG_H
