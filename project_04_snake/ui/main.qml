import QtQuick 2.15
import QtQuick.Window 2.2
import QtQuick.Controls 2.3
import QtQuick.Layouts 1.15

ApplicationWindow {
    id: root
    visible: true
    width: 1800
    height: 1200

    property var startFlag : false
    property var stopFlag : false 
    property var gameoverFlag : false
    property int score : 0

    signal startSignal()
    signal stopSignal()
    signal updateSignal()

    function gameoverSlot() {
        gameoverFlag = true
        updateTimer.running = false
        console.debug("gameover")
    }

    function scoreSlot(_score : int) {
        scoreText.text = _score.toString()
    }

    function timerIntervalSlot(intvl : int) {
        updateTimer.interval = intvl
    }

    // Define the keyboard signal
    signal keyboardSignal(int keydir)
    
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

    Rectangle {
        id: snakeWindow
        width: 1200
        height: 1000
        focus: true
        anchors.verticalCenter: parent.verticalCenter
        anchors.left: parent.left
        anchors.leftMargin: 20
        border.color: "black"
        border.width: 5
        color: "transparent"

        Component.onCompleted: {
            for(var j = 0; j < 24 ; j++) {
                for (var i = 0; i < 20; i++)  {   
                    addChildRect("skB"+String(i+20*j), snakeWindow.x+50*j, snakeWindow.y+50*i+45, 48, 48)
                }
            }
        }

        
    }
    
    Rectangle {
        id: funcWindow
        width: 500
        height: 1000
        color: "transparent"
        border.color: "black"
        border.width: 1
        anchors.verticalCenter: parent.verticalCenter
        anchors.left: snakeWindow.right
        anchors.leftMargin: 50
        Text {
            id: scoreName
            text: "score"
            anchors.top: funcWindow.top
            anchors.topMargin: 100
            font.bold: true
            font.pointSize: 24
            Text {
                id: scoreText
                anchors.left: scoreName.right
                anchors.leftMargin: 50
                anchors.topMargin: 200
                font.bold: true
                font.pointSize: 24
                text: "0"
            }
        }

        Button {
            id: btnStart
            text: "start"
            width: parent.width
            anchors.top: funcWindow.top
            anchors.topMargin: 400
            font.bold: true
            font.pointSize: 24
            onClicked: {
                startSignal()
                updateTimer.running = true
                btnStart.text = "restart"
            }
            Timer {
                id: updateTimer
                interval: 500; running: false; repeat: true;
                onTriggered: {
                    console.debug("timer")
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
            id: btnStop
            text: "pause"
            width: parent.width
            anchors.top: funcWindow.top
            anchors.topMargin: 600
            font.bold: true
            font.pointSize: 24
            onClicked: {
                stopSignal()
                if(stopFlag) {
                    updateTimer.running = true
                    stopFlag = false
                    btnStop.text = "pause"
                }
                else {
                    updateTimer.running = false
                    stopFlag = true
                    btnStop.text = "resume"
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
    }
    function addChildRect(id, x, y, width, height) {
        var component;
        component = Qt.createComponent("Snakebody.qml");
        component.createObject(this, {
                               id:id,
                               objectName:id,
                               x:x,
                               y:y,
                               color:"black",
                               width:width,
                               height:height,
                               visible:false});
    }

    
}
