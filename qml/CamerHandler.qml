import QtQuick
import QtMultimedia
import CarPrice

Item {
    id: root
    property alias videoOutput: captureSession.videoOutput
    property alias objectsDetected: handler.objectsDetected
    property alias scoreDetectedObject: handler.score
    readonly property bool carDetected: handler.carDetected

    MediaDevices {
        id: mediaDevices
    }

    CaptureSession {
        id: captureSession

        camera: Camera {
            id: camera
            cameraDevice: mediaDevices.defaultVideoInput
            active: true
            focusMode: Camera.FocusModeInfinity
        }
    }

    // Process frame throug model
    VideoHandler {
        id: handler
        videoSink: videoOutput.videoSink
    }
}
