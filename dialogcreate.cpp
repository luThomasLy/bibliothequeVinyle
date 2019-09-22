#include "dialogcreate.h"
#include "ui_dialogcreate.h"

Dialogcreate::Dialogcreate(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Dialogcreate)
{
    ui->setupUi(this);

    connect(ui->buttonQuitCreate, SIGNAL(clicked()), this, SLOT(quitcreate()));

    connect(ui->buttonSaveCreate, SIGNAL(clicked()), this, SLOT(savecreate()));
}

Dialogcreate::~Dialogcreate()
{
    delete ui;
}

enum{
    idVinyle = 0,
    titreAlbumMaxiVinyle = 1,
    quantiteVinyle = 2,
    categorieVinyle = 3,
    genreVinyle = 4,
    anneeVinyle = 5,
};


void Dialogcreate::creer()
{

}

void Dialogcreate::quitcreate()
{
    close();
}

void Dialogcreate::savecreate()
{

}
