import QtQuick 2.15
import QtQuick.Window 2.2
import QtQuick.Controls 1.4

ApplicationWindow {
    id: root
    visible: true
    width: 450
    height: 100

    
    property int firstObj_x: 50
    property int firstObj_y: 20
    
    property string temp_celsius;
    property string temp_fahrenheit;

    signal textChangeCSignal(string changeText)
    signal textChangeFSignal(string changeText)
    
    TextField {
        objectName: "txtfield_c"
        id: txtField_c
        x: firstObj_x
        y: firstObj_y
        onTextChanged: {
            temp_celsius = text
            console.debug("temp_celsius")
            textChangeCSignal(temp_celsius)
        }
        width: 100
        height: 50
        text: "0.00"
        focus: true
    }
    Text {      
        id: txt_c
        anchors.left: txtField_c.right
        y: firstObj_y
        height: 50
        text: " C"
        font.pointSize: 14
    }
    TextField {
        objectName: "txtfield_f"
        id: txtField_f
        y: firstObj_y
        anchors.left: txt_c.right
        anchors.leftMargin: 50
        onTextChanged: {
            temp_fahrenheit = text
            console.debug("temp_fahrenheit")
            textChangeFSignal(temp_fahrenheit)
        }
        width: 100
        height: 50
        text: "32.00"
        focus: true
    }
    Text {
        id: txt_f
        anchors.left: txtField_f.right
        y: firstObj_y
        height: 50
        text: " F"
        font.pointSize: 14
    }
    
    
}

