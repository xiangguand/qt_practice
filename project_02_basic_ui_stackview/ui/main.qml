import QtQuick 2.15
import QtQuick.Window 2.2
import QtQuick.Controls 2.3
import QtQuick.Layouts 1.15

ApplicationWindow {
    id: root
    visible: true
    width: 1800
    height: 1200

    property int pageIndex: 0    
    property var pageArray: [
        "page0.qml",
        "page1.qml",
        "page2.qml"
    ];

    ListModel {
        id: pageModel
        ListElement {
            title: "page1"
            page: "ui/page1.qml"
        }
        ListElement {
            title: "page2"
            page: "ui/page2.qml"
        }
    }

    menuBar: MenuBar {
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

    header: ToolBar {
        RowLayout {
            anchors.fill: parent
            Button {
                text: qsTr("‹")
                onClicked: {
                    myStackView.pop()
                    if(pageIndex > 0) {
                        pageIndex--
                    }
                    console.debug("pageIndex: ", pageIndex)
                }
            }
            Label {
                text: "Title"
                elide: Label.ElideRight
                horizontalAlignment: Qt.AlignHCenter
                verticalAlignment: Qt.AlignVCenter
                Layout.fillWidth: true
            }
            Button {
                text: qsTr(">")
                onClicked: {
                    if(pageIndex < pageArray.length-1) {
                        pageIndex++
                    }
                    console.debug("pageIndex: ", pageIndex)
                    myStackView.push(Qt.resolvedUrl(pageArray[pageIndex]))
                }
            }
        }
    }

    StackView {
        id: myStackView
        anchors.centerIn: parent
        initialItem: Qt.resolvedUrl(pageArray[pageIndex])
        MouseArea {
                anchors.fill: parent;
                onClicked: {
                    console.debug("mouse click")
                }
        }
    }   
}
