#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QSerialPort>
#include <QSerialPortInfo>
#include <QMessageBox>
#include <QTimer>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget();
   void Window_init();

private slots:
   void on_btnCheck_clicked();

   void on_btnOpen_clicked();
   void receive_data();
   void StatusChange();
   void on_timeSend_clicked();

   void on_BtnSend_clicked();

   void on_btnClearRec_clicked();

   void on_btnClearSend_clicked();

private:
    Ui::Widget *ui;
    QSerialPort* m_serialport;
    QTimer* timeSend;
};

#endif // WIDGET_H
