import QtQuick
import QtQuick.Controls

import "../../themes"

Rectangle {
    id: root

    radius: 3
    border.width: 3

    Theme { id: theme }

    // colors
    color: mouseArea.pressed
        ? theme.buttonPressed
        : mouseArea.containsMouse
            ? theme.buttonHover
            : theme.button
    border.color: mouseArea.pressed
        ? theme.buttonBorderPressed
        : mouseArea.containsMouse
            ? theme.buttonBorderHover
            : theme.buttonBorder
    property color textColor: mouseArea.pressed
        ? theme.buttonTextPressed
        : mouseArea.containsMouse
            ? theme.buttonTextHover
            : theme.buttonText

    property alias text: buttonText.text
    signal clicked

    Behavior on color { ColorAnimation { duration: 120 } }

    Text {
        id: buttonText
        anchors.centerIn: parent

        color: root.textColor

        font.pixelSize: 16
        font.bold: true
        text: qsTr("Button")
    }

    MouseArea {
        id: mouseArea
        anchors.fill: parent
        hoverEnabled: true
        cursorShape: Qt.PointingHandCursor
        onClicked: root.clicked()
    }
}
