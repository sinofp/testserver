#ifndef MYSERVER_H
#define MYSERVER_H

#include "mythread.h"
#include <QTcpServer>
class MyServer: public QTcpServer
{
    Q_OBJECT
public:
    MyServer(QObject *parent = nullptr);
    void start_at(quint16 port);
protected:
    void incomingConnection(qintptr handle);
};

#endif // MYSERVER_H
