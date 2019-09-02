#include "mythread.h"
#include "gv.h"

MyThread::MyThread(qintptr ID, QObject *parent) :
    QThread(parent)
{
    this->socketDescriptor = ID;
}

void MyThread::run()
{
    // thread starts here
    qDebug() << " Thread started";

    socket = new QTcpSocket();

    // set the ID
    if(!socket->setSocketDescriptor(this->socketDescriptor))
    {
        // something's wrong, we just emit a signal
        emit error(socket->error());
        return;
    }

    // connect socket and signal
    // note - Qt::DirectConnection is used because it's multithreaded
    //        This makes the slot to be invoked immediately, when the signal is emitted.

    connect(socket, SIGNAL(readyRead()), this, SLOT(readyRead()), Qt::DirectConnection);
    connect(socket, SIGNAL(disconnected()), this, SLOT(disconnected()));

    // 与servpanel连接
    connect(this, SIGNAL(emit_recv(QString)), pw, SLOT(display_recv(QString)));
    connect(pw, SIGNAL(emit_send(QString)), this, SLOT(send_send(QString)));

    // We'll have multiple clients, we want to know which is which
    qDebug() << socketDescriptor << " Client connected";

    // make this thread a loop,
    // thread will stay alive so that signal/slot to function properly
    // not dropped out in the middle when thread dies

    exec();
}

void MyThread::readyRead()
{
    // get the information
    QByteArray data = socket->readAll();

    // will write on server side window
    qDebug() << socketDescriptor << " Data in: " << data;

    emit emit_recv(data);
//    socket->write(Data);
}

void MyThread::disconnected()
{
    qDebug() << socketDescriptor << " Disconnected";


    disconnect(this, SIGNAL(emit_recv(QString)), pw, SLOT(display_recv(QString)));
    disconnect(pw, SIGNAL(emit_send(QString)), this, SLOT(send_send(QString)));

    socket->deleteLater();
    exit(0);
}

void MyThread::send_send(QString str)
{
    socket->write(str.toUtf8());
}
