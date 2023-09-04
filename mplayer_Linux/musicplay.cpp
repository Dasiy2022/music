#include "musicplay.h"
#include "ui_musicplay.h"

musicPlay::musicPlay(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::musicPlay)
{
    ui->setupUi(this);
}

musicPlay::~musicPlay()
{
    delete ui;
}
