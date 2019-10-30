#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <string>
#include <QMessageBox>
#include<ctime>

#include "admin.h"
#include "admintransaction.h"
#include "client.h"
#include "clienttransaction.h"
#include "livre.h"
#include "livretransaction.h"
#include "reservationtransaction.h"
#include "reservation.h"
using namespace std;
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setUpClientsTable();
    setUpLivresTable();
    setUpReservationsTable();
}

MainWindow::~MainWindow(){
    delete ui;
}

void MainWindow::setUpClientsTable(){

    ClientTransaction ct;
    QVector<Client> clients = ct.getClients();
    Client tmp;

    clientModel = new QStandardItemModel(clients.length(),4,this);
    ui->clientsTable->setModel(clientModel);
    ui->clientsTable->verticalHeader()->hide();
    ui->clientsTable->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    clientModel->setHeaderData(0,Qt::Orientation::Horizontal,"ID",Qt::DisplayRole);
    clientModel->setHeaderData(1,Qt::Orientation::Horizontal,"Prenom",Qt::DisplayRole);
    clientModel->setHeaderData(2,Qt::Orientation::Horizontal,"Nom",Qt::DisplayRole);
    clientModel->setHeaderData(3,Qt::Orientation::Horizontal,"Status",Qt::DisplayRole);
    for(int row = 0; row < clients.length(); row++){
        tmp = clients.at(row);
        qDebug() << "Adding " << tmp.getPrenom() << " " << tmp.getNom();
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
void MainWindow::deleteClients(){

    QItemSelectionModel *select = ui->clientsTable->selectionModel();
    if(!select->hasSelection()){
        qDebug() << "No selection";
        return;
    }

    ClientTransaction ct;
    QModelIndexList ids = select->selection().indexes();
    bool skipMe = false;
    for(int i = 0;i < ids.length();i++){
        for(int j=0;j<i;j++)
            if(ids.at(j).row() == ids.at(i).row()){
                skipMe = true;
                break;
            }
        if(!skipMe){
            qDebug() << "Deleting: " <<  ui->clientsTable->model()->data(clientModel->index(ids.at(i).row(),0)).toInt();
            ct.deleteClient(ui->clientsTable->model()->data(clientModel->index(ids.at(i).row(),0)).toInt());
        }
   }

}

void MainWindow::addClient(){
    QString fName = ui->clientPrenom->text();
    QString lName = ui->clientNom->text();

    ClientTransaction ct;
    Client client(fName,lName,0);
    ct.addClient(client);
    setUpClientsTable();
    ui->clientPrenom->setText("");
    ui->clientNom->setText("");
}

void MainWindow::blockClients(){
    QItemSelectionModel *select = ui->clientsTable->selectionModel();
    if(!select->hasSelection()){
        qDebug() << "No selection";
        return;
    }

    ClientTransaction ct;
    QModelIndexList ids = select->selection().indexes();
    for(int i = 0;i < ids.length();i++){
        qDebug() << "Blocking: " <<  ui->clientsTable->model()->data(clientModel->index(ids.at(i).row(),0)).toInt();
        ct.blockClient(ui->clientsTable->model()->data(clientModel->index(ids.at(i).row(),0)).toInt());
    }
}

void MainWindow::setUpLivresTable(){

    LivreTransaction lt;
    QVector<Livre> livres = lt.getLivres();
    Livre tmp;


    livreModel = new QStandardItemModel(livres.length(),3,this);
    ui->livresTable->setModel(livreModel);
    ui->livresTable->verticalHeader()->hide();
    ui->livresTable->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    livreModel->setHeaderData(0,Qt::Orientation::Horizontal,"ID",Qt::DisplayRole);
    livreModel->setHeaderData(1,Qt::Orientation::Horizontal,"Titre",Qt::DisplayRole);
    livreModel->setHeaderData(2,Qt::Orientation::Horizontal,"Auteur",Qt::DisplayRole);
//    livreModel->setHeaderData(3,Qt::Orientation::Horizontal,"Disponible",Qt::DisplayRole);
    // Generate data
    for(int row = 0; row < livres.length(); row++){
        tmp = livres.at(row);
        qDebug() << "Adding " << tmp.getNom() << " " << tmp.getAuteur();
        livreModel->setData(
                    livreModel->index(row,0,QModelIndex()),
                    tmp.getId()
                    );
        livreModel->setData(
                    livreModel->index(row,1,QModelIndex()),
                    tmp.getNom()
                    );
        livreModel->setData(
                    livreModel->index(row,2,QModelIndex()),
                    tmp.getAuteur()
                    );
    }
}

void MainWindow::addLivre(){
    QString title = ui->bookTitle->text();
    QString author = ui->bookAuthor->text();

    LivreTransaction lt;
    Livre livre(title,author);
    lt.addLivre(livre);
    setUpLivresTable();

    ui->bookTitle->setText("");
    ui->bookAuthor->setText("");
}

void MainWindow::deleteLivres(){

    QItemSelectionModel *select = ui->livresTable->selectionModel();
    if(!select->hasSelection()){
        qDebug() << "No selection";
        return;
    }

    LivreTransaction lt;
    QModelIndexList ids = select->selectedIndexes();
    qDebug() << "size: " << ids.length();
    bool skipMe = false;
    for(int i = 0;i < ids.length();i++){
        for(int j=0;j<i;j++)
            if(ids.at(j).row() == ids.at(i).row()){
                skipMe = true;
                break;
            }
        if(!skipMe){
            qDebug() << "Deleting: " <<  ui->livresTable->model()->data(livreModel->index(ids.at(i).row(),0)).toInt();
            lt.deleteLivre(ui->livresTable->model()->data(livreModel->index(ids.at(i).row(),0)).toInt());
        }
        skipMe = false;
    }
    setUpLivresTable();
}

void MainWindow::setUpReservationsTable(){
    ReservationTransaction rt;
    QVector<Reservation> reservations = rt.getReservations();
    Reservation tmp;

    reservationModel = new QStandardItemModel(reservations.length(),5,this);
    ui->reservationsTable->setModel(reservationModel);
    ui->reservationsTable->verticalHeader()->hide();
    ui->reservationsTable->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    reservationModel->setHeaderData(0,Qt::Orientation::Horizontal,"ID",Qt::DisplayRole);
    reservationModel->setHeaderData(1,Qt::Orientation::Horizontal,"ID Livre",Qt::DisplayRole);
    reservationModel->setHeaderData(2,Qt::Orientation::Horizontal,"ID Client",Qt::DisplayRole);
    reservationModel->setHeaderData(3,Qt::Orientation::Horizontal,"Debut",Qt::DisplayRole);
    reservationModel->setHeaderData(4,Qt::Orientation::Horizontal,"Retourne",Qt::DisplayRole);
    for(int row = 0; row < reservations.length(); row++){
        tmp = reservations.at(row);
        qDebug() << "Adding " << tmp.getDebut() << " " << tmp.getId() << " " << tmp.getIdLivre();
        reservationModel->setData(
                    reservationModel->index(row,0,QModelIndex()),
                    tmp.getId()
                    );
        reservationModel->setData(
                    reservationModel->index(row,1,QModelIndex()),
                    tmp.getIdLivre()
                    );
        reservationModel->setData(
                    reservationModel->index(row,2,QModelIndex()),
                    tmp.getIdClient()
                    );
        reservationModel->setData(
                    reservationModel->index(row,3,QModelIndex()),
                    tmp.getDebut()
                    );
        reservationModel->setData(
                    reservationModel->index(row,4,QModelIndex()),
                    tmp.getReturned()
                    );
        qDebug() << "Added " << tmp.getDebut()  << " " << tmp.getId() << " " << tmp.getIdLivre();
    }
}

void MainWindow::deleteReservation(){
    QItemSelectionModel *select = ui->reservationsTable->selectionModel();
    if(!select->hasSelection()){
        qDebug() << "No selection";
        return;
    }

    ReservationTransaction rt;
    QModelIndexList ids = select->selectedIndexes();
    qDebug() << "size: " << ids.length();
    bool skipMe = false;
    for(int i = 0;i < ids.length();i++){
        for(int j=0;j<i;j++)
            if(ids.at(j).row() == ids.at(i).row()){
                skipMe = true;
                break;
            }
        if(!skipMe){
            qDebug() << "Deleting: " <<  ui->reservationsTable->model()->data(livreModel->index(ids.at(i).row(),0)).toInt();
            rt.deleteReservation(ui->reservationsTable->model()->data(reservationModel->index(ids.at(i).row(),0)).toInt());
        }
        skipMe = false;
    }
    setUpReservationsTable();
}

void MainWindow::returnReservation(){
    QItemSelectionModel *select = ui->reservationsTable->selectionModel();
    if(!select->hasSelection()){
        qDebug() << "No selection";
        return;
    }

    ReservationTransaction rt;
    QModelIndexList ids = select->selectedIndexes();
    qDebug() << "size: " << ids.length();
    bool skipMe = false;
    Reservation tmp;
    for(int i = 0;i < ids.length();i++){
        for(int j=0;j<i;j++)
            if(ids.at(j).row() == ids.at(i).row()){
                skipMe = true;
                break;
            }
        if(!skipMe){
            qDebug() << "Returning: " <<  ui->reservationsTable->model()->data(livreModel->index(ids.at(i).row(),0)).toInt();
            tmp = rt.getReservation(ui->reservationsTable->model()->data(reservationModel->index(ids.at(i).row(),0)).toInt());
            tmp.setReturned(1);
            rt.updateReservation(tmp.getId(),tmp);
        }
        skipMe = false;
    }
    setUpReservationsTable();
}

void MainWindow::addReservation(){
    int client = ui->clientID->text().toInt();
    int livre = ui->bookID->text().toInt();

    LivreTransaction lt;
    ClientTransaction ct;

    if(!lt.livreExists(livre) || !ct.clientExists(client)){
        QMessageBox *msgBox = new QMessageBox(this);
        msgBox->warning(this,"Erreur","Impossible de trouver le client ou le livre..");
        return;
    }


    time_t tt;
    struct tm * ti;

    time (&tt);

    ti = localtime(&tt);
    int day = ti->tm_mday;
    int month = ti->tm_mon + 1;
    int year = 1900 + ti->tm_year;
    string today = to_string(day) + '-' + to_string(month) + '-' + to_string(year);
    string returnDate = to_string(ti->tm_mday) + '-' + to_string(ti->tm_mon + 1) + '-' + to_string(1900 + ti->tm_year);
    ReservationTransaction rt;
    Reservation r(QString::fromStdString(today),client,livre);
    rt.addReservation(r);
    setUpReservationsTable();
    ui->bookID->setText("");
    ui->clientID->setText("");
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
    addClient();
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

void MainWindow::on_pushButton_7_clicked()
{
    setUpClientsTable();
}

void MainWindow::on_pushButton_6_clicked()
{
    deleteClients();
}

void MainWindow::on_pushButton_8_clicked()
{
    blockClients();
}

void MainWindow::on_pushButton_19_clicked()
{
    addLivre();
}

void MainWindow::on_pushButton_21_clicked()
{
    setUpLivresTable();
}

void MainWindow::on_pushButton_20_clicked()
{
    deleteLivres();
}

void MainWindow::on_bookTitle_textChanged(const QString &arg1)
{
    ui->pushButton_19->setEnabled(ui->bookTitle->text().length() > 0 && ui->bookAuthor->text().length() > 0);
}

void MainWindow::on_bookAuthor_textChanged(const QString &arg1)
{
    ui->pushButton_19->setEnabled(ui->bookTitle->text().length() > 0 && ui->bookAuthor->text().length() > 0);
}

void MainWindow::on_pushButton_clicked()
{
    addReservation();
}

void MainWindow::on_pushButton_2_clicked()
{
    deleteReservation();
}

void MainWindow::on_pushButton_9_clicked()
{
    returnReservation();
}

void MainWindow::on_clientID_textChanged(const QString &arg1)
{
    ui->pushButton->setEnabled(ui->bookID->text().length() > 0 && ui->clientID->text().length() > 0);
}

void MainWindow::on_bookID_textChanged(const QString &arg1)
{
    ui->pushButton->setEnabled(ui->bookID->text().length() > 0 && ui->clientID->text().length() > 0);
}
