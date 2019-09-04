#ifndef DBMANAGER_H
#define DBMANAGER_H

#include <QSqlTableModel>
#include <QSqlRelationalTableModel>
#include <QModelIndex>

class Dbmanager
{    
public:
    Dbmanager();
    void connect();

};
#endif // DBMANAGER_H
