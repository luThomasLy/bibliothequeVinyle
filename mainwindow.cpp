#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QModelIndex"
#include "QDebug"
#include "QSqlRelationalTableModel"
#include "QSqlRelationalDelegate"
#include "qsqlquery.h"
#include "qsqlerror.h"
#include "QMessageBox"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->buttonCreate, SIGNAL(clicked()), this, SLOT(clicCreer()));
    connect(ui->buttonRead, SIGNAL(clicked()), this, SLOT(clicLecture()));
    connect(ui->buttonQuit, SIGNAL(clicked()), this, SLOT(quitter()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::clicCreer()
{
    clicLecture();

    QSqlTableModel model;
    model.setTable("Vinyle");
    for (int i = 0; i<6; ++i) {
        model.insertRows(i,1);
        model.setData(model.index(i,0), i);
        model.setData(model.index(i,1), i);
        model.setData(model.index(i,2), i);
        model.setData(model.index(i,3), i);
        model.setData(model.index(i,4), i);
        model.setData(model.index(i,5), i);
        model.submitAll();
    }
}

void MainWindow::clicLecture()
{
    conn->connect();

    //2019/09/04 - permet d'afficher la table vinyle mais pas les relations
    //2019/09/05 - ajout du resize de la colonne
    QSqlTableModel *model = new QSqlTableModel();

    model->setTable("vinyle");
    model->select();
    ui->tableViewMain->setModel(model);
    ui->tableViewMain->resizeColumnsToContents();
}

void MainWindow::quitter()
{
    close();
}



