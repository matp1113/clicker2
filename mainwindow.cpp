#include "mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QObject *parent)
    : QObject{parent}, parentObject(parent)
{
    qDebug() << "connect main";
}

MainWindow::~MainWindow()
{

}

