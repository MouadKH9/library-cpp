#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <string>

using namespace std;
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setUpClientsTable();
    setUpLivresTable();
}

MainWindow::~MainWindow(){
    delete ui;
}

void MainWindow::setUpClientsTable(){
    clientModel = new QStandardItemModel(4,4,this);
    ui->clientsTable->setModel(clientModel);
    ui->clientsTable->verticalHeader()->hide();
    ui->clientsTable->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    clientModel->setHeaderData(0,Qt::Orientation::Horizontal,"ID",Qt::DisplayRole);
    clientModel->setHeaderData(1,Qt::Orientation::Horizontal,"Prenom",Qt::DisplayRole);
    clientModel->setHeaderData(2,Qt::Orientation::Horizontal,"Nom",Qt::DisplayRole);
    clientModel->setHeaderData(3,Qt::Orientation::Horizontal,"Status",Qt::DisplayRole);
    // Generate data
    for(int row = 0; row < 4; row++){
        clientModel->setData(clientModel->index(row,0,QModelIndex()),row);
        clientModel->setData(clientModel->index(row,1,QModelIndex()),"Mouad");
        clientModel->setData(clientModel->index(row,2,QModelIndex()),"Khchich");
        clientModel->setData(clientModel->index(row,3,QModelIndex()),0);
    }
}

void MainWindow::setUpLivresTable(){
    livreModel = new QStandardItemModel(4,4,this);
    ui->livresTable->setModel(livreModel);
    ui->livresTable->verticalHeader()->hide();
    ui->livresTable->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    livreModel->setHeaderData(0,Qt::Orientation::Horizontal,"ID",Qt::DisplayRole);
    livreModel->setHeaderData(1,Qt::Orientation::Horizontal,"Titre",Qt::DisplayRole);
    livreModel->setHeaderData(2,Qt::Orientation::Horizontal,"Auteur",Qt::DisplayRole);
    livreModel->setHeaderData(3,Qt::Orientation::Horizontal,"Disponible",Qt::DisplayRole);
    // Generate data
    for(int row = 0; row < 4; row++){
        livreModel->setData(livreModel->index(row,0,QModelIndex()),row + 1);
        livreModel->setData(livreModel->index(row,1,QModelIndex()), "Livre");
        livreModel->setData(livreModel->index(row,2,QModelIndex()),"Mouad");
        livreModel->setData(livreModel->index(row,3,QModelIndex()),true);
    }
}


void MainWindow::on_pushButton_5_clicked(){
    ui->stackedWidget->setCurrentIndex(0);
}
