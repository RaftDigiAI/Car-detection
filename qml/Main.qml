import QtQuick
import QtQuick.Controls
import QtQuick.Window
import QtMultimedia
import QtQuick.Controls.Material
import CarPrice

Window {
    id: root

    // Default camera size.
    width: 640
    height: 480
    visible: true

    readonly property double aspectRation: 4 / 3
    property bool itLandscape: width > height

    // Theme
    Material.theme: Material.Light

    // Default camera state - is Active
    //    onClosing: camera.stop()
    MediaDevices {
        id: mediaDevices
    }

    CaptureSession {
        imageCapture: ImageCapture {
            id: imageCapture
        }

        camera: Camera {
            id: camera
            cameraDevice: mediaDevices.defaultVideoInput
            active: true
        }

        videoOutput: preview
    }

    VideoHandler {
        id: handler
        videoSink: preview.videoSink
    }

    Component.onCompleted: {
        preview.rotation = itLandscape ? 90 : 0
    }

    VideoOutput {
        id: preview
        anchors.centerIn: parent
        width: height * aspectRation
        height: parent.height
    }

    Rectangle {
        id: carItem
        color: Material.background
        height: carQuestion.height
        width: carQuestion.width + icon.width * 1.5

        radius: 20

        anchors {
            top: parent.top
            left: parent.left
        }

        anchors.margins: 10

        Text {
            id: carQuestion
            x: 5
            width: 92
            height: 20
            text: "Car on frame?"
            anchors {
                top: parent.top
                bottom: parent.botom
            }
        }

        Image {
            id: icon
            source: handler.score > 0.5 ? "qrc:/res/check.svg" : "qrc:/res/discard.svg"
            height: parent.height / 2
            width: height
            anchors {
                top: carQuestion.top
                left: carQuestion.right
                bottom: carQuestion.bottom
            }
        }
    }
}
