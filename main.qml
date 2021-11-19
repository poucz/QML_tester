import QtQuick 2.10
import QtQuick.Window 2.10
import QtQuick.Controls 2.0


Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")

    Rectangle{
        anchors.fill: parent
        color: "black"
    }

    Row{
        Button{
            text:"ZK"
            onClicked:{
                console.log("Cnt:"+handler.sensorsObj.length)
                console.log("Cnt:"+handler.sensors.length)
            }
        }
    }
}
