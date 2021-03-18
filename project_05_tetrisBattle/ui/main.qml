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

    // Create object
    function addComponent(componentName: string, x: int, y: int, color: string) {
        var comp = Qt.createComponent("TetrisUnit.qml")
        var sprite = comp.createObject(tetrisBattleWindow)
        sprite.objectName = componentName
        sprite.x = x
        sprite.y = y
        sprite.color = color
        console.debug("create object")
        return sprite
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
        border.color: "black"
        border.width: 5

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
            text: qsTr("Start")
            width: parent.width - 20
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.bottom: parent.bottom
            anchors.bottomMargin: 200

            font.bold: true
            font.pointSize: 24

            onClicked: {
                startSignal();
                updateTimer.running = true
            }

            Timer {
                id: updateTimer
                interval: 1000; running: false; repeat: true;
                onTriggered: {
                    updateSignal()
                }
            }
            Keys.onUpPressed: {
                console.debug("Up")
                keyboardSignal(1)
            }
            Keys.onDownPressed: {
                console.debug("Down")
                keyboardSignal(2)
            }
            Keys.onLeftPressed: {
                console.debug("Left")
                keyboardSignal(3)
            }
            Keys.onRightPressed: {
                console.debug("Right")
                keyboardSignal(4)
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
            }
        }
    }
    
}
