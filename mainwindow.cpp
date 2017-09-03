#include "mainwindow.h"
#include "card.h"
#include <iostream>
#include <time.h>
#include "window.h"
MainWindow::MainWindow(QWidget* parent, int s)
    : QDialog(parent)
{
    siz = s;
    im[0].load("s1.png");
    im[1].load("s2.png");
    im[2].load("s3.png");
    im[3].load("s4.png");
    im[4].load("s5.png");
    im[5].load("s6.png");
    im[6].load("s7.png");
    im[7].load("s8.png");
    im[8].load("s9.png");
    im[9].load("s10.png");
    im[10].load("s11.png");
    im[11].load("s12.png");
    im[12].load("s13.png");
    im[13].load("s14.png");
    im[14].load("s15.png");
    im[15].load("s16.png");
    im[16].load("s17.png");
    im[17].load("s18.png");

    int mass [6][6] = {{1 ,1, 2, 2, 3, 3},
                       {4, 4, 5, 5, 6, 6},
                       {7, 7, 8, 8, 9, 9},
                       {10, 10, 11, 11, 12, 12},
                       {13, 13, 14, 14, 15, 15},
                       {16, 16, 17, 17, 0, 0}};
    int i, j;
    srand(time(NULL));
    for ( i = 0; i < s; i ++)
        for(j = 0; j < s; j++)
        {
            std::swap(mass[i][j], mass[rand()%s][rand()%s]);
        }
    gr = new QGridLayout;
    Card *arr [s][s];
    for (int i = 0; i<s ; i++)
        for (int j = 0; j<s; j++)
            {
                arr[i][j]= new Card (this);
                *(arr[i][j]->cu) = mass[i][j];
                arr[i][j]->crd = new glcard (im[*(arr[i][j]->cu)]);
                gr->addWidget(arr[i][j]->crd, i, j);
                QObject::connect(arr[i][j]->crd, SIGNAL (clicked()), arr[i][j], SLOT(check()));
            }
    gr->columnMinimumWidth(100);
    this->setLayout(gr);
    this->show();
}

Window *dial;

void MainWindow::win()
{
    dial = new Window;
    dial->show();
    dial->setFixedSize(400, 250);
    dial->setWin();
    this->close();
}

MainWindow::~MainWindow()
{

}
