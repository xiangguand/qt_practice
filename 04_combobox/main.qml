import QtQuick 2.5
import QtQuick.Window 2.2
import QtQuick.Controls 1.4

ApplicationWindow {
    id: root
    visible: true
    width: 600
    height: 200
    signal buttonClickSignal()
    signal comboBoxSignal()

    Component {
        id: myDelegate
        Item {
            width: 180
            height: 40
            Column {
                Rectangle {
                    width: 60
                    height: 30
                    color: "red"
                    Text { text: "test" }
                }
                Text { text: "list 1" }
                Text { text: "list 2" }
            }
        }
    }
    Column {
        spacing: 2
        Text {
            text: qsTr("ComboBox test !!!")
            color: "blue"
            font.bold: true
            font.pointSize: 12
        }
        ComboBox {
            objectName: "comboBox1"
            editable: false
            model: ListModel {
                ListElement {
                    text: "list 1"
                }
                ListElement {
                    text: "list 2"
                }
                ListElement {
                    text: "list 3"
                }
            }
            onCurrentIndexChanged: {
                comboBoxSignal()
                console.debug("Index change " + currentIndex);
            }
        }
        Button {
            text: qsTr("reset")
            onClicked: buttonClickSignal()
        }
        Text {
            objectName: "txt_show"
            text: qsTr("")
        }
    }
}

