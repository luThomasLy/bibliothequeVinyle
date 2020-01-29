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
    QSqlTableModel *model = new QSqlTableModel();

private slots :
    void insertDb();
    void readDb();
//    void maj();
    void deleteDb();
    void quit();

};

#endif // MAINWINDOW_H
