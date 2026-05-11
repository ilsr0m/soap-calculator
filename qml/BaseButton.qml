import QtQuick
import QtQuick.Controls

Rectangle {
    id: root

    width: 160
    height: 44

    radius: 10
    color: mouseArea.pressed
           ? "#2f6fd1"
           : mouseArea.containsMouse
             ? "#3b82f6"
             : "#2563eb"

    border.width: 1
    border.color: "#1e40af"

    property alias text: buttonText.text
    signal clicked

    Behavior on color {
        ColorAnimation {
            duration: 120
        }
    }

    Text {
        id: buttonText

        anchors.centerIn: parent

        color: "white"
        font.pixelSize: 16
        font.bold: true

        text: "Button"
    }

    MouseArea {
        id: mouseArea

        anchors.fill: parent
        hoverEnabled: true
        cursorShape: Qt.PointingHandCursor

        onClicked: root.clicked()
    }
}
