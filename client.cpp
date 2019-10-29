#include "client.h"

Client :: Client(){}

Client::Client(int id ,  QString prenom ,QString nom , int etat)
{
    this->id=id;
    this->nom=nom;
    this->prenom=prenom;
    this->etat=etat;

}
Client::Client( QString prenom , QString nom  , int etat)
{
    this->nom=nom;
    this->prenom=prenom;
    this->etat=etat;

}
int Client ::getId(){
    return this->id;
}
QString Client::getNom(){
    return this->nom;
}
QString Client ::getPrenom(){
    return this->prenom;
}
int Client ::getEtat(){
    return this->etat;
}
void Client ::setId(int id){
    this->id =id;
}
void Client ::setNom(QString nom){
    this->nom=nom;
}
void Client ::setPrenom(QString prenom){
    this->prenom=prenom;
}
void Client ::setEtat(int etat){
    this->etat=etat;
}
