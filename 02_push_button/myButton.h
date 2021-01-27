#ifndef MYBUTTON_H
#define MYBUTTON_H

#include "QObject"
#include "QDebug"

class myButton : public QObject {
public:
    int counter = 0;
    void setQObectText(QObject *obj);
private:
    QObject *text = NULL;
    void setText(void);
Q_OBJECT
public slots:
    void buttonClick(void);
    void resetClick(void);
};


#endif
