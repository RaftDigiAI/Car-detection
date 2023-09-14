import QtQuick
import QtQuick.Controls
import QtQuick.Window
import QtMultimedia
import CarPrice

ApplicationWindow {
    id: root

    width: 640
    height: 480
    visible: true

    onClosing: camera.stop()

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

    VideoOutput {
        id: preview
        anchors.fill: parent
    }

    footer: Item {
        height: 0.05 * parent.height
        Text {
            id: detectionStatus
            anchors.left: parent
            anchors.top: parent
            anchors.bottom: parent
            text: handler.objectOnFrame ? qsTr("Car on frame") : qsTr("Car not found")
        }

        Text {
            id:inferenseStatus;

            anchors.top: parent
            anchors.bottom: parent
            anchors.left: detectionStatus.right
            anchors.margins: {
                left: 10
            }

            text: handler.inferenceCorrect ? qsTr("Inference fine") : qsTr("Problem with model")
        }
    }


}
