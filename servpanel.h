#ifndef SERVPANEL_H
#define SERVPANEL_H

#include "myserver.h"
#include <QMainWindow>

namespace Ui {
class ServPanel;
}

class ServPanel : public QMainWindow
{
    Q_OBJECT

public:
    explicit ServPanel(QWidget *parent = nullptr);
    ~ServPanel();
signals:
    void emit_send(QString str);
public slots:
    void display_recv(QString str);

private slots:
    void on_pushButton_send_clicked();

    void on_pushButton_start_clicked();

private:
    Ui::ServPanel *ui;
    MyServer myserver;

};

#endif // SERVPANEL_H
