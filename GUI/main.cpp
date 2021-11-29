#include "dialog.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Dialog w;
    w.setWindowTitle("Temperature Sensor Reading");
    //w.setFixedSize(1024,600);
    w.showFullScreen();
    w.show();

    return a.exec();
}
