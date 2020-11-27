#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlTableModel>
#include <QSqlRelationalTableModel>
#include <QSqlRelationalDelegate>
#include <QSqlRelation>
#include <QModelIndex>
#include <QDebug>
#include <dbmanager.h>
#include <QSqlRecord>
#include <QMessageBox>
#include <QSqlDriver>
#include <QTableWidget>
#include <QModelIndex>
#include <QAbstractItemModel>
#include <QtCore>

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
    Dbmanager *conn = new Dbmanager ();
    //QSqlTableModel *model = new QSqlTableModel();
    QSqlRelationalTableModel *model = new QSqlRelationalTableModel();

    QSqlQuery query;
    int numRows;

private slots :
    void addVinyle();
    void readVinyle();
    void deleteVinyle();
    void quit();

//    void maj();    
//    void searchVinyle();

};

#endif // MAINWINDOW_H
