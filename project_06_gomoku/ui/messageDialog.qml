import QtQuick 2.3
import QtQuick.Controls 2.3

Dialog {
    id: dialog
    width: 300
    height: 150
    anchors.centerIn: parent
    title: "Result"
    standardButtons: Dialog.Ok
    property alias text : textContainer.text

    Text {
        id: textContainer

        anchors.fill: parent

        horizontalAlignment: Qt.AlignLeft
        verticalAlignment: Qt.AlignTop
    }
    onAccepted: {
        console.log("Ok clicked")
    }
}
