import QtQuick
import QtQuick.Layouts
import QtQuick.Controls

import SoapCalculator

Rectangle {
    id: actionArea
    color: Theme.panel

    property double buttonWidthScale: 0.48
    property double buttonHeightScale: 0.9

    property string infoButtonText: "info"
    property string addButtonText: "add"

    Row {
        id: row
        anchors.centerIn: parent
        spacing: 10
        BaseButton {
            id: infoButton
            buttonType: BaseButton.Neutral

            text: actionArea.infoButtonText
            width : actionArea.width  * actionArea.buttonWidthScale
            height: actionArea.height * actionArea.buttonHeightScale
        }
        BaseButton {
            id: addButton
            buttonType: BaseButton.Positive
            text: actionArea.addButtonText
            width : actionArea.width  * actionArea.buttonWidthScale
            height: actionArea.height * actionArea.buttonHeightScale
        }
    }
}
