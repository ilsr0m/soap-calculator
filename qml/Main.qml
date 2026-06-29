import QtQuick
import QtQuick.Layouts
import "components/panels/ingredient-panel"
import "themes"
import SoapCalculator 1.0
import QtQuick.Controls

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

    // Инструкции к программе после загрузки Window
    Component.onCompleted: {
        appSettings.language = "en"
    }

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

            ComboBox {
                id: typeBox
                Layout.preferredWidth: parent.width
                Layout.preferredHeight: parent.height * 0.04
                model: [qsTr("  LIPIDS"), qsTr("  ACIDS"), qsTr("  ADDITIVES")]
                focusPolicy: Qt.NoFocus

                font.pixelSize: parent.height * 0.02
                font.bold: true

                HoverHandler {
                    id: hoverHandler
                    cursorShape: Qt.PointingHandCursor
                }
            }

            // Блок с липидами
            IngredientPanel {
                // radius: Theme.radius
                width : parent.width  * 0.25
                height: parent.height * 0.85

                Layout.fillWidth: true
                Layout.fillHeight: true

                // title: qsTr("CHOOSE LIPIDS")
                model: setIngredientModel()

                function setIngredientModel(){
                    return typeBox.currentIndex === 0 ? lipidProxyModel :
                            typeBox.currentIndex === 1 ? acidProxyModel :
                                                         additiveProxyModel
                }
            }
        }

        // Центр
        Rectangle {
            // radius: Theme.radius

            Layout.fillHeight: true
            Layout.fillWidth: true
            Layout.preferredWidth: parent.width * 0.36
            color: Theme.panel

            ColumnLayout {
                anchors.fill: parent
                anchors.margins: 6
                spacing: 6

                RowLayout {
                    Layout.fillWidth: true
                    Layout.preferredHeight: parent.height * 0.1

                    // Layout.preferredHeight: 70
                    // Layout.minimumHeight: 70
                    // Layout.maximumHeight: 70

                    Rectangle {
                        Layout.fillHeight: true
                        Layout.fillWidth: true
                        color: "white"
                    }

                    Rectangle {
                        Layout.fillHeight: true
                        Layout.fillWidth: true
                        color: "white"
                    }
                }

                RowLayout {
                    Layout.fillWidth: true
                    Layout.preferredHeight: parent.height * 0.1

                    // Layout.preferredHeight: 70
                    // Layout.minimumHeight: 70
                    // Layout.maximumHeight: 70

                    Rectangle {
                        Layout.fillHeight: true
                        Layout.fillWidth: true
                        color: "white"
                    }

                    Rectangle {
                        Layout.fillHeight: true
                        Layout.fillWidth: true
                        color: "white"
                    }
                }

                Rectangle{
                    // Layout.fillHeight: true
                    Layout.fillWidth: true
                    Layout.preferredHeight: parent.height * 0.8
                    color: "white"
                }
            }

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
