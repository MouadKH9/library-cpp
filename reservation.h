#include <iostream>
#include <string>
#include <QtSql>
#ifndef RESERVATION_H
#define RESERVATION_H

using namespace std;
class Reservation
{
    int id ;
    QString debut;
    int idClient;
    int idLivre;
    int returned;
public:
    Reservation();
    Reservation(int,QString,int,int);
    Reservation(int,QString,int,int,int);
    Reservation(QString,int,int);
    int getId();
    QString getDebut();
    int getIdClient();
    int getIdLivre();
    void setId(int);
    void setDebut(QString);
    void setIdClient(int);
    void setIdLivre(int);
    void setReturned(int);
    int getReturned();
};

#endif // RESERVATION_H
