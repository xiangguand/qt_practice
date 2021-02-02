import QtQuick 2.5
import QtQuick.Window 2.2
import QtQuick.Controls 1.4

ApplicationWindow {
    id: root
    visible: true
    width: 600
    height: 200
    
    ListModel {
        id: myModel
        ListElement {
            itemColor: "red"
        }
        ListElement {
            itemColor: "green"
        }
    }
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
            text: qsTr("Listview button test !!!")
            color: "blue"
            font.bold: true
            font.pointSize: 12
        }
        ListView {
            x: 2; y: 50
            model: myModel
            delegate: myDelegate
            focus: true
        }
    }
}

