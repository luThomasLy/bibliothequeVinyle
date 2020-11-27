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
}

void MainWindow::addVinyle()
{
    conn->connect();
    //les requêtes préaprées avec marqueur ?
    query.prepare("INSERT INTO Artiste (nomArtiste, categorieArtiste, idPays) VALUES (:nomArtiste,:categorieArtiste,:idPays)");
    query.bindValue(":nomArtiste", "IAM");
    query.bindValue(":categorieArtiste", "Rappeur");
    query.bindValue(":idPays", "FRANCE");

    query.exec();

    if (query.execBatch())
    {
        qDebug("Ça marche !");
    }
    else
    {
        qDebug("Ça marche pas !");
    }

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
