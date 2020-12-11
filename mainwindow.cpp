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

    ui->tableViewMain->setModel(model); // Liaison entre le modèle et le tableau
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::readVinyle()
{
    conn->connect();
    query.exec("SELECT titreAlbumMaxiVinyle, quantiteVinyle, categorieVinyle, genreVinyle, anneeVinyle, libelleExemplaire, qualiteExemplaire FROM Vinyle "
               "INNER JOIN Exemplaire ON Exemplaire.idVinyle = Vinyle.idVinyle "

               /*"SELECT nomArtiste, categorieArtiste, idPays AS Artiste, nomChanson AS Chanson FROM Artiste INNER JOIN compose ON compose.idArtiste = Artiste.idArtiste "
               "INNER JOIN chanson ON chanson.idChanson = compose.idChanson"*/);
    while (query.next())
    {
        QString titreAlbumMaxiVinyle = query.value(0).toString();
        QString quantiteVinyle = query.value(1).toString();
        QString categorieVinyle = query.value(2).toString();
        QString genreVinyle = query.value(3).toString();
        int anneeVinyle = query.value(4).toInt();
        QString libelleExemplaire = query.value(5).toString();
        QString qualiteExemplaire = query.value(6).toString();

        qWarning() << titreAlbumMaxiVinyle << quantiteVinyle << categorieVinyle << genreVinyle << anneeVinyle << libelleExemplaire << qualiteExemplaire;

//        QString nomArtiste = query.value(0).toString();
//        QString categorieArtiste = query.value(1).toString();
//        QString idPays = query.value(2).toString();
//        QString nomChanson = query.value(3).toString();
//        qWarning() << nomArtiste << categorieArtiste << idPays << nomChanson;
    }
//    model->setTable("Artiste");

//    model->setRelation(2, QSqlRelation("idArtiste", "id", "name"));
//    model->setRelation(3, QSqlRelation("country", "id", "name"));

//    model->select();
}

void MainWindow::addVinyle()
{
    conn->connect();
    //les requêtes préaprées avec marqueur named binding
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
    model->setTable("Artiste");
    model->select();
}

void MainWindow::deleteVinyle()
{
    conn->connect();

    query.prepare("DELETE FROM Artiste WHERE nomArtiste = (:nomArtiste)");
    query.bindValue(":nomArtiste", "IAM");
    query.bindValue(":categorieArtiste", "Rappeur");
    query.bindValue(":idPays", "FRANCE");

    if (!query.exec())
    {
        qWarning() << "error";
    }
    model->setTable("Artiste");
    model->select();
}

void MainWindow::quit()
{
    conn->close_connect();
    close();
}
