#include "dialogcreate.h"
#include "ui_dialogcreate.h"

Dialogcreate::Dialogcreate(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Dialogcreate)
{
    ui->setupUi(this);

    connect(ui->buttonQuitCreate, SIGNAL(clicked()), this, SLOT(quittercreate()));
}

Dialogcreate::~Dialogcreate()
{
    delete ui;
}

void Dialogcreate::quittercreate()
{
    close();
}
