#include "mainwindow.h"

#include <QApplication>
#include "client.h"
#include "clienttransaction.h"
int main(int argc, char *argv[])
{
    ClientTransaction ct;
    ct.getClients();
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
