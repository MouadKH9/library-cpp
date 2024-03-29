#include "livretransaction.h"
#include <QtSql>
#include<QDebug>

void LivreTransaction ::addLivre(Livre l){
    QSqlQuery qr ;
    qr.prepare("INSERT INTO Book ("
               "Name,"
               "Authur)"
               "VALUES (?,?);");


    qr.addBindValue(l.getNom());
    qr.addBindValue(l.getAuteur());

    if(! qr.exec()){
        qDebug()<<"error in adding values";
        qDebug()<<"ERROR! "<< qr.lastError();
    }

}
void LivreTransaction ::deleteLivre(int id){
        QSqlQuery qr ;
        qr.prepare("DELETE FROM Book WHERE Id="+QString::number(id));
        if(! qr.exec()){
            qDebug()<<"error in deleting values";
        }

}
void LivreTransaction ::updateLivre(int id, Livre l){
      QSqlQuery qr ;
      qr.prepare("UPDATE Book SET Name=?, Authur =? WHERE Id="+QString::number(id));
      qr.addBindValue(l.getNom());
      qr.addBindValue(l.getAuteur());
      if(! qr.exec()){
          qDebug()<<"error in edding values";
      }
}

QVector<Livre> LivreTransaction ::getLivres(QString bookName){
   QVector <Livre> list;
    QSqlQuery qr;
    qr.prepare("SELECT * FROM Book WHERE Name LIKE '%" + bookName + "%'");
    if(!qr.exec()){
          qDebug()<<"error in displaying values";
    }
    while(qr.next()){
        int id = qr.value(0).toInt();
        QString Name = qr.value(1).toString();
        QString Authur = qr.value(2).toString();
        Livre l(id,Name,Authur);
        list.push_back(l);
        qDebug()<<"Fetched: " << id << " " << Name;
    }
    return list;

}
Livre LivreTransaction :: getLivre(int id){
  Livre *l=NULL;
  QSqlQuery qr;
  qr.prepare("SELECT * FROM Book WHERE Id="+QString::number(id));
  if(!qr.exec()){
        qDebug()<<"error in displaying one value";
  }
  while(qr.next()){
      QString Name = qr.value(1).toString();
      QString Authur = qr.value(2).toString();

      l=new Livre(Name,Authur);
  }
  return *l;

}

bool LivreTransaction::livreExists(int id){
    QSqlQuery qr;
    qr.prepare("SELECT * FROM Book WHERE Id="+QString::number(id));
    if(!qr.exec()){
          qDebug()<<"error in displaying one value";
    }
    while(qr.next()){
        return true;
    }
   return false;
}
