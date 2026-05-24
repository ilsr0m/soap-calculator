import QtQuick
import QtQuick.Layouts
import QtQuick.Controls

import SoapCalculator

Rectangle {
    id: searchArea
    color: Theme.panel

    property string watermark: "search..."

    RowLayout {
        id: searchRow
        anchors.fill: parent
        spacing: parent.width * 0.008

        Rectangle {
            color: Theme.searchTextInputBackgroundColor
            Layout.fillWidth: true
            Layout.fillHeight: true
            RowLayout {
                anchors.fill: parent
                Rectangle {
                    Layout.preferredHeight: searchRow.height
                    Layout.preferredWidth : searchRow.height
                    Image {
                        id: searchIcon
                        source: Theme.searchIconPath

                        height: parent.height * 0.6
                        width : height

                        anchors.centerIn: parent
                        fillMode: Image.PreserveAspectFit
                    }
                }
                Rectangle {
                    color: Theme.searchTextInputBackgroundColor
                    Layout.fillWidth: true
                    Layout.fillHeight: true
                    TextInput {
                        id: searchInput

                        height: parent.height
                        width: parent.width
                        verticalAlignment: TextInput.AlignVCenter
                        font.pixelSize: parent.height * 0.5
                        font.bold: true
                        clip: true

                        color            : Theme.searchTextInputColor
                        selectionColor   : Theme.searchSelectionColor
                        selectedTextColor: Theme.searchSelectionTextColor

                        Text {
                            anchors.fill: parent
                            verticalAlignment: Text.AlignVCenter
                            text: searchArea.watermark
                            color: Theme.searchTextColor
                            font.pixelSize: searchInput.font.pixelSize
                            visible: searchInput.text.length === 0
                            font.bold: true
                        }

                        HoverHandler { cursorShape: Qt.IBeamCursor }

                        onTextChanged: {
                            //  TODO: Отображать только соответствующие игредиенты если введенное слово есть в имени
                            console.log("text changed: " + appSettings.language)
                        }
                    }
                }

            }
        }

        Rectangle {
            id: editIconBackground

            Layout.preferredHeight: searchRow.height
            Layout.preferredWidth : searchRow.height

            function resolveColor(normal, hover, selected) {
                if(mouseArea.pressed)
                    return selected
                if(mouseArea.containsMouse)
                    return hover
                return normal
            }

            color: resolveColor(Theme.editIconBackground, Theme.editIconBackgroundHover, Theme.editIconBackgroundPressed)

            IconImage {
                id: editIcon
                source: Theme.editIconPath
                height: parent.height * 0.8
                width : height

                anchors.centerIn: parent
                fillMode: Image.PreserveAspectFit

                // color logic
                color: editIconBackground.resolveColor(Theme.editIcon, Theme.editIconHover, Theme.editIconHover)
            }

            signal clicked
            Behavior on color { ColorAnimation { duration: Theme.animationDuration } }
            MouseArea {
                id: mouseArea
                anchors.fill: parent
                hoverEnabled: true
                cursorShape: Qt.PointingHandCursor

                onClicked: {
                    // TODO: Open edit ingredients window
                }
            }
        }
    }
}
