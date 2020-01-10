#include "dbmanager.h"
#include "QDebug"

Dbmanager::Dbmanager()
{
}

void Dbmanager::connect()
{
    /*le driver de QSQLITE*/
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");

    /*donner le bon chemin de la database*/
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

void Dbmanager::close()
{
    db.close();
    qDebug("Database : connection is close");
}

