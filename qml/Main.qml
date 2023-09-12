import QtQuick
import QtQuick.Controls
import QtQuick.Window
import QtMultimedia
import CarPrice

Window {
    id: root

    width: 640
    height: 480
    visible: true

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
}
