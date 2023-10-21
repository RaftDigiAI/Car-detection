import QtQuick
import QtQuick.Layouts

Rectangle {
    id: backgroung
    property bool carDetected: false
    property bool objectsDetected: false
    property int inferenceTime: 0

    height: carQuestion.height * 3 + grid.rowSpacing * 2
    width: 147

    radius: 10

    // Setup anchors
    anchors {
        top: parent.top
        left: parent.left
    }
    anchors.margins: 10

    // Load font where deffined icons
    FontLoader {
        id: iconFont
        source: "qrc:/res/resource/fonts/icon_font.ttf"
    }

    GridLayout {
        id: grid
        columns: 2
        anchors.fill: parent
        anchors.bottomMargin: 0
        anchors.leftMargin: 2
        anchors.topMargin: 0
        anchors.rightMargin: 2
        columnSpacing: 0

        // Icons:
        // e900 - car
        // e901 - ai chip v1
        // e902 - ai chip v2
        // e903 - group objects
        // e904 - timer icon
        Text {
            id: carQuestion
            text: "Car on frame?"
        }

        Text {
            id: carQuestionIcon
            text: "\ue900"
            horizontalAlignment: Text.AlignHCenter
            color: carDetected ? "green" : "red"
            Layout.fillWidth: true
        }

        Text {
            id: objectsDetectedQuestions
            text: "Objects detected?"
        }

        Text {
            id: objectsDetectedIcon
            text: "\ue903"
            horizontalAlignment: Text.AlignHCenter
            color: objectsDetected ? "green" : "red"
            Layout.fillWidth: true
        }

        Text {
            id: inferenceText
            text: "Inference(ms):"
        }

        Text {
            id: inferenceIcon
            text: inferenceTime + "\ue904"
            horizontalAlignment: Text.AlignHCenter
            Layout.fillWidth: true
        }
    }
}
