import QtQuick
import QtQuick.Controls

import SoapCalculator

Rectangle {
    id: root
    border.width: 3

    enum ButtonType { Neutral, Positive, Negative }
    property int buttonType: BaseButton.Neutral

    function resolveColor(normal, hover, pressed) {
        if(mouseArea.pressed)
            return pressed
        if(mouseArea.containsMouse)
            return hover
        return normal
    }

    function palette() {
        switch(buttonType) {
            case BaseButton.Positive:
                return {
                    background: resolveColor(Theme.buttonPositive      , Theme.buttonHoverPositive      , Theme.buttonPressedPositive      ),
                    border    : resolveColor(Theme.buttonBorderPositive, Theme.buttonBorderHoverPositive, Theme.buttonBorderPressedPositive),
                    text      : resolveColor(Theme.buttonTextPositive  , Theme.buttonTextHoverPositive  , Theme.buttonTextPressedPositive  )
                }
            case BaseButton.Negative:
                return {
                    background: resolveColor(Theme.buttonNegative      , Theme.buttonHoverNegative      , Theme.buttonPressedNegative      ),
                    border    : resolveColor(Theme.buttonBorderNegative, Theme.buttonBorderHoverNegative, Theme.buttonBorderPressedNegative),
                    text      : resolveColor(Theme.buttonTextNegative  , Theme.buttonTextHoverNegative  , Theme.buttonTextPressedNegative  )
                }
            default:
                return {
                    background: resolveColor(Theme.button      , Theme.buttonHover      , Theme.buttonPressed      ),
                    border    : resolveColor(Theme.buttonBorder, Theme.buttonBorderHover, Theme.buttonBorderPressed),
                    text      : resolveColor(Theme.buttonText  , Theme.buttonTextHover  , Theme.buttonTextPressed  )
                }
        }
    }

    color       : palette().background
    border.color: palette().border
    property color textColor: palette().text

    property alias text: buttonText.text
    signal clicked
    Behavior on color { ColorAnimation { duration: 120 } }

    Text {
        id: buttonText
        anchors.centerIn: parent

        color: root.textColor

        font.pixelSize: parent.height * 0.5
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
