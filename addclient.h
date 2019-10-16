#ifndef ADDCLIENT_H
#define ADDCLIENT_H

#include <QWidget>

namespace Ui {
class AddClient;
}

class AddClient : public QWidget
{
    Q_OBJECT

public:
    explicit AddClient(QWidget *parent = nullptr);
    ~AddClient();

private:
    Ui::AddClient *ui;
};

#endif // ADDCLIENT_H
