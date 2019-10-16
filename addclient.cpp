#include "addclient.h"
#include "ui_addclient.h"

AddClient::AddClient(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AddClient)
{
    ui->setupUi(this);
}

AddClient::~AddClient()
{
    delete ui;
}
