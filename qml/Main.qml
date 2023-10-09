import QtQuick
import QtQuick.Controls
import QtQuick.Window
import QtMultimedia
import QtQuick.Controls.Material
import CarPrice

Window {
    id: root

    // Default camera size.
    visible: true

    property bool itLandscape: width > height

    // Theme
    Material.theme: Material.Light

    // Default camera state - is Active
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
            focusMode: Camera.FocusModeInfinity
        }

        videoOutput: preview
    }

    VideoHandler {
        id: handler
        videoSink: preview.videoSink
        onVideoSizeChanged: console.log("Video size:" + videoSize)
    }

    Component.onCompleted: {
        preview.rotation = itLandscape ? 90 : 0
    }

    VideoOutput {
        id: preview

        property double aspectRation: 1

        anchors.centerIn: parent
        // View set preview eqaul parent size, but what if videSize will be
        height: parent.height
        width: aspectRation * height

        fillMode: VideoOutput.Stretch

        onFrameUpdated: {
            aspectRation = preview.videoSink.videoSize.height / preview.videoSink.videoSize.width
        }
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
