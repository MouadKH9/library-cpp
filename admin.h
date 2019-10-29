#include <iostream>
#include <string>
#include <QtSql>
#include <QCryptographicHash>
#ifndef ADMIN_H
#define ADMIN_H

using namespace std;

class Admin
{
    int id;
    QString username;
    QString password;
public:
    Admin(int,QString,QString);
    Admin(QString,QString);
    int getId();
    QString getUsername();
    QString getPassword();
    void setId(int);
    void setUsername(QString);
    void setPassword(QString);

};

#endif // ADMIN_H
