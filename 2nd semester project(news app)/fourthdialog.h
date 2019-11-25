#ifndef FOURTHDIALOG_H
#define FOURTHDIALOG_H

#include <QDialog>

#include<QtSql>
#include<QSqlDatabase>
#include<QMessageBox>
#include <QDialog>
#include <QLabel>
#include <QVector>


namespace Ui {
class fourthDialog;
}

class fourthDialog : public QDialog
{
    Q_OBJECT

public:
     static int x,y;
    explicit fourthDialog(QWidget *parent = nullptr);
    ~fourthDialog();

private slots:
     void on_pushButton_clicked();

     void on_pushButton_2_clicked();

     void on_pushButton_3_clicked();
      void onlabelclicked();
      void onlabel1clicked();

      void on_pushButton_4_clicked();

private:
    Ui::fourthDialog *ui;
};

#endif // FOURTHDIALOG_H
