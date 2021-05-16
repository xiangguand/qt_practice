#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWebSocketServer>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

private slots:
    void on_connected();
    void on_disconnected();
    void on_close();
    void processTextMessage(QString message);
    void processBinaryMessage(QByteArray message);

    void on_btTest_clicked();

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QWebSocketServer *m_pWebSocketServer;
    QWebSocket *psocket;
};
#endif // MAINWINDOW_H
