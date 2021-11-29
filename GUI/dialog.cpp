#include "dialog.h"
#include "ui_dialog.h"
#include <QSerialPort>
#include <QSerialPortInfo>
#include <string>
#include <QDebug>
#include <QMessageBox>
#include <QProcess>
#include <QDateTime>
#include <QTime>


Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    Dialog::makeplot();
    QObject::connect(mytimer, SIGNAL(timeout()), this, SLOT(timeresponse()));
    QObject::connect(mytimerled, SIGNAL(timeout()), this, SLOT(timerled()));
    mytimerled->start(100);
    wiringPiSetup();
    pinMode(4, OUTPUT);
    arduino = new QSerialPort(this);
    serialBuffer = "";

    /*
     * program ini digunakan untuk membaca id dan vendor dari arduino
     *
     *
    qDebug() << "Number of ports: " << QSerialPortInfo::availablePorts().length() << "\n";
    foreach(const QSerialPortInfo &serialPortInfo, QSerialPortInfo::availablePorts()){
        qDebug() << "Description: " << serialPortInfo.description() << "\n";
        qDebug() << "Has vendor id?: " << serialPortInfo.hasVendorIdentifier() << "\n";
        qDebug() << "Vendor ID: " << serialPortInfo.vendorIdentifier() << "\n";
        qDebug() << "Has product id?: " << serialPortInfo.hasProductIdentifier() << "\n";
        qDebug() << "Product ID: " << serialPortInfo.productIdentifier() << "\n";
    }
    */


    //cek keberadaan arduino
    bool arduino_is_available = false;
    QString arduino_uno_port_name;
    //cek port dan id dari arduino
    foreach(const QSerialPortInfo &serialPortInfo, QSerialPortInfo::availablePorts()){
        if(serialPortInfo.hasProductIdentifier() && serialPortInfo.hasVendorIdentifier()){
            if((serialPortInfo.productIdentifier() == arduino_uno_product_id)
                    && (serialPortInfo.vendorIdentifier() == arduino_uno_vendor_id)){
                arduino_is_available = true; //arduino uno is available on this port
                arduino_uno_port_name = serialPortInfo.portName();
            }
        }
    }
    //mulai komunikasi serial dengan arduino
    if(arduino_is_available){
        qDebug() << "Found the arduino port...\n";
        arduino->setPortName(arduino_uno_port_name);
        arduino->open(QSerialPort::ReadOnly);
        arduino->setBaudRate(QSerialPort::Baud9600);
        arduino->setDataBits(QSerialPort::Data8);
        arduino->setFlowControl(QSerialPort::NoFlowControl);
        arduino->setParity(QSerialPort::NoParity);
        arduino->setStopBits(QSerialPort::OneStop);
        QObject::connect(arduino, SIGNAL(readyRead()), this, SLOT(readSerial()));
    }else{
        qDebug() << "Couldn't find the correct port for the arduino.\n";
        QMessageBox::information(this, "Serial Port Error", "Couldn't open serial port to arduino.");
    }
}

