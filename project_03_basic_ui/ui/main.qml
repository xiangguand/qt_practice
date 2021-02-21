import QtQuick 2.15
import QtQuick.Window 2.2
import QtQuick.Controls 2.3
import QtQuick.Layouts 1.15

ApplicationWindow {
    id: root
    visible: true
    width: 1800
    height: 1200

    menuBar: MenuBar {
        Menu {
            title: qsTr('File')
            MenuItem {
                text: qsTr('&Test')
                onTriggered: {
                    console.debug('test')
                }
            }
            MenuItem {
                text: qsTr('&Exit')
                onTriggered: {
                    Qt.quit();
                }
            }
        }
    }

    Rectangle {
        id: topButton
        width: parent.width - 40
        height: 200
        anchors.horizontalCenter: parent.horizontalCenter
        border.color: "black"
        border.width: 1
        color: "transparent"
    }
    
    Rectangle {
        id: buttomButton
        width: parent.width - 40
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.top: topButton.bottom
        anchors.topMargin: 20
        height: parent.height - topButton.height - 100
        border.color: "black"
        border.width: 1
        color: "transparent"
        ShowHelloWorld {
            id: v0
            anchors.centerIn: parent
            visible: true
        }
        ShowTest {
            id: v1
            anchors.centerIn: parent
            visible: false
        }
        ShowBasicUI {
            id: v2
            anchors.centerIn: parent
            visible: false
        }
    }

    Rectangle {
        id: menuButtom
        anchors.top: buttomButton.top
        anchors.horizontalCenter: parent.horizontalCenter
        height: bt0.height
        width: parent.width - 40
        border.color: "black"

        Row {
            Button {
                id: bt0
                text: "bt0"
                background: Rectangle {
                    implicitWidth: 100
                    implicitHeight: 40
                    color: bt0.down ? "#d6d6d6" : "#f6f6f6"
                    border.color: "#26282a"
                    border.width: 1
                    radius: 4
                }
                onClicked: {
                    console.debug("bt0")
                    v0.visible = true
                    v1.visible = false
                    v2.visible = false
                }
            }
            Button {
                id: bt1
                text: "bt1"
                background: Rectangle {
                    implicitWidth: 100
                    implicitHeight: 40
                    color: bt1.down ? "#d6d6d6" : "#f6f6f6"
                    border.color: "#26282a"
                    border.width: 1
                    radius: 4
                }
                onClicked: {
                    console.debug("bt1")
                    v0.visible = false
                    v1.visible = true
                    v2.visible = false
                }
            }
            Button {
                id: bt2
                text: "bt2"
                background: Rectangle {
                    implicitWidth: 100
                    implicitHeight: 40
                    color: bt2.down ? "#d6d6d6" : "#f6f6f6"
                    border.color: "#26282a"
                    border.width: 1
                    radius: 4
                }
                onClicked: {
                    console.debug("bt2")
                    v0.visible = false
                    v1.visible = false
                    v2.visible = true
                }
            }
        }
    }
    

}
