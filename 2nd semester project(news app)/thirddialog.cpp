#include "thirddialog.h"
#include "ui_thirddialog.h"
#include"database.h"
#include<QDebug>
#include<QSqlDatabase>
#include<QSqlQuery>
#include<QString>
#include<QMessageBox>
#include<secdialog.h>
#include<mainwindow.h>
#include<QComboBox>
#include <QFileDialog>
#include<QFile>
#include<QFileInfo>
#include<QScreen>
#include <QtWidgets>


thirdDialog::thirdDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::thirdDialog)
{
    ui->setupUi(this);
    QString user= MainWindow :: pro_user;

 database con;
    con.Connect();
    QSqlQuery query;
    query.prepare("select * from login where username='"+ MainWindow :: pro_user +"'");
    if(query.exec())
        while(query.next())
        {

            ui->label_7->setText(query.value(0).toString());
            ui->label_7->setObjectName("btnName_1");
            ui->label_7->setStyleSheet("   QLabel#btnName_1 {"
                                                   "     color:white;border:2px;font-size:20px;"
                                                   " }"
                                                   );
        }
    con.Disconnect();







    ui->comboBox->addItem("Corruption");
    ui->comboBox->addItem("Smugling");
    ui->comboBox->addItem("Injustice");
    ui->comboBox->addItem("Rape");
    ui->comboBox->addItem("Social Problem");
    ui->comboBox->addItem("Lost ");
    ui->comboBox->addItem("Others");

}

thirdDialog::~thirdDialog()
{
    delete ui;
}

void thirdDialog::on_submit2_clicked()
{
     QString title =ui->lineEdit_4->text();
    QString location= ui->lineEdit->text();
    QString description =ui->lineEdit_2->text();
    QString contract  =ui->lineEdit_3->text();
    QString valueComboBox;

     valueComboBox = ui->comboBox->currentText();

     QString problem=valueComboBox;

    database connection;
    if(connection.Connect()){
        qDebug()<<"connected"<< endl;


    QSqlQuery query;

    if(( ui->lineEdit->text().isEmpty())||(ui->lineEdit_2->text().isEmpty())||(ui->lineEdit_4->text().isEmpty())||( ui->lineEdit_3->text().isEmpty()
   ))
          {
                QMessageBox::warning(this,"Not Inserted","Some Field Missing");
          }

     else if /*(query.exec ("INSERT INTO submit(title,problem,location,description,contract) VALUES('"+title+"','"+problem+"','"+location+"','"+description+"','"+contract
                    +"')"))*/
    (query.exec(("update submit set title ='"+title+"' , Problem ='"+problem+"' , location ='"+location+"' , description ='"+description+"' , contract ='"+contract+"' where id IS NULL")))


    {
        qDebug()<<"query executed"<< endl;


        QMessageBox::information(this,"Inserted","Promlem Submitted Successfully");

     }
    else{
         QMessageBox::warning(this,"Not Inserted","Failed To Submit");
    }
   connection.Disconnect();
}

   database d;
   if(d.Connect()){
       qDebug()<<"connected"<< endl;
   }

      QSqlQuery qry2;

      qry2.prepare(("update submit set id='+1+'"));

      if(qry2.exec()){


          qDebug()<<"incremented"<<endl;

}
      d.Disconnect();


}

void thirdDialog::on_signout2_clicked()
{
    MainWindow *newmain= new MainWindow();
    newmain->showMaximized();
    this->hide();
}

void thirdDialog::on_newsfeed_clicked()
{
   SecDialog *newmain= new SecDialog();
    newmain->showMaximized();
    this->hide();
}



void thirdDialog::on_Upload_clicked()
{
   QString picpath=QFileDialog::getOpenFileName
              (
                  this,
              tr("Open File"),
              "C://",
              "All File (*.*);;JPG File (*.jpg);;PNG File (*.png)"
                  );
   database c;
   if(c.Connect()){
       qDebug()<<"connected"<< endl;


      QSqlQuery qry;

      //qry.prepare(("update submit set propic ='"+picpath+"'where id IS NULL"));
     qry.prepare( ("INSERT INTO submit(propic) VALUES('"+picpath+"')"));

      if(qry.exec()){

         QMessageBox::information(this,tr("Update Result"),tr("<font color=black>Photo Update Successfully"));
      c.Disconnect();
      c.Connect();
      QSqlQuery qry;
      qry.prepare("select * from submit where propic='"+picpath +"'");
      if(qry.exec())
          while(qry.next())
          {
              QPixmap pro_pic;
              QString location=qry.value(5).toString();
              pro_pic.load(location);
              ui->label_5->setPixmap(pro_pic);
              ui->label_5->setScaledContents(true);
          }

      }else {

          QMessageBox::critical(this,tr("error ::"),qry.lastError().text());
  }

       c.Disconnect();
   }


      }
