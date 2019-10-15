#ifndef LOGINFORM_H
#define LOGINFORM_H

#include <QWidget>

namespace Ui {
class LoginForm;
}

class LoginForm : public QWidget
{
    Q_OBJECT

public:
    explicit LoginForm(QWidget *parent = nullptr);
    ~LoginForm();

private:
    Ui::LoginForm *ui;

protected:
    void closeEvent(QCloseEvent *event) override;
private slots:
    void on_pushButton_2_clicked();
    void on_pushButton_clicked();
};

#endif // LOGINFORM_H
