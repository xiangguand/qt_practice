import QtQuick 2.15
import "MyComponents"

Item {
    function myQmlFunction(msg) {
        console.log("Got message:", msg)
        console.log(skGrid.itemAt(1))
        return "some return value"
    }
}

