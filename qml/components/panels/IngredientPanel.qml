import QtQuick
import QtQuick.Layouts

import SoapCalculator

// import "../../themes"
// import "../base"

Rectangle {
    id: root
    color: Theme.panel

    property int gap: 6

    property string title: qsTr("TITLE")
    property string searchWatermark: qsTr("SEARCH...")

    property string addButtonText : qsTr("ADD TO RECIPE")
    property string infoButtonText: qsTr("INFO")

    property var model

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

            color: Theme.header

            Text {
                anchors.centerIn: parent
                text: root.title
                color: Theme.headerText
                font.pixelSize: 16
                font.bold: true
            }
        }

        // Search area
        Rectangle {
            id: searchArea
            Layout.fillWidth: true
            Layout.preferredHeight: parent.height * 0.12
            // color: "salmon"

            Row {
                id: searchRow

                anchors.fill: parent
                anchors.leftMargin: parent.width * 0.03
                anchors.rightMargin: parent.width * 0.03
                spacing: parent.width * 0.02

                Image {
                    id: searchIcon
                    source: Theme.seachIcon

                    height: parent.height * 0.5
                    width: height
                    fillMode: Image.PreserveAspectFit

                    anchors.verticalCenter: parent.verticalCenter
                }

                TextInput {
                    id: searchInput
                    width: searchRow.width - searchIcon.width - searchRow.spacing
                                   - searchRow.anchors.leftMargin - searchRow.anchors.rightMargin
                    height: parent.height

                    verticalAlignment: TextInput.AlignVCenter
                    font.pixelSize: parent.height * 0.5

                    color: "black"
                    clip: true

                    Text {
                        anchors.fill: parent
                        verticalAlignment: Text.AlignVCenter

                        text: "SEARCH..."
                        color: "#999999"
                        font.pixelSize: searchInput.font.pixelSize

                        visible: searchInput.text.length === 0
                    }

                    HoverHandler { cursorShape: Qt.IBeamCursor }
                }

            }
        }

        // ListView of ingredients
        Rectangle {
            id: listArea
            Layout.fillWidth: true
            Layout.fillHeight: true
            color: Theme.panel

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
            color: Theme.panel

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



