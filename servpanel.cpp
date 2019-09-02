#include "servpanel.h"
#include "ui_servpanel.h"

ServPanel::ServPanel(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ServPanel)
{
    ui->setupUi(this);
    ui->spinBox_port->setRange(0, 65535);
    ui->spinBox_port->setValue(1234);

    setFixedSize(this->width(), this->height());
}

ServPanel::~ServPanel()
{
    delete ui;
}

void ServPanel::display_recv(QString str) {
    ui->textEdit_get->setText(str);
}

void ServPanel::on_pushButton_send_clicked()
{
    QString buf = ui->textEdit_post->toPlainText();
    emit emit_send(buf);
}

void ServPanel::on_pushButton_start_clicked()
{
    quint16 port = static_cast<quint16>(ui->spinBox_port->value());
    myserver.start_at(port);
}
