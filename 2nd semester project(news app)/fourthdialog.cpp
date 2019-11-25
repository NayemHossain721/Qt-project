#include "fourthdialog.h"
#include "ui_fourthdialog.h"
#include"database.h"
#include<QString>
#include<QMessageBox>
#include<secdialog.h>
#include<mainwindow.h>
#include<QLabel>
#include<QString>
#include<database.h>
#include<QSqlQueryModel>
#include "QVBoxLayout"
#include <QScrollArea>
#include <QPixmap>
#include <QtSql>
#include <QDebug>
#include <QSqlDatabase>
#include <QMessageBox>
#include <QGridLayout>
#include <QVBoxLayout>
#include <QFrame>
#include <QLineEdit>
#include <QPixmap>
#include <QEvent>
#include<QSqlQuery>

fourthDialog::fourthDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::fourthDialog)
{
    ui->setupUi(this);
    database conn;
    QSqlQueryModel *modal= new QSqlQueryModel();
    QSqlQueryModel *modal1= new QSqlQueryModel();


    conn.Connect();
    QSqlQuery *qry= new QSqlQuery(conn.dataBase);
    QSqlQuery *qry1= new QSqlQuery(conn.dataBase);


    qry->prepare("select title from submit");
    qry1->prepare("select location from submit");


    qry->exec();
    qry1->exec();


    modal->setQuery(*qry);
    modal1->setQuery(*qry1);


    QGridLayout *lay=new QGridLayout(this);
     QPushButton *label[100];
    for(int j=0;j<=modal->rowCount()-1;j++)
    {
        QString str=modal->record(j).value(0).toString();
        QString str1=modal1->record(j).value(0).toString();


        label[j]=new QPushButton(str);

        QLabel *lab=new QLabel("Location : "+str1+" ");
        QFrame *line;
        line = new QFrame();
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        label[j]->setObjectName("btnName_1");
        label[j]->setStyleSheet(
                    "   QPushButton#btnName_1 {"
                    "     background:transparent; Text-align:left;font-family:MS Shell Dlg 2;font-size:18px; color:white;"
                    " }"
                    " QPushButton#btnName_1:hover {"
                    "     color: white;font-size:22px;"
                    " }");
        lab->setStyleSheet("background:transparent; Text-align:left;font-family:MS Shell Dlg 2;font-size:18px; color:white");

        {
            label[j]->setIcon(QIcon("btnLogs/1_hover.jpg"));
        }
        label[j]->setGeometry(10,10,10,10);
        lay->addWidget(label[j]);
        lay->addWidget(lab);
        lay->addWidget(line);

        connect(label[j],SIGNAL(clicked()),this,SLOT(onlabelclicked()));
    }
    ui->scrollArea_3->setGeometry(40,200,940,450);
    ui->scrollAreaWidgetContents_2->setLayout(lay);
    conn.Disconnect();
    ui->scrollArea_2->hide();
}

int fourthDialog:: x=0;
QPushButton * pButton1[100];
void fourthDialog::onlabelclicked()
{

ui->scrollArea_3->hide();
ui->scrollArea_2->show();
ui->scrollArea_2->setGeometry(40,200,940,450);
QPushButton *label1=new QPushButton("Location");
label1->setObjectName("btnName_9");
label1->setStyleSheet("   QPushButton#btnName_9 {"
                      "     background:transparent;border:2px solid white;font-size:18px;Text-align:center;font-family:MS Shell Dlg 2;"
                      " }"
                      " QPushButton#btnName_9:hover {"
                      "     color: white;border:2px solid white;font-size:22px;"
                      " }");
  connect(label1,SIGNAL(clicked()),this,SLOT(onlabel1clicked()));

    if(x>0){
        pButton1[x-1]->setObjectName("btnName_1");
        pButton1[x-1]->setStyleSheet(
                    "   QPushButton#btnName_1 {"
                    "     background:transparent; Text-align:left;font-family:MS Shell Dlg 2;font-size:18px; color:white;"
                    " }"
                    " QPushButton#btnName_1:hover {"
                    "     color: white;font-size:25px;"
                    " }");
    }
    pButton1[x]=new QPushButton;
    pButton1[x] = qobject_cast<QPushButton*>(sender());
    int index=senderSignalIndex();
    pButton1[x]->setObjectName("btnName_1");
    pButton1[x]->setStyleSheet(
                "   QPushButton#btnName_1 {"
                "     background:transparent; Text-align:left;font-family:MS Shell Dlg 2;font-size:25px;font-weight: bold;text-transform: capitalize; color:rgb(224, 255, 0);font-style: bold;"
                " }"
                " QPushButton#btnName_1:hover {"
                "     color: yellow;font-size:25px;"
                " }");
    QString buttonText = pButton1[x]->text();
    // recognize buttonText here
   ui->label_6->setText(buttonText);
   ui->label_6->setStyleSheet("font-family:Algerian;background:transparent;font-size:20px;color:white");
    QString temp=buttonText;

    database conn;
    conn.Connect();
    QSqlQuery qry;
    qry.prepare("select * from submit where  title='"+buttonText+"'");
    if(qry.exec())
        while(qry.next()){

            QPixmap pro_pic;
            QString location=qry.value(5).toString();
            pro_pic.load(location);
            ui->label_8->setPixmap(pro_pic);
            ui->label_8->setScaledContents(true);

            ui->label_2->setText("<font color=white>Problem: </font>"+qry.value(1).toString());
            ui->label_2->setStyleSheet("font-size:16px;font-family:MS Shell Dlg 2;color:white");
            ui->label_3->setText("<font color=white>Location: </font>"+qry.value(2).toString());
            ui->label_3->setStyleSheet("font-size:16px;font-family:century MS Shell Dlg 2;color:white");
            ui->label_4->setText("<font color=white>Description: </font>"+qry.value(3).toString()+"<font color=white></font>");
            ui->label_4->setStyleSheet("font-size:16px;font-family:MS Shell Dlg 2;color:white");
            ui->label_5->setText("<font color=white>Contract: </font>"+qry.value(4).toString());
            ui->label_5->setStyleSheet("font-size:16px;font-family:MS Shell Dlg 2;color:white");
        }

    x++;
    index++;
    conn.Disconnect();
}


