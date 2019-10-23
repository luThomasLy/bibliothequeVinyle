#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSqlTableModel>
#include <QModelIndex>
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

    //déclarer les instanciations en global pour pouvoir les utiliser en dehors
    Dbmanager *conn = new Dbmanager ();
    //QSqlTableModel *model = new QSqlTableModel();

private slots :
    void clicCreer();
    void clicLecture();
//    void maj();
    void supprimer();
    void quitter();


};

#endif // MAINWINDOW_H
