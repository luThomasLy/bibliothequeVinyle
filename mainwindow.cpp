#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QModelIndex"
#include "QDebug"
#include "QSqlRelationalTableModel"
#include "QSqlRelationalDelegate"
#include "qsqlquery.h"
#include "qsqlerror.h"
#include "QMessageBox"
#include "dbmanager.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

//    connect(ui->buttonCreate, SIGNAL(clicked()), this, SLOT(clicCreer()));
    connect(ui->buttonRead, SIGNAL(clicked()), this, SLOT(read()));
//    connect(ui->buttonDelete, SIGNAL(clicked()), this, SLOT(clicSupprimer()));
    connect(ui->buttonQuit, SIGNAL(clicked()), this, SLOT(quit()));
    //connect(ui->buttonSearch, SIGNAL(clicked(), this, SLOT()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

//void MainWindow::clicCreer()
//{
//    clicLecture();

//    QSqlTableModel model;
//    model.setTable("Vinyle");
//    for (int i = 0; i<6; ++i) {
//        model.insertRows(i,1);
//        model.setData(model.index(i,0), i);
//        model.setData(model.index(i,1), i);
//        model.setData(model.index(i,2), i);
//        model.setData(model.index(i,3), i);
//        model.setData(model.index(i,4), i);
//        model.setData(model.index(i,5), i);
//        model.submitAll();
//    }
//}

void MainWindow::read()
{
    conn->connect();

    QSqlTableModel *model = new QSqlTableModel();
    model->setTable("vinyle");
    model->select();

//    QSqlQuery query;
//    result_read = query.exec("SELECT * FROM vinyle");

    ui->tableViewMain->setModel(model);
    ui->tableViewMain->resizeColumnsToContents();

    close();
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
    close();
}



