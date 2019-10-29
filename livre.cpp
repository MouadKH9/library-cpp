#include "livre.h"

Livre::Livre(){}

Livre::Livre(int id , QString nom ,QString auteur)
{
    this->id=id;
    this->nom=nom;
    this->auteur=auteur;
}
Livre::Livre(QString nom ,QString auteur)
{
    this->id=id;
    this->nom=nom;
    this->auteur=auteur;
}

int Livre :: getId(){
    return this->id;
}
QString Livre :: getNom(){
    return this->nom ;
}
QString Livre :: getAuteur(){
    return this->auteur;
}
void Livre ::setId(int id){
    this->id =id;
}
void Livre :: setNom(QString nom){
    this->nom=nom;
}
void Livre :: setAuteur(QString auteur){
    this->auteur=auteur;
}


