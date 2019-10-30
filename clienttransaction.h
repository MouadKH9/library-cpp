#include "client.h"
#include <QVector>
#ifndef CLIENTTRANSACTION_H
#define CLIENTTRANSACTION_H


class ClientTransaction
{
public:
   void connection();
   void addClient(Client);
   void deleteClient(int );
   void updateClient(int ,Client);
   void blockClient(int);
   QVector<Client> getClients();
   Client getClient(int);
   bool clientExists(int);

};

#endif // CLIENTTRANSACTION_H
