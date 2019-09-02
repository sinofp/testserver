#include "myserver.h"

MyServer::MyServer(QObject *parent):
    QTcpServer(parent)
{

}

void MyServer::start_at(quint16 port) {
    if (this->listen(QHostAddress::Any, port)) {
        qDebug() << "Listening: " << port;
    } else {
        qDebug() << "Could not start server";
    }
}

void MyServer::incomingConnection(qintptr handle) {
    qDebug() << "connecting" << handle;
    //todo
    // Every new connection will be run in a newly created thread
    MyThread *thread = new MyThread(handle, this);

    // connect signal/slot
    // once a thread is not needed, it will be beleted later
    connect(thread, SIGNAL(finished()), thread, SLOT(deleteLater()));

    thread->start();
}
