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

    function addChildRect(id, x, y, width, height) {
        var component;
        component = Qt.createComponent("TetrisUnit.qml");
        component.createObject(this, {
                               id:id,
                               objectName:id,
                               x:x,
                               y:y,
                               color:"transparent",
                               width:width,
                               height:height,
                               visible:true});
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

        Component.onCompleted: {
            for(var j = 0; j < 10 ; j++) {
                for (var i = 0; i < 20; i++)  {   
                    addChildRect("skB"+String(i+20*j), tetrisBattleWindow.x+50*j, tetrisBattleWindow.y+50*i+50, 50, 50)
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
            }
        }
    }
    
}