fourthDialog::~fourthDialog()
{
    delete ui;
}

void fourthDialog::on_pushButton_clicked()
{
    MainWindow *newmain= new MainWindow();
    newmain->showMaximized();
    this->hide();
}

void fourthDialog::on_pushButton_2_clicked()
{
    QString title;
    title=ui->lineEdit->text();
    database con;
    if(!con.Connect()){
        qDebug()<<"NOT connected"<< endl;
        return;

    }
    con.Connect();
    QSqlQuery query;
     query.prepare("Delete from submit where title='"+title+"'");

    if(( ui->lineEdit->text().isEmpty()))
          {
                QMessageBox::warning(this,"Not Inserted","Unable to Delete");
          }


    //query.prepare("Delete from submit where title='"+title+"'");
    else if(query.exec())
    {
        QMessageBox::information(this,tr("Delete"),tr("Deleted"));
        con.Disconnect();

    }
    else{

       QMessageBox::critical(this,tr("Not Delete"),tr("Unable to Delete"));
    }

}

void fourthDialog::on_pushButton_3_clicked()
{

    QPushButton *label1=new QPushButton("Location");
    label1->setObjectName("btnName_9");
    label1->setStyleSheet("   QPushButton#btnName_9 {"
                          "     background:transparent;border:2px solid white;font-size:18px;Text-align:center;font-family:MS Shell Dlg 2;"
                          " }"
                          " QPushButton#btnName_9:hover {"
                          "     color: white;border:2px solid white;font-size:22px;"
                          " }");
    connect(label1,SIGNAL(clicked()),this,SLOT(onlabel1clicked()));
    database conn;
    QSqlQueryModel *modal= new QSqlQueryModel();
    QSqlQueryModel *modal1= new QSqlQueryModel();

    conn.Connect();
    QSqlQuery *qry= new QSqlQuery(conn.dataBase);
    QSqlQuery *qry1= new QSqlQuery(conn.dataBase);

    qry->prepare("select title from submit");
    qry1->prepare("select location from submit");

    qry->exec();
    qry1->exec();

    modal->setQuery(*qry);
    modal1->setQuery(*qry1);
     QGridLayout *lay=new QGridLayout(this);
    QString s=ui->lineEdit_2->text();
    QPushButton *label[100];
    for(int j=0;j<=modal->rowCount();j++)
    {
        QString str=modal->record(j).value(0).toString();
        QString str1=modal1->record(j).value(0).toString();
        //checking for match
        int x = QString::compare(s, str1, Qt::CaseInsensitive);
        //if matches....
        if(x==0)
        {
            //clearing previous layout
            if ( ui->scrollAreaWidgetContents_2->layout() != NULL )
            {
                QLayoutItem* item;
                while ( ( item = ui->scrollAreaWidgetContents_2->layout()->takeAt( 0 ) ) != NULL )
                {
                    delete item->widget();
                    delete item;
                }
                delete ui->scrollAreaWidgetContents_2->layout();
            }
            //setting up new layout
            ui->scrollArea_3->setGeometry(40,200,940,450);
            label[j]=new QPushButton(/*QString::number(j+1)+". "+ */str);
            QLabel *lab=new QLabel("Location: "+str1+"");

            QFrame *line;
            line = new QFrame();
            line->setFrameShape(QFrame::HLine);
            line->setFrameShadow(QFrame::Sunken);
            lab->setStyleSheet("background:transparent; Text-align:left;font-family:MS Shell Dlg 2;font-size:18px; color:white");
            label[j]->setObjectName("btnName_1");
            label[j]->setStyleSheet(
                        "   QPushButton#btnName_1 {"
                        "     background:transparent; Text-align:left;font-family:MS Shell Dlg 2;font-size:18px; color:white;"
                        " }"
                        " QPushButton#btnName_1:hover {"
                        "     color: white;font-size:22px;"
                        " }");
            label[j]->setGeometry(10,10,10,10);
            lay->addWidget(label[j]);
            lay->addWidget(lab);
            lay->addWidget(line);



            connect(label[j],SIGNAL(clicked()),this,SLOT(onlabel1clicked()));

        }
    }
    if ( ui->scrollAreaWidgetContents_2->layout() != NULL )
    {
        QLayoutItem* item;
        while ( ( item = ui->scrollAreaWidgetContents_2->layout()->takeAt( 0 ) ) != NULL )
        {
            delete item->widget();
            delete item;
        }
        delete ui->scrollAreaWidgetContents_2->layout();
    }
    ui->scrollAreaWidgetContents_2->setLayout(lay);
    ui->scrollAreaWidgetContents_2->setVisible(true);
    ui->scrollAreaWidgetContents_2->show();


}
int fourthDialog:: y=0;
QPushButton * pButton2[100];

