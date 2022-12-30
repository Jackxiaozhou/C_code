#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    Window_init();
    m_serialport=new QSerialPort();
    connect(m_serialport,SIGNAL(readyRead()),this,SLOT(receive_data()));
    connect(ui->radioBtnChar2,SIGNAL(clicked()),this,SLOT(StatusChange()));
    connect(ui->radioBtnHex2,SIGNAL(clicked()),this,SLOT(StatusChange()));
}

Widget::~Widget()
{
    delete ui;
}

void Widget::Window_init()
{
    //列表清单
    QStringList strListBaud,strListParity,strListDataBits,strListStopBits;
    strListBaud<<"1200"<<"2400"<<"4800"<<"9600"<<"19200"<<"38400"<<"57600"<<"115200";
    strListParity<<"无"<<"奇校验"<<"偶校验";
    strListDataBits<<"5"<<"6"<<"7"<<"8";
    strListStopBits<<"1"<<"1.5"<<"2";
    for(int i=0;i<=10;i++)
    {
        ui->cmbBoxPort->addItem(QString::asprintf("COM%d",i));//每次加一个
    }
    ui->cmbBoxBaud->addItems(strListBaud);//一次加多个
    ui->cmbBoxBaud->setCurrentIndex(3);
    ui->cmbBoxParity->addItems(strListParity);
    ui->cmbBoxParity->setCurrentIndex(0);
    ui->cmbBoxDataBits->addItems(strListDataBits);
    ui->cmbBoxDataBits->setCurrentIndex(3);
    ui->cmbBoxStopBits->addItems(strListStopBits);
}


void Widget::on_btnCheck_clicked()
{
    ui->cmbBoxPort->clear();
    QList<QSerialPortInfo> serialPortInfoList =QSerialPortInfo::availablePorts();
    if(serialPortInfoList.isEmpty()){
        QMessageBox::information(this,"错误提示","没有可用串口",QMessageBox::Ok);
    }
    QList<QSerialPortInfo>::iterator iter=serialPortInfoList.begin();//指针，首地址
    while(iter!=serialPortInfoList.end())
    {
        ui->cmbBoxPort->addItem(iter->portName());
        iter++;
    }
}

void Widget::on_btnOpen_clicked()
{
    if(m_serialport->isOpen())
    {
        m_serialport->clear();
        m_serialport->close();
        ui->labelStatus->setStyleSheet("background-color:rgb(170,0,0);border-radius:12px;");
        ui->btnOpen->setText("打开串口");
        return ;
    }
    else {
        m_serialport->setPortName(ui->cmbBoxPort->currentText());
        int bandIndex=ui->cmbBoxBaud->currentIndex();
        switch (bandIndex)
        {
        case 0:
            m_serialport->setBaudRate(QSerialPort::Baud1200);
            break;
        case 1:
            m_serialport->setBaudRate(QSerialPort::Baud2400);
            break;
        case 2:
            m_serialport->setBaudRate(QSerialPort::Baud4800);
            break;
        case 3:
            m_serialport->setBaudRate(QSerialPort::Baud9600);
            break;
        case 4:
            m_serialport->setBaudRate(QSerialPort::Baud19200);
            break;
        case 5:
            m_serialport->setBaudRate(QSerialPort::Baud38400);
            break;
        case 6:
            m_serialport->setBaudRate(QSerialPort::Baud57600);
            break;
        case 7:
            m_serialport->setBaudRate(QSerialPort::Baud115200);
            break;
        }
        int dataIndex=ui->cmbBoxDataBits->currentIndex();
        switch (dataIndex)
        {
        case 0:
            m_serialport->setDataBits(QSerialPort::Data5);
            break;
        case 1:
            m_serialport->setDataBits(QSerialPort::Data6);
            break;
        case 2:
            m_serialport->setDataBits(QSerialPort::Data7);
            break;
        case 3:
            m_serialport->setDataBits(QSerialPort::Data8);
            break;
        }
        int stopIndex=ui->cmbBoxStopBits->currentIndex();
        switch ( stopIndex)
        {
        case 0:
            m_serialport->setStopBits(QSerialPort::OneStop);
            break;
        case 1:
            m_serialport->setStopBits(QSerialPort::OneAndHalfStop);
            break;
        case 2:
            m_serialport->setStopBits(QSerialPort::TwoStop);
            break;
        }
        int parityIndex=ui->cmbBoxParity->currentIndex();
        switch (parityIndex)
        {
        case 0:
            m_serialport->setParity(QSerialPort::NoParity);
            break;
        case 1:
            m_serialport->setParity(QSerialPort::OddParity);
            break;
        case 2:
            m_serialport->setParity(QSerialPort::EvenParity);
            break;
        }
        m_serialport->setFlowControl(QSerialPort::NoFlowControl);
        m_serialport->open(QIODevice::ReadWrite);
        ui->labelStatus->setStyleSheet("background-color:rgb(0,255,0);border-radius:12px;");
        ui->btnOpen->setText("关闭串口");
    }
}

void Widget::receive_data()
{
    QByteArray message;
    message.append(m_serialport->readAll());
    if(ui->radioBtnHex->isChecked())
    {
        message=message.toHex(' ').toUpper();
    }
    ui->textEditRec->setText(ui->textEditRec->toPlainText()+QString::fromLocal8Bit(message));
}

void Widget::StatusChange()
{
    QString str=ui->textEditSend->document()->toPlainText();
    if(ui->radioBtnChar2->isChecked())
    {
        QByteArray sendData1=str.toUtf8();
        sendData1=sendData1.fromHex(sendData1);
        ui->textEditSend->document()->setPlainText(sendData1);
    }
    else if (ui->radioBtnHex2->isChecked())
    {
        QByteArray sendData=str.toUtf8();
        sendData=sendData.toHex(' ').toUpper();
        ui->textEditSend->document()->setPlainText(sendData);
    }
}

void Widget::on_timeSend_clicked()
{
    ui->BtnSend->setEnabled(false);
    int time;
    static bool en=true; //标识. 是否设置自动发送时间
    if(ui->lineEdit->text()==NULL)
        QMessageBox::about(this,tr("提示信息"),tr("请设置时间"));
    else
    {
        if(en==true)
        {
            QMessageBox::about(this,tr("提示信息"),tr("已开始自动发送"));
            time=ui->lineEdit->text().toInt();  //获取自动发送的时间间隔
            ui->lineEdit->setEnabled(false);
            timeSend =new QTimer();
            timeSend->setInterval(1000);
            connect(timeSend,&QTimer::timeout,this,[=](){on_BtnSend_clicked();
            });

            timeSend->start(time);
            en=false;
        }
        else if(en==false)
        {
            timeSend->stop();
            QMessageBox::about(this,tr("提示信息"),tr("已停止自动发送"));
            en=true;
            ui->lineEdit->setEnabled(true);
            ui->BtnSend->setEnabled(true);
        }
    }

}

void Widget::on_BtnSend_clicked()
{
    QString message =ui->textEditSend->document()->toPlainText();
    QByteArray messageSend;
    if(ui->radioBtnHex2->isChecked())
    {
        QByteArray sendData1=message.toUtf8();
        sendData1=sendData1.fromHex(sendData1);
        messageSend.append(sendData1);
        m_serialport->write(messageSend);
    }
    else {
        m_serialport->write(message.toLocal8Bit());
    }
}

void Widget::on_btnClearRec_clicked()
{
    ui->textEditRec->clear();
}

void Widget::on_btnClearSend_clicked()
{
    ui->textEditSend->clear();
}
