
#include "admin.h"

Admin::Admin(int id , QString username, QString password )
{
    this->id=id;

    this->username=username;
    this->password=password;

}
Admin::Admin( QString username, QString password )
{

    this->password=password;
    this->username=username;

}
int Admin :: getId(){
    return this->id;
}
QString Admin :: getUsername(){
    return this->username;
}
QString Admin ::getPassword(){
    return this->password;
}
void Admin ::setId(int id){
    this->id=id;
}
void Admin :: setPassword(QString password){
    this->password=password;
}
void Admin ::setUsername(QString username){
    this->username=username;
}


