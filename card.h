#ifndef CARD_H
#define CARD_H

#include <QObject>
#include"glcard.h"
#include "mainwindow.h"

class Card : public QObject
{
    Q_OBJECT

public:
    Card (MainWindow* x);
    glcard *crd;
    MainWindow* x1;
    int *cu;
private slots:
    void check();
};

#endif // CARD_H
