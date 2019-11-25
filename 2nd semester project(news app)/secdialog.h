#ifndef SECDIALOG_H
#define SECDIALOG_H

#include <QDialog>

#include<QtSql>
#include<QSqlDatabase>
#include<QMessageBox>
#include <QDialog>
#include <QLabel>
#include <QVector>


namespace Ui {
class SecDialog;
}

class SecDialog : public QDialog
{
    Q_OBJECT

public:
    static int x;

    explicit SecDialog(QWidget *parent = nullptr);
    ~SecDialog();

private slots:
    void on_submitpblm_clicked();

    void on_signout_clicked();
     void onlabelclicked();
      void onlabel1clicked();

     void on_back_clicked();

     void on_searchbttn_clicked();

private:

    Ui::SecDialog *ui;

};

#endif // SECDIALOG_H
