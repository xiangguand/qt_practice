#ifndef TEMP_H
#define TEMP_H

#include "QObject"

class temp : public QObject {
public:
    temp(QObject *ctextField, QObject *ftextField);
    ~temp();
private:
    QObject *ctextField;
    QObject *ftextField;
    double temperature_c;
    double temperature_f;
    int state;
Q_OBJECT
public slots:
    void handleCelsius(QString changeText);
    void handleFehrenheit(QString changeText);
};

#endif /* TEMP_H */
