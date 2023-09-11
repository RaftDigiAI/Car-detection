import QtQuick
import QtQuick.Window
import QtMultimedia

Window {
    id: root

    width: 640
    height: 480
    visible: true

    CaptureSession {
        imageCapture: ImageCapture {
            id: imageCapture
        }

        camera: Camera {
            id: camera
            active: true
        }

        videoOutput: preview
    }

    VideoOutput {
        id: preview
        anchors.fill: parent
        videoSink.call: {
            preview.frameUpdated()
        }
    }
}
