#include "mainwindow.h"
#include "longinform.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    LonginForm lg;

    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("localhost");
    db.setDatabaseName("mplayer_user");
    db.setPort(3306);
    db.setUserName("root");
    db.setPassword("root");
    db.open();

    lg.show();


    return a.exec();
}
