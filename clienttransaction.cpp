#include "clienttransaction.h"
#include <QtSql>
#include<QDebug>
#include <QVector>
using namespace std;


void ClientTransaction ::addClient(Client c){
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

    if(! qr1.exec())
        qDebug()<<"Error adding new client: " << qr1.lastError();
    else
        qDebug() << "Added client " << c.getPrenom() << " " << c.getNom();
}

void ClientTransaction ::deleteClient(int id) {
    QSqlQuery qr ;
    qr.prepare("DELETE FROM Client WHERE Id="+QString::number(id));
    if(! qr.exec())
        qDebug()<<"Error deleting client: " << qr.lastError();

}
void ClientTransaction ::updateClient(int id, Client c) {
      QSqlQuery qr ;
      qr.prepare("UPDATE Client SET First=?, Last =? , Stat=? WHERE Id="+QString::number(id));
      qr.addBindValue(c.getPrenom());
      qr.addBindValue(c.getNom());
      qr.addBindValue(c.getEtat());
      if(! qr.exec())
          qDebug()<<"Error updating client: "<< qr.lastError();
}
void ClientTransaction ::toggleBlockClient(int id){
      QSqlQuery qr ;
      Client c = getClient(id);
      qr.prepare("UPDATE Client SET Stat=" + QString::number(c.getEtat() == 0 ? 1 : 0) + " WHERE Id="+QString::number(id));
      if(! qr.exec())
          qDebug()<<"Error in blocking client: " << qr.lastError();

}

QVector<Client> ClientTransaction ::getClients(QString clientName){

    QVector <Client> list ;
    QSqlQuery qr;
    qr.prepare("SELECT * FROM Client WHERE First || ' ' || Last LIKE '%" + clientName + "%'");

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

bool ClientTransaction::clientExists(int id){
    QSqlQuery qr;
    qr.prepare("SELECT * FROM Client WHERE Id="+QString::number(id));
    if(!qr.exec()){
          qDebug()<<"error in displaying one value";
    }
    while(qr.next()){
        return true;
    }
   return false;
}


