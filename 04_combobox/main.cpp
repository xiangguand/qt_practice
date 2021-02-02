#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQuickItem>
#include <QDebug>
#include <iostream>
#include "myComboBox.h"

int main(int argc, char *argv[]) {
    qDebug() << "Start";
    QGuiApplication app(argc, argv);
    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    // Create the QObject
    myComboBox myComboBox;
    QObject *item = engine.rootObjects().first();
    QObject::connect(item, SIGNAL(comboBoxSignal()),
                     &myComboBox, SLOT(handleComboBox()));
    QObject::connect(item, SIGNAL(buttonClickSignal()),
                     &myComboBox, SLOT(handleButton()));
    QObject *comboBox = engine.rootObjects()[0]->findChild<QObject *>("comboBox1");
    QObject *txtShow = engine.rootObjects()[0]->findChild<QObject *>("txt_show");
    if(comboBox == NULL) {
        qDebug() << "comboBox object is NULL";
    }
    if(txtShow == NULL) {
        qDebug() << "text object is NULL";
    }
    myComboBox.setHandleObject(comboBox, txtShow);

    qDebug() << "Execute";
    qDebug() << "=========================";
    return app.exec();
}



