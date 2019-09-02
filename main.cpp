#include "gv.h"
#include <QApplication>

ServPanel *pw;

int main(int argc, char *argv[])
{
    //https://www.bogotobogo.com/Qt/Qt5_QTcpServer_Multithreaded_Client_Server.php
    QApplication a(argc, argv);
    ServPanel w;
    pw = &w;
    w.show();

    return a.exec();
}
