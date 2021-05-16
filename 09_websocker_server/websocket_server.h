#ifndef WEBSOCKET_SERVER_H
#define WEBSOCKET_SERVER_H

#include <QObject>

class websocket_server : public QObject
{
    Q_OBJECT
public:
    explicit websocket_server(QObject *parent = nullptr);

signals:

};

#endif // WEBSOCKET_SERVER_H
