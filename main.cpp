#include <QtGui/QApplication>
#include "mainwindow.h"
#include "glcard.h"
#include "window.h"
#include <iostream>


int main(int argc, char *argv[])
{

    QApplication a(argc, argv);
    Window *e = new Window;
    e->setFixedSize(400, 200);
    e->show();

    return a.exec();
}
