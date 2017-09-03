#ifndef WINDOW_H
#define WINDOW_H

#include <QMainWindow>
#include "mainwindow.h"

namespace Ui {
class Window;
}

class Window : public QMainWindow
{
    Q_OBJECT
    
public:
    int p_size;
    explicit Window(QWidget *parent = 0);
    ~Window();
    MainWindow *win;
    void make_Game(int s);
    void setWin();
    Ui::Window *ui;
public slots:
    void getS ();
    void setButton();

};

#endif // WINDOW_H
