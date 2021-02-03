import QtQuick 2.15
import QtQuick.Window 2.2
import QtQuick.Controls 1.4

ApplicationWindow {
    id: root
    visible: true
    width: 600
    height: 300

    property string textEditText;
    property string textFieldText;
    property string textInputText;
    
    signal textEditChangeSignal(string changeText)
    signal textFieldCompleteSignal(string changeText)
    signal textInputCompleteSignal(string changeText)

    Column {
        spacing: 2
        Text {
            text: qsTr("TextEdit test !!!")
            color: "blue"
            font.bold: true
            font.pointSize: 12
        }
        TextEdit {
            onTextChanged: {
                textEditText = text
                console.debug("TextEdit enter detect: " + textEditText)
                textEditChangeSignal(textEditText)
            }
            width: 500
            height: 150
            text: "TextEdit, edit me !"
            focus: true
        }
        TextField {
            onEditingFinished: {
                textFieldText = text
                console.debug("TextField enter detect: " + textFieldText)
                textFieldCompleteSignal(textFieldText)
            }
            width: 500
            height: 50
            text: "TextField, edit me !"
            focus: true
        }
        TextInput {
            onEditingFinished: {
                textInputText = text
                console.debug("TextInput enter detect: " + textInputText)
                textInputCompleteSignal(textInputText)
            }
            width: 500
            height: 50
            text: "TextInput, edit me !"
            focus: true
        }
    }
}

