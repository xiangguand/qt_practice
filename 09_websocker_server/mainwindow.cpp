#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QtWebSockets/QWebSocket>
#include <QWebSocketServer>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->m_pWebSocketServer = new QWebSocketServer(QStringLiteral("Echo Server"),
                                               QWebSocketServer::NonSecureMode,
                                               this);
    if (m_pWebSocketServer->listen(QHostAddress::Any, 1111)) {
        qDebug() << "Echoserver listening on port" << 1111;
        connect(m_pWebSocketServer, &QWebSocketServer::newConnection,
                this, &MainWindow::on_connected);
        connect(m_pWebSocketServer, &QWebSocketServer::closed,
                this, &MainWindow::on_close);
        qDebug() << m_pWebSocketServer;
        qDebug() << m_pWebSocketServer->serverAddress();
        qDebug() << m_pWebSocketServer->serverPort();
    }
    else {
        qDebug() << "listen fail !!!";
    }

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_connected() {
    qDebug() << "connected";
    this->psocket = this->m_pWebSocketServer->nextPendingConnection();
    connect(psocket, &QWebSocket::textMessageReceived,
            this, &MainWindow::processTextMessage);
    connect(psocket, &QWebSocket::binaryMessageReceived,
            this, &MainWindow::processBinaryMessage);
}

void MainWindow::on_disconnected() {
    qDebug() << "disconnected";
}

void MainWindow::on_close() {
    qDebug() << "close";
}


void MainWindow::processTextMessage(QString message) {
    qDebug() << "Message received:" << message;
}

void MainWindow::processBinaryMessage(QByteArray message) {
    qDebug() << "Binary Message received:" << message;
}

void MainWindow::on_btTest_clicked() {
    if(this->psocket != NULL) {
        this->psocket->sendTextMessage("Hi, I am server.\n");
    }
}
