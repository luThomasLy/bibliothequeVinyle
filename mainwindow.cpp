#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->buttonCreate, SIGNAL(clicked()), this, SLOT(insertDb()));
    connect(ui->buttonRead, SIGNAL(clicked()), this, SLOT(readDb()));
//    connect(ui->buttonDelete, SIGNAL(clicked()), this, SLOT(clicSupprimer()));
    connect(ui->buttonQuit, SIGNAL(clicked()), this, SLOT(quit()));
    //connect(ui->buttonSearch, SIGNAL(clicked(), this, SLOT()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::insertDb()
{
    readDb();
    QSqlTableModel model;
    model.setTable("Vinyle");
    for (int i=0; i<6; ++i)
    {
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

void MainWindow::readDb()
{
    conn->connect();

    QSqlTableModel *model = new QSqlTableModel();
    model->setTable("vinyle");
    model->select();
    ui->tableViewMain->setModel(model);
    ui->tableViewMain->resizeColumnsToContents();

//    QSqlQuery query;
//    query.exec("SELECT * FROM vinyle");
//    while (query.next())
//    {
//        int idVinyle = query.value(0).toInt();
//        QString titreVinyle = query.value(1).toString();
//        QString quantiteVinyle = query.value(2).toString();
//        QString categorieVinyle = query.value(3).toString();
//        QString genreVinyle = query.value(4).toString();
//        int anneeVinyle = query.value(5).toInt();
//        //qDebug() << idVinyle << titreVinyle << quantiteVinyle << categorieVinyle << genreVinyle << anneeVinyle;
//    }
}

//void MainWindow::clicSupprimer()
//{
//    QSqlTableModel modelView;
//    modelView.setTable("vinyle");
//    modelView.select();
//    for(int i = 0; i < modelView.rowCount(); ++i)
//    {
//        QSqlRecord record = modelView.record(i);
//        information(
//            0,
//            tr("Information récupérée"),
//            "Id : " + QString::number(record.value(0).toInt()) +
//            "\nLibellé : " + record.value(1).toString()
//            );
//    }
//}

void MainWindow::quit()
{
    conn->close_connect();
    close();
}



