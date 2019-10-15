#include "loginform.h"
#include "ui_loginform.h"
#include <QCloseEvent>
#include <string>

using namespace std;
LoginForm::LoginForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::LoginForm)
{
    ui->setupUi(this);
    this->setWindowFlag(Qt::WindowStaysOnTopHint,true);
}

LoginForm::~LoginForm()
{
    delete ui;
}

void LoginForm::closeEvent (QCloseEvent *event){
    event->ignore();
    QApplication::quit();
}

void LoginForm::on_pushButton_2_clicked(){
    string username = ui->lineEdit->text().toUtf8().data();
    string password = ui->lineEdit->text().toUtf8().data();
}

void LoginForm::on_pushButton_clicked(){
    QApplication::quit();
}
