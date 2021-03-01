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

    // Define the keyboard signal
    QObject::connect(item, SIGNAL(keyboardSignal(int)),
                      &snake, SLOT(keyboardHandler(int)));

    // Define the gameover signal
    QObject::connect(&snake, SIGNAL(gameoverSignalSend()),
                      item, SLOT(gameoverSlot()));

    // Define the gameover signal
    QObject::connect(&snake, SIGNAL(scoreSignalSend(int)),
                      item, SLOT(scoreSlot(int)));
    
    // Define the timer interval signal
    QObject::connect(&snake, SIGNAL(timerIntervelSignal(int)),
                      item, SLOT(timerIntervalSlot(int)));

    // Define the timer signal
    QObject::connect(item, SIGNAL(updateSignal()),
                      &snake, SLOT(updateHandler()));

    QObject *start = rootQObject->findChild<QObject *>("start");
    if(start == NULL) {
        qDebug() << "not create";
    }
    else {
        qDebug() << "find";
    }

    qDebug() << "Execute";
    qDebug() << "=========================";
    return app.exec();
}



