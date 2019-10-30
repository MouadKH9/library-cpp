#include "reservationtransaction.h"
#include <QtSql>
#include<QDebug>


void ReservationTransaction::connection(){
    QSqlDatabase mydb = QSqlDatabase::addDatabase("QSQLITE");
    mydb.setDatabaseName("C:/Users/lg/Desktop/db.sqlite");
    if(!mydb.open()){
        qDebug()<<"we have a prob";
    }
    else{
        qDebug()<<"we don't have a prob";
    }
}

void ReservationTransaction ::addReservation(Reservation r){
    connection();
    QSqlQuery qr1 ;
    qr1.prepare("INSERT INTO Reservation ("
               "Start,"
               "End,"
               "Id_client,"
               "Id_book)"
               "VALUES (?,?,?,?);"
                );

    qr1.addBindValue(r.getDebut());
    qr1.addBindValue(r.getFin());
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
    connection();
        QSqlQuery qr ;
        qr.prepare("DELETE FROM Reservation WHERE Id="+QString::number(id));
        if(! qr.exec()){
            qDebug()<<"error in deleting values";
        }

}
void ReservationTransaction ::updateReservation(int id, Reservation r) {
    connection();
      QSqlQuery qr ;
      qr.prepare("UPDATE Reservation SET Start=?, End =? , Id_client =? , Id_book=? WHERE Id="+QString::number(id));
      qr.addBindValue(r.getDebut());
      qr.addBindValue(r.getFin());
      qr.addBindValue(r.getIdClient());
      qr.addBindValue(r.getIdLivre());
      if(! qr.exec()){
          qDebug()<<"error in edding values";
      }
}


QVector<Reservation> ReservationTransaction ::getReservations(){
   connection();
   QVector<Reservation> list;
    QSqlQuery qr;
    qr.prepare("SELECT * FROM Reservation");
    if(!qr.exec()){
          qDebug()<<"error in displaying values";
    }
    while(qr.next()){
        QString Start = qr.value(1).toString();
        QString End = qr.value(2).toString();
        int id_client = qr.value(3).toInt();
        int id_book = qr.value(5).toInt();
        int id = qr.value(0).toInt();
        int returned = qr.value(4).toInt();
        Reservation r(id,Start,End,id_client,id_book,returned);
        list.push_back(r);
    }
    return list;

}
Reservation ReservationTransaction :: getReservation(int id){
  connection();
  Reservation *r = NULL;
  QSqlQuery qr;
  qr.prepare("SELECT * FROM Reservation WHERE Id="+QString::number(id));
  if(!qr.exec()){
        qDebug()<<"error in displaying one value";
  }
  while(qr.next()){
      QString Start = qr.value(1).toString();
      QString End = qr.value(2).toString();
      int id_client = qr.value(3).toInt();
      int id_book = qr.value(4).toInt();

      r = new Reservation(Start,End,id_client,id_book);
  }
  return *r;
}






