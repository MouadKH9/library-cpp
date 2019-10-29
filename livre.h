#include <iostream>
#include <string>
#include <QtSql>
#ifndef LIVRE_H
#define LIVRE_H

using namespace std;
class Livre
{
    int id;
   QString nom;
    QString auteur;

public:
    Livre();
    Livre(int  , QString  , QString );
    Livre( QString  , QString );

    int getId();
    QString getNom();
    QString getAuteur();
    void setId(int);
    void setNom(QString);
    void setAuteur(QString);


};

#endif // LIVRE_H
