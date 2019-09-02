#ifndef MYTHREAD_H
#define MYTHREAD_H

#include <QThread>
#include <QTcpSocket>

class MyThread: public QThread
{
    Q_OBJECT
public:
    explicit MyThread(qintptr ID, QObject *parent = nullptr);
    void run();
    signals:
        void error(QTcpSocket::SocketError socketerror);
        void emit_recv(QString str);

public slots:
    void readyRead();
    void disconnected();
    void send_send(QString str);
private:
    QTcpSocket *socket;
    qintptr socketDescriptor;
};

#endif // MYTHREAD_H
