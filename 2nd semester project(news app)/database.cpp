#include "database.h"
#include<qdebug.h>
#include<mainwindow.h>
#include<secdialog.h>


database::database()
{
    dataBase=QSqlDatabase::addDatabase("QSQLITE");
    dataBase.setDatabaseName("E:/login.db");

}
bool database::Connect()
{
    if (dataBase.open())
    return true;
    else
        return false;
}
void database::Disconnect()
{
    dataBase.close();

}
