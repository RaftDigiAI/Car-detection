import QtQuick
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

    CamerHandler {
        id: handler
        videoOutput: preview
    }

    StatusOverlay {
        id: carStatusOverlay
        inferenceTime: handler.inferenceMs
        carDetected: handler.carDetected
        objectsDetected: handler.objectsDetected
    }
}
