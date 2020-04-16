#ifndef DBMANAGER_H
#define DBMANAGER_H

#include <QDebug>
#include <QSqlDatabase>

class Dbmanager
{    
public:
    Dbmanager();

    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    void connect();
    void close_connect();
};
#endif // DBMANAGER_H
