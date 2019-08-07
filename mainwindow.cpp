#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "dbvinyle.h"
#include "QModelIndex"
#include "QDebug"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    /*le driver de QSQLITE*/
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");

    /*donner le bon chemin de la database*/
    db.setDatabaseName("/home/ninko/Projets/sqlite_database/mabiblio.db");
    bool ok = db.open();

    QSqlTableModel *model = new QSqlTableModel();

    model->setTable("vinyles");
    model->select();
    ui->tableView->setModel(model);
}

MainWindow::~MainWindow()
{
    delete ui;
}



