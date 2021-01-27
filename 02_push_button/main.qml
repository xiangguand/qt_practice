import QtQuick 2.5
import QtQuick.Window 2.2
import QtQuick.Controls 1.4

Window {
    id: root
    visible: true
    width: 300
    height: 200
    signal clickSignal()
    signal resetSignal()

    Column {
        spacing: 2
        Text {
            text: qsTr("push button test !!!")
            color: "blue"
            font.bold: true
            font.pointSize: 13
        }
        Button {
            id: bt_click
            text: qsTr("click me")
            onClicked: clickSignal()
        }
        Text {
            objectName: "txt_counter"
            text: qsTr("counter: 0")
            color: "black"
            font.bold: true
        }
        Button {
            id: bt_reset
            text: qsTr("reset")
            onClicked: resetSignal()
        }
    }
}

