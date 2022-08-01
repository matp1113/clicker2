#include "appRoot.h"
#include <QQmlContext>
#include <QDebug>
#include <QUrl>

AppRoot::AppRoot(QObject *parent, QQmlApplicationEngine *engine, std::unique_ptr<Game> game, std::unique_ptr<MainWindow> main, std::unique_ptr<Settings> settings)
    : QObject{parent}, _engine{engine}, _game{std::move(game)}, _main{std::move(main)}, _settings{std::move(settings)}
{
    const QUrl url(u"qrc:/clicker/main.qml"_qs);
    _engine->load(url);

    _main = std::make_unique<MainWindow>(this);
    _engine->rootContext()->setContextProperty("myMain", _main.get());

    _settings = std::make_unique<Settings>(this->_main.get());
    _engine->rootContext()->setContextProperty("mySettings", _settings.get());

    _game = std::make_unique<Game>(this->_main.get());
    _engine->rootContext()->setContextProperty("myGame", _game.get());


    qDebug() << "constructed";
}

void AppRoot::changeWindow(Window w)
{
    QUrl url;
    switch(w){
        case mainWindow:
            url.setUrl(u"qrc:/clicker/main.qml"_qs);
            _engine->load(url);
        break;

        case settings:
            url.setUrl(u"qrc:/clicker/settings.qml"_qs);
            _engine->load(url);
        break;

        case gameWindow:
            url.setUrl(u"qrc:/clicker/game.qml"_qs);
            _engine->load(url);
        break;
    }
}

AppRoot::~AppRoot()
{

}

void AppRoot::openSettings()
{
    changeWindow(settings);

}

void AppRoot::exitSettings()
{
    changeWindow(mainWindow);
}

void AppRoot::enterGame()
{
    changeWindow(gameWindow);
    //_game->setPlay(true);
}

