TEMPLATE = app

QT += qml quick gui widgets
CONFIG += c++11
CONFIG += console

SOURCES += main.cpp snake.cpp handleKeyboard.cpp threadTask.cpp

RESOURCES += qml.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

HEADERS += snake.h handleKeyboard.h common.h threadTask.h

