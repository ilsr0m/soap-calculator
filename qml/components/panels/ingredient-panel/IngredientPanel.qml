import QtQuick
import QtQuick.Layouts
import QtQuick.Controls

import SoapCalculator
import "ingredient-components"

Rectangle {
    id: root
    color: Theme.panel

    property int gap: 6

    property string title: qsTr("TITLE")
    property string searchWatermark: qsTr("SEARCH...")
    property string addButtonText : qsTr("ADD TO RECIPE")
    property string infoButtonText: qsTr("INFO")

    property var model

    ColumnLayout {
        anchors.fill: parent
        anchors.margins: root.gap
        spacing: root.gap

        IngredientTitle {
            Layout.fillWidth: true
            Layout.preferredHeight: parent.height * 0.1
            titleText: root.title
        }

        IngredientSearch {
            Layout.fillWidth: true
            Layout.preferredHeight: parent.height * 0.10
            watermark: root.searchWatermark
        }

        IngredientView {
            Layout.fillWidth: true
            Layout.fillHeight: true
            model: root.model
        }

        IngredientButtons {
            Layout.fillWidth: true
            Layout.preferredHeight: parent.height * 0.12

            infoButtonText: root.infoButtonText
            addButtonText : root.addButtonText
        }
    }
}



