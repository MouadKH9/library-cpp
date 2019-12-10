#include"DB.h"

using namespace std;

DB::DB(){}

DB::DB(QString path){
    this->path = path;
}

QSqlDatabase DB::connect(){
    QSqlDatabase mydb = QSqlDatabase::addDatabase("QSQLITE");
    mydb.setDatabaseName(this->path);

    if(!mydb.open())
        qDebug()<<"Error connecting to the DB: " << mydb.lastError() ;
    else
        qDebug()<<"Connected successfully to the DB.";

    return mydb;
}
