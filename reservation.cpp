#include "reservation.h"
Reservation::Reservation(){}

Reservation::Reservation(int id , QString debut , int idClient , int idLivre)
{
    this->id=id;
    this->debut=debut;
    this->idClient=idClient;
    this->idLivre=idLivre;
}
Reservation::Reservation(int id , QString debut , int idClient , int idLivre,int returned)
{
    this->id=id;
    this->debut=debut;
    this->idClient=idClient;
    this->idLivre=idLivre;
    this->returned=returned;
}
Reservation::Reservation(QString debut  , int idClient , int idLivre)
{
    this->debut=debut;
    this->idClient=idClient;
    this->idLivre=idLivre;
}
int Reservation::getId(){
    return this->id;
}
QString Reservation :: getDebut(){
    return this->debut;
}
int Reservation::getIdLivre(){
    return this->idLivre;
}
int Reservation::getIdClient(){
    return this->idClient;
}
void Reservation::setId(int id ){
    this->id=id;
}
void Reservation::setDebut(QString debut){
    this->debut=debut;
}
void Reservation::setIdClient(int idClient){
    this->idClient=idClient;
}
void Reservation :: setIdLivre(int idLivre){
    this->idLivre=idLivre;
}
void Reservation::setReturned(int n){
    this->returned = n;
}
int Reservation::getReturned(){
    return this->returned;
}



