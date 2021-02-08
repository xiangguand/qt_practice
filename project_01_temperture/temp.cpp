#include "temp.h"
#include "QObject"
#include <QDebug>

temp:: temp(QObject *ctextField, QObject *ftextField) {
    qDebug() << "Contructor";
    temp::ctextField = ctextField;
    temp::ftextField = ftextField;
    temperature_c = 0.00;
    temperature_f = 32.00;
}
temp:: ~temp() {
    qDebug() << "Deontructor";
}

void temp::handleCelsius(QString changeText) {
    try {
        temp::state = 1;
        temp::temperature_f = std::stod(changeText.toUtf8().constData()) * 1.8 + 32;
        temp::ftextField->blockSignals(true);
        temp::ftextField->setProperty("text", temp::temperature_f);
        temp::ftextField->blockSignals(false);
    }
    catch(const std::exception& e) {
        qDebug() << "Error, please enter a number";
    }
    qDebug() << "handleCelsius: " << temperature_f << " F";
}

void temp::handleFehrenheit(QString changeText) {
    try {
        temp::temperature_c = std::stod(changeText.toUtf8().constData()) * 0.5555555555555556 - 32;
        temp::ctextField->blockSignals(true);
        temp::ctextField->setProperty("text", temp::temperature_c);
        temp::ctextField->blockSignals(false);
    }
    catch(const std::exception& e) {
        qDebug() << "Error, please enter a number";
    }
    qDebug() << "handleFehrenheit: " << temperature_c << " C";
}

