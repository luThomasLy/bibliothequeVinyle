#ifndef DBMANAGER_H
#define DBMANAGER_H

#include <QSqlTableModel>
#include <QSqlRelationalTableModel>
#include <QModelIndex>
#include "QDebug"
#include <QSqlDatabase>
#include <QSqlDriver>
#include <QSqlError>
#include <QSqlQuery>

class Dbmanager
{    
public:
    Dbmanager();

    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    void connect();
    void close_connect();
};
#endif // DBMANAGER_H
