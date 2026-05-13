import QtQuick
import QtQuick.Layouts
import "../../themes"
import "../base"

Rectangle {
    id: root
    Theme { id: theme }

    color: theme.panel
    property int gap: 6

    property string title: qsTr("TITLE")
    property string searchWatermark: qsTr("SEARCH...")

    property string addButtonText : qsTr("ADD TO RECIPE")
    property string infoButtonText: qsTr("INFO")

    property var model: dummyModel

    width : parent.width  * 0.25
    height: parent.height * 0.25

    ColumnLayout {
        anchors.fill: parent
        anchors.margins: root.gap
        spacing: root.gap

        // Title
        Rectangle {
            id: titleArea
            Layout.fillWidth: true
            Layout.preferredHeight: parent.height * 0.08

            color: theme.header

            Text {
                anchors.centerIn: parent
                text: root.title
                color: theme.headerText
                font.pixelSize: 16
                font.bold: true
            }
        }

        // Search area
        Rectangle {
            id: searchArea
            Layout.fillWidth: true
            Layout.preferredHeight: parent.height * 0.08
            color: "salmon"

            RowLayout {
                TextInput {
                    id: searchInput
                }
            }
        }

        // ListView of ingredients
        Rectangle {
            id: listArea
            Layout.fillWidth: true
            Layout.fillHeight: true
            color: theme.background

            ListView {
                anchors.fill: parent
                model: root.model
            }
        }

        // Action Buttons
        Rectangle {
            id: actionArea
            Layout.fillWidth: true
            Layout.preferredHeight: parent.height * 0.12
            color: theme.panel

            property double buttonWidthScale: 0.48
            property double buttonHeightScale: 0.9

            Row {
                id: row
                anchors.centerIn: parent
                spacing: 10
                BaseButton {
                    id: infoButton
                    text: root.infoButtonText
                    width : actionArea.width  * actionArea.buttonWidthScale
                    height: actionArea.height * actionArea.buttonHeightScale
                }
                BaseButton {
                    id: addButton
                    text: root.addButtonText
                    width : actionArea.width  * actionArea.buttonWidthScale
                    height: actionArea.height * actionArea.buttonHeightScale
                }
            }
        }
    }
}



