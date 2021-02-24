import QtQuick 2.15
import QtQuick.Window 2.2
import QtQuick.Controls 2.3
import QtQuick.Layouts 1.15



ApplicationWindow {

    id: root
    visible: true
    width: 1800
    height: 1200

    signal startSignal()
    signal stopSignal()
    signal testSignal()


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
            }
        }
        Button {
            id: btnStop
            text: "stop"
            width: parent.width
            anchors.top: funcWindow.top
            anchors.topMargin: 600
            font.bold: true
            font.pointSize: 24
            onClicked: {
                stopSignal()
            }
        }
        Button {
            id: btnTest
            text: "test"
            width: parent.width
            anchors.top: funcWindow.top
            anchors.topMargin: 800
            font.bold: true
            font.pointSize: 24
            onClicked: {
                testSignal()
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
                               width:width,
                               height:height,
                               visible:true});
    }

}
