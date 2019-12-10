#include<QString>
#include<QtSql>
#ifndef DB_H
#define DB_H

class DB{
    QString path;
public:
    DB();
    DB(QString);
    QSqlDatabase connect();
};

#endif // DB_H
