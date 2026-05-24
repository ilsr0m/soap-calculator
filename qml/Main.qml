import QtQuick
import QtQuick.Layouts
import "components/panels/ingredient-panel"
import "themes"
import SoapCalculator 1.0

Window {
    id: mainRoot

    // Theme { id: theme }

    width: 1100
    height: 800
    visible: true

    minimumWidth: 1100
    minimumHeight: 800

    title: qsTr("SOAP CALCULATOR")

    property int gap: 6

    color: Theme.mainWindow

    Component.onCompleted: { appSettings.language = "ru" }

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
                // radius: Theme.radius
                width : parent.width  * 0.25
                height: parent.height * 0.25

                Layout.fillWidth: true
                Layout.fillHeight: true
                title: qsTr("CHOOSE LIPIDS")
                model: lipidModel
            }

            IngredientPanel {
                // radius: Theme.radius
                width : parent.width  * 0.25
                height: parent.height * 0.25

                Layout.fillWidth: true
                Layout.fillHeight: true
                title: qsTr("CHOOSE ACIDS")
                model: acidModel
            }

            IngredientPanel {
                // radius: Theme.radius
                width : parent.width  * 0.25
                height: parent.height * 0.25

                Layout.fillWidth: true
                Layout.fillHeight: true
                title: qsTr("CHOOSE ADDITIVES")
                model: additiveModel
            }
        }

        // Центр
        Rectangle {
            // radius: Theme.radius

            Layout.fillHeight: true
            Layout.fillWidth: true
            Layout.preferredWidth: parent.width * 0.36
            color: Theme.panel
        }

        // Правая колонка
        Rectangle {
            // radius: Theme.radius

            Layout.fillHeight: true
            Layout.fillWidth: true
            Layout.preferredWidth: parent.width * 0.36
            color: Theme.panel
        }

    }





}
