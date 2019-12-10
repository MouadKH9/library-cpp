#include <QtSql>
#include<QDebug>
#include "admintransaction.h"

bool AdminTransaction::Login(Admin a){
    QCryptographicHash calculatMD5 (QCryptographicHash::Md5);
    QByteArray input;
    input.append(a.getPassword());
    calculatMD5.addData(input);
    QString password  = QTextCodec::codecForMib(106)->toUnicode(calculatMD5.result().toHex());
    QSqlQuery qr1 ;
    qr1.prepare("SELECT * FROM Admin WHERE Username=? AND Password=?");
    qr1.addBindValue(a.getUsername());
    qr1.addBindValue(password);
    if(qr1.exec())
        while(qr1.next())
            return true;
    return false;
}

void AdminTransaction ::addAdmin(Admin a){
    QSqlQuery qr1 ;
    qr1.prepare("INSERT INTO Admin ("
               "Username,"
               "Password)"
               "VALUES (?,?);"
                );
    QCryptographicHash calculatMD5 (QCryptographicHash::Md5);
    QByteArray input;
    input.append(a.getPassword());
    calculatMD5.addData(input);

    qr1.addBindValue(a.getUsername());
    QString password  = QTextCodec::codecForMib(106)->toUnicode(calculatMD5.result().toHex());

    qr1.addBindValue(password);
    if(! qr1.exec()){
        qDebug()<<"error in adding values -- here";
        qDebug()<<"ERROR! "<< qr1.lastError();
    }else{
        qDebug() << "Cool. Added admin: " << a.getUsername();
    }
}
void AdminTransaction ::deleteAdmin(int id) {
    QSqlQuery qr ;
    qr.prepare("DELETE FROM Admin WHERE Id="+QString::number(id));
    if(! qr.exec())
        qDebug()<<"error in deleting values";
}

void AdminTransaction ::updateAdmin(int id, Admin a) {
      QSqlQuery qr ;
      qr.prepare("UPDATE Admin SET Username=?, Password=? WHERE Id="+QString::number(id));
      qr.addBindValue(a.getUsername());
      qr.addBindValue(a.getPassword());
      if(! qr.exec())
          qDebug()<<"error in edding values";
}
