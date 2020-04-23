#include "dbmanager.h"

Dbmanager::Dbmanager()
{
}

void Dbmanager::connect()
{

//    {
//        QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
//        QSqlQuery query("SELECT * FROM VYNILE", db);
//    }
//    QSqlDatabase::removeDatabase("QSQLITE");

    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setHostName("");
    db.setDatabaseName("/home/ninko/Documents/projet_bibliotheque_vynile/biblioVynile.db");

    //db.setDatabaseName(":/db/biblioVynile.db");

    bool ok = db.open();

    if (!ok)
    {
        qDebug() << "Error: connection with database fail";
    }
    else
    {
        qDebug() << "Database : connection is open";
    }
}

void Dbmanager::close_connect()
{
    db.close();
    qDebug("Database : connection is close");
}

