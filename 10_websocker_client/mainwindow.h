#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtWebSockets/QWebSocket>
#include <QWebSocket>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

private slots:
    void on_connected(void);
    void on_closed(void);
    void processTextMessage(QString message);
    void processBinaryMessage(QByteArray message);

    void on_btTest_clicked();

    void on_btSendSine_clicked();

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QWebSocket *websocket;
};
#endif // MAINWINDOW_H
