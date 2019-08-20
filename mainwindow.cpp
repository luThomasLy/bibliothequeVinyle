#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QModelIndex"
#include "QDebug"
#include "dialogcreate.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

//    /*le driver de QSQLITE*/
//    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");

//    /*donner le bon chemin de la database*/
//    db.setDatabaseName("/home/ninko/Projets/sqlite_database/mabiblio.db");
//    bool ok = db.open();

//    Dbmanager *conn = new Dbmanager ();
//    conn->connect();

//    QSqlTableModel *model = new QSqlTableModel();
//    model->setTable("vinyle");
//    model->select();
//    ui->tableView->setModel(model);


    connect(ui->buttonCreate, SIGNAL(clicked()), this, SLOT(creer()));

    connect(ui->buttonRead, SIGNAL(clicked()), this, SLOT(afficher()));

    connect(ui->buttonQuit, SIGNAL(clicked()), this, SLOT(quitter()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::creer()
{
    Dialogcreate *create = new Dialogcreate();
    create->show();
}

void MainWindow::afficher()
{
    Dbmanager *conn = new Dbmanager ();
    conn->connect();

    QSqlTableModel *model = new QSqlTableModel();
    model->setTable("vinyle");
    model->select();
    ui->tableView->setModel(model);
}

void MainWindow::quitter()
{
    close();
}



