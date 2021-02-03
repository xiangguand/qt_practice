#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQuickItem>
#include <QDebug>
#include <iostream>
#include "myImage.h"

int main(int argc, char *argv[]) {
    qDebug() << "Start";
    QGuiApplication app(argc, argv);
    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    // Create the QObject
    myImage myImage;
    QObject *item = engine.rootObjects().first();
    (void) item;


    qDebug() << "Execute";
    qDebug() << "=========================";
    return app.exec();
}



