#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQuickItem>
#include <QDebug>
#include <iostream>
#include "myTableView.h"

int main(int argc, char *argv[]) {
    qDebug() << "Start";
    QGuiApplication app(argc, argv);
    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    // Create the QObject
    myTableView myTableView;
    QObject *item = engine.rootObjects().first();
    QObject::connect(item, SIGNAL(tableViewClickSignal(int)),
                    &myTableView, SLOT(handleTableView(int)));


    qDebug() << "Execute";
    qDebug() << "=========================";
    return app.exec();
}