Dialog::~Dialog()
{
    if(arduino->isOpen()){
        arduino->close(); //    Close the serial port if it's open.
    }
    delete ui;
}
//baca data serial dari arduino
void Dialog::readSerial()
{
    QStringList buffer_split = serialBuffer.split(",");
   //split data dari arduino
   if(buffer_split.length() < 2){
        serialData = arduino->readAll();
        serialBuffer = serialBuffer + QString::fromStdString(serialData.toStdString());
        serialData.clear();
    }else{
        serialBuffer = "";
         temp1 = buffer_split[0].toFloat();
        Dialog::updateTemperature1(temp1);
         humid1 = buffer_split[1].toInt();
        Dialog::updateHumidity1(humid1);
         temp2 = buffer_split[2].toFloat();
        Dialog::updateTemperature2(temp2);
         humid2 = buffer_split[3].toInt();
        Dialog::updateHumidity2(humid2);
        float temp3 = buffer_split[4].toFloat();
        Dialog::updateTemperature3(temp3);
        int humid3 = buffer_split[5].toInt();
        Dialog::updateHumidity3(humid3);

   }
}
//update data temperature 1
void Dialog::updateTemperature1(float a){
    ui->temp1_lcdNumber->display(a);
}
//update data temperature 2
void Dialog::updateTemperature2(float b){
    ui->temp2_lcdNumber->display(b);
}
//update data temperature 3
void Dialog::updateTemperature3(float c){
    ui->temp3_lcdNumber->display(c);
}
//update data humidity 1
void Dialog::updateHumidity1(int d){
    ui->humid1_lcdNumber->display(d);
}
//update data humidity 2
void Dialog::updateHumidity2(int e){
    ui->humid2_lcdNumber->display(e);
}
//update data humidity 3
void Dialog::updateHumidity3(int f){
    ui->humid3_lcdNumber->display(f);
}
//tampilan grafik
void Dialog::makeplot()
{
    // generate some data:
   /* QVector<double> x(101), y(humid1); // initialize with entries 0..100
    for (int i=0; i<101; ++i)
    {
      x[i] = i;
      //x[i] = i/50.0 - 1; // x goes from -1 to 1
      //y[i] = x[i]*x[i]; // let's plot a quadratic function
    } */
    // create graph and assign data to it:
    ui->customplot->addGraph();
  //  ui->customplot->graph(0)->setData(x, y);
    // give the axes some labels:
    ui->customplot->xAxis->setLabel("Time");
    ui->customplot->yAxis->setLabel("Temperature");
    // set axes ranges, so we see all data:
    ui->customplot->xAxis->setRange(0, 50);
    ui->customplot->yAxis->setRange(0, 50);
    double key = QDateTime::currentDateTime().toMSecsSinceEpoch() / 1000.0;
    ui->customplot->graph(0)->addData(key, humid1);
    qDebug()<<humid1;
    ui->customplot->replot();
}
//tombol ON led
void Dialog::on_on_pushButton_clicked()
{
    digitalWrite(4, LOW);
}
//tombol OFF led
void Dialog::on_off_pushButton_clicked()
{
    digitalWrite(4, HIGH);
}
//tombol ambil data
void Dialog::on_pushButton_2_clicked()
{
       QString path = "/home/pi/Penelitian";
       QString  command("python3");
       QStringList params = QStringList() << "stepperV2.py";

       QProcess *process = new QProcess();
       process->startDetached(command, params, path);
       process->waitForFinished();
       process->close();
}
void Dialog::on_pushButton_clicked()
{
    mytimer->start(500);
    timevalue=ui->timeEdit->time();
    spinboxvalue=ui->spinBox->value();
}

//ambil data otomatis
void Dialog::timeresponse()
{
   if(timevalue.hour()==QTime::currentTime().hour() && timevalue.minute()==QTime::currentTime().minute()){
       if(pengulangan==spinboxvalue && b==0){
           a=0;
           delayMicroseconds(200);
           b=1;
           pengulangan = 1;
        }
        else{pengulangan ++;}
   }
   if(a == 0){
        QString path = "/home/pi/Penelitian";
        QString  command("python3");
        QStringList params = QStringList() << "stepperV2.py";

        QProcess *process = new QProcess();
        process->startDetached(command, params, path);
        process->waitForFinished();
        process->close();
        mytimer->start(500);
        a=1;
   }
}
//otomatis led
void Dialog::timerled()
{
   QTime timeledon = QTime::fromString("21.00","h.m");
   QTime timeledoff = QTime::fromString("5.00","h.m");
   if(timeledon.hour()==QTime::currentTime().hour() && timeledon.minute()==QTime::currentTime().minute()){
      digitalWrite(4, HIGH);
   }
   if(timeledoff.hour()==QTime::currentTime().hour() && timeledoff.minute()==QTime::currentTime().minute()){
      digitalWrite(4, LOW);
   }

}
//ambil data manual
void Dialog::on_pushButton_3_clicked()
{
    QString path = "/home/pi/Penelitian";
    QString  command("python3");
    QStringList params = QStringList() << "datalogger.py";

    QProcess *process = new QProcess();
    process->startDetached(command, params, path);
    process->waitForFinished();
    process->close();
}
