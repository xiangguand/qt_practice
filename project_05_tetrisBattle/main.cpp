#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQuickItem>
#include <QDebug>
#include "tetrisBattle.h"


int main(int argc, char *argv[]) {
    qDebug() << "Start";
    QGuiApplication app(argc, argv);
    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/ui/main.qml")));

    QObject *rootQObject = engine.rootObjects()[0];
    QObject *item = engine.rootObjects().first();

    TetrisBattle tetris(rootQObject);

    QObject::connect(item, SIGNAL(startSignal()),
                      &tetris, SLOT(startHandler()));
    QObject::connect(item, SIGNAL(stopSignal()),
                      &tetris, SLOT(stopHandler()));
    QObject::connect(&tetris, SIGNAL(createRectSignal(QString, int, int, QString)),
                      item, SLOT(addComponent(QString, int, int, QString)));
    // Define the keyboard signal
    QObject::connect(item, SIGNAL(keyboardSignal(int)),
                      &tetris, SLOT(keyboardHandler(int)));
    QObject::connect(item, SIGNAL(updateSignal()),
                      &tetris, SLOT(updateHandler()));

    qDebug() << "Execute";
    qDebug() << "=========================";
    return app.exec();
}



