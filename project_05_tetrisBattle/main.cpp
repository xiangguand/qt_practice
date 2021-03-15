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

    TetrisBattle tetris;

    QObject::connect(item, SIGNAL(startSignal()),
                      &tetris, SLOT(startHandler()));
    QObject::connect(item, SIGNAL(stopSignal()),
                      &tetris, SLOT(stopHandler()));

    qDebug() << "Execute";
    qDebug() << "=========================";
    return app.exec();
}



