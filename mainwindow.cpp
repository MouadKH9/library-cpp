#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <string>
#include <QMessageBox>


#include "admin.h"
#include "admintransaction.h"
#include "client.h"
#include "clienttransaction.h"
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
    ClientTransaction ct;
    QVector<Client> clients = ct.getClients();
    // Generate data
    Client tmp;
    for(int row = 0; row < clients.length(); row++){
        tmp = clients.at(row);
        qDebug() << tmp.getId();
        clientModel->setData(
                    clientModel->index(row,0,QModelIndex()),
                    tmp.getId()
                    );
        clientModel->setData(
                    clientModel->index(row,1,QModelIndex()),
                    tmp.getPrenom()
                    );
        clientModel->setData(
                    clientModel->index(row,2,QModelIndex()),
                    tmp.getNom()
                    );
        clientModel->setData(
                    clientModel->index(row,3,QModelIndex()),
                    tmp.getEtat()
                    );
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
    QString username = ui->lineEdit->text().toUtf8();
    QString password = ui->lineEdit_2->text().toUtf8();
    Admin admin(username,password);
    AdminTransaction at;
    if(at.Login(admin))
        ui->stackedWidget->setCurrentIndex(0);
    else{
        QMessageBox *msgBox = new QMessageBox(this);
        msgBox->warning(this,"Erreur","Les informations d'identification sont invalides.");

    }

}

void MainWindow::on_pushButton_16_clicked(){
    QList<QStandardItem *> items;

    items.append(new QStandardItem("1"));
    items.append(new QStandardItem(ui->clientPrenom->text().toUtf8().data()));
    items.append(new QStandardItem(ui->clientNom->text().toUtf8().data()));
    items.append(new QStandardItem("0"));
    clientModel->appendRow(items);

    ui->clientPrenom->setText("");
    ui->clientNom->setText("");
}

void MainWindow::on_clientPrenom_textChanged(const QString &arg1){
    ui->pushButton_16->setEnabled(ui->clientPrenom->text().length() > 0 && ui->clientNom->text().length() > 0);
}

void MainWindow::on_clientNom_textChanged(const QString &arg1)
{
    ui->pushButton_16->setEnabled(ui->clientPrenom->text().length() > 0 && ui->clientNom->text().length() > 0);
}

void MainWindow::on_pushButton_4_clicked()
{
    QApplication::exit();
}
