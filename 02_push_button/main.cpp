#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQuickItem>
#include <QDebug>
#include <iostream>
#include "myButton.h"

int main(int argc, char *argv[]) {
    qDebug() << "Start";
    QGuiApplication app(argc, argv);
    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    // Create the QObject
    myButton bt_click;
    QObject *item = engine.rootObjects().first();
    QObject::connect(item, SIGNAL(clickSignal()),
                      &bt_click, SLOT(buttonClick()));
    QObject::connect(item, SIGNAL(resetSignal()),
                      &bt_click, SLOT(resetClick()));
    QQuickItem *textCnt = engine.rootObjects()[0]->findChild<QQuickItem *>("txt_counter");
    if(textCnt == NULL) {
        qDebug() << "Text is NULL";
    }
    bt_click.setQObectText(textCnt);

    qDebug() << "Execute";
    return app.exec();
}



