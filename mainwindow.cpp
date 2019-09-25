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

//    QSqlQuery requeteur;
//    requeteur.exec("INSERT INTO Vinyle(idVinyle, titreAlbumMaxiVinyle, quantiteVinyle, categorieVinyle, genreVinyle, anneeVinyle)"
//                   "VALUES (1, 'nouveauVinyle')");

//    while(requeteur.next()){
//        int idVinyle = requeteur.value(0).toInt();
//        QString titreAlbumMaxiVinyle = requeteur.value(1).toString();
//        int quantiteVinyle = requeteur.value(2).toInt();
//        QString categorieVinyle = requeteur.value(3).toString();
//        QString genreVinyle = requeteur.value(4).toString();
//        int anneeVinyle = requeteur.value(5).toInt();

//        QMessageBox::information(
//                    nullptr,
//                    QObject::tr("information récupérée"),
//                    "Id : " + QString::number(idVinyle) +
//                    "\nTitre : " + titreAlbumMaxiVinyle +
//                    "\nQuantite : " + QString::number(quantiteVinyle) +
//                    "\nCategorie : " + categorieVinyle +
//                    "\nGenre : " + genreVinyle +
//                    "\nAnnee : " + QString::number(anneeVinyle)
//                                 );
//    }

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



