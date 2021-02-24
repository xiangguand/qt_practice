#ifndef snake_H
#define snake_H

#include "QObject"
#include "QDebug"

class snake : public QObject {
public:
    snake(QObject *obj);
    snake(void);
    ~snake(void);
    void setRootQObject(QObject *obj);
private:
    QObject *rootQObject;

Q_OBJECT
public slots:
    void startClick(void);
    void stopClick(void);
    void testClick(void);
};


#endif /* snake_H */
