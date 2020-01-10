#include "dbmanager.h"

Dbmanager::Dbmanager()
{
}

void Dbmanager::connect()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("/home/ninko/Projets/sqlite_database/mabiblio.db");
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

