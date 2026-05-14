import QtQuick
import QtQuick.Controls

// import "../../themes"
import SoapCalculator

Rectangle {
    id: root

    radius: 3
    border.width: 3

    // Theme { id: theme }

    // colors
    color: mouseArea.pressed
        ? Theme.buttonPressed
        : mouseArea.containsMouse
            ? Theme.buttonHover
            : Theme.button
    border.color: mouseArea.pressed
        ? Theme.buttonBorderPressed
        : mouseArea.containsMouse
            ? Theme.buttonBorderHover
            : Theme.buttonBorder
    property color textColor: mouseArea.pressed
        ? Theme.buttonTextPressed
        : mouseArea.containsMouse
            ? Theme.buttonTextHover
            : Theme.buttonText

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
