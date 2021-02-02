#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQuickItem>
#include <QDebug>
#include <iostream>
#include "myListview.h"

int main(int argc, char *argv[]) {
    qDebug() << "Start";
    QGuiApplication app(argc, argv);
    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    // Create the QObject
    myListview listview;
    QObject *item = engine.rootObjects().first();
    QObject::connect(item, SIGNAL(listviewSignal()),
                     &listview, SLOT(handleListview()));


    qDebug() << "Execute";
    return app.exec();
}



