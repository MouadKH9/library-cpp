#include "clienttransaction.h"
#include <QtSql>
#include<QDebug>
#include <QVector>
using namespace std;

void ClientTransaction::connection(){
    QSqlDatabase mydb = QSqlDatabase::addDatabase("QSQLITE");
    mydb.setDatabaseName("C:/Users/lg/Desktop/db.sqlite");
    if(!mydb.open()){
        qDebug()<<"we have a prob";
    }
    else{
        qDebug()<<"we don't have a prob";
    }
}


void ClientTransaction ::addClient(Client c){
    connection();
    QSqlQuery qr1 ;
    qr1.prepare("INSERT INTO Client ("
               "First,"
               "Last,"
               "Stat)"
               "VALUES (?,?,?);"
                );

    qr1.addBindValue(c.getPrenom());
    qr1.addBindValue(c.getNom());
    qr1.addBindValue(c.getEtat());

    if(! qr1.exec()){
        qDebug()<<"error in adding values";
        qDebug()<<"ERROR! "<< qr1.lastError();
    }else
        qDebug() << "added client " << c.getPrenom() << " " << c.getNom();
}

void ClientTransaction ::deleteClient(int id) {
    connection();
        QSqlQuery qr ;
        qr.prepare("DELETE FROM Client WHERE Id="+QString::number(id));
        if(! qr.exec()){
            qDebug()<<"error in deleting values";
        }

}
void ClientTransaction ::updateClient(int id, Client c) {
    connection();
      QSqlQuery qr ;
      qr.prepare("UPDATE Client SET First=?, Last =? , Stat=? WHERE Id="+QString::number(id));
      qr.addBindValue(c.getPrenom());
      qr.addBindValue(c.getNom());
      qr.addBindValue(c.getEtat());
      if(! qr.exec()){
          qDebug()<<"error in edding values";
      }
}
void ClientTransaction ::blockClient(int id){
    connection();
      QSqlQuery qr ;
      qr.prepare("UPDATE Client SET Stat=1 WHERE Id="+QString::number(id));
      if(! qr.exec()){
          qDebug()<<"error in blocking client";
      }

}

QVector<Client> ClientTransaction ::getClients(){

    QVector <Client> list ;
   connection();
    QSqlQuery qr;
    qr.prepare("SELECT * FROM Client");

    if(!qr.exec()){
          qDebug()<<"error in displaying values";
    }
    while(qr.next()){
        QString First = qr.value(1).toString();
        QString Last = qr.value(2).toString();
        int Stat = qr.value(3).toInt();
        int id = qr.value(0).toInt();
        Client c(id,First,Last,Stat);
        list.push_back(c);
    }
    return list;

}
Client ClientTransaction :: getClient(int id){
  connection();
  Client *c = NULL ;
  QSqlQuery qr;
  qr.prepare("SELECT * FROM Client WHERE Id="+QString::number(id));

  if(!qr.exec()){
        qDebug()<<"error in displaying one value";
  }
  while(qr.next()){
      QString First = qr.value(1).toString();
      QString Last = qr.value(2).toString();
      int Stat = qr.value(3).toInt();

      c = new Client(First,Last,Stat);

  }

 return *c;
}


