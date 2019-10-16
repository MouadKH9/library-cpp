#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
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
    static void enable();

private slots:
    void on_pushButton_5_clicked();

private:
    Ui::MainWindow *ui;
    QStandardItemModel *clientModel;
    QStandardItemModel *livreModel;
    QStandardItemModel *reservationModel;
    void setUpClientsTable();
    void setUpLivresTable();
    void setUpReservationsTable();
};
#endif // MAINWINDOW_H
