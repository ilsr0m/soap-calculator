pragma Singleton
import QtQuick

QtObject {
    /* --- Header / Sections --- */
    readonly property color header: "#5d5c61"
    readonly property color headerText: "white"

    /* --- Search --- */
    readonly property string seachIcon: "qrc:/resources/icons/search.svg"

    /* --- View --- */

    /* --- Buttons --- */
    // Base


    readonly property color button              : "#7395ae"
    readonly property color buttonText          : "white"
    readonly property color buttonBorder        : "#7395ae"



    // Hover
    readonly property color buttonHover         : "#5d5c61"
    readonly property color buttonTextHover     : "white"
    readonly property color buttonBorderHover   : "#5d5c61"
    // Pressed
    readonly property color buttonPressed       : "#d1cfc9"
    readonly property color buttonTextPressed   : "#5d5c61"
    readonly property color buttonBorderPressed : "#5d5c61"


    // Base
    property color background: "#d1cfc9"
    property color panel: "#d1cfc9"
    property color surface: "#fafafa"

    // Text
    property color text: "#46211a"
    property color secondaryText: "#693d3d"

    // Borders
    property color border: "#d0d7de"

    // Accent
    property color accent: "#4f8cff"
    property color accentHover: "#3d7df0"
    property color accentPressed: "#2f6fe5"

    // States
    property color success: "#2e7d32"
    property color warning: "#ed6c02"
    property color error: "#d32f2f"

    // Inputs
    property color inputBackground: "#ffffff"
    property color inputBorder: "#c7c7c7"
    property color inputFocus: "#4f8cff"



    // ListView
    property color listItem: "#ffffff"
    property color listItemHover: "#eef4ff"
    property color listItemSelected: "#dbe9ff"

    // Radius
    property int radiusSmall: 6
    property int radiusMedium: 10

    // Spacing
    property int spacingSmall: 4
    property int spacingMedium: 8
    property int spacingLarge: 12

    property int radius: 8
    property int spacing: 8
}
