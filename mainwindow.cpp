#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->boutonLire, SIGNAL(clicked()), this, SLOT(lireVinyle()));
    connect(ui->boutonCreer, SIGNAL(clicked()), this, SLOT(ajouterVinyle()));
    connect(ui->boutonEffacer, SIGNAL(clicked()), this, SLOT(effacerVinyle()));
    connect(ui->boutonQuitter, SIGNAL(clicked()), this, SLOT(quitter()));
    //connect(ui->buttonSearch, SIGNAL(clicked()), this, SLOT());
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::lireVinyle()
{
    conn->connect();

    QSqlRelationalTableModel *model = new QSqlRelationalTableModel();
    model->setTable("Vinyle");
    //mise en relation avec les autres tables
    model->setRelation(0,QSqlRelation("Exemplaire","idVinyle","qualiteExemplaire"));

    model->select();

//    QSqlTableModel *model = new QSqlTableModel();
//    model->setTable("Vinyle");
//    model->select();

//    model->setHeaderData(0, Qt::Horizontal,tr("Qualité du vinyle"));
//    model->setHeaderData(1, Qt::Horizontal,tr("Titre de l'album ou maxi"));
//    model->setHeaderData(2, Qt::Horizontal,tr("Quantité"));
//    model->setHeaderData(3, Qt::Horizontal,tr("Catégorie : EP / LP"));
//    model->setHeaderData(4, Qt::Horizontal,tr("Genre musical"));
//    model->setHeaderData(5, Qt::Horizontal,tr("Année de prod"));
//    model->setHeaderData(6, Qt::Horizontal,tr("Etat du vinyle"));

    ui->tableViewMain->setModel(model);
    ui->tableViewMain->resizeColumnsToContents();
}

void MainWindow::ajouterVinyle()
{
    conn->connect();

    QSqlTableModel *model = new QSqlTableModel();
    model->setTable("Vinyle");
    model->select();
    ui->tableViewMain->setModel(model);
    ui->tableViewMain->resizeColumnsToContents();

    for (int i=0; i<6; ++i)
    {
        model->insertRows(i,1);
        model->setData(model->index(i,0), QString(i));
        model->setData(model->index(i,1), QString(i));
        model->setData(model->index(i,2), QString(i));
        model->setData(model->index(i,3), QString(i));
        model->setData(model->index(i,4), QString(i));
        model->setData(model->index(i,5), QString(i));
        model->submitAll();
    }
}

void MainWindow::effacerVinyle()
{
    conn->connect();

    QSqlTableModel *model = new QSqlTableModel();
    model->setTable("Vinyle");
    model->select();
    ui->tableViewMain->setModel(model);
    ui->tableViewMain->resizeColumnsToContents();

    model->removeRow(0);

//    for (int i=0; i<6; ++i)
//    {
//        model->removeRow(0);
//        model->submitAll();
//    }
}

void MainWindow::quitter()
{
    conn->close_connect();
    close();
}
