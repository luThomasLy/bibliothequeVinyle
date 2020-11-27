#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->buttonRead, SIGNAL(clicked()), this, SLOT(readVinyle()));
    connect(ui->buttonCreate, SIGNAL(clicked()), this, SLOT(addVinyle()));
    connect(ui->buttonDelete, SIGNAL(clicked()), this, SLOT(deleteVinyle()));
    connect(ui->buttonQuit, SIGNAL(clicked()), this, SLOT(quit()));
    //connect(ui->buttonSearch, SIGNAL(clicked()), this, SLOT());
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::readVinyle()
{
    conn->connect();

    query.exec("SELECT * FROM Artiste");
    while (query.next())
    {
        QString nomArtiste = query.value(1).toString();
        QString categorieArtiste = query.value(2).toString();
        QString idPays = query.value(3).toString();
        qWarning() << nomArtiste << categorieArtiste << idPays; //
    }

//    conn->connect();

//    QSqlRelationalTableModel *model = new QSqlRelationalTableModel();

//    model->setTable("Vynile");
//    model->setRelation(0,QSqlRelation("Exemplaire","idVynile","qualiteExemplaire"));
//    model->moveColumn();

//    model->select();

//    QSqlTableModel *model = new QSqlTableModel();
//    model->setTable("Vynile");
//    model->select();

//    model->setHeaderData(0, Qt::Horizontal,tr("Identifiant"));
//    model->setHeaderData(1, Qt::Horizontal,tr("Titre de l'album ou maxi"));
//    model->setHeaderData(2, Qt::Horizontal,tr("Quantité"));
//    model->setHeaderData(3, Qt::Horizontal,tr("Catégorie : EP / LP"));
//    model->setHeaderData(4, Qt::Horizontal,tr("Genre musical"));
//    model->setHeaderData(5, Qt::Horizontal,tr("Année de prod"));
//    model->setHeaderData(6, Qt::Horizontal,tr("Etat du vynile"));

//    ui->tableViewMain->setModel(model);
//    ui->tableViewMain->resizeColumnsToContents();
}

void MainWindow::addVinyle()
{



    //readVinyle();
//    conn->connect();

//    QSqlTableModel *model = new QSqlTableModel();
//    model->setTable("Vinyle");
//    model->select();
//    ui->tableViewMain->setModel(model);
//    ui->tableViewMain->resizeColumnsToContents();

//    for (int i=0; i<6; ++i)
//    {
//        model->insertRows(i,1);
//        model->setData(model->index(i,0), QString(i));
//        model->setData(model->index(i,1), QString(i));
//        model->setData(model->index(i,2), QString(i));
//        model->setData(model->index(i,3), QString(i));
//        model->setData(model->index(i,4), QString(i));
//        model->setData(model->index(i,5), QString(i));
//        model->submitAll();
//    }
}

void MainWindow::deleteVinyle()
{
//    conn->connect();

//    QSqlTableModel *model = new QSqlTableModel();
//    model->setTable("Vinyle");
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
