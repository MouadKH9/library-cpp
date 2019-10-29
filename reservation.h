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
    QString fin;
    int idClient;
    int idLivre;
public:
    Reservation();
    Reservation(int,QString,QString,int,int);
    Reservation(QString,QString,int,int);
    int getId();
    QString getDebut();
    QString getFin();
    int getIdClient();
    int getIdLivre();
    void setId(int);
    void setDebut(QString);
    void setFin(QString);
    void setIdClient(int);
    void setIdLivre(int);
};

#endif // RESERVATION_H
