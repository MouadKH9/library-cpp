#include "admin.h"
#include<iostream>
#include <string>

#ifndef ADMINTRANSACTION_H
#define ADMINTRANSACTION_H


class AdminTransaction
{
public:
    void connection();
    void addAdmin(Admin);
    void deleteAdmin(int);
    void updateAdmin(int,Admin);
    bool Login(Admin);
};

#endif // ADMINTRANSACTION_H
