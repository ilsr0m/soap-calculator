import QtQuick
import SoapCalculator

Rectangle {
    id: titleArea
    property string titleText: "title"
    color: Theme.header
    Text {
        anchors.centerIn: parent
        text: parent.titleText
        color: Theme.headerText
        font.pixelSize: parent.height * 0.7
        font.bold: true
    }
}
