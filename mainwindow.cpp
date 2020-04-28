#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->buttonRead, SIGNAL(clicked()), this, SLOT(readVynile()));
    connect(ui->buttonCreate, SIGNAL(clicked()), this, SLOT(addVynile()));    
    connect(ui->buttonDelete, SIGNAL(clicked()), this, SLOT(deleteVynile()));
    connect(ui->buttonQuit, SIGNAL(clicked()), this, SLOT(quit()));
    //connect(ui->buttonSearch, SIGNAL(clicked()), this, SLOT());
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::readVynile()
{
    conn->connect();

    QSqlRelationalTableModel *model = new QSqlRelationalTableModel();
    model->setTable("Vynile");
    model->setRelation(0,QSqlRelation("Exemplaire","idVynile","libelleExemplaire"));
    model->select();

//    QSqlTableModel *model = new QSqlTableModel();
//    model->setTable("Vynile");
//    model->select();

    model->setHeaderData(0, Qt::Horizontal,tr("Qualité du vynile"));
    model->setHeaderData(1, Qt::Horizontal,tr("Titre de l'album ou maxi"));
    model->setHeaderData(2, Qt::Horizontal,tr("Quantité"));
    model->setHeaderData(3, Qt::Horizontal,tr("Catégorie : EP / LP"));
    model->setHeaderData(4, Qt::Horizontal,tr("Genre musical"));
    model->setHeaderData(5, Qt::Horizontal,tr("Année de prod"));
    model->setHeaderData(6, Qt::Horizontal,tr("Etat du vynile"));

    ui->tableViewMain->setModel(model);
    ui->tableViewMain->resizeColumnsToContents();
}

void MainWindow::addVynile()
{
    //readVynile();
    conn->connect();

    QSqlTableModel *model = new QSqlTableModel();
    model->setTable("Vynile");
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

void MainWindow::deleteVynile()
{
//    conn->connect();

//    QSqlTableModel *model = new QSqlTableModel();
//    model->setTable("Vynile");
//    model->select();
//    ui->tableViewMain->setModel(model);
//    ui->tableViewMain->resizeColumnsToContents();

//    for (int i=0; i<6; ++i)
//    {
//        model->removeRow(0);
//        model->submitAll();
//    }
}

void MainWindow::quit()
{
    conn->close_connect();
    close();
}
