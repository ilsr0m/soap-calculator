pragma Singleton
import QtQuick

QtObject {
    /* --- Header / Sections --- */
    readonly property color header: "#5d5c61"
    readonly property color headerText: "white"

    /* --- Search --- */
    readonly property string seachIcon: "qrc:/resources/icons/search.svg"
    readonly property color searchSelectionColor: "#7395ae"
    readonly property color searchSelectionTextColor: "white"

    /* --- View --- */

    /* --- Buttons --- */
    // -> Neutral
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
    // -> Positive
    // Base
    readonly property color buttonPositive              : "#6fa36f"
    readonly property color buttonTextPositive          : "white"
    readonly property color buttonBorderPositive        : "#6fa36f"
    // Hover
    readonly property color buttonHoverPositive         : "#5d5c61"
    readonly property color buttonTextHoverPositive     : "white"
    readonly property color buttonBorderHoverPositive   : "#5d5c61"
    // Pressed
    readonly property color buttonPressedPositive       : "#d1cfc9"
    readonly property color buttonTextPressedPositive   : "#5d5c61"
    readonly property color buttonBorderPressedPositive : "#5d5c61"
    // -> Negative
    // Base
    readonly property color buttonNegative              : "#bf5054"
    readonly property color buttonTextNegative          : "white"
    readonly property color buttonBorderNegative        : "#bf5054"
    // Hover
    readonly property color buttonHoverNegative         : "#5d5c61"
    readonly property color buttonTextHoverNegative     : "white"
    readonly property color buttonBorderHoverNegative   : "#5d5c61"
    // Pressed
    readonly property color buttonPressedNegative       : "#d1cfc9"
    readonly property color buttonTextPressedNegative   : "#5d5c61"
    readonly property color buttonBorderPressedNegative : "#5d5c61"
    /* --- Buttons end --- */

    // Base
    readonly property color background: "#d1cfc9"
    readonly property color panel: "#d1cfc9"

    // ListView
    readonly property color listView        : "white"
    // readonly property color listItem        : "white"
    // readonly property color listItemBorder  : "white"
    // readonly property color listItemText    : "#5d5c61"

    readonly property color listItem          : "white"
    readonly property color listItemText      : "#5d5c61"
    readonly property color listItemHover     : "#5d5c61"
    readonly property color listItemTextHover : "white"
    readonly property color listItemPressed     : "#7395ae"
    readonly property color listItemTextPressed : "white"
    // readonly property color listItemBorder  : "white"





    // readonly property color listItemHover   : "#5d5c61"
    // readonly property color listItemSelected: "#5d5c61"

    // readonly property color listItemHover   : "#5d5c61"
    // readonly property color listItemSelected: "#5d5c61"

    readonly property int radius: 0
    readonly property int spacing: 8
}
