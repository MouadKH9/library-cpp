#include "reservation.h"
#include <QVector>
#ifndef RESERVATIONTRANSACTION_H
#define RESERVATIONTRANSACTION_H


class ReservationTransaction
{
public:
    void connection();
    void addReservation(Reservation);
    void deleteReservation(int);
    void updateReservation(int ,Reservation);
    QVector<Reservation> getReservations();
    Reservation getReservation(int);

};

#endif // RESERVATIONTRANSACTION_H
