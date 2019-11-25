#include "mainwindow.h"
#include "ui_mainwindow.h"
#include"database.h"
#include<QDebug>
#include<QSqlDatabase>
#include<QSqlQuery>
#include<QtSql>
#include<QString>
#include<QMessageBox>
#include<secdialog.h>
QString MainWindow :: pro_user="";


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    ui->lineEdit_username->setPlaceholderText("Enter your name");
    ui->lineEdit_password->setPlaceholderText("Enter your password");
    ui->lineEdit_email->setPlaceholderText("Enter your email");
    ui->lineEdit_phone->setPlaceholderText("Enter your phone no");
     ui->login_username->setPlaceholderText("Username");
     ui->login_password->setPlaceholderText("Password");

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_registerbtn_clicked()
{
    //connecting to mysql database

        QString username=ui->lineEdit_username->text();
        QString password=ui->lineEdit_password->text();
        QString email=ui->lineEdit_email->text();
        QString phone=ui->lineEdit_phone->text();

        database connection;
        if(connection.Connect()){
            qDebug()<<"connected"<< endl;
        }
        QSqlQuery query;

 if(( ui->lineEdit_username->text().isEmpty())||(ui->lineEdit_password->text().isEmpty())||( ui->lineEdit_email->text().isEmpty())||( ui->lineEdit_phone->text().isEmpty()
))
       {
             QMessageBox::warning(this,"Not Inserted","Some Field Missing");
       }

       else if (query.exec ("INSERT INTO login(username,password,email,phone) VALUES('"+username+"','"+password+"','"+email+"','"+phone
                        +"')"))
        {
            qDebug()<<"query executed"<< endl;

            QMessageBox::information(this,"Inserted","Registration Successfull");

         }
      else{
             QMessageBox::warning(this,"Not Inserted","Registration Failed");
        }
       connection.Disconnect();

}


void MainWindow::on_Login_clicked()
{  //login with  mysql database
    QString username = ui->login_username->text();
    QString password = ui->login_password->text();
    if(username=="admin" && password=="admin")
    {
        this->hide();
        fourthDialog *newmain= new fourthDialog();
        newmain->showMaximized();

    }
    else{
    database con;
    if(con.Connect()){
        qDebug()<<"connected"<< endl;

    }
    QSqlQuery query;

    if (query.exec ("SELECT * FROM login WHERE Username='"+username+"' and Password='"+password+"'")){
        qDebug()<<"query executed"<< endl;
        int c=0;
        while(query.next()) ++c;
        if(c>=1){

            pro_user = username;
               this->hide();
               SecDialog *newmain= new SecDialog();
               newmain->showMaximized();

        }

        else {
            QMessageBox::warning(this,"Info","Login Failed");}
    }
   con.Disconnect();

}
}
