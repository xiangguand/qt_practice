import QtQuick 2.3
import QtQuick.Window 2.2
import QtQuick.Controls 2.3

ApplicationWindow {
    id: root
    visible: true
    width: 1800
    height: 1200

    signal startSignal()
    signal stopSignal()
    signal updateSignal()
    signal keyboardSignal(int keydir)

    property var btState : false

    // Create object
    function addComponent(componentName: string, x: int, y: int, color: string) {
        var comp = Qt.createComponent("TetrisUnit.qml")
        var rect = comp.createObject(tetrisBattleWindow)
        rect.objectName = componentName
        rect.x = x
        rect.y = y
        rect.color = color
        if(x < 0 || y < 0) {
            rect.visible = false
        }
        console.debug("create object")
        return rect
    }

    function timerIntervalSlot(intvl : int) {
        updateTimer.interval = intvl
    }
    
    menuBar: MenuBar {
        id: menubar
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
        Timer {
            id: updateTimer
            interval: 1000; running: false; repeat: true;
            onTriggered: {
                updateSignal()
            }
        }
    }


    // Tetris battle (10X20), each rectangle (50X50)
    // window 500X1000
    Rectangle {
        id: tetrisBattleWindow
        anchors.left: parent.left
        anchors.bottom: parent.bottom
        anchors.leftMargin: 50
        anchors.bottomMargin: 100
        
        width: 500
        height: 1000
        
        border.color: "black"
        border.width: 5

        Grid {
            rows: 20; columns: 10
            Repeater { 
                model: 200
                Rectangle {
                    width: 50
                    height: 50
                    color: "slategray"
                    border.color: "black"
                }
            }
        }
    }

    // Show the score
    Rectangle {
        id: informationWindow
        anchors.left: tetrisBattleWindow.right
        anchors.top: tetrisBattleWindow.top
        anchors.leftMargin: 50

        width: 500
        height: 1000
        focus: true
        activeFocusOnTab: true
        border.color: "black"
        border.width: 5
        Keys.onPressed: {
            if (event.key == Qt.Key_Up) {
                console.debug("CW")
            keyboardSignal(1)
            }
            else if(event.key == Qt.Key_Down) {
                console.debug("Down")
            keyboardSignal(2)
            }
            else if(event.key == Qt.Key_Left) {
                console.debug("Left")
                keyboardSignal(3)
            }
            else if(event.key == Qt.Key_Right) {
                console.debug("Right")
                keyboardSignal(4)
            }
            else if(event.key == Qt.Key_x || event.key == Qt.Key_X) {
                console.debug("X")
                keyboardSignal(5)
            }
            else if(event.key == Qt.Key_c || event.key == Qt.Key_C) {
                console.debug("C")
                keyboardSignal(6)
            }
            else if(event.key == Qt.Key_z || event.key == Qt.Key_Z) {
                console.debug("Z")
                keyboardSignal(7)
            }
            else if(event.key == Qt.Key_Space) {
                console.debug("Key_Space")
                keyboardSignal(8)
            }
        }

        Text {
            id: scoreTxt
            text: qsTr("score: 0")
            anchors.left: parent.left
            anchors.top: parent.top
            anchors.leftMargin: 20
            anchors.topMargin: 20

            font.bold: true
            font.pointSize: 24
            color: "black"
        }

        Button {
            id: startBt
            text: qsTr("Start")
            width: parent.width - 20
            checkable: true
            checked: false
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.bottom: parent.bottom
            anchors.bottomMargin: 200

            font.bold: true
            font.pointSize: 24

            onClicked: {
                if(!btState) {
                    startSignal();
                    updateTimer.running = true
                }
                startBt.checked = true
                btState = true
            }
        }

        Button {
            text: qsTr("Stop")
            width: parent.width - 20
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.bottom: parent.bottom
            anchors.bottomMargin: 100

            font.bold: true
            font.pointSize: 24
            onClicked: {
                stopSignal()
                updateTimer.running = false
                startBt.checked = false
                btState = false
            }
        }
    }
    
}
