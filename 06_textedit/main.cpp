#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQuickItem>
#include <QDebug>
#include <iostream>
#include "myTextEdit.h"

int main(int argc, char *argv[]) {
    qDebug() << "Start";
    QGuiApplication app(argc, argv);
    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    // Create the QObject
    myTextEdit myTextEdit;
    QObject *item = engine.rootObjects().first();
    QObject::connect(item, SIGNAL(textEditChangeSignal(QString)),
                    &myTextEdit, SLOT(handleTextEdit(QString)));
    QObject::connect(item, SIGNAL(textFieldCompleteSignal(QString)),
                    &myTextEdit, SLOT(handleTextField(QString)));
    QObject::connect(item, SIGNAL(textInputCompleteSignal(QString)),
                    &myTextEdit, SLOT(handleTextInput(QString)));


    qDebug() << "Execute";
    qDebug() << "=========================";
    return app.exec();
}



