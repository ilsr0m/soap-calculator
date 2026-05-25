import QtQuick
import QtQuick.Controls

import SoapCalculator

Rectangle {
    id: root

    // border.width: 3
    property bool checked: false
    property color accentColor: Theme.listItemText
    property color backgroundColor: "transparent"
    property int borderSize: 3

    signal clicked

    color: root.backgroundColor
    border.width: root.borderSize
    border.color: root.accentColor

    Behavior on border.color {
        ColorAnimation { duration: Theme.animationDuration }
    }

    Behavior on color {
        ColorAnimation { duration: Theme.animationDuration }
    }

    IconImage {
        id: checkIcon
        source: Theme.checkboxIconPath
        height: parent.height * 0.8
        width : height

        anchors.centerIn: parent
        fillMode: Image.PreserveAspectFit

        color: root.accentColor

        visible: root.checked

        Behavior on color {
            ColorAnimation { duration: Theme.animationDuration }
        }
    }

    // Поведение политры
    function resolveColor(normal, hover, pressed) {
        if(tapHandler.pressed)
            return pressed
        if(hoverHandler.hover)
            return hover
        return normal
    }

    TapHandler {
        id: tapHandler
        onTapped: root.clicked()
    }
}
