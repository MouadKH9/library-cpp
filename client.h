#include <iostream>
#include <string>
#include <QtSql>
#ifndef CLIENT_H
#define CLIENT_H

using namespace std;
class Client
{
    int id;
    QString nom;
    QString prenom;
    int etat;

public:
    Client();
    Client(int , QString , QString , int);
    Client( QString , QString , int);
    int getId();
    QString getNom();
    QString getPrenom();
    int getEtat();
    void setId(int);
    void setNom(QString);
    void setPrenom(QString);
    void setEtat(int);
};

#endif // CLIENT_H
