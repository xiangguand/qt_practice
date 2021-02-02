import QtQuick 2.5
import QtQuick.Window 2.2
import QtQuick.Controls 1.4

ApplicationWindow {
    id: root
    visible: true
    width: 600
    height: 200

    property int tableViewRow: 0    
    signal tableViewClickSignal(int row)

    ListModel {
        id: libraryModel
        ListElement {
            title: "A Masterpiece"
            author: "Gabriel"
        }
        ListElement {
            title: "Brilliance"
            author: "Jens"
        }
        ListElement {
            title: "Outstanding"
            author: "Frederik"
        }
    }
    Column {
        spacing: 2
        Text {
            text: qsTr("TableView test !!!")
            color: "blue"
            font.bold: true
            font.pointSize: 12
        }
        TableView {
            onCurrentRowChanged: {
                tableViewRow = currentRow
                tableViewClickSignal(tableViewRow)
                console.debug("Row change " + currentRow);
            }
            width: 400
            height: 200
            TableViewColumn {
                role: "title"
                title: "Title"
                width: 150
            }
            TableViewColumn {
                role: "author"
                title: "Author"
                width: 200
            }
            model: libraryModel
        }
    }
}

