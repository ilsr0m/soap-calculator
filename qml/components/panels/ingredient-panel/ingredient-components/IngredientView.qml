import QtQuick
import QtQuick.Layouts
import QtQuick.Controls

import SoapCalculator

Rectangle {
    id: listArea
    color: Theme.listView
    property var model

    ListView {
        id: listView
        currentIndex: -1

        anchors.fill: listArea
        model: listArea.model

        clip: true
        boundsBehavior: Flickable.StopAtBounds
        flickableDirection: Flickable.VerticalFlick
        ScrollBar.vertical: ScrollBar { policy: ScrollBar.AsNeeded }

        focus: true

        delegate: Rectangle {
            id: viewDelegate

            width: ListView.view.width
            height: listArea.height * 0.06

            RowLayout {
                anchors.fill: parent
                spacing: 0
                // Оборачиваем checkbox
                Item {
                    // Layout.fillHeight: true
                    Layout.preferredHeight: parent.height
                    Layout.preferredWidth : parent.height

                    BaseCheckbox {
                        id: checkbox
                        width: parent.width * 0.5
                        height: parent.height * 0.5
                        anchors.centerIn: parent

                        accentColor: viewDelegate.contentColor

                        checked: model.checked === undefined ? false : model.checked
                        onClicked: {
                                model.checked = !model.checked
                        }
                    }
                }

                // Оборачиваем текст
                Item {
                    Layout.fillWidth: true
                    Text {
                        id: textName
                        anchors.left: parent.left
                        anchors.verticalCenter: parent.verticalCenter
                        anchors.leftMargin: 10

                        color: viewDelegate.contentColor

                        text: model.name
                        font.pixelSize: listArea.height * 0.02
                        font.bold: true
                    }
                }

            }

            // Поведение палитры делегата
            function resolveColor(normal, hover, selected) {
                if (ListView.isCurrentItem) {
                    return selected
                }
                if(tapHandler.pressed){
                    return selected
                }
                if(hoverHandler.hovered){
                    return hover
                }
                return normal
            }

            color: viewDelegate.resolveColor(
                Theme.listItem,Theme.listItemHover,Theme.listItemPressed)
            property color contentColor: viewDelegate.resolveColor(
                Theme.listItemText, Theme.listItemTextHover,Theme.listItemTextPressed)

            // Поведение списка при работе с компьютерной мышью
            Behavior on color {
                ColorAnimation {
                    duration: Theme.animationDuration
                }
            }

            HoverHandler {
                id: hoverHandler
                cursorShape: Qt.PointingHandCursor
                onHoveredChanged: function() {

                }
            }

            TapHandler {
                id: tapHandler
                acceptedButtons: Qt.LeftButton | Qt.RightButton
                onTapped: function(eventPoint, button) {

                    if(button === Qt.LeftButton) {
                        listView.currentIndex =
                                (listView.currentIndex === index) ? -1 : index
                    }
                    if(button === Qt.RightButton) {
                        listView.currentIndex = -1
                    }
                }

                onDoubleTapped: {
                    model.checked = !model.checked
                }
            }

            // Keys.onReturnPressed: {
            //     if (currentIndex >= 0)
            //             model.setData(
            //                 model.index(currentIndex, 0),
            //                 !model.data(
            //                     model.index(currentIndex, 0),
            //                     Roles.CheckedRole
            //                 ),
            //                 Roles.CheckedRole
            //             )
            //     }
        }
    }
}
