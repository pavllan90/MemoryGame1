#include "card.h"
#include <iostream>
#include <QTimer>
#include <QtTest/QTest>
#include "window.h"

Card::Card (MainWindow* x) : QObject ()
{
    this->cu = new int;
    *cu=0;
    x1 = x;
}
Card *ch1 = NULL;
Card *ch2 = NULL;
int d = 0;
QTime timer;

void Card::check()
{
    if(!ch2)
    {
        if(ch1==NULL)
        {
            ch1=this;
            ch1->crd->rot();

        }
        if(ch2==NULL&&this!=ch1)
        {
            ch2=this;
            ch2->crd->rot();


        }
        if(ch1!=NULL&&ch2!=NULL)
        {
            if(*(ch1->cu)!=*(ch2->cu))
            {
                QEventLoop loop; QTimer::singleShot(2000, &loop, SLOT(quit())); loop.exec();
                ch1->crd->rot();
                ch2->crd->rot();
                ch1->crd->setEnabled(true);
                ch2->crd->setEnabled(true);

            }
            else
            {
                QEventLoop loop; QTimer::singleShot(1000, &loop, SLOT(quit())); loop.exec();
                ch1->crd->setDisabled(true);
                ch2->crd->setDisabled(true);
                d++;
            }
           if(d==x1->siz*x1->siz/2)
           {
               QEventLoop loop; QTimer::singleShot(1000, &loop, SLOT(quit())); loop.exec();
               x1->win();
               d = 0;
           }
            ch1=NULL;
            ch2=NULL;
        }
    }
}
