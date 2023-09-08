import QtQuick
import QtQuick.Window

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")

    Rectangle {
        anchors.centerIn: parent
        implicitHeight: parent.height - 10
        implicitWidth: parent.width - 10
        color: "red"

        Text {
            id: name
            text: qsTr("text")
            anchors.centerIn: parent
        }
    }
}
