import QtQuick 2.15
import QtQuick.Window 2.2
import QtQuick.Controls 1.4

ApplicationWindow {
    id: root
    visible: true
    width: 600
    height: 300
    
    signal textEditChangeSignal(string changeText)

    Column {
        spacing: 2
        Text {
            text: qsTr("Image test !!!")
            color: "blue"
            font.bold: true
            font.pointSize: 12
        }
        Image {
            width: 500
            height: 250
            source: "file:figure/sky-690293__340.png"
        }
    }
}

