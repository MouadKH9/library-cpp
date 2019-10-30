#include "livre.h"
#include <QVector>
#ifndef LIVRETRANSACTION_H
#define LIVRETRANSACTION_H


class LivreTransaction
{
public:
    void connection();
    void addLivre(Livre);
    void deleteLivre(int);
    void updateLivre(int ,Livre);
    QVector<Livre> getLivres();
    Livre getLivre(int);
    bool livreExists(int);
};

#endif // LIVRETRANSACTION_H
