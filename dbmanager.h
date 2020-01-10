#ifndef DBMANAGER_H
#define DBMANAGER_H

#include <QSqlTableModel>
#include <QSqlRelationalTableModel>
#include <QModelIndex>

class Dbmanager
{    
public:
    Dbmanager();

    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    void connect();
    void close();
};
#endif // DBMANAGER_H
