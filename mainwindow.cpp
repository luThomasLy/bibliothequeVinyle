#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QModelIndex"
#include "QDebug"
#include "dialogcreate.h"
#include "QSqlRelationalTableModel"
#include "QSqlRelationalDelegate"

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

    //2019/09/04 - permet d'afficher la table vinyle mais pas les relations
//    QSqlTableModel *model = new QSqlTableModel();
//    model->setTable("vinyle");
//    model->select();
//    ui->tableView->setModel(model);

    //2019/09/04 - tentative de DAO
    QSqlRelationalTableModel *modelVinyle = new QSqlRelationalTableModel();
    modelVinyle->setTable("vinyle");
    modelVinyle->select();

    ui->tableView->setModel(modelVinyle);
    ui->tableView->setItemDelegate(new QSqlRelationalDelegate ());
    ui->tableView->resizeColumnsToContents();
}

void MainWindow::quitter()
{
    close();
}



