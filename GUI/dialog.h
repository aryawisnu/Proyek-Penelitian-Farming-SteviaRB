#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QSerialPort>
#include <QProcess>
#include <QWidget>
#include <QTimer>
#include <QTime>
#include "wiringPi.h"

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();

private slots:
    void readSerial();
    void timeresponse();
    void timerled();
    void updateTemperature1(float);
    void updateTemperature2(float);
    void updateTemperature3(float);
    void updateHumidity1(int);
    void updateHumidity2(int);
    void updateHumidity3(int);
    void on_on_pushButton_clicked();
    void on_off_pushButton_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_clicked();
    void on_pushButton_3_clicked();
    void makeplot();

private:
    Ui::Dialog *ui;
    QSerialPort *arduino;
    static const quint16 arduino_uno_vendor_id = 6790;
    static const quint16 arduino_uno_product_id = 29987;
    QByteArray serialData;
    QString serialBuffer;
    QTime timevalue;
    int spinboxvalue;
    QTimer *mytimer = new QTimer(this);
    QTimer *mytimerled = new QTimer(this);
    int a = 1;
    int b = 0;
    int pengulangan = 1;
    float temp1;
    float temp2;
    int humid1;
    int humid2;
};

#endif // DIALOG_H
