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
    void addVynile();
    void readVynile();
//    void maj();
    void deleteVynile();
    void quit();
};

#endif // MAINWINDOW_H
