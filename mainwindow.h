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

    void on_pushButton_16_clicked();

    void on_clientPrenom_textChanged(const QString &arg1);

    void on_clientNom_textChanged(const QString &arg1);

    void on_pushButton_4_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_19_clicked();

    void on_pushButton_21_clicked();

    void on_pushButton_20_clicked();

    void on_bookTitle_textChanged(const QString &arg1);

    void on_bookAuthor_textChanged(const QString &arg1);

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_9_clicked();

    void on_clientID_textChanged(const QString &arg1);

    void on_bookID_textChanged(const QString &arg1);

    void on_pushButton_3_clicked();

    void on_comboBox_currentIndexChanged(int index);

    void on_lineEdit_3_textChanged(const QString &arg1);

    void on_lineEdit_4_textChanged(const QString &arg1);

    void on_lineEdit_5_textChanged(const QString &arg1);

    void on_lineEdit_6_textChanged(const QString &arg1);

private:
    Ui::MainWindow *ui;
    QStandardItemModel *clientModel;
    QStandardItemModel *livreModel;
    QStandardItemModel *reservationModel;
    void setUpClientsTable();
    void addClient();
    void deleteClients();
    void blockClients();
    void setUpLivresTable();
    void addLivre();
    void deleteLivres();
    void setUpReservationsTable();
    void addReservation();
    void returnReservation();
    void deleteReservation();
};
#endif // MAINWINDOW_H
