#include <QApplication>

#include "besselview.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    BesselView w;
    w.show();

    return a.exec();
}
