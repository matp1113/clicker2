#include "settings.h"
#include <QDebug>

Settings::Settings(QObject *parent)
    : QObject{parent}
{
    qDebug() << "construct settings";
}

Settings::~Settings()
{

}

