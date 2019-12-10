#include "reservationtransaction.h"
#include <QtSql>
#include<QDebug>


void ReservationTransaction ::addReservation(Reservation r){
    QSqlQuery qr1 ;
    qr1.prepare("INSERT INTO Reservation ("
               "Start,"
               "Id_client,"
               "Id_book)"
               "VALUES (?,?,?);"
                );

    qr1.addBindValue(r.getDebut());
    qr1.addBindValue(r.getIdClient());
    qr1.addBindValue(r.getIdLivre());

    if(! qr1.exec()){
        qDebug()<<"error in adding values";
        qDebug()<<"ERROR! "<< qr1.lastError();
    }else{
        qDebug() << "Inserting reservation: " << r.getIdClient() << " " << r.getIdLivre();
    }
}

void ReservationTransaction ::deleteReservation(int id) {
    QSqlQuery qr ;
    qr.prepare("DELETE FROM Reservation WHERE Id="+QString::number(id));
    if(! qr.exec()){
        qDebug()<<"error in deleting values";
    }

}
void ReservationTransaction ::updateReservation(int id, Reservation r) {
    QSqlQuery qr ;
    qr.prepare("UPDATE Reservation SET Start=? , Id_client =? , Id_book=? , returned=? WHERE Id="+QString::number(id));
    qr.addBindValue(r.getDebut());
    qr.addBindValue(r.getIdClient());
    qr.addBindValue(r.getIdLivre());
    qr.addBindValue(r.getReturned());
    if(! qr.exec())
        qDebug()<<"error in edding values";
    else
        qDebug() << "Updated #"<< id<< " " << r.getIdLivre();
}


QVector<Reservation> ReservationTransaction ::getReservations(int returned,QString clientName, QString bookName){
   QVector<Reservation> list;
    QSqlQuery qr;
    QString returnedCondition = "";
    if(returned >= 0) returnedCondition = " AND r.returned = " + QString::fromStdString(to_string(returned));
    QString QUERY = "SELECT * FROM Reservation r, Client c, Book l WHERE l.Name LIKE '%" + bookName + "%' AND c.First || ' ' || c.Last LIKE '%" + clientName + "%' AND c.id = r.Id_client AND l.id = r.Id_book " + returnedCondition;
    qr.prepare(QUERY);
    if(!qr.exec()){
          qDebug()<< QUERY;
    }
    while(qr.next()){
        int id = qr.value(0).toInt();
        QString Start = qr.value(1).toString();
        int id_client = qr.value(2).toInt();
        int id_book = qr.value(4).toInt();
        int returned = qr.value(3).toInt();
        Reservation r(id,Start,id_client,id_book,returned);
        list.push_back(r);
    }
    return list;

}
Reservation ReservationTransaction :: getReservation(int id){
  Reservation *r = NULL;
  QSqlQuery qr;
  qr.prepare("SELECT * FROM Reservation WHERE Id="+QString::number(id));
  if(!qr.exec()){
        qDebug()<<"error in displaying one value";
  }
  while(qr.next()){
      int id = qr.value(0).toInt();
      QString Start = qr.value(1).toString();
      int id_client = qr.value(2).toInt();
      int returned = qr.value(3).toInt();
      int id_book = qr.value(4).toInt();

      r = new Reservation(id,Start,id_client,id_book,returned);
  }
  return *r;
}






