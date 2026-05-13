import QtQuick
import QtQuick.Layouts
import "components/panels"
import "themes"

Window {
    id: mainRoot

    Theme { id: theme }

    width: 1100
    height: 800
    visible: true

    minimumWidth: 1100
    minimumHeight: 800

    title: qsTr("SOAP CALCULATOR")

    property int gap: 6

    RowLayout
    {
        anchors.fill: parent
        anchors.margins: mainRoot.gap
        spacing: mainRoot.gap

        // Левая колонка
        ColumnLayout {
            Layout.fillHeight: true
            Layout.preferredWidth: parent.width * 0.28
            Layout.minimumWidth: 220
            Layout.maximumWidth: 420

            IngredientPanel {
                Layout.fillWidth: true
                Layout.fillHeight: true
                title: qsTr("CHOOSE LIPIDS")
                model: lipidsModel
            }

            IngredientPanel {
                Layout.fillWidth: true
                Layout.fillHeight: true
                title: qsTr("CHOOSE ACIDS")
                model: acidsModel
            }

            IngredientPanel {
                Layout.fillWidth: true
                Layout.fillHeight: true
                title: qsTr("CHOOSE ADDITIVES")
                model: additivesModel
            }
        }

        // Центр
        Rectangle {
            Layout.fillHeight: true
            Layout.fillWidth: true
            Layout.preferredWidth: parent.width * 0.36
            color: theme.panel
        }

        // Правая колонка
        Rectangle {
            Layout.fillHeight: true
            Layout.fillWidth: true
            Layout.preferredWidth: parent.width * 0.36
            color: theme.panel
        }

    }





}
