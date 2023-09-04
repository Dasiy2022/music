#include "longinform.h"
#include "ui_longinform.h"
#include "mainwindow.h"

LonginForm::LonginForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::LonginForm)
{
    setAttribute(Qt::WA_StyledBackground);
    this->setWindowTitle("Login");
    this->setWindowIcon(QIcon(":/player/logo/logoMax.png"));
    ui->setupUi(this);
}

LonginForm::~LonginForm()
{
    delete ui;
}

void LonginForm::on_pushButton_2_clicked()
{
    QString usernm,passwd,nameMsg;
    bool login = false;
    QString user = ui->lineEdit->text();
    QString pass = ui->lineEdit_2->text();

    QSqlQuery query("select * from user");
    while (query.next()) {
        usernm = query.value(0).toString();
        passwd = query.value(1).toString();
        if(user == usernm && pass == passwd)
        {
            login = true;
            nameMsg = query.value(2).toString();
            break;
        }
    }
    if(login)
    {
        QString msg = nameMsg + " *欢迎*";
        QMessageBox::about(this,"提示",msg);
        MainWindow *win = new MainWindow();
        win->name = nameMsg;
        this->close();
        win->show();
    }
    else
        QMessageBox::warning(this,"提示","用户名或密码错误");

}

void LonginForm::on_pushButton_clicked()
{
    QSqlQuery query;
    QString user = ui->lineEdit->text();
    QString pass = ui->lineEdit_2->text();
    QString insert = "insert into user(userid,passwd) values("
            + user + "," + pass + ")";
    if(query.exec(insert))
    {
        QMessageBox::about(this,"提示","注册成功");
        ui->lineEdit->clear();
        ui->lineEdit_2->clear();
    }
    else
        QMessageBox::warning(this,"提示","注册失败");
}
