#ifndef MYBUTTON_H
#define MYBUTTON_H

#include "QObject"
#include "QDebug"

class myListview : public QObject {

Q_OBJECT
public slots:
    void handleListview(void);
};


#endif
