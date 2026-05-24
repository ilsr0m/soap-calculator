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
                text: name

                font.pixelSize: listArea.height * 0.1
                font.bold: true
            }

            color: viewDelegate.resolveColor(Theme.listItem,
                                             Theme.listItemHover,
                                             Theme.listItemPressed)
            signal clicked
            Behavior on color { ColorAnimation { duration: Theme.animationDuration } }
            MouseArea {
                id: mouseArea
                anchors.fill: parent
                hoverEnabled: true
                cursorShape: Qt.PointingHandCursor

                acceptedButtons: Qt.LeftButton | Qt.RightButton
                onClicked: function(mouse) {
                    if(mouse.button === Qt.LeftButton)
                        listView.currentIndex = index
                    if(mouse.button === Qt.RightButton)
                        listView.currentIndex = -1
                }
            }
        }
    }
}
