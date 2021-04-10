#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QDebug>
#include "gomoku.h"


int main(int argc, char *argv[]) {
    qDebug() << "Start";
    QGuiApplication app(argc, argv);
    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/ui/main.qml")));

    QObject *rootQObject = engine.rootObjects()[0];
    QObject *item = engine.rootObjects().first();

    Gomoku gomoku(rootQObject);

    QObject::connect(item, SIGNAL(mouseClickSignal(int, int)),
                      &gomoku, SLOT(mouseClickHandler(int, int)));
    QObject::connect(&gomoku, SIGNAL(addPieseSignal(QString, int, int, QString)),
                     item, SLOT(addPiece(QString, int, int, QString)));
    QObject::connect(item, SIGNAL(resetSignal()),
                      &gomoku, SLOT(resetHandler()));
    QObject::connect(&gomoku, SIGNAL(showDialogSignal(QString)),
                     item, SLOT(showDialog(QString)));

    qDebug() << "Execute";
    qDebug() << "=========================";
    return app.exec();
}



