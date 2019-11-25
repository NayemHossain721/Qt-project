#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QtSql>
#include<QSqlDatabase>
#include<QMessageBox>
#include<secdialog.h>
#include<thirddialog.h>
#include<fourthdialog.h>


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    static QString pro_user;
    ~MainWindow();

private slots:
    void on_registerbtn_clicked();

    void on_Login_clicked();
public:
    QSqlDatabase dataBase;



private:
    Ui::MainWindow *ui;

};


#endif // MAINWINDOW_H
