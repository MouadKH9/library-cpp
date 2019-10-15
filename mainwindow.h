#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "loginform.h"
#include <QTableView>
#include <QItemDelegate>
#include <QStandardItemModel>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    LoginForm *loginForm;
    QStandardItemModel *clientModel;
    QStandardItemModel *livreModel;
    QStandardItemModel *reservationModel;
    void setUpClientsTable();
    void setUpLivresTable();
    void setUpReservationsTable();
};
#endif // MAINWINDOW_H
