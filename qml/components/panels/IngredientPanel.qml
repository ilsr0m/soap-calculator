import QtQuick
import QtQuick.Layouts
import QtQuick.Controls

import SoapCalculator

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
            radius: Theme.radius

            id: titleArea
            Layout.fillWidth: true
            Layout.preferredHeight: parent.height * 0.1

            color: Theme.header

            Text {
                anchors.centerIn: parent
                text: root.title
                color: Theme.headerText
                // font.pixelSize: 16
                font.pixelSize: parent.height * 0.7
                font.bold: true
            }
        }

        // Search area
        Rectangle {
            radius: Theme.radius

            id: searchArea
            Layout.fillWidth: true
            Layout.preferredHeight: parent.height * 0.10
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



                    selectionColor: Theme.searchSelectionColor
                    selectedTextColor: Theme.searchSelectionTextColor

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
            // radius: Theme.radius
            id: listArea
            Layout.fillWidth: true
            Layout.fillHeight: true
            color: Theme.listView

            ListView {
                id: listView
                currentIndex: -1

                anchors.fill: listArea
                model: root.model

                clip: true
                boundsBehavior: Flickable.StopAtBounds
                flickableDirection: Flickable.VerticalFlick
                ScrollBar.vertical: ScrollBar { policy: ScrollBar.AsNeeded }

                // spacing: -3

                delegate: Rectangle {

                    id: viewDelegate

                    width: ListView.view.width
                    height: listArea.height * 0.2

                    function resolveColor(normal, hover, selected) {
                        if (ListView.isCurrentItem)
                            return selected

                        if(mouseArea.pressed)
                            return selected
                        if(mouseArea.containsMouse)
                            return hover
                        return normal
                    }

                    Text {
                        color: viewDelegate.resolveColor(Theme.listItemText,
                                                         Theme.listItemTextHover,
                                                         Theme.listItemTextPressed)

                        anchors.left: parent.left
                        anchors.verticalCenter: parent.verticalCenter
                        anchors.leftMargin: 10
                        text: nameEn

                        font.pixelSize: listArea.height * 0.1
                        font.bold: true
                    }

                    color: viewDelegate.resolveColor(Theme.listItem,
                                                     Theme.listItemHover,
                                                     Theme.listItemPressed)
                    signal clicked
                    Behavior on color { ColorAnimation { duration: 120 } }
                    MouseArea {
                        id: mouseArea
                        anchors.fill: parent
                        hoverEnabled: true
                        cursorShape: Qt.PointingHandCursor

                        acceptedButtons: Qt.LeftButton | Qt.RightButton
                        onClicked: {
                            if(mouse.button === Qt.LeftButton)
                                listView.currentIndex = index
                            if(mouse.button === Qt.RightButton)
                                listView.currentIndex = -1
                        }
                    }
                }
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
                    buttonType: BaseButton.Neutral

                    text: root.infoButtonText
                    width : actionArea.width  * actionArea.buttonWidthScale
                    height: actionArea.height * actionArea.buttonHeightScale
                }
                BaseButton {
                    id: addButton
                    buttonType: BaseButton.Positive
                    text: root.addButtonText
                    width : actionArea.width  * actionArea.buttonWidthScale
                    height: actionArea.height * actionArea.buttonHeightScale
                }
            }
        }
    }
}



