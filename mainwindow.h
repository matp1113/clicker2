#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QObject>

class MainWindow : public QObject
{
    Q_OBJECT

public:
    explicit MainWindow(QObject *parent = nullptr);
    ~MainWindow();

private:
    QObject *parentObject;
};

#endif // MAINWINDOW_H
