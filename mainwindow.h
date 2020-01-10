#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlTableModel>
#include <QModelIndex>
#include <dbmanager.h>
#include "QDebug"
#include "QSqlRelationalTableModel"
#include "QSqlRelationalDelegate"
#include "qsqlquery.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QString result_read;
    Dbmanager *conn = new Dbmanager ();

private slots :
//    void clicCreer();
    void read();
//    void maj();
//    void clicSupprimer();
    void quit();


};

#endif // MAINWINDOW_H
