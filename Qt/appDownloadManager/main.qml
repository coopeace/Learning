import QtQuick 2.15
import QtQuick.Controls 2.15
import MyApp 1.0

ApplicationWindow {
    visible: true
    width: 400
    height: 350
    title: "Download Manager"

    Downloader {
        id: downloader
        onProgressChanged: {
            progressBarValue = progress
        }
        onFinished: {
            statusText = "Finished"
        }
        onLastSavedPathChanged: {
            lastPathText = "Saved to: " + lastSavedPath
        }
    }

    Column {
        anchors.centerIn: parent
        spacing: 10
        width: parent.width - 40

        TextField {
            id: urlInput
            placeholderText: "Enter URL"
            width: parent.width
        }

        Button {
            text: "Download"
            anchors.horizontalCenter: parent.horizontalCenter
            onClicked: {
                statusText = "Downloading..."
                lastPathText = ""
                downloader.startDownload(urlInput.text)
            }
        }

        ProgressBar {
            value: progressBarValue
            width: parent.width
        }

        Text {
            text: statusText
            anchors.horizontalCenter: parent.horizontalCenter
        }

        Text {
            text: lastPathText
            wrapMode: Text.WrapAnywhere
            width: parent.width
            font.pixelSize: 10
            color: "gray"
        }
    }

    property real progressBarValue: 0
    property string statusText: "Idle"
    property string lastPathText: ""
}
