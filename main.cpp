#include "mainwindow.h"

#include <QApplication>
#include "client.h"
#include "clienttransaction.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}

//#include <QCoreApplication>
//#include <QDebug>
//#include <QtSql>

//void addValue(QString name , QString auteur);

//int main(int argc, char *argv[])
//{
//    QCoreApplication a(argc, argv);
//    qDebug()<<"starting";

//    QSqlDatabase db ;
//    db = QSqlDatabase::addDatabase("QSQLITE");
//    db.setDatabaseName("C:/Users/lg/Desktop/db.sqlite");

//    if(! (db.open())){
//        qDebug()<<"having some problems here";
//    }
//    QString query1 = "CREATE TABLE Book ("
//                    "Id integer PRIMARY KEY AUTOINCREMENT ," "Name VARCHAR(20)," "Authur VARCHAR(20));";
//    QString query2 = "CREATE TABLE Admin ("
//                    "Id integer PRIMARY KEY AUTOINCREMENT ," "Username VARCHAR(20)," "Password VARCHAR(255));";
//    QString query3 = "CREATE TABLE Client ("
//                    "Id integer PRIMARY KEY AUTOINCREMENT ," "First VARCHAR(20)," "Last VARCHAR(20)," "Stat integer);";
//    QString query4 = "CREATE TABLE Reservation ("
//                    "Id integer PRIMARY KEY AUTOINCREMENT ," "Start DATETIME," "Id_client integer," "returned integer default 0," " Id_book integer);";
//    QSqlQuery qry;

//    if(! qry.exec(query1)){

//        qDebug()<<"error in the query1";
//    }

//    if(! qry.exec(query2)){

//        qDebug()<<"error in the query2";
//    }

//    if(! qry.exec(query3)){

//        qDebug()<<"error in the query3";
//    }

//    if(! qry.exec(query4)){

//        qDebug()<<"error in the query4";
//    }

//    db.close();

//    qDebug()<<"end";



//    return a.exec();
//}

//void addValue( QString name , QString auteur){

//    QSqlQuery qr ;
//    qr.prepare("INSERT INTO Book ("

//               "Name,"
//               "Authur)"
//               "VALUES (?,?);");

////    qr.addBindValue(id);
//    qr.addBindValue(name);
//    qr.addBindValue(auteur);

//    if(! qr.exec()){
//        qDebug()<<"error in adding values";
//    }

//}
