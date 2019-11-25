#include "secdialog.h"
#include "ui_secdialog.h"
#include<thirddialog.h>
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
#include<database.h>
#include<fourthdialog.h>



SecDialog::SecDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SecDialog)
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
                                       "     color:black;border:2px;font-size:20px;"
                                       " }"
                                       );
        }
    con.Disconnect();

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
    ui->scrollArea->setGeometry(40,200,940,450);
    ui->scrollContents->setLayout(lay);
    conn.Disconnect();
    ui->scrollArea_2->hide();
}
int SecDialog:: x=0;
QPushButton * pButton[100];
void SecDialog::onlabelclicked()
{

    ui->scrollArea->hide();
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
        pButton[x-1]->setObjectName("btnName_1");
        pButton[x-1]->setStyleSheet(
                    "   QPushButton#btnName_1 {"
                    "     background:transparent; Text-align:left;font-family:MS Shell Dlg 2;font-size:18px; color:white;"
                    " }"
                    " QPushButton#btnName_1:hover {"
                    "     color: white;font-size:25px;"
                    " }");
    }
    pButton[x]=new QPushButton;
    pButton[x] = qobject_cast<QPushButton*>(sender());
    int index=senderSignalIndex();
    pButton[x]->setObjectName("btnName_1");
    pButton[x]->setStyleSheet(
                "   QPushButton#btnName_1 {"
                "     background:transparent; Text-align:left;font-family:MS Shell Dlg 2;font-size:25px;font-weight: bold;text-transform: capitalize; color:rgb(224, 255, 0);font-style: bold;"
                " }"
                " QPushButton#btnName_1:hover {"
                "     color: yellow;font-size:25px;"
                " }");
    QString buttonText = pButton[x]->text();
    // recognize buttonText here
    ui->label->setText(buttonText);
    ui->label->setStyleSheet("font-family:Algerian;background:transparent;font-size:20px;color:white");
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


SecDialog::~SecDialog()
{
    delete ui;
}

void SecDialog::on_submitpblm_clicked()
{

    this->hide();
    thirdDialog *newmain= new thirdDialog();
    newmain->showMaximized();

}

void SecDialog::on_signout_clicked()
{

    MainWindow *newmain= new MainWindow();
    newmain->showMaximized();
    this->hide();
}



void SecDialog::on_back_clicked()
{

    SecDialog *newmain= new SecDialog();
    newmain->showMaximized();
    hide();
}



void SecDialog::on_searchbttn_clicked()
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
    QString s=ui->search->text();
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
            if ( ui->scrollContents->layout() != NULL )
            {
                QLayoutItem* item;
                while ( ( item = ui->scrollContents->layout()->takeAt( 0 ) ) != NULL )
                {
                    delete item->widget();
                    delete item;
                }
                delete ui->scrollContents->layout();
            }
            //setting up new layout
            ui->scrollArea->setGeometry(40,200,940,450);
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
    if ( ui->scrollContents->layout() != NULL )
    {
        QLayoutItem* item;
        while ( ( item = ui->scrollContents->layout()->takeAt( 0 ) ) != NULL )
        {
            delete item->widget();
            delete item;
        }
        delete ui->scrollContents->layout();
    }
    ui->scrollContents->setLayout(lay);
    ui->scrollContents->setVisible(true);
    ui->scrollContents->show();
}


void SecDialog::onlabel1clicked()
{

    ui->scrollArea->hide();
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
        pButton[x-1]->setObjectName("btnName_1");
        pButton[x-1]->setStyleSheet(
                    "   QPushButton#btnName_1 {"
                    "     background:transparent; Text-align:left;font-family:MS Shell Dlg 2;font-size:18px; color:white;"
                    " }"
                    " QPushButton#btnName_1:hover {"
                    "     color: white;font-size:25px;"
                    " }");
    }
    pButton[x]=new QPushButton;
    pButton[x] = qobject_cast<QPushButton*>(sender());
    int index=senderSignalIndex();
    pButton[x]->setObjectName("btnName_1");
    pButton[x]->setStyleSheet(
                "   QPushButton#btnName_1 {"
                "     background:transparent; Text-align:left;font-family:MS Shell Dlg 2;font-size:25px;font-weight: bold;text-transform: capitalize; color:rgb(224, 255, 0);font-style: bold;"
                " }"
                " QPushButton#btnName_1:hover {"
                "     color: white;font-size:25px;"
                " }");
    QString buttonText = pButton[x]->text();
    // recognize buttonText here
    ui->label->setText(buttonText);
    ui->label->setStyleSheet("font-family:Algerian;background:transparent;font-size:18px;color:white");
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

    x++;
    index++;
    conn.Disconnect();
}
