import QtQuick 2.3
import QtQuick.Window 2.2
import QtQuick.Controls 2.3

ApplicationWindow {
    id: root
    visible: true

    width: 1600
    height: 1100

    signal mouseClickSignal(int x, int y)
    signal resetSignal()

    property variant pieceCollector: Array()

    // Create piece
    function addPiece(componentName: string, x: int, y: int, color: string) {
        var component = Qt.createComponent("piece.qml")
        if(component.status == Component.Ready) {
            var piece = component.createObject(gameWindow)
            piece.objectName = componentName
            piece.x = x - piece.width / 2
            piece.y = y - piece.width / 2
            piece.color = color
            pieceCollector.push(piece)
        }
        else {
            console.error(component.errorString())
        }
    }

    function showDialog(message: string) {
        var component = Qt.createComponent("messageDialog.qml")
        if(component.status == Component.Ready) {
            var dialog = component.createObject(gameWindow)

            dialog.title = qsTr("Result")
            dialog.text = message

            dialog.open()
        } 
        else {
            console.error(component.errorString())
        }
    }

    menuBar: MenuBar {
        id: menubar
        height: 50
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

    // Gaming window
    Rectangle {
        id: gameWindow
        width: 1000
        height: 1000
        anchors.bottom: parent.bottom
        anchors.left: parent.left
        anchors.leftMargin: 20
        anchors.bottomMargin: 20
        
        color: "#D26900"
        border.color: "black"
        border.width: 5

        // Draw the gaming map
        Grid {
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.verticalCenter: parent.verticalCenter
            
            rows: 18; columns: 18
            Repeater { 
                model: 324
                Rectangle {
                    width: 50
                    height: 50
                    color: "#D26900"
                    border.color: "black"
                    border.width: 2
                }
            }
        }

        MouseArea {
            anchors.fill: parent
            onClicked: {
                // sending the signal
                mouseClickSignal(mouse.x, mouse.y)
            }
        }
    }
    
    // Information
    Rectangle {
        id: infoWindow
        objectName: "infoWindow"
        width: 500
        height: 1000

        anchors.bottom: parent.bottom
        anchors.left: gameWindow.right
        anchors.leftMargin: 20
        anchors.bottomMargin: 20

        border.color: "black"

        Text {
            id: infoText
            objectName: "infoText"
            text: qsTr("Now: black")
            anchors.left: parent.left
            anchors.top: parent.top
            anchors.leftMargin: 50
            anchors.topMargin: 50

            font.bold: true
            font.pointSize: 24
            color: "black"
        }
    
        Button {
            id: btReset
            text: qsTr("reset")
            font.bold: true
            font.pointSize: 24
            width: parent.width - 20
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.bottom: parent.bottom
            anchors.bottomMargin: 200
            onClicked: {
                console.debug("Reset")
                resetSignal()
                pieceCollector.forEach(function(item, index, array) {
                    // console.log(item, index);
                    item.destroy()
                });
                pieceCollector = []
            }
        }
    }
    
    
}
