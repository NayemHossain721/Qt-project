#ifndef DATABASE_H
#define DATABASE_H
#include<QSqlDatabase>
#include<mainwindow.h>
#include<secdialog.h>
#include<fourthdialog.h>
#include<thirddialog.h>

class database
{
public:
    QSqlDatabase dataBase;
public:
    database();
    bool Connect();
    void Disconnect();
};

#endif // DATABASE_H
