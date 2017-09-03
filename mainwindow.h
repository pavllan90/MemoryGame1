#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtGui/QMainWindow>
#include <QDialog>
#include <QImage>
#include <QGridLayout>

class MainWindow : public QDialog
{
    Q_OBJECT

public:
    MainWindow(QWidget* parent = 0, int s = 0);
    QImage im [18];
    QGridLayout *gr;
    int siz;
    void win ();

    ~MainWindow();
};



#endif // MAINWINDOW_H
