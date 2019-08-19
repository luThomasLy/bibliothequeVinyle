#include "dbmanager.h"

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
}

