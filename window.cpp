#include "window.h"
#include "ui_window.h"
#include "mainwindow.h"
#include <iostream>

Window::Window(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Window)
{
    p_size = 0;
    ui->setupUi(this);
    ui->pushButton->setDisabled(true);
    QObject::connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(getS()));
    QObject::connect(ui->pushButton_2, SIGNAL(clicked()), this, SLOT(close()));
    QObject::connect(ui->lineEdit, SIGNAL(textEdited(QString)), this, SLOT(setButton()));
}

Window::~Window()
{
    delete ui;
}

void Window::getS()
{
    p_size = ui->lineEdit->text().toInt();
    if(p_size*p_size%2 == 0&&p_size>1&&p_size<7)
    emit make_Game(p_size);
    else ui->lineEdit->setText(QString::fromLocal8Bit("Некорректные данные"));
}

void Window::setButton()
{
    this->ui->pushButton->setEnabled(true);
}

void Window::make_Game(int s)
{
    win = new MainWindow(0, s);
    win->resize(600, 600);
    win->setFixedSize(600, 600);
    win->show();
    this->close();
}

void Window::setWin()
{
    this->ui->label_3->setText(QString::fromLocal8Bit("Ты победил! "));
}
