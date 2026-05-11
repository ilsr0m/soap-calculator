import QtQuick

Rectangle {
    width: 200
    height: 40
    color: "#2b2b2b"
    radius: 6
    border.color: "#808080"

    TextInput {
        id: textInput4
        color: "#ffffff"
        anchors.fill: parent
        anchors.margins: 8
        font.pixelSize: 18

        validator: DoubleValidator {
            bottom: 0.0
            top: 1000000.0
            decimals: 3
            notation: DoubleValidator.StandardNotation
        }

        selectionColor: "#ffa500"
        selectedTextColor: "#000000"
    }
}
