#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->buttonCreate, SIGNAL(clicked()), this, SLOT(addVynile()));
    connect(ui->buttonRead, SIGNAL(clicked()), this, SLOT(readVynile()));
    connect(ui->buttonDelete, SIGNAL(clicked()), this, SLOT(deleteVynile()));
    connect(ui->buttonQuit, SIGNAL(clicked()), this, SLOT(quit()));
    //connect(ui->buttonSearch, SIGNAL(clicked(), this, SLOT()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::readVynile()
{
    conn->connect();

    QSqlTableModel *model = new QSqlTableModel();
    model->setTable("Vynile");
    model->select();
    ui->tableViewMain->setModel(model);
    ui->tableViewMain->resizeColumnsToContents();
}

void MainWindow::addVynile()
{
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
    QSqlTableModel modelView;
    modelView.setTable("Vynile");
    modelView.select();

    if(modelView.rowCount() > 0)
    {
        modelView.removeRows(0, modelView.rowCount());
        modelView.submitAll();
    }
}

void MainWindow::quit()
{
    conn->close_connect();
    close();
}
