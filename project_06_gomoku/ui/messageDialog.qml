import QtQuick 2.15
import QtQuick.Dialogs 1.1

MessageDialog {
    id: dialog
    width: 300
    height: 150
    
    title: "Result"
    standardButtons: StandardButton.Ok

    onAccepted: {
        console.log("Ok clicked")
    }
}
