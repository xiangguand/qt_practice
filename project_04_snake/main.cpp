#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQuickItem>
#include <QDebug>
#include "snake.h"


int main(int argc, char *argv[]) {
    qDebug() << "Start";
    QGuiApplication app(argc, argv);
    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/ui/main.qml")));

    QObject *rootQObject = engine.rootObjects()[0];
    
    Snake snake(rootQObject);

    QObject *item = engine.rootObjects().first();
    QObject::connect(item, SIGNAL(startSignal()),
                      &snake, SLOT(startClick()));
    QObject::connect(item, SIGNAL(stopSignal()),
                      &snake, SLOT(stopClick()));
    QObject::connect(item, SIGNAL(testSignal()),
                      &snake, SLOT(testClick()));

    // Define the keyboard signal
    QObject::connect(item, SIGNAL(keyboardSignal(int)),
                      &snake, SLOT(keyboardHandler(int)));

    // Define the timer signal
    QObject::connect(item, SIGNAL(updateSignal()),
                      &snake, SLOT(updateHandler()));

    qDebug() << "Execute";
    qDebug() << "=========================";
    return app.exec();
}



