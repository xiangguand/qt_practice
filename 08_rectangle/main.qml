import QtQuick 2.15
import QtQuick.Window 2.2
import QtQuick.Controls 1.4

ApplicationWindow {
    id: root
    visible: true
    width: 600
    height: 800
    
    Rectangle {
        id: rect1
        width: parent.width / 2
        height: parent.height / 2
        color: "red"
        anchors.centerIn: parent
    }
    Rectangle {
        id: move_rect
        width: 100
        height: 100
        x: rect1.x - move_rect.width
        y: rect1.y - move_rect.height
        color: "black"
        SequentialAnimation {
            running: true
            loops: Animation.Infinite
            PropertyAnimation {
                target: move_rect
                property: "x"
                from: rect1.x - move_rect.width
                to: rect1.x + rect1.width
                duration: 3000
            }
            PropertyAnimation {
                target: move_rect
                property: "y"
                from: rect1.y - move_rect.height
                to: rect1.y + rect1.height
                duration: 3000
            }
            PropertyAnimation {
                target: move_rect
                property: "x"
                from: rect1.x + rect1.width
                to: rect1.x - move_rect.width
                duration: 3000
            }
            PropertyAnimation {
                target: move_rect
                property: "y"
                from: rect1.y + rect1.height
                to: rect1.y - move_rect.height
                duration: 3000
            }
        }
        RotationAnimation on rotation {
            from: 0
            to: 360
            duration: 500
            loops: Animation.Infinite
        }
    }
    Button {
        text: "Debug"
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.bottom: parent.bottom
        
        onClicked: {
            console.debug("===============")
            console.debug(rect1.x)
            console.debug(rect1.y)
        }
    }
    
}