void fourthDialog::onlabel1clicked()
{

ui->scrollArea_3->hide();
ui->scrollArea_2->show();
ui->scrollArea_2->setGeometry(40,200,940,450);
QPushButton *label1=new QPushButton("Location");
label1->setObjectName("btnName_9");
label1->setStyleSheet("   QPushButton#btnName_9 {"
                      "     background:transparent;border:2px solid white;font-size:18px;Text-align:center;font-family:MS Shell Dlg 2;"
                      " }"
                      " QPushButton#btnName_9:hover {"
                      "     color: white;border:2px solid white;font-size:22px;"
                      " }");
  connect(label1,SIGNAL(clicked()),this,SLOT(onlabel1clicked()));

    if(y>0){
        pButton2[y-1]->setObjectName("btnName_1");
        pButton2[y-1]->setStyleSheet(
                    "   QPushButton#btnName_1 {"
                    "     background:transparent; Text-align:left;font-family:MS Shell Dlg 2;font-size:18px; color:white;"
                    " }"
                    " QPushButton#btnName_1:hover {"
                    "     color: white;font-size:25px;"
                    " }");
    }
    pButton2[y]=new QPushButton;
    pButton2[y] = qobject_cast<QPushButton*>(sender());
    int index=senderSignalIndex();
    pButton2[y]->setObjectName("btnName_1");
    pButton2[y]->setStyleSheet(
                "   QPushButton#btnName_1 {"
                "     background:transparent; Text-align:left;font-family:MS Shell Dlg 2;font-size:25px;font-weight: bold;text-transform: capitalize; color:rgb(224, 255, 0);font-style: bold;"
                " }"
                " QPushButton#btnName_1:hover {"
                "     color: white;font-size:25px;"
                " }");
    QString buttonText = pButton2[y]->text();
    // recognize buttonText here
   ui->label_6->setText(buttonText);
   ui->label_6->setStyleSheet("font-family:Algerian;background:transparent;font-size:18px;color:white");
    QString temp=buttonText;
    database conn;
    conn.Connect();
    QSqlQuery qry;
    qry.prepare("select * from submit where  title='"+buttonText+"'");
    if(qry.exec())
        while(qry.next()){

            QPixmap pro_pic;
            QString location=qry.value(5).toString();
            pro_pic.load(location);
            ui->label_8->setPixmap(pro_pic);
            ui->label_8->setScaledContents(true);


            ui->label_2->setText("<font color=white>Problem :  </font>"+qry.value(1).toString());
            ui->label_2->setStyleSheet("font-size:18px;font-family:sitka display;color:white");
            ui->label_3->setText("<font color=white>Location: </font>"+qry.value(2).toString());
            ui->label_3->setStyleSheet("font-size:18px;font-family:sitka display;color:white");
            ui->label_4->setText("<font color=white>Description: </font>"+qry.value(3).toString()+"<font color=white></font>");
            ui->label_4->setStyleSheet("font-size:18px;font-family:sitka display;color:white");
            ui->label_5->setText("<font color=white>Contract: </font>"+qry.value(4).toString());
            ui->label_5->setStyleSheet("font-size:18px;font-family:sitka display;color:white");
        }

    y++;
    index++;
    conn.Disconnect();


}


void fourthDialog::on_pushButton_4_clicked()
{
    fourthDialog *newmain= new fourthDialog();
    newmain->showMaximized();
    hide();

}
