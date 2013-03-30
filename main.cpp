#include <QtGui/QApplication>
#include "dstation.h"
#include <QPlastiqueStyle>

int main(int argc, char *argv[])
{
   QApplication::setStyle(new QPlastiqueStyle);
    QApplication a(argc, argv);

    DStation w;

    /* We start with maximizing the main application window */
    w.setWindowState(w.windowState() ^ Qt::WindowMaximized);
    w.show();


    return a.exec();
}
