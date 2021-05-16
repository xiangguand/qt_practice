#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QtWebSockets/QWebSocket>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->websocket = new QWebSocket();
    connect(this->websocket, &QWebSocket::connected, this, &MainWindow::on_connected);
    connect(this->websocket, &QWebSocket::disconnected, this, &MainWindow::on_closed);
    connect(this->websocket, &QWebSocket::textMessageReceived,
            this, &MainWindow::processTextMessage);
    connect(this->websocket, &QWebSocket::binaryMessageReceived,
            this, &MainWindow::processBinaryMessage);
    this->websocket->open(QUrl("ws://localhost:1111"));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_connected(void) {
    qDebug() << "websocket client connected";
}

void MainWindow::on_closed(void) {
    qDebug() << "websocket client close";
    this->websocket->close();
}

void MainWindow::processTextMessage(QString message) {
    qDebug() << "Message received:" << message;
}

void MainWindow::processBinaryMessage(QByteArray message) {
    qDebug() << "Binary Message received:" << message;
}

void MainWindow::on_btTest_clicked() {
    if(this->websocket != NULL) {
        this->websocket->sendTextMessage("Hi, I am client !\n");
    }
}

void MainWindow::on_btSendSine_clicked() {
    float fd = 0.0;
    if(this->websocket != NULL) {
        for(int i=0;i<10;i++) {
            this->websocket->sendTextMessage(QString::number(fd));
            fd += 0.12345678;
        }
    }
}
