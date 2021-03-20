import QtQuick 2.3

Item {
    anchors.fill: parent
    focus: true
    Keys.onPressed: {
        if (event.key == Qt.Key_Up) {
            console.debug("Up")
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
        else if(event.key == Qt.Key_Space) {
            console.debug("Space")
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
    }
}
