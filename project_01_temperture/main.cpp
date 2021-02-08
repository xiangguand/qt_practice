#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQuickItem>
#include <QDebug>
#include <iostream>
#include "temp.h"

int main(int argc, char *argv[]) {
    qDebug() << "Start";
    QGuiApplication app(argc, argv);
    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    
    QObject *item = engine.rootObjects().first();
    QObject *ctextField = engine.rootObjects()[0]->findChild<QObject *>("txtfield_c");
    QObject *ftextField = engine.rootObjects()[0]->findChild<QObject *>("txtfield_f");
    temp temp_handle(ctextField, ftextField);
    QObject::connect(item, SIGNAL(textChangeCSignal(QString)),
                    &temp_handle, SLOT(handleCelsius(QString)));
    QObject::connect(item, SIGNAL(textChangeFSignal(QString)),
                    &temp_handle, SLOT(handleFehrenheit(QString)));


    qDebug() << "Execute";
    qDebug() << "=========================";
    return app.exec();
}



